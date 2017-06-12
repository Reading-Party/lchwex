/*
深入数组和字符串，了解内存布局

打印结果：

numbers: 0 0 0 0
name each : a
name: a
numbers: 1 2 3 4
name each : Z e d
name: Zed
another Zed
another each : Z e d


TODO:

去掉字符串中的\0来让程序崩溃：
   删除name的初始化表达式
   设置name[3] = 'A'，就把\0去掉了
将name转换成another形式，看代码是否工作

*/


#include <stdio.h>

int main(int argc, char *argv[])
{
  // 创建数组的简化方式，创建一个长度为4，元素都为0的数组
  int numbers[4] = {0};
  // 创建字符串，长度为4， 只有第一个元素被填充了'a'，后面的用'\0'填充
  char name[4] = {'a'};

  // 打印全部
  printf("numbers: %d %d %d %d  \n", numbers[0], numbers[1], numbers[2], numbers[3]);

  printf("name each : %c %c %c %c\n", name[0], name[1], name[2], name[3]);
  printf("name: %s \n", name);

  numbers[0] = 1;
  numbers[1] = 2;
  numbers[2] = 3;
  numbers[3] = 4;

  name[0] = 'Z';
  name[1] = 'e';
  name[2] = 'd';
  name[3] = '\0';

  printf("numbers: %d %d %d %d  \n", numbers[0], numbers[1], numbers[2], numbers[3]);
  printf("name each : %c %c %c %c\n", name[0], name[1], name[2], name[3]);
  printf("name: %s \n", name);

  // 另一种方法来创建字符串字面量，一般更加常用更省事
  char *another = "Zed";
  printf("another %s \n", another);
  printf("another each : %c %c %c %c \n", another[0], another[1], another[2], another[3]);
  return 0;
}
