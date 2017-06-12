#ifndef lcthw_List_h
#define lcthw_List_h

#include <stdlib.h>

struct ListNode;

// 定义结构体类型ListNode
typedef struct ListNode {
  // 指向下一个ListNode
  struct ListNode *next;
  // 指向前一个ListNode
  struct ListNode *prev;
  // 值，无类型的指针，存储在链表中我们想要放置的东西
  void *value;
} ListNode;

// List结构体是ListNode的容器
// 记录数量，以及第一个和最后一个ListNode
typedef struct List {
  int count;
  ListNode *first;
  ListNode *last;
} List;

List *List_create();
void List_destroy(List *list);
void List_clear(List *list);
void List_clear_destroy(List *list);

#define List_count(A) ((A)->count)
#define List_first(A) ((A)->first != NULL ? (A)->first->value : NULL)
#define List_last(A) ((A)->last != NULL ? (A)->last->value : NULL)

void List_push(List *list, void *value);
void *List_pop(List *list);

void List_unshift(List *list, void *value);
void *List_shift(List *list);

void *List_remove(List *list, ListNode *node);

#define LIST_FOREACH(L, S, M, V) ListNode *_node = NULL;\
  ListNode *V = NULL;\
  for(V = _node = L->S; _node != NULL; V = _node = _node->M)

#endif
