#include <stdlib.h>
//SV-COMP slist append_equal
struct SLL {
    struct SLL *tail;
    int head;
  };
  
  
  struct SLL * main2(struct SLL *l, int data) 
  {
    struct SLL *p;
    p = l;

    /*@
    loop invariant p == \at(p,LoopEntry) || p == l || \exists struct SLL* q; q == \at(p,LoopEntry) && \valid(q);
    loop invariant l == \at(l,Pre);
    loop invariant data == \at(data,Pre);
    loop invariant \forall struct SLL* q; (\exists struct SLL* r; r == \at(p,LoopEntry) && q == r || q == p) ==> q->head == data;
    loop assigns p;
    */
    while (p) {
      if (p->head != data) {
        // @ assert data == \at(data,Pre);
        // @ assert l == \at(l,Pre);
        return l;
      }
      p = p->tail;
    }
  
    return l;
  }