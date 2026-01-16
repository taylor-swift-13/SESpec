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
    Looking at this ACSL loop invariant generation task, I need to analyze the loop in the `main2` function.
    
    The loop iterates through a singly-linked list, checking if each node's `head` field equals `data`. If any node doesn't match, it returns early. The pointer `p` traverses the list until it becomes NULL.
    
    Here are the loop invariants:
    
    ```c
    loop invariant p == \null || \valid(p);
    loop invariant data == \at(data, Pre);
    loop invariant l == \at(l, Pre);
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