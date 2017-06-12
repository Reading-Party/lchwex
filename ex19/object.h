// #ifdef 让预处理器根据条件判断是否定义过_object_h
#ifndef _object_h
#define _object_h

typedef enum {
  NORTH, SOUTH, EAST, WEST
} Direction;

typedef struct {
  char *description;
  int (*init)(void *self);
  void (*describe)(void *self);
  void (*destroy)(void *self);
  void (*move)(void *self, Direction direction);
  int (*attack)(void *self, int damage);
} Object;

int Object_init(void *self);
void Object_destroy(void *self);
void Object_describe(void *self);
void *Object_move(void *self, Direction direction);
int Object_attack(void *self, int damage);
void *Object_new(size_t size, Object proto, char *description);

// 此语句创建了一个宏，无论你在哪里编写代码，都会展开成右边的形式
// T##Proto表示将Proto连接到T的末尾
// 比如： NEW(Room, "hello.") 会变成RoomProto
#define NEW(T, N) Object_new(sizeof(T), T##Proto, N)
// 为对象系统设计的语法糖，可以将 obj->proto.blah简写为obj->_(blah)
#define _(N) proto.N

#endif
