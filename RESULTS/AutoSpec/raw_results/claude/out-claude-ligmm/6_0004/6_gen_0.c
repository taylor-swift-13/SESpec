#include <stdlib.h>
//Sling slist find

struct SNnode {
    int head;
    struct SNnode *tail;
};



int main6(struct SNnode * x, int data)
{
    struct SNnode * p;
    p = x;
   
    /*@
    loop invariant \valid_read(p);
    loop invariant p == \null || \valid_read(p);
    loop invariant \forall struct SNnode* q;  (reachable from x via tail in zero or more steps, and before p) ==> q->head != data;
    loop assigns p;
    */
    while (p) {
      if (p->head == data) {
    // @ assert data == \at(data,Pre);
    // @ assert x == \at(x,Pre);
        return 1;
      }
      p = p->tail;
    }
    return -1;
}