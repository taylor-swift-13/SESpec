//SV-COMP insert_unequal
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
  
  
  struct SLL * main21(struct SLL *l, int data) {
    struct SLL *p;
    struct SLL *new_node;
    new_node = 0;
    p = l;
    
    while (p) {
      if (p-> head == data) {
        new_node = malloc_SLL(data);
        new_node->tail = p->tail;
        p->tail = new_node;
        return l;
      }
      p = p->tail;
    }
    /*@ assert data == \at(data,Pre); */
    return l;
  }