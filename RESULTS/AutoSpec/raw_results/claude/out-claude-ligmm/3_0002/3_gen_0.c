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
    loop invariant \valid(l) || l == NULL;
    loop invariant \valid(p) || p == NULL;
    loop invariant \forall struct SLL* q; \at(l, Pre) != NULL && \at(l, Pre) != q && reachable(\at(l, Pre), q, \at(l, Pre)) ==> q != NULL;
    loop invariant p == NULL || \valid(p);
    loop invariant \forall struct SLL* q; reachable(l, q, \at(l, Pre)) ==> q->head == data;
    loop assigns p->head, p;
    loop assigns p;
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