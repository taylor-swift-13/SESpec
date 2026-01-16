//SLing delete_all
#include <stdlib.h>

struct SNnode {
    int head;
    struct SNnode *tail;
};

/*@
requires \valid(l);
ensures l == \null;
*/
void free_SNnode(struct SNnode *l){
}

void * main16(struct SNnode * l)
{
    struct SNnode *p;
    p = l;
    
    /*@
    /*@ 
      loop invariant \valid(p) || p == \null;
      loop invariant (l == \null) || \valid(l);
      loop invariant \forall struct SNnode* q; 
        (q != \null && q != l) ==> \freeable(q) == 0;
      loop assigns l, p;
      loop variant l;
    */
    */
    while (l) {
      p = l->tail;
      free_SNnode(l);
      l = p;
    } 
    // @ assert l == p;
}