/*
手工编译执行文件：

$ cc -Wall -g -DNDEBUG -c -o ex22.o ex22.c
$ cc -Wall -g -DNDEBUG ex22_main.c ex22.o -o ex22_main
$ ./ex22_main

TODO:

研究“值传递”和“引用（指针）传递”的差异
使用指针访问原来不能访问的变量
使用Valgrind来观察出错的样子
编写一个递归导致栈溢出的函数。可以尝试在scope_demo底部调用scope_demo。
重新编写Makefile

*/

#include "ex22.h"
#include "bdg.h"

// const 可以代替#define来创建常量
const char *MY_NAME = "Zed A. Shaw";

void scope_demo(int count)
{
  log_info("count is : %d ", count);

  // if语句会开辟一个新的作用域
  if(count > 10){
    int count = 100;
    log_info("count in this scope is %d", count);
  }

  log_info("count is at exit: %d", count);

  count = 3000;
  log_info("count after assign: %d", count);
}

int main(int argc, char *argv[])
{
  log_info("My name: %s, age : %d", MY_NAME, get_age());
  set_age(100);
  log_info("My age is now: %d", get_age());

  log_info("THE_SIZE IS: %d", THE_SIZE);
  print_size();

  THE_SIZE = 9;
  log_info("THE_SIZE IS Now: %d", THE_SIZE);
  print_size();

  log_info("Ratio at first : %f ", update_ratio(2.0));
  log_info("Ratio agian : %f ", update_ratio(2.0));
  log_info("Ratio once more : %f ", update_ratio(2.0));

  int count = 4;
  scope_demo(count);
  scope_demo(count * 20);

  // count在调用后保持不变
  // 如果想改变它，需要传入指针
  log_info("count after calling scope_demo: %d ", count);

  return 0;
}
