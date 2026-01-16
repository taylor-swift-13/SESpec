#include <stdlib.h>
//Sling slist reverse

struct SNnode {
    int head;
    struct SNnode *tail;
};

struct SNnode *main7(struct SNnode *p)
{
    struct SNnode *w, *t, *v;
    w = 0;
    v = p;
    
    /*@
    Looking at this singly linked list reversal function, I need to generate loop invariants that capture the reversal process and memory safety properties.
    
    ```c
    loop invariant v == \null || \valid(v);
    loop invariant w == \null || \valid(w);
    loop invariant \separated(v, w);
    loop assigns v;
    loop assigns w;
    loop assigns t;
    ```
    */
    while (v) {
        t = v->tail;
        v->tail = w;
        w = v;
        v = t;
    }
    // @ assert p == \at(p,Pre);
    return w;
}