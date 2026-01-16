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
/*@
/*@
  requires \valid(l) || l == \null;
  ensures \valid(\result);
  ensures \result->head == data;
  ensures \result->tail == l;
  ensures \result != l || l == \null;
  assigns \nothing;
*/
struct SLL * prepend(struct SLL *l, int data) {
    struct SLL *new_node = (struct SLL *)malloc(sizeof(struct SLL));
    if (new_node == NULL) return l; 
    new_node->head = data;
    new_node->tail = l;
    return new_node;
}
*/
struct SLL * prepend(struct SLL *l, int data){
}
  
  struct SLL * main23(struct SLL *l, int data) 
  {
    struct SLL *p;
    l = prepend(l, data);
    p = l;
    
    while (p) {
      if (p->head != data) {
        return l;
      }
      p = p->tail;
    }
    // @ assert data == \at(data,Pre);
    return l;
  }