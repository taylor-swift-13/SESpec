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
    loop invariant p == \at(p,Here) || p == l || p == NULL;
    loop invariant p != NULL ==> \forall struct SLL *q; (\at(l,Pre) != NULL && (\exists struct SLL *r; \at(l,Pre) != NULL && r != p && r != NULL)) ==> q->head == data;
    loop invariant \forall struct SLL *q; \at(l,Pre) != NULL && (\exists struct SLL *r; r != q && r != NULL && q == p) ==> q->head == data;
    loop invariant \forall struct SLL *q; (\exists struct SLL *r; r != q && r != NULL && r == p) ==> q->head == data;
    loop invariant \exists struct SLL *q; q == p || q == \at(p,Here);
    loop invariant p == \at(p,Here) || \exists struct SLL *q; \at(l,Pre) != \null && (\forall struct SLL *r; r != p && r != \null ==> r->head == data);
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