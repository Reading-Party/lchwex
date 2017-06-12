#ifndef _ex22_h
#define _ex22_h

// extern的作用就是声明函数或全局变量的作用范围的关键字，
// 其声明的函数和变量可以在本模块活其他模块中使用，记住它是一个声明不是定义!
extern int THE_SIZE;

// set和get在ex22.c文件中的静态变量
int get_age();
void set_age(int age);

// 更新静态变量
double update_ratio(double ratio);

void print_size();

#endif
