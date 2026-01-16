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
struct SLL * prepend(struct SLL *l, int data){
}

struct SLL * main22(struct SLL *l, int data) 
{
  struct SLL *p;
  l = prepend(l, data);
  p = l;
  
  /*@
  loop invariant \valid(l);
  loop invariant \forall struct SLL* q;;
  loop invariant \exists struct SLL* q; q == l && q != NULL;
  loop assigns p;
  /*@;
  ( ( \exists struct SLL* r; r != NULL && r->head == data ) ==> ( (q != NULL && q->head == data) || \exists struct SLL* s; s == q->tail && s != NULL ));
  */
  while (p) {
    if (p->head == data) {
      return l;
    }
    p = p->tail;
  }
  // @ assert data == \at(data,Pre);
  return l;
}