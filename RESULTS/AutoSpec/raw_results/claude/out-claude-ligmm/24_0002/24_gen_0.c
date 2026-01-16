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
      loop invariant \valid(l) || l == \null;
      loop assigns l, p;
      loop variant \valid(l) ? 1 : 0;
    */
    */
    while (l) {
      p = l->tail;
      free_SLL(l);
      l = p;
    }
    // @ assert l == p;
  }