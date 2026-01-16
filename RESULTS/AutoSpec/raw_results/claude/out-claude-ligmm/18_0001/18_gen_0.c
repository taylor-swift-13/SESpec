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
/*@
```c
struct SNnode* malloc_SNnode(int data){
    struct SNnode* node = malloc(sizeof(struct SNnode));
    if (node != NULL) {
        node->head = data;
        node->tail = NULL;
    }
    return node;
}
```
*/
struct SNnode* malloc_SNnode(int data){
}


struct SNnode * main18(struct SNnode * x, int data)
{
    struct SNnode *p;
    p = x;
    
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