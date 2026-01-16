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
    loop invariant \valid(l) || l == NULL;
    loop invariant \valid(p) || p == NULL;
    loop invariant \forall struct SLL* q;  (\exists struct SLL* r; \at(l, Pre) == r && r != NULL) ==> ( (p == q || \exists struct SLL* s; s->tail == q) );
    loop invariant \forall struct SLL* q; (q != NULL && q != p) ==> (q->head == data);
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