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
    loop invariant l == \at(l,Pre);
    loop invariant data == \at(data,Pre);
    */
    while (p) {
      if (p->head != data) {
        p -> head = data;
      }
      p = p->tail;
    }
    //@ assert data == \at(data,Pre);
    //@ assert l == \at(l,Pre);
    return l;
  }