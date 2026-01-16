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
    loop invariant \valid(p) || p == \null;
    loop invariant \forall struct SLL* q;;
    (\reach(\at(l, Pre), r) && (q == p || \reach(q, p)))) ) ==> q->head == data;
    (\exists struct SLL* r; r == q &&;
    ((\at(l, Pre) != \null && \valid(q)) &&;
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