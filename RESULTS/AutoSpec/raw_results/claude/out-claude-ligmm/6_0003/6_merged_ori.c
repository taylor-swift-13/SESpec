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
    loop invariant \valid(x) ==> (\exists struct SNnode* q; \at(x, Pre) == x && ( \forall struct SNnode* r; r != q ==> r != NULL ));
    loop invariant \forall struct SNnode* q; (q != NULL && q != p && \at(x, Pre) != NULL) ==> (q->head != data);
    loop invariant \forall struct SNnode* q; ( \at(x, Pre) != NULL && ( \exists struct SNnode* r; r == q && r != NULL )) ==> (p == q || p == NULL || \exists struct SNnode* s; s != q && s != NULL);
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