#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/timer.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Hello world kernel module");

#define PROC_FILE_NAME "print_count"

static struct timer_list hello_timer;
static unsigned int interval = 5;  // Default interval is 5 seconds
static unsigned int print_count = 0;

module_param(interval, uint, 0644);
MODULE_PARM_DESC(interval, "Interval in seconds");

static struct proc_dir_entry *proc_file_entry;

void hello_timer_callback(struct timer_list *timer)
{
#ifdef CONFIG_X86_32
  printk(KERN_INFO "32\n");
#endif
#ifdef CONFIG_X86_64
  printk(KERN_INFO "64\n");
#endif   
  printk(KERN_INFO "Hello world\n");
  print_count++;
  mod_timer(timer, jiffies + msecs_to_jiffies(interval * 1000));
}

static ssize_t print_count_read(struct file *file, char __user *buf,
                                size_t count, loff_t *ppos)
{
  char buffer[16];
  int len;
  len = snprintf(buffer, sizeof(buffer), "%u\n", print_count);
  if (*ppos >= len)
    return 0;
  if (count > len - *ppos)
    count = len - *ppos;
  if (copy_to_user(buf, buffer + *ppos, count))
    return -EFAULT;
  *ppos += count;
  return count;
}

static const struct file_operations proc_file_fops = {
                                                      .owner = THIS_MODULE,
                                                      .read = print_count_read,
};

static int __init hello_init(void)
{
  printk(KERN_INFO "Hello module loaded\n");
    
  timer_setup(&hello_timer, hello_timer_callback, 0);
  mod_timer(&hello_timer, jiffies + msecs_to_jiffies(interval * 1000));
    
  proc_file_entry = proc_create(PROC_FILE_NAME, 0644, NULL, &proc_file_fops);
  if (!proc_file_entry) {
    printk(KERN_ALERT "Failed to create /proc/%s\n", PROC_FILE_NAME);
    return -ENOMEM;
  }
    
  return 0;
}

static void __exit hello_exit(void)
{
  del_timer(&hello_timer);
  printk(KERN_INFO "Hello module unloaded\n");
    
  remove_proc_entry(PROC_FILE_NAME, NULL);
}

module_init(hello_init);
module_exit(hello_exit);
