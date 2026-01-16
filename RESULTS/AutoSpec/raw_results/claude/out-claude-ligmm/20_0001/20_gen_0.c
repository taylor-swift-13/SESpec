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
/*@
/*@
  ensures \valid(\result);
  ensures \result->head == data;
  ensures \result->tail == \null;
  assigns \fresh(\result);
*/
struct SLL* malloc_SLL(int data){
    struct SLL* node = (struct SLL*) malloc(sizeof(struct SLL));
    if (node != NULL) {
        node->head = data;
        node->tail = NULL;
    }
    return node;
}

/*@
  requires \valid(l) || l == \null;
  assigns \nothing;
  ensures l == \null;
*/
void free_SLL(struct SLL *l){
    /* empty body as specified */
}
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