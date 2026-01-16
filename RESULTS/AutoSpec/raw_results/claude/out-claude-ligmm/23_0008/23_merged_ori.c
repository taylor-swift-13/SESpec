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
struct SLL * prepend(struct SLL *l, int data){
}
  
  struct SLL * main23(struct SLL *l, int data) 
  {
    struct SLL *p;
    l = prepend(l, data);
    p = l;
    
    /*@
    loop invariant \valid(p) || p == \null;
    loop invariant \forall struct SLL *q;;
    loop invariant \exists struct SLL *q; q == p || q == \null;
    loop assigns p;
    /*@;
    (q == \at(p, Here) || q == \null) ) ==> q->head == data );
    ( ( \valid(q) && \valid(q- > tail) &&;
    */
    while (p) {
      if (p->head != data) {
        return l;
      }
      p = p->tail;
    }
    // @ assert data == \at(data,Pre);
    return l;
  }