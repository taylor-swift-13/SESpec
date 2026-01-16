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
    /*@ 
      loop invariant (p == NULL || p != NULL);
      loop invariant \exists struct SNnode* q; q == p || q == NULL;
      loop invariant \forall struct SNnode* n; 
        ( \valid(n) && n != NULL && n != p && n != \null && n != x) ==> 
        ( (\exists struct SNnode* m; m == n->tail) );
      loop invariant \forall struct SNnode* n; 
        ( \valid(n) && n != NULL && n != p && n != \null && n != x && n->head == data) ==> (p != n);
      loop assigns p;
    */
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