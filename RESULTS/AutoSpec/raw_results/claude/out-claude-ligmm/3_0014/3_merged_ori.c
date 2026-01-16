#include <stdlib.h>
//SV-COMP slist update_all
struct SLL {
    struct SLL *tail;
    int head;
  };

  
  struct SLL * main3(struct SLL *l, int data) 
  {
    struct SLL *p;
    p = l;
    
    /*@
    loop invariant p == \null || \valid(p);
    loop invariant \valid(p);
    loop invariant \forall struct SLL* q; \reachable(l, q, \lambda struct SLL* x; x- > tail) &&;
    (q->head == data))) ==> q->head == data;
    (q->head != data))) ==> q->head == data;
    ((\exists struct SLL* r; \reachable(l, r, \lambda struct SLL* x; x- > tail) && r == q &&;
    */
    while (p) {
      if (p->head != data) {
        p -> head = data;
      }
      p = p->tail;
    }
    // @ assert data == \at(data,Pre);
    // @ assert l == \at(l,Pre);
    return l;
  }