

/*
  执行命令编译它：
    $ make ex1
  编译后执行：
    $ ./ex1
  使它崩溃：
    $ CFLAGS="-Wall" make ex1
  输出警告：
    warning: implicit declaration of function ‘puts’ ...
  想去除警告就得添加头文件
   #include <stdio.h>

  TODO:
  删除下面代码种的任意部分，编译看看出什么问题
  多打印几行文本
  查看man puts


*/

#include <stdio.h>
int main(int argc, char *argv[])
{
  puts("hello world");
  return 0;
}
