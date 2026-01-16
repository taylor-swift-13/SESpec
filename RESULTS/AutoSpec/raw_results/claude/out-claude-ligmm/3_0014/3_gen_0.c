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
    loop invariant \valid(p);
    loop invariant \forall struct SLL* q; \reachable(l, q, \lambda struct SLL* x; x->tail) && 
      ((\exists struct SLL* r; \reachable(l, r, \lambda struct SLL* x; x->tail) && r == q && 
        (q->head == data))) ==> q->head == data;
    loop invariant \forall struct SLL* q; \reachable(l, q, \lambda struct SLL* x; x->tail) && 
      ((\exists struct SLL* r; \reachable(l, r, \lambda struct SLL* x; x->tail) && r == q && 
        (q->head != data))) ==> q->head == data;
    loop invariant p == \null || \valid(p);
    loop assigns p->head, p;
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