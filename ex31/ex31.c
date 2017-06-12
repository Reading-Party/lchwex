/*
代码调试

使用gdb来调试代码

*/



#include <unistd.h>

int main(int argc, char *argv[]) {
  int i = 0;

  while(i < 100) {
    usleep(3000);
  }

  return 0;
}
