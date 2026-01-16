#include <stdlib.h>
//SV-COMP slist append_equal
struct SLL {
    struct SLL *tail;
    int head;
  };
  
  
  struct SLL * main2(struct SLL *l, int data) 
  {
    struct SLL *p;
    p = l;

    /*@
    ```c
    loop invariant p == \null || \valid(p);
    loop invariant data == \at(data,Pre);
    loop invariant l == \at(l,Pre);
    loop assigns p;
    ```
    */
    while (p) {
      if (p->head != data) {
        // @ assert data == \at(data,Pre);
        // @ assert l == \at(l,Pre);
        return l;
      }
      p = p->tail;
    }
  
    return l;
  }