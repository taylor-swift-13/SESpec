//SV-COMP remove_all            
#include <stdlib.h>
struct SLL {
    struct SLL *tail;
    int head;
  };
  
  
  /*@
  requires \valid(l);
  ensures l == \null;
  */
/*@
/*@ 
  requires l == \null || \valid(l);
  assigns \nothing;
  ensures \true;
*/
void free_SLL(struct SLL *l) {
    if (l == NULL) return;
    free_SLL(l->tail);
    free(l);
}
*/
  void free_SLL(struct SLL *l){
  }
  
  
  void main24(struct SLL *l) 
  {
    struct SLL *p;
    p = l;
    while (l) {
      p = l->tail;
      free_SLL(l);
      l = p;
    }
    // @ assert l == p;
  }