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
      loop invariant p == \null || \valid(p);
      loop invariant \valid(t);
      loop invariant \valid(y);
      loop invariant \forall struct SNnode* q; 
        (q != \null && q != p && q != t) ==> \valid(q);
      loop assigns p, t->head, t->tail;
      loop assigns t;
      loop variant p; 
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