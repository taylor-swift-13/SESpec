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
    loop invariant \forall struct SLL* node; \at(p,Pre) != \null && \in_list(node, \at(p,Pre)) ==> (node->head == data || \at(node->head,Pre) == node->head);
    loop invariant \forall struct SLL* node; \in_list(node, w) ==> node->head == data;
    loop invariant \forall struct SLL* node; \in_list(node, v) ==> node->head != data;
    loop invariant \forall struct SLL* node; \in_list(node, w) ==> node->tail == \null || \in_list(node->tail, w);
    loop invariant \forall struct SLL* node; \in_list(node, v) ==> node->tail == \null || \in_list(node->tail, v);
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