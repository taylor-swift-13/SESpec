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
    loop invariant l != p ==> \exists struct SNnode* q; l == q && \valid(q);
    loop invariant \valid(p) || p == \null;
    loop invariant (\forall struct SNnode* q; q != \null && q != l ==> \valid(q) == false);
    loop assigns p;
    loop assigns l;
    /*@;
    */
    while (l) {
      p = l->tail;
      free_SNnode(l);
      l = p;
    } 
    // @ assert l == p;
}