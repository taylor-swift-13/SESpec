//SLing sll_copy
#include <stdlib.h>
struct SNnode {
    int head;
    struct SNnode *tail;
};

/*@
ensures \valid(\result);
ensures \result->head == data;
ensures \result->tail == \null;
*/
struct SNnode* malloc_SNnode(int data){
}


struct SNnode * main19(struct SNnode * x)
{
    struct SNnode *y, *p, *t;
    y = malloc_SNnode(0);
    t = y;
    p = x;

    /*@
    /*@
      loop invariant p != NULL ==> \valid(t);
      loop invariant \exists struct SNnode *q; q != NULL && q == t;
      loop invariant t != NULL;
      loop invariant \forall struct SNnode *q; (q == y || q != NULL) ==> \valid(q);
      loop assigns p, t->head, t->tail, t;
      loop variant ???;  // (optional: can be p's length remaining if available)
    */
    */
    while (p) {
      t -> head = p -> head;
      t -> tail = malloc_SNnode(0);
      p = p -> tail;
      t = t -> tail;
    }
    // @ assert t->tail == \null;
    // @ assert t->head == 0;
    return y;
}