/*
  C程序的结构

  请仔细阅读下面源码注释，并编译，使用valgrind运行

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

  // printf函数，接受两个参数，第一个是字符串，第二个是要替换占位符的变量
  printf("you are %d miles away. \n", distance);

  // 返回0，告诉系统要退出了
  return 0;
}
