/*
栈和堆的内存分配

测试命令：

$ make ex17
$  valgrind ./ex17 db.dat c
$  valgrind ./ex17 db.dat s 1 zed zed@163.com
$  valgrind ./ex17 db.dat s 2 frank frank@163.com
$  valgrind ./ex17 db.dat s 3 joe joe@163.com
$  valgrind ./ex17 db.dat l
$  valgrind ./ex17 db.dat g 1
$  valgrind ./ex17 db.dat d 1


TODO:

尝试弄乱数据或者移除安全检查观察输出
向程序中传递非法参数
程序中有bug，strncpy有设计缺陷。查询strncpy的相关资料，然后试着弄清楚如果name或address超过512个字节会发生什么
尝试找出最大数据库的尺寸是多少
die函数需要接收conn变量作为参数，以便执行清理并关闭它
修改代码，使其接收参数作为MAX_DATA和MAX_ROWS，将它们存储在Database结构体中，并写到文件中。这样就可以创建任意大小的数据库了。
向数据库中添加更多操作，比如find
查询C如何打包结构体，看看你是否可以计算出结构体添加一些字段后的新大小
重构程序，使用单一全局变量来存储数据库连接
搜索栈数据结构，并由C来实现它

*/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// 使用C预处理器来定义常量
#define MAX_DATA 512
#define MAX_ROWS 100

// 使用了MAX_ROWS和MAX_DATA来创建的定长结构体
// 并不高效，但是便于存储和读取
struct Address {
  int id;
  int set;
  char name[MAX_DATA];
  char email[MAX_DATA];
};

// 此结构体也是定长的，因为Address是定长结构体
struct Database {
  struct Address rows[MAX_ROWS];
};

// FILE结构体由C标准库定义
struct Connection {
  FILE *file;
  struct Database *db;
};

// 用于在出现错误时杀掉进程退出程序
// errno和perror，都是数字，用于报告错误信息
void die(const char *message)
{
  if(errno){
    perror(message);
  } else {
    printf("ERROR %s\n", message);
  }
  exit(1);
}

void Address_print(struct Address *addr)
{
  printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

// 使用文件函数来处理文件
// fopen fread fclose rewind等
void Database_load(struct Connection *conn)
{
  int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
  if(rc != 1) die("File to load Database");
}

struct Connection *Database_open(const char *filename, char mode)
{
  struct Connection *conn = malloc(sizeof(struct Connection));
  if(!conn) die("memory error");

  conn->db = malloc(sizeof(struct Database));
  if(!conn->db) die("memory error");

  if(mode == 'c'){
    conn->file = fopen(filename, "w");
  } else {
    conn->file = fopen(filename, "r+");
    if(conn->file){
      Database_load(conn);
    }
  }
  if(!conn->file) die("Failed to open the file.");
  return conn;
}

void Database_close(struct Connection *conn)
{
  if(conn){
    if(conn->file) fclose(conn->file);
    if(conn->db) free(conn->db);
    free(conn);
  }
}

void Database_write(struct Connection *conn)
{
  rewind(conn->file);
  int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);

  if(rc != 1) die("Failed to write database.");

  rc = fflush(conn->file);
  if(rc == -1) die("Cannot flush database.");
}

void Database_create(struct Connection *conn)
{
  int i = 0;
  for(i=0; i < MAX_ROWS; i++){
    struct Address addr = {.id = i, .set = 0};
    conn->db->rows[i] = addr;
  }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
  struct Address *addr = &conn->db->rows[id];
  if(addr->set) die("Already set, delete it first");

  addr->set = 1;

  char *res = strncpy(addr->name, name, MAX_DATA);

  if(!res) die("Name Copy failed.");

  res = strncpy(addr->email, email, MAX_DATA);
  if(!res) die("Email Copy failed.");
}

void Database_get(struct Connection *conn, int id)
{
  struct Address *addr = &conn->db->rows[id];

  if(addr->set){
    Address_print(addr);
  } else {
    die("ID is not set");
  }
}

void Database_delete(struct Connection *conn, int id)
{
  struct Address addr = {.id=id, .set=0};
  conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
  int i = 0;
  struct Database *db = conn->db;

  for(i=0; i < MAX_ROWS; i++){
    // 读取db中conn的rows的第i个元素，并返回地址（&）
    struct Address *cur = &db->rows[i];
    if(cur->set){
      Address_print(cur);
    }
  }

}

int main(int argc, char *argv[])
{
  if(argc < 3) die("USAGE: ex17 <dbfile> <action> [action params]");

  char *filename = argv[1];
  char action = argv[2][0];
  struct Connection *conn = Database_open(filename, action);
  int id = 0;
  // atoi函数将字符串转换为整数
  if(argc > 3) id = atoi(argv[3]);
  if(id >= MAX_ROWS) die("There's not that many records");

  switch (action) {
    case 'c':
        Database_create(conn);
        Database_write(conn);
        break;
    case 'g':
        if(argc != 4) die("Need an id to get");
        Database_get(conn, id);
        break;
    case 's':
        if(argc != 6) die("Need id, name, email to set");
        Database_set(conn, id, argv[4], argv[5]);
        Database_write(conn);
        break;
    case 'd':
        if(argc != 4) die("Need an id to delete");

        Database_delete(conn, id);
        Database_write(conn);
        break;
    case 'l':
        Database_list(conn);
        break;
    default:
        die("Invalid action, only: c=create, g=get, s=set, d=del, l=list");
  }

  Database_close(conn);

  return 0;
}
