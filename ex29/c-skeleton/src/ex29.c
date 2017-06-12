/*

库和链接

手动构建命令：

$ cc -fPIC -c libex29.c -o libex29.o
$ cc -shared -fPIC -o libex29.so libex29.o
$ cc -Wall -g -DNDEBUG ex29.c -ldl -o ex29

$ ./ex29 ./libex29.so print_a_message "hello there"
$ ./ex29 ./libex29.so uppercase "hello there"
$ ./ex29 ./libex29.so lowercase "HelLo ThEre"
$ ./ex29 ./libex29.so fail_on_purpose "i Fail"


TODO:

修正libex29.c中的bug
修改Makefile使得可以构建libex29.so

*/

#include <stdio.h>
#include "dbg.h"
#include <dlfcn.h>

typedef int (*lib_function)(const char *data);

int main(int argc, char *argv[]) {
  int rc = 0;
  check(argc == 4, "USAGE: ex29 libex29.so function data");

  char *lib_file = argv[1];
  char *func_to_run = argv[2];
  char *data = argv[3];

  // 使用dlopen函数来加载由lib_file表示的库
  void *lib = dlopen(lib_file, RTLD_NOW);
  check(lib != NULL, "Failed to open the library %s: %s", lib_file, dlerror());

  // 使用dlsym来获取lib中的函数，动态获取了一份函数指针
  lib_function func = dlsym(lib, func_to_run);
  check(func != NULL, "Did not find %s function in the library %s: %s", func_to_run, lib_file, dlerror());

  // 调用func
  rc = func(data);
  check(rc == 0, "Function %s return %d for data: %s", func_to_run, rc, data);

  rc = dlclose(lib);
  check(rc == 0, "Failed to close %s", lib_file);

  return 0;
error:
  return 1;
}
