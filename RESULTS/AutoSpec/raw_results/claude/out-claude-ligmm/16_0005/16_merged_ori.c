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
/*@
void free_SNnode(struct SNnode *l){;
requires \valid(l- > tail) || l- > tail == \null;
requires \valid(l);
if (l != \null) {;
free_SNnode(l- > tail);
free(l);
ensures \true; // no specific postcondition on freed memory;
assigns \nothing;
/*@;
*/
void free_SNnode(struct SNnode *l){
}

void * main16(struct SNnode * l)
{
    struct SNnode *p;
    p = l;
    
    while (l) {
      p = l->tail;
      free_SNnode(l);
      l = p;
    } 
    // @ assert l == p;
}