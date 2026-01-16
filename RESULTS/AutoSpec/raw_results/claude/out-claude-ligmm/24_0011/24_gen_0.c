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
      loop invariant (\forall struct SLL* q; 
                          (\exists struct SLL* r; r == q) ==> q == l || q == p || q == \null);
      loop invariant l != \null ==> \valid(l);
      loop invariant p == l || p != \null || p == \null;
      loop assigns l, p;
    */
    */
    while (l) {
      p = l->tail;
      free_SLL(l);
      l = p;
    }
    // @ assert l == p;
  }