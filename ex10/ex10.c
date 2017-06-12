/*
字符串数组和循环

直接使用main函数参数 *argv[]这个字符串

TODO:

打印一下argv[0]看看是什么
弄清楚for循环
尝试在states中增加一个元素NULL，看看会打印什么
看看能否在打印前将states中的元素赋值给argv，然后再试试相反的操作

*/


#include <stdio.h>

/*
每个命令行的参数会作为字符串传入argv数组
argc会被置为argv数组中参数的数量
比如：
  $ ./ex10 a b c
输出：
  arg 1 : a
  arg 2 : b
  arg 3 : c
  state 0: California
  state 1: Orgon
  state 2: Washington
  state 3: Texas
*/
int main(int argc, char *argv[])
{
  int i = 0;
  // for循环语句。
  // 第一个参数用来初始化循环，中间的为终止循环条件，第三个参数增加循环变量以便进入下一个循环
  for(i = 1; i < argc; i++){
    printf("arg %d : %s \n", i, argv[i]);
  }

  // 这种写法创建了一个二维字符串数组
  char *states[] = {
    "California", "Orgon",
    "Washington", "Texas"
  };

  int num_states = 4;

  for(i=0; i < num_states; i++){
    printf("state %d: %s\n", i, states[i]);
  }
  return 0;
}
