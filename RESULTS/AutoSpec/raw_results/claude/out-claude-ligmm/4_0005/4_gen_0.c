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
    loop invariant \forall struct SLL* node; \reachable(p, node) ==> node->head == data || node->head != data;
    loop invariant \forall struct SLL* node; \reachable(w, node) ==> node->head == data;
    loop invariant \forall struct SLL* node; (\reachable(v, node) ==> node->head != data || node->head == data);
    loop invariant \forall struct SLL* node; \separated(w, v);
    loop invariant \forall struct SLL* node; \fresh(t) || t == \null;
    loop invariant \valid(w) || w == \null;
    loop invariant \valid(v) || v == \null;
    loop assign w, v, t;
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