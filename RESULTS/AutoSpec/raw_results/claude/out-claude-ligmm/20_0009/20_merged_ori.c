//SV-COMP insert_equal
#include <stdlib.h>

struct SLL {
    struct SLL *tail;
    int head;
  };

  /*@
  ensures \valid(\result);
  ensures \result->head == data;
  ensures \result->tail == \null;
  */
  struct SLL* malloc_SLL(int data){
  }
  
  /*@
  requires \valid(l);
  ensures l == \null;
  */
  void free_SLL(struct SLL *l){
  }
  
  struct SLL * main20(struct SLL *l, int data) {
    struct SLL *p;
    struct SLL *new_node;
    new_node = 0;
    p = l;
    /*@
    loop invariant new_node == \null || (\valid(new_node) && new_node- > head == data);
    loop invariant \valid(p) || p == \null;
    loop invariant \forall struct SLL* q;;
    loop invariant 0; // (if termination proof needed);
    loop assigns p;
    loop assigns new_node;
    /*@;
    (q == l || \exists struct SLL* r; r->tail == q) ==> (q != p ==> q->head == data);
    */
    while (p) {
      if (p-> head != data) {
        new_node = malloc_SLL(data);
        new_node->tail = p->tail;
        p->tail = new_node;
        return l;
      }
      p = p->tail;
    }
    // @ assert data == \at(data,Pre);
    return l;
  }