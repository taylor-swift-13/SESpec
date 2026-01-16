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
    Looking at this linked list search problem, I need to generate loop invariants for the while loop that searches for a value in a singly linked list.
    
    ```c
    loop invariant p == \null || \valid(p);
    loop invariant data == \at(data,Pre);
    loop invariant x == \at(x,Pre);
    loop assigns p;
    ```
    */
    while (p) {
      if (p->head == data) {
    // @ assert data == \at(data,Pre);
    // @ assert x == \at(x,Pre);
        return 1;
      }
      p = p->tail;
    }
    return -1;
}