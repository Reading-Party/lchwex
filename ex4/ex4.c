/*
  下面是错误的代码，为了尝试使用valgrind，主要有两个错误：

  1. height未初始化
  2. 第一条printf未传变量（编译器会警告）

  执行命令：

  $  make ex4
  $ valgrind ./ex4

TODO：
  仔细阅读valgrind的检查信息来理解这里面的错误，并修正
  互联网上多参考valgrind的资料
  看valgrind源码的组织方式以及Makefile(https://github.com/svn2github/valgrind)
*/

#include <stdio.h>

int main()
{
  int age = 10;
  int height;

  printf("I'm %d years old\n");
  printf("I'm %d inches tall\n", height);

  return 0;
}
