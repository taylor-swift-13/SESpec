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
    loop invariant \forall struct SNnode* n;;
    loop invariant \exists struct SNnode* q; q == p || q == NULL;
    loop invariant (p == NULL || p != NULL);
    loop assigns p;
    /*@;
    ( \valid(n) && n != NULL && n != p && n != \null && n != x) == >;
    ( \valid(n) && n != NULL && n != p && n != \null && n != x && n->head == data) ==> (p != n);
    ( (\exists struct SNnode* m; m == n- > tail) );
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