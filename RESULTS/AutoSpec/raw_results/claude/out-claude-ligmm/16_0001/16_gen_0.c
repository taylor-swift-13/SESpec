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
/*@
  requires l == \null || \valid(l);
  assigns l->tail; 
  ensures \true; 
@*/
void free_SNnode(struct SNnode *l) {
    if (l != NULL) {
        free_SNnode(l->tail);
        free(l);
    }
}
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