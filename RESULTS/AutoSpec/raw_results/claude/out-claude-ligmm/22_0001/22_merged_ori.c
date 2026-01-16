//SV-COMP prepend_unequal
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
struct SLL *new_node = malloc(sizeof(struct SLL));
struct SLL * prepend(struct SLL *l, int data){;
return new_node;
requires \valid(l) || l == \null;
new_node- > tail = l;
new_node- > head = data;
if (new_node == NULL) return l; // handle malloc failure gracefully;
ensures \result- > tail == l;
ensures \result- > head == data;
ensures \result != \null;
assigns \result, \result- > head, \result- > tail;
*/
struct SLL * prepend(struct SLL *l, int data){
}

struct SLL * main22(struct SLL *l, int data) 
{
  struct SLL *p;
  l = prepend(l, data);
  p = l;
  
  while (p) {
    if (p->head == data) {
      return l;
    }
    p = p->tail;
  }
  // @ assert data == \at(data,Pre);
  return l;
}