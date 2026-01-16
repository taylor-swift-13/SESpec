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
    loop invariant t != NULL;
    loop invariant p != NULL ==> \valid(t);
    loop invariant \valid(y);
    loop invariant \forall struct SNnode* q;;
    loop invariant \exists struct SNnode* last; last == t || last == NULL;
    loop invariant (\forall struct SNnode* n;;
    loop assigns t;
    loop assigns t->tail;
    loop assigns t->head;
    loop assigns p;
    \valid(q);
    /*@;
    (n != p && n != NULL) ==> \valid(n));
    (\exists struct SNnode* r; (q == x || \valid(q)) && r == p) == >;
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