//SV-COMP prepend_equal
#include <stdlib.h>
struct SLL {
    struct SLL *tail;
    int head;
  };
  

/*@
requires \valid(l);
ensures \result == l;
*/
struct SLL * prepend(struct SLL *l, int data){
}
  
  struct SLL * main23(struct SLL *l, int data) 
  {
    struct SLL *p;
    l = prepend(l, data);
    p = l;
    
    /*@
    /*@ 
      loop invariant \valid(p) || p == NULL;
      loop invariant \forall struct SLL* q; \inv(sll_segment(l, q)) ==> q == p || q == NULL ==> (q == NULL || q->head == data);
      loop assigns p;
    */
    */
    while (p) {
      if (p->head != data) {
        return l;
      }
      p = p->tail;
    }
    // @ assert data == \at(data,Pre);
    return l;
  }