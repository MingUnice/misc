#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "ioctl_example"
#define IOCTL_SET_MSG _IOR('k', 0, char *)

static char msg[256] = {0};

static int device_open(struct inode *inode, struct file *file)
{
  pr_info("Device opened\n");
  return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
  pr_info("Device released\n");
  return 0;
}

static long device_ioctl(struct file *file, unsigned int ioctl_num, unsigned long ioctl_param)
{
  int err = 0;
  char *ptr = (char *)ioctl_param;

  switch (ioctl_num) {
  case IOCTL_SET_MSG:
    err = copy_from_user(msg, ptr, sizeof(msg));
    if (err) {
      pr_err("Failed to copy message from user\n");
      return -EFAULT;
    }
    pr_info("Message from user: %s\n", msg);
    break;
  default:
    pr_err("Invalid IOCTL command\n");
    return -EINVAL;
  }

  return 0;
}

static ssize_t device_write(struct file *file, const char __user *buf, size_t count, loff_t *offset)
{
  char buffer[16];
  copy_from_user(buffer, buf, sizeof(buffer));
  pr_info("device write get msg: %s\n", buffer);
  return sizeof(buffer);
}

static struct file_operations fops = {
                                      .open = device_open,
                                      .release = device_release,
                                      .unlocked_ioctl = device_ioctl,
                                      .write = device_write,
};

static struct cdev cdev;
static dev_t dev;
static struct class *class;

static int __init ioctl_example_init(void)
{
  if (alloc_chrdev_region(&dev, 0, 1, DEVICE_NAME) < 0) {
    pr_err("Failed to allocate character device region\n");
    return -1;
  }

  cdev_init(&cdev, &fops);
  if (cdev_add(&cdev, dev, 1) < 0) {
    pr_err("Failed to add character device\n");
    unregister_chrdev_region(dev, 1);
    return -1;
  }

  class = class_create(THIS_MODULE, DEVICE_NAME);
  if (IS_ERR(class)) {
    pr_err("Failed to create device class\n");
    cdev_del(&cdev);
    unregister_chrdev_region(dev, 1);
    return -1;
  }

  device_create(class, NULL, dev, NULL, DEVICE_NAME);

  pr_info("Module loaded\n");
  return 0;
}

static void __exit ioctl_example_exit(void)
{
  device_destroy(class, dev);
  class_destroy(class);
  cdev_del(&cdev);
  unregister_chrdev_region(dev, 1);
  pr_info("Module unloaded\n");
}

module_init(ioctl_example_init);
module_exit(ioctl_example_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A kernel module with IOCTL communication");
