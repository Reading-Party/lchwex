/*
格式化输出: printf语句

执行命令 : make ex3
语句说明：

1. 头文件stdio.h中，定义了printf函数
2. age变量被设置为了10，int为整数类型
3. height变量被设置为72，同样是int
4. printf函数打印这两个变量
5. printf中含有格式化占位符: %d，变量会被替换掉

printf所有的格式化字占位符和转义序列看README文件。

TODO：

尽可能的修改下面代码，在编译的时候让其崩溃，仔细看错误提示。
执行man 3 printf来看文档，熟悉其他的占位符
删掉Makefile文件，自己重新写一个来编译ex3


*/

#include <stdio.h>

int main()
{
  int age = 10;
  int height = 72;
  printf("I'm %d years old\n", age);
  printf("I'm %d inches tall\n", height);

  return 0;
}
