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
  requires \valid(l);
  ensures \true; 
  assigns \nothing;
*/
void free_SNnode(struct SNnode *l) {
    free(l);
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