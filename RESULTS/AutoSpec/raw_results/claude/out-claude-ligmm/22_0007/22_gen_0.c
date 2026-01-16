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
  requires \true;
  ensures \result != \null;
  ensures \result->head == data;
  ensures \result->tail == l;
  assigns \result->head, \result->tail;
*/
struct SLL * prepend(struct SLL *l, int data){
    struct SLL *node = (struct SLL *) malloc(sizeof(struct SLL));
    if (node == NULL) return NULL; // handle allocation failure gracefully
    node->head = data;
    node->tail = l;
    return node;
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