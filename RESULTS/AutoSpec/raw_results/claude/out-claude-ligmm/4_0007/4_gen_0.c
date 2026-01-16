#include <stdlib.h>
//SV-COMP slist update_all_reverse
struct SLL {
    struct SLL *tail;
    int head;
  };

  
  
  struct SLL * main4(struct SLL *p, int data) 
  {
    struct SLL *w, *t, *v;
    w = (void *)0;
    v = p;
    /*@
    loop invariant 
      (\forall struct SLL* node; 
         ( \reach(\at(p, Pre), node) && \before(node, v, \at(p, Pre)) ) ==> node->head == data );
    loop invariant 
      (\forall struct SLL* node; 
         ( \reach(v, node) ) ==> \old(node->head) == node->head );
    loop invariant \reach(w, \at(w, LoopEntry)) && !\reach(v, w);
    loop invariant \old(data) == data;
    loop assigns v, w, t;
    loop assigns (\union(\from(v->tail), \from(v->head)));
    */
    while (v) {
      t = v->tail;
      v->tail = w;
      if (v-> head != data) {
        v -> head = data;
      }
      w = v;
      v = t;
    }
    // @ assert data == \at(data,Pre);
    // @ assert p == \at(p,Pre);
    return w;
  }