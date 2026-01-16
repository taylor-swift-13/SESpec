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
    Looking at the pattern from the examples, I need to generate loop invariants for the `while (v)` loop in the `main4` function.
    
    ```c
    loop invariant v == \null || \valid(v);
    loop invariant w == \null || \valid(w);
    loop invariant \separated(v, w);
    loop assigns v;
    loop assigns w;
    loop assigns t;
    ```
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