/*
  更多变量和算术

  int  float  char 和 double类型

TODO:

把universe_of_defects的值改成不同的大小，观察编译器警告
巨大的数字打印成了什么
讲long改成unsigned long，并试着找出该类型最大的数字
上网搜索unsigned是什么
解释下char和int为什么可以相乘
你可以打开READEME文件做点笔记
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
  int bugs = 100;
  double bug_rate = 1.2;
  printf("you are %d bugs at the imaginary rate of %f. \n", bugs, bug_rate);

  long universe_of_defects = 1L * 1024L * 1024L * 1024L;
  printf("the entire universe has %ld bugs. \n", universe_of_defects);

  double expected_bugs = bugs * bug_rate;
  printf("you are expected  to have %f bugs. \n", expected_bugs);

  double part_of_universe = expected_bugs / universe_of_defects;
  printf("That is only a %e portion of the universe. \n", part_of_universe);

  char nul_byte = '\0';//空字节字符，实际上是数字0
  int care_percentage = bugs * nul_byte;
  printf("Which means you should care %d%%. \n", care_percentage);


  // 返回0，告诉系统要退出了
  return 0;
}
