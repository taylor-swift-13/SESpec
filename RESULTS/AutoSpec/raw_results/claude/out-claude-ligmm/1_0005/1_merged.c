#include <stdlib.h>
//SV-COMP slist append_unequal
struct SLL {
    struct SLL *tail;
    int head;
};
  
  struct SLL * main1(struct SLL *l, int data) 
{
    struct SLL *p;
    p = l;

    /*@
    loop invariant (p == NULL) || (\exists struct SLL* q; q == p && q != NULL);
    loop assigns p;
    */
    while (p) {
      if (p->head == data) {
        //@ assert data == \at(data,Pre);
        //@ assert l == \at(l,Pre);
        return l;
      }
      p = p->tail;
    }
    return l;
}