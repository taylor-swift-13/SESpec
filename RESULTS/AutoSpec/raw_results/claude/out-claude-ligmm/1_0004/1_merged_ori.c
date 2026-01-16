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
    loop invariant \valid(p) || p == NULL;
    loop invariant (\forall struct SLL* q; \valid(q) && q != NULL && q != p ==> q->tail != NULL || q->tail == p);
    loop invariant (\forall struct SLL* q; \valid(q) && q != NULL && q != p ==> q->head != data);
    loop assigns p;
    */
    while (p) {
      if (p->head == data) {
        // @ assert data == \at(data,Pre);
        // @ assert l == \at(l,Pre);
        return l;
      }
      p = p->tail;
    }
    return l;
}