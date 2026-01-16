#include <stdlib.h>
//SV-COMP slist update_all
struct SLL {
    struct SLL *tail;
    int head;
  };

  
  struct SLL * main3(struct SLL *l, int data) 
  {
    struct SLL *p;
    p = l;
    
    /*@
    Looking at this problem, I need to generate loop invariants for the `main3` function that updates all nodes in a singly linked list.
    
    ```c
    loop invariant \valid(l) || l == \null;
    loop invariant p == \null || \valid(p);
    loop invariant data == \at(data,Pre);
    loop invariant l == \at(l,Pre);
    loop assigns p;
    loop assigns p->head;
    ```
    */
    while (p) {
      if (p->head != data) {
        p -> head = data;
      }
      p = p->tail;
    }
    // @ assert data == \at(data,Pre);
    // @ assert l == \at(l,Pre);
    return l;
  }