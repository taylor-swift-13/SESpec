//SLing insert_back
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


struct SNnode * main18(struct SNnode * x, int data)
{
    struct SNnode *p;
    p = x;
    
    /*@
    /*@ 
      loop invariant \valid(p) || p == \null;
      loop assigns p->tail, p;
      loop invariant (\forall struct SNnode* q; \valid(q) && q != \null && q != p ==> q->tail != \null);
    */
    */
    while (p) {
      if (p->tail == 0) {
        p -> tail = malloc_SNnode(data);
        p = p -> tail;
      }
      p = p -> tail;
    }
    // @ assert data == \at(data,Pre);
    return x;
}