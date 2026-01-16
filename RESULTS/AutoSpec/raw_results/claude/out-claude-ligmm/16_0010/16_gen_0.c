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
      loop invariant \forall struct SNnode *q; 
        // nodes from original l to current l are freed (cannot be expressed simply here)
      loop assigns l, p; 
      loop variant ???; 
    */
    */
    while (l) {
      p = l->tail;
      free_SNnode(l);
      l = p;
    } 
    // @ assert l == p;
}