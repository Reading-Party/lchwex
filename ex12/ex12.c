/*
if语句


TODO:

移除else看看能否处理边界
将 && 改成 ||
在if中使用break
第一个参数的判断是否正确？修正一下，第一参数是程序文件本身

*/


#include <stdio.h>

int main(int argc, char *argv[])
{
  int i  = 0;
  if (argc == 1) {
    printf("you only have one argument. you suck. \n" );
  } else if(argc > 1 && argc < 4) {
    printf("Here's your arguments: \n");
    for(i=0; i<argc; i++){
      printf("%s\n", argv[i]);
    }
    printf("\n");
  }else{
    printf("you have too many arguments. you suck. \n" );
  }
  return 0;
}
