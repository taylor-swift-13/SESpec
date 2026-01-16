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
    loop invariant \forall struct SLL* q; \reachable(l, q) ==> q->head == data || (\exists struct SLL* r; \reachable(l, r) && r == p && q->head != data);
    loop invariant \forall struct SLL* q; \reachable(l, q) ==> q == p || q != p ==> q->head == data;
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