/*

Switch 语句

C中的Switch语句实际上是一个“跳转表”

TODO:

去掉break或default查看编译信息
编写另一个程序，在字母上做算术运算将它们转换为小写，并在switch中移出大写字母
使用逗号在for循环中初始化letter
将switch转换为if感受一下

*/


#include <stdio.h>

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("ERROR: You need one argument. \n");
    return 1;
  }

  int i = 0;
  for(i=0; argv[1][i] != '\0'; i++){
    char letter = argv[1][i];

    switch (letter) {
      // case 'a'没有break，所以会继续执行到下面的case 'A'
      case 'a':
      case 'A':
          printf("%d: 'A'\n", i);
          // break跳出switch语句
          break;
      case 'e':
      case 'E':
          printf("%d: 'E'\n", i);
          break;
      case 'i':
      case 'I':
          printf("%d: 'I'\n", i);
          break;
      case 'o':
      case 'O':
          printf("%d: 'O'\n", i);
          break;
      case 'u':
      case 'U':
          printf("%d: 'U'\n", i);
          break;
      case 'y':
      case 'Y':
          if(i > 2){
            printf("%d: 'Y'\n", i);
          }
          break;
      default:
          printf("%d: %c is not a vowel\n", i, letter);
    }
  }
  return 0;
}
