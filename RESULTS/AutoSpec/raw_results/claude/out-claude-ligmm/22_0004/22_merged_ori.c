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
  loop invariant p == \at(l, LoopEntry) || \exists struct SLL *q; q != \null && p == q- > tail;
  loop invariant \valid(p) || p == \null;
  loop invariant \valid(l);
  loop invariant \length_list(p);
  loop invariant \forall struct SLL *q; q != p && q != \null ==> q->head != data;
  loop assigns p;
  /*@;
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