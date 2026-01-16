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
    loop invariant \reachable(w, w);
    loop invariant \reachable(p, p);
    loop invariant \forall struct SLL* node;;
    loop invariant (v == NULL) || \valid(v);
    loop invariant (\forall struct SLL* node;;
    (node != NULL && \reachable(p, node)) ==> node->head == data);
    (\reachable(p, node) ==> \reachable(w, node) || \reachable(v, node));
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