#include <stdlib.h>
//Sling slist find

struct SNnode {
    int head;
    struct SNnode *tail;
};



int main6(struct SNnode * x, int data)
{
    struct SNnode * p;
    p = x;
   
    /*@
    loop invariant x == \at(x,Pre);
    loop invariant data == \at(data,Pre);
    loop assigns p;
    */
    while (p) {
      if (p->head == data) {
    //@ assert data == \at(data,Pre);
    //@ assert x == \at(x,Pre);
        return 1;
      }
      p = p->tail;
    }
    return -1;
}