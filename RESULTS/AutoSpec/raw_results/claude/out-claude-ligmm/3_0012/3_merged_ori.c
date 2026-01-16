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
    loop invariant p == \null || (\exists integer m; 0 <= m && p == \nth(\at(l, Pre), m));
    loop invariant \forall struct SLL* q;;
    loop invariant \forall struct SLL* q; reachable from \at(l, Pre) implies preserved;
    ==> q->head == data );;
    ( (\exists struct SLL* r; \at(l, Pre) == r && (\exists integer k; 0 <= k && q == \nth(r, k)));
    loop invariant l == \at(l, Pre);
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