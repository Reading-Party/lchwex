/*
栈、作用域和全局


*/


#include <stdio.h>
#include "ex22.h"
#include "bdg.h"

// 该变量是被定义于头文件中的extern变量，意味着在ex22_main.c中也可以访问它
int THE_SIZE = 1000;
// 定义于文件中的static变量只能在本文件中使用
static int THE_AGE = 37;

// 在其他文件里你不能直接访问THE_AGE，但可以通过此函数来访问THE_AGE
int get_age()
{
  return THE_AGE;
}

// 在其他文件里你不能直接访问THE_AGE，但可以通过此函数来设置THE_AGE
void set_age(int age)
{
  THE_AGE = age;
}

double update_ratio(double new_ratio)
{
  static double ratio = 1.0;
  double old_ratio = ratio;
  ratio = new_ratio;

  return old_ratio;
}

void print_size()
{
  log_info("I think size is : %d", THE_SIZE);
}
