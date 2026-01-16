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
    loop invariant;
    ==> node->head == data);
    (w == \at(v,Pre) || w == (struct SLL*)0 || \exists struct SLL* prev; prev- > tail == w);
    (node != v && node != w && \exists struct SLL* cur; cur == node &&;
    (cur == p || \exists struct SLL* prev; prev- > tail == cur));
    (\forall struct SLL* node;;
    (\forall struct SLL* node; (node == w || node == v || node == (struct SLL*)0) ==> \true);
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