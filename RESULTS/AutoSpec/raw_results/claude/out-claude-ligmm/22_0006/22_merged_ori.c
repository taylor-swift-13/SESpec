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
  loop invariant \valid(p) || p == NULL;
  loop invariant \exists struct SLL* q;;
  loop invariant (\forall struct SLL* r; l <= r < p ==> r->head != data);
  loop assigns p;
  /*@;
  (\forall struct SLL* r; l <= r < p ==> r->head != data) ==> q == NULL;;
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