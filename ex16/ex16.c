/*
结构体和指针

TODO:

确保能理解每一行代码的作用
对于不理解的自行查阅互联网
试着给Person_destroy传递NULL看看会发生什么
忘记调用Person_destroy，用valgrind运行看看会有什么报告
忘记free who->name，用valgrind运行看看有什么报告
给Person_print传递NULL，观察valgrind会输出什么
将此程序改成不用指针和malloc的版本，所以你需要研究下面东西：
   如何在栈上创建结构体，因为malloc是在堆上分配内存
   使用x.y而不是x->y来初始化结构体
   如何不使用指针将结构体传递给其他函数

*/


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// 注意struct加分号
// struct创建结构体，包含了四个成员
struct Person{
  char *name;
  int age;
  int height;
  int weight;
};

// 创建结构体实例的函数
// struct Person是作为一个类型存在
// 此函数为结构体类型的指针函数，返回一个指针
struct Person *Person_create(char *name, int age, int height, int weight)
{
  // malloc分配内存
  // sizeof用来计算所需内存大小
  struct Person *who = malloc(sizeof(struct Person));
  // assert确保得到一块有效的内存
  // NULL代表无效指针
  assert(who != NULL);

  // x->y 语法来初始化每个成员，等价于*(x).y
  // strdup赋值name，确保结构体真正拥有它
  // strdup的行为类似于malloc但是它同时会将原来的字符串复制到新的内存
  who->name = strdup(name);
  who->age = age;
  who->height = height;
  who->weight = weight;

  return who;
}

// void无返回值
// free释放掉strdup name和malloc分配所占用的内存，否则会有内存泄漏
// 也有第三方库来帮助你回收内存，那就是引入GC，比如libGC，把所有的malloc换成GC_malloc即可
void Person_destroy(struct Person *who)
{
  assert(who != NULL);
  free(who->name);
  free(who);
}

void Person_print(struct Person *who)
{
  printf("Name: %s\n", who->name);
  printf("\tAge: %d\n", who->age);
  printf("\tHeight: %d\n", who->height);
  printf("\tWeight: %d\n", who->weight);

}

int main(int argc, char *argv[])
{
  struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
  struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

  printf("Joe is at memory location %p: \n", joe);
  Person_print(joe);
  printf("Frank is at memory location %p: \n", frank);
  Person_print(frank);

  joe->age += 20;
  joe->height -= 20;
  joe->weight += 40;
  Person_print(joe);

  frank->age += 20;
  frank->weight += 20;
  Person_print(frank);

  Person_destroy(joe);
  Person_destroy(frank);

  return 0;
}
