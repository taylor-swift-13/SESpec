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
    loop invariant p != \null ==> \forall struct SLL *q;;
    loop invariant \exists struct SLL *q; \reachable(l, q) && q == p || p == \null;
    \reachable(l, q) && q != p ==> q->head == data;
    /*@;
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