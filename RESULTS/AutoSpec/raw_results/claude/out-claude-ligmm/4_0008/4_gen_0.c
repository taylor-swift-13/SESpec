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
         (node != v && node != w && \exists struct SLL* cur; cur == node && 
           (cur == p || \exists struct SLL* prev; prev->tail == cur)) 
         ==> node->head == data);
    loop invariant 
      (\forall struct SLL* node; (node == w || node == v || node == (struct SLL*)0) ==> \true);
    loop invariant 
      (w == \at(v,Pre) || w == (struct SLL*)0 || \exists struct SLL* prev; prev->tail == w);
    loop assigns v, w, t;
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