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
    loop invariant \valid(p) || p == \null;
    loop invariant (\forall struct SLL* node; \reachable(l, node) && !\reachable(p, node) ==> node->head == data);
    loop invariant \forall struct SLL* node; \reachable(p, node) ==> node->head != data || node->head == data;
    loop invariant \reachable_or_null(l);
    loop invariant \reachable_or_null(p);
    loop assigns p;
    loop assigns (\mutable \reachable(l));
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