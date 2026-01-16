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
    loop invariant \valid(w) || w == \null;
    loop invariant \valid(v) || v == \null;
    loop invariant v == \null || \valid(v);
    loop invariant \forall struct SLL* node; (node != w && node != v) ==> 
      // nodes not yet reversed or processed remain unchanged
      \true;
    loop invariant \forall struct SLL* node; node != \null && node == w ==> node->head == data;
    loop assigns w, v, t;
    loop assigns v->tail, v->head;
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