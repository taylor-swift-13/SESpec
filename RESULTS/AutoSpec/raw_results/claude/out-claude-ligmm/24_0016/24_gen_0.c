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
  void free_SLL(struct SLL *l){
  }
  
  
  void main24(struct SLL *l) 
  {
    struct SLL *p;
    p = l;
    /*@
    /*@ 
      loop invariant \valid(p) || p == \null;
      loop invariant l == p || \exists struct SLL* q; l == q && q != \null;
      loop assigns l, p;
      loop variant (size of list starting at l);
    */
    */
    while (l) {
      p = l->tail;
      free_SLL(l);
      l = p;
    }
    // @ assert l == p;
  }