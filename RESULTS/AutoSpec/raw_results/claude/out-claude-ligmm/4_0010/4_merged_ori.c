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
    node on the unreversed part (v) ==> node->head == \at(node->head, Pre);
    node on the reversed part (w) ==> node->head == data;
    loop invariant w == \reverse_prefix(\at(p,Pre), v);
    loop invariant \valid(w) || w == \null;
    loop invariant \valid(v) || v == \null;
    loop invariant \valid(p) || p == \null;
    loop invariant \forall struct SLL* node;;
    loop assigns w;
    loop assigns v;
    loop assigns t;
    (node != \null && \exists struct SLL* cur; cur == \at(p,Pre) && (cur == node || \valid(node)));;
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