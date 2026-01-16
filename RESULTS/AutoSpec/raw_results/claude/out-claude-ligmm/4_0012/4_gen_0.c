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
        (\exists struct SLL* before; 
          (before == \at(p, Pre) && 
           (node == before || node == w || node == v || node == t))) ==>
        (node == w || node == v || node == t || node == NULL));
    loop invariant 
      \forall struct SLL* n; 
        ( 
          (\exists struct SLL* x; x == \at(p, Pre) && 
           (\exists int cnt; cnt >= 0 && n == \at(p, Pre) || ... )
          ) =>
          (
            (n == w || n == v || n == t) ==> n->tail == \at(n->tail, Pre) || n->tail == w || n->tail == v || n->tail == t
          )
        );
    loop invariant \forall struct SLL* n; (n == w || n == v || n == t) ==> n->head == data;
    loop invariant 
      \at(data, Pre) == data;
    loop invariant (w == NULL && v == \at(p, Pre)) || w != NULL;
    loop assigns w, v, t;
    loop assigns \result;
    loop assigns \nothing else;
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