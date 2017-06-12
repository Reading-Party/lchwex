/*
  变量类型

  仔细观察下面代码中printf占位符及其对应的变量类型

TODO：

随便修改下面代码让其崩溃，查看并理解错误信息
使用printf的一些高级占位符
尝试按八进制或十进制来打印数字
打印空字符串

*/

// 引入头文件stdio.h，头文件一般以.h为扩展名
#include <stdio.h>

/*

main 函数，为入口函数
花括号{}，表示函数块的开始和结束

*/
int main(int argc, char *argv[])
{
  // 定义变量，前面需要指定类型
  // 任何语句必须以分号结尾
  int distance = 100;
  float power = 2.345f;
  double super_power = 56789.4532;
  char initial = 'A';
  char first_name[] = "Zed";
  char last_name[] = "Shaw";

  // printf函数，接受两个参数，第一个是字符串，第二个是要替换占位符的变量
  printf("you are %d miles away. \n", distance);
  printf("you have %f levels of power. \n", power);
  printf("you have %f awesome super powers. \n", super_power);
  printf("I have an initial %c. \n", initial);
  printf("I have an first name %s. \n", first_name);
  printf("I have an first name %s. \n", last_name);
  printf("My whole name is %s %c.  %s. \n", first_name, initial, last_name);

  // 返回0，告诉系统要退出了
  return 0;
}
