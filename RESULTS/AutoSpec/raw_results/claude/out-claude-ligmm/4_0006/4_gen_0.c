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
    loop invariant \valid_read(p) || p == \null;
    loop invariant \forall struct SLL* node; \reachable(p, node) ==> (node->head == data);
    loop invariant \forall struct SLL* node; \reachable(w, node) ==> (node->head == data);
    loop invariant \forall struct SLL* node; \reachable(v, node) ==> (node->head != data) && \reachable(p, node);
    loop invariant \forall struct SLL* node; \reachable(p, node) <==> (\reachable(w, node) || \reachable(v, node));
    loop invariant \forall struct SLL* node; \reachable(w, node) ==> \reachable(w, node->tail) || node->tail == \null;
    loop invariant \valid(w) || w == \null;
    loop invariant \valid(v) || v == \null;
    loop assigns w, v, t;
    loop assigns \result;
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