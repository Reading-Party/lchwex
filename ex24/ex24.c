/*
输入输出文件

关于IO函数可以参考README

*/


#include <stdio.h>
#include "../bdg.h"

#define MAX_DATA 100

// 注意看enum的使用
typedef enum EyeColor {
  BLUE_EYES, GREE_EYES, BROWN_EYES,
  BLACK_EYES, OTHER_EYES
} EyeColor;

const char *EYE_COLOR_NAMES[] = {
  "Blue", "Green", "Brown", "Black", "Other"
};

typedef struct Person {
  int age;
  char first_name[MAX_DATA];
  char last_name[MAX_DATA];
  EyeColor eyes;
  float income;
} Person;

int main(int argc, char *argv[])
{
  Person you = {.age = 0};
  int i = 0;
  char *in = NULL;

  printf("What's your first name? \n");
  // fgets 从输入（stdin）读取字符串，然后赋值给struct实例you的first_name字段
  in = fgets(you.first_name, MAX_DATA-1, stdin);
  check(in != NULL, "Failed to read first name.");

  printf("What's your last name?\n");
  in = fgets(you.last_name, MAX_DATA-1, stdin);
  check(in != NULL, "Failed to read last name.");

  printf("How old are you?\n");
  // fscanf以某种格式读取输入，此处是读取整数
  // 传入了you.age的地址，以便于修改
  int rc = fscanf(stdin, "%d", &you.age);
  check(rc > 0, "you have to enter a number.");

  printf("What color are you eyes :\n");
  for(i=0; i <= OTHER_EYES; i++){
    printf("%d) %s \n", i+1, EYE_COLOR_NAMES[i]);
  }

  printf(">  ");

  int eyes = -1;
  rc = fscanf(stdin, "%d", &eyes);
  check(rc > 0, "you have to enter a number.");

  you.eyes = eyes - 1;
  check(you.eyes <= OTHER_EYES && you.eyes >= 0, "Do it right , that's not an option");

  printf("How much do you make an hour?\n");
  rc = fscanf(stdin, "%f", &you.income);
  check(rc > 0, "Enter a floating point number.");

  printf("-----RESULTES --------\n");

  printf("First Name : %s\n", you.first_name);
  printf("Last Name : %s\n", you.last_name);
  printf("Age : %d\n", you.age);
  printf("Eyes : %s\n", EYE_COLOR_NAMES[you.eyes]);
  printf("Income : %f\n", you.income);

  return 0;

error:
  return -1;
}
