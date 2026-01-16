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
    node- > head == data;
    loop invariant \valid(w) || w == \null;
    loop invariant \valid(v) || v == \null;
    loop invariant \valid(p) || p == \null;
    loop invariant \forall struct SLL* node;;
    loop invariant \exists struct SLL* last;;
    loop assigns w;
    loop assigns v;
    loop assigns t;
    last == w || last == v || last == t || last == p;
    /*@;
    (node == w || (node != \null && \valid(node))) == >;
    (node != v && node != w) ==> node == \at(node,Pre);
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