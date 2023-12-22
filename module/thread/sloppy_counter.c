#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/delay.h>

static struct task_struct *sloppy_thread;
static atomic_t counter = ATOMIC_INIT(0);

static int sloppy_counter_thread(void *data)
{
  while (!kthread_should_stop()) {
    atomic_inc(&counter);
    msleep_interruptible(1000); // Increment counter every second
  }

  return 0;
}

static int __init sloppy_counter_init(void)
{
  pr_info("Sloppy Counter module loaded\n");

  sloppy_thread = kthread_run(sloppy_counter_thread, NULL, "sloppy_counter");
  if (IS_ERR(sloppy_thread)) {
    pr_err("Failed to create sloppy counter thread\n");
    return PTR_ERR(sloppy_thread);
  }

  return 0;
}

static void __exit sloppy_counter_exit(void)
{
  kthread_stop(sloppy_thread);
  pr_info("Sloppy Counter module unloaded\n");
}

module_init(sloppy_counter_init);
module_exit(sloppy_counter_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A Linux kernel module with a sloppy counter");
