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
    
    /*@
    loop invariant new_node == \null || (\valid(new_node) && new_node- > head == data && new_node- > tail == \null);
    loop invariant \valid(x) || x == \null;
    loop invariant \forall struct SNnode* q; \valid(q) ==> (\exists struct SNnode* r; r == q && (r == p || \false));;
    loop assigns p;
    loop assigns new_node;
    */
    while (p) {
      if (p->head < data) {
        new_node = malloc_SNnode(data);
        new_node -> tail = p -> tail;
        p -> tail = new_node;
        return x;
      }
      p = p -> tail;
    }
    // @ assert data == \at(data,Pre);
    return x;
}