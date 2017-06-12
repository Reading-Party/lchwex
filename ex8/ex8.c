/*
大小和数组

sizeof和数组

C中的字符为字节数组

输出：

the size of an int : 4
the size of areas (int[]) : 20
the numbers of ints in  areas : 5
the first areas is : 10 , the 2nd 12.
the size of an char : 1
the size of name (char[]) : 4
the numbers of chars : 4
the size of full name (char[]) : 12.
the numbers of chars : 12

可以看到各个类型占了多少字节

TODO：

移除full_name结尾的\0，让其崩溃，在valgrind下运行查看错误信息
尝试赋值  areas[0] = 100;
尝试将areas中的某个元素改成字符
尝试对name和full_name赋值: name[0] = 'A'; full_name[0] = 'A';

*/


#include <stdio.h>

int main(int argc, char *argv[])
{
  // 这种方式来创建数组
  int areas[] = {10, 12, 13, 14, 20};

  // 效果和上面areas一样，会创建一个字符数组
  // 末尾有个\0代表字符串结束，所以name会占4个字节
  char name[] = "Zed";

  char full_name[] = {
    'Z', 'e', 'd',
    ' ', 'A', '.', ' ',
    'S', 'h', 'a', 'w', '\0'
  };

  // sizeof来查看占多少字节
  printf("the size of an int : %ld \n", sizeof(int));
  printf("the size of areas (int[]) : %ld \n", sizeof(areas));
  printf("the numbers of ints in  areas : %ld \n", sizeof(areas)/sizeof(int));
  printf("the first areas is : %d , the 2nd %d. \n", areas[0], areas[1]);

  printf("the size of an char : %ld \n", sizeof(char));
  printf("the size of name (char[]) : %ld \n", sizeof(name));
  printf("the numbers of chars : %ld \n", sizeof(name)/sizeof(char));
  printf("the size of full name (char[]) : %ld. \n", sizeof(full_name));
  printf("the numbers of chars : %ld \n", sizeof(full_name)/sizeof(char));
  printf("name = \"%s\" and full_name = \"%s\" \n", name, full_name);


  return 0;
}
