/*
While循环和布尔表达式

C语言中，其实没有真正的布尔表达式，而是用整数0来表示false，其他值表示true
在ex10中的 i < argc 表达式，实际上会返回0或1，而不会返回true或false之类的字符。


TODO:

修改while条件，使其从argc开始递减循环，用i--
使用while循环，将argv中的值复制到states中
让这个循环复制不会失败，即使argv之中有很多元素也不会被全部放进states中
研究你是否真正复制了字符串
*/


#include <stdio.h>

int main(int argc, char *argv[])
{
  int i = 0;
  // for循环语句。
  // 第一个参数用来初始化循环，中间的为终止循环条件，第三个参数增加循环变量以便进入下一个循环
  while(i < argc){
    printf("arg %d : %s \n", i, argv[i]);
    i++;
  }

  // 这种写法创建了一个二维字符串数组
  char *states[] = {
    "California", "Orgon",
    "Washington", "Texas"
  };

  int num_states = 4;
  i = 0;
  while(i < num_states){
    printf("state %d: %s\n", i, states[i]);
    i++;
  }
  return 0;
}
