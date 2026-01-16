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
    loop invariant \valid(p) || p == \null;
    loop invariant \valid(w) || w == \null;
    loop invariant \valid(v) || v == \null;
    loop invariant \forall struct SLL* node; 
      (node != \null && \exists struct SLL* cur; cur == \at(p,Pre) && (cur == node || \valid(node))); 
    loop invariant w == \reverse_prefix(\at(p,Pre), v);
    loop invariant \forall struct SLL* node; 
      node on the reversed part (w) ==> node->head == data;
    loop invariant \forall struct SLL* node; 
      node on the unreversed part (v) ==> node->head == \at(node->head, Pre);
    loop assigns w, v, t;
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