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
    loop invariant l == \null ? 0 : 1;
    loop invariant (l == p) || \valid(l) || l == \null;
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