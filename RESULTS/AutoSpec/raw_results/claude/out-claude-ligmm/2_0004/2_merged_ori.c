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
    loop invariant p == l || \exists struct SLL* q; q != NULL && p == q- > tail;
    loop invariant \valid(l) || l == NULL;
    loop invariant \forall struct SLL* node; reachable from l and before p in list ==> node->head == data;
    loop assigns p;
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