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
void free_SLL(struct SLL *l){;
requires \valid(l);
if (l == \null) return;
free_SLL(l- > tail);
free(l);
ensures l == \null;
assigns \nothing;
/*@;
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