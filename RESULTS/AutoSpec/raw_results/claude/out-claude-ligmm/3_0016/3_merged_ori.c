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
    loop invariant p == \null || \valid(p);
    loop invariant \valid(p);
    loop invariant \forall struct SLL* node; \reach(p, struct SLL, tail, node) ==> node->head == data;
    loop invariant (\forall struct SLL* node; \reach(l, struct SLL, tail, node) && node != p ==> node->head == data);
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