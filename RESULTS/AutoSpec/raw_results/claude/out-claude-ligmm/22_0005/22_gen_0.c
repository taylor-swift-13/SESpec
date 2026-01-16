//SV-COMP prepend_unequal
#include <stdlib.h>
struct SLL {
  struct SLL *tail;
  int head;
};



/*@
requires \valid(l);
ensures \result == l;
*/
/*@
/*@
  requires \valid(l) || l == \null;
  allocates \result;
  ensures \result != \null;
  ensures \result->head == data;
  ensures \result->tail == l;
  ensures \valid(\result);
*/
struct SLL * prepend(struct SLL *l, int data){
    struct SLL *new_node = malloc(sizeof(struct SLL));
    if (new_node == NULL) return NULL;
    new_node->head = data;
    new_node->tail = l;
    return new_node;
}
*/
struct SLL * prepend(struct SLL *l, int data){
}

struct SLL * main22(struct SLL *l, int data) 
{
  struct SLL *p;
  l = prepend(l, data);
  p = l;
  
  while (p) {
    if (p->head == data) {
      return l;
    }
    p = p->tail;
  }
  // @ assert data == \at(data,Pre);
  return l;
}