//Sling insert
#include <stdlib.h>

struct SNnode {
    int head;
    struct SNnode *tail;
};

/*@
ensures \valid(\result);
ensures \result->head == data;
ensures \result->tail == \null;
*/
struct SNnode* malloc_SNnode(int data){
}


struct SNnode * main17(struct SNnode * x, int data)
{
    struct SNnode *p, *new_node;
    new_node = 0;
    p = x;
    
    while (p) {
      if (p->head < data) {
        new_node = malloc_SNnode(data);
        new_node -> tail = p -> tail;
        p -> tail = new_node;
        return x;
      }
      p = p -> tail;
    }
    /*@ assert data == \at(data,Pre); */
    return x;
}