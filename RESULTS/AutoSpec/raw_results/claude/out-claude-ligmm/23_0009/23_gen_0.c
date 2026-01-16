//SV-COMP prepend_equal
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
requires \valid(l) || l == \null;
assigns \fresh(\result);
ensures \result != \null;
ensures \result->head == data;
ensures \result->tail == l;
ensures \result != l || l == \null;
{
    struct SLL *node = malloc(sizeof(struct SLL));
    if (node == NULL) return NULL;
    node->head = data;
    node->tail = l;
    return node;
}
*/
struct SLL * prepend(struct SLL *l, int data){
}
  
  struct SLL * main23(struct SLL *l, int data) 
  {
    struct SLL *p;
    l = prepend(l, data);
    p = l;
    
    while (p) {
      if (p->head != data) {
        return l;
      }
      p = p->tail;
    }
    // @ assert data == \at(data,Pre);
    return l;
  }