/*

指针，传说中的指针
可以参考README里指针惯用法

TODO:

不要看下面注释，先自己搞明白指针的意义
使用访问指针的方式重写所有使用指针的地方，比如 ptr[i]
在其他程序中使用指针来代替数组访问
使用指针处理命令行参数
将获取值和获取地址组合在一起
添加for循环，打印出指针指向的地址，需要占位符为%p
把每一个打印数组的方法使用函数来重写，并且把指针当参数传入
将for循环改成while循环，观察对于每种指针用法哪种循环方便

*/


#include <stdio.h>

int main(int argc, char *argv[])
{
  int ages[] = {23, 43, 12, 89, 2};
  char *names[] = {
    "Alan", "Frank",
    "Mary", "John", "Lisa"
  };

  int count = sizeof(ages)/sizeof(int);
  int i = 0;

  for(i=0; i<count; i++){
    printf("%s has %d years alive. \n", names[i], ages[i]);
  }

  printf("---\n");

  // 创建了指向ages的指针
  // int * 指针类型为int型
  // 指向的是args第一个元素的地址
  int *cur_age = ages;
  // 创建指向字符串的指针
  // 因为names是二维的，所以需要两个*
  // 指向的是names第一个元素的地址
  char **cur_name = names;

  for(i=0; i<count; i++){
    // *(cur_name+i)等价于names[i]
    // 指针加偏移量
    // *操作符操作指针，就是解指针，取出对应的值
    printf("%s is %d years old .\n", *(cur_name+i), *(cur_age+i));
  }

  printf("---\n");

  for(i=0; i<count; i++) {
    // cur_name[i]等价于*(cur_name+i)
    printf("%s is %d years old again . \n", cur_name[i], cur_age[i]);
  }

  printf("---\n");

  // 通过将cur_name和cur_age的值置为相应数组起始位置来初始化for循环
  // cur_age - ages 差值是cur_age与起始位置的距离，也就是数组元素个数
  for(cur_name = names, cur_age = ages;
      (cur_age - ages)<count;
      cur_name++, cur_age++)
  {
    printf("%s lived %d years so far. \n", *cur_name, *cur_age);
  }

  return 0;
}
