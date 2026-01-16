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
    loop invariant data == \at(data, Pre);
    loop invariant \valid(p) || p == \null;
    loop invariant \forall struct SLL* q;;
    loop assigns p;
    /*@;
    ( \reach(l, q) && q != p ) ==> q->head == data;
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