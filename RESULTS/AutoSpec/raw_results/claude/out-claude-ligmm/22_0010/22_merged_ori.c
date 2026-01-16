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
  q != \at(p,Pre) ==> q != p;
  loop invariant \valid(p);
  loop invariant \forall struct SLL *q;;
  loop invariant \exists struct SLL *q;;
  loop assigns p;
  \at(q,Pre) == p && (\forall struct SLL *r; r != q ==> p != r);
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