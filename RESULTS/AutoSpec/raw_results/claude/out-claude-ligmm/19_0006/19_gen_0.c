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
      loop invariant \forall struct SNnode* q; 
        (\exists struct SNnode* r; (q == x || \valid(q)) && r == p) ==> 
          \valid(q);
      loop invariant (\forall struct SNnode* n; 
        (n != p && n != NULL) ==> \valid(n));
      loop invariant t != NULL;
      loop invariant \valid(y);
      loop invariant \exists struct SNnode* last; last == t || last == NULL;
      loop assigns p, t, t->head, t->tail;
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