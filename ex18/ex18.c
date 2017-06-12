/*
函数指针

函数在C中，实际上只是指向程序中某个代码存在位置的指针。
函数指针的主要作用是，向其他函数传递“回调（稍后执行的函数）”，或者模拟类或对象

函数指针的格式： int (*POINTER_NAME)(int a, int, b)

编写一个函数指针的通用步骤：

1. 编写一个普通的函数声明： int callme(int a, int b)
2. 将函数用指针语法包装： int (*callme)(int a, int b)
3. 将名称改成指针名称： int (*compare_cb)(int a, int b)

函数的名称从callme变成了compare_cb，你可以将其用作函数。
指向函数的指针，可以表示所指向的函数，只不过是名字不同而已。
即使对于返回指针的函数指针，上述方法依然有效：

当你需要使用函数指针向其他函数提供参数时比较困难，解决办法是用typedef，用它可以给更复杂的类型起个新名字。

更多关于函数指针的资料可以参考README

TODO：

编写另外一个排序算法，修改test_sorting使它可以接受任意的排序函数和排序函数的回调函数

*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char *message)
{
  if(errno){
    perror(message);
  } else {
    printf("ERROR %s\n", message);
  }
  exit(1);
}

// 通过typedef关键字，将函数指针声明为一个新类型compare_cb
typedef int (*compare_cb)(int a, int b);

// 冒泡排序的实现
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
  int temp = 0;
  int i = 0;
  int j = 0;

  int *target = malloc(count * sizeof(int));

  if(!target) die("memory error.");

  memcpy(target, numbers, count * sizeof(int));

  for(i=0; i < count; i++){
    for(j=0; j < count - 1; j++){
      if(cmp(target[j], target[j+1]) > 0) {
        temp = target[j+1];
        target[j+1] = target[j];
        target[j] = temp;
      }
    }
  }
  return target;
}

// 正序compare_cb
int sorted_order(int a, int b)
{
  return a - b;
}

// 反序compare_cb
int reverse_order(int a, int b)
{
  return b - a;
}

// 乱序compare_cb
int strange_order(int a, int b)
{
  if(a==0 || b ==0){
    return 0;
  } else {
    return a % b;
  }
}

// 按比较回调cmp来测试不同的排序
void test_sorting(int *numbers, int count, compare_cb cmp)
{
  int i = 0;
  int *sorted = bubble_sort(numbers, count, cmp);
  if(!sorted) die("Failed to sort as requested");

  for(i=0; i < count; i++){
    printf("%d\n", sorted[i]);
  }
  printf("\n");
  free(sorted);
}

int main(int argc, char *argv[])
{
  if(argc < 2) die("USAGE: ex18 4 3 1 5 6");

  int count = argc - 1;
  int i = 0;
  char **inputs = argv + 1;
  int *numbers = malloc(count * sizeof(int));
  if(!numbers) die("memory error");

  for(i=0; i < count; i++){
    numbers[i] = atoi(inputs[i]);
  }

  test_sorting(numbers, count, sorted_order);
  test_sorting(numbers, count, reverse_order);
  test_sorting(numbers, count, strange_order);

  free(numbers);

  return 0;
}
