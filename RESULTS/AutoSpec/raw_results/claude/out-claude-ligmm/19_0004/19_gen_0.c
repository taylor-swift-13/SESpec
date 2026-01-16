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
      loop invariant y != NULL;
      loop invariant \forall struct SNnode* q; q != NULL && q != p ==> \valid(q);
      loop invariant \valid(t);
      loop invariant \forall struct SNnode* q; q != NULL && q != p ==> q->tail != NULL || q == t;
      loop assigns t->head, t->tail, t, p;
      loop variant \length(p);
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