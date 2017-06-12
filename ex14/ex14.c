/*

使用自己的函数


TODO:

重构代码，减少函数
使用strlen函数，让print_arguments知道每个字符串参数有多长，然后将长度传入print_letters
重写print_letters，只处理固定长度，而不需要\0终止符，这需要 #include <string.h>
*/


#include <stdio.h>
// 该头文件中包含了isalpha(ch) 和 isblank(ch)函数
#include <ctype.h>

// 前向声明
int can_print_it(char ch);
void print_letters(char arg[]);

// 定义函数
void print_arguments(int argc, char *argv[])
{
  int i = 0;
  for(i=0; i < argc; i++){
    print_letters(argv[i]);
  }
}

void print_letters(char arg[])
{
  int i = 0;
  for(i=0; arg[i] != '\0'; i++){
    char ch = arg[i];

    if(can_print_it(ch)) {
      printf(" '%c' == %d \n", ch, ch);
    }
  }
  printf("\n");
}

// 返回0或1
int can_print_it(char ch)
{
  return isalpha(ch) || isblank(ch);
}

int main(int argc, char *argv[])
{
  print_arguments(argc, argv);
  return 0;
}
