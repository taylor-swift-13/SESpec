//Zephyr slist rev
#include <stdlib.h>
struct sys_slist_t {
    struct sys_slist_t *next;
};


struct sys_slist_t *main14(struct sys_slist_t *p)
{
    struct sys_slist_t *w, *t, *v;
    w = 0;
    v = p;
    /*@
    loop invariant w == NULL || \valid(w);
    loop invariant v == NULL || \valid(v);
    loop invariant \separated(w, v);
    loop assigns w;
    loop assigns v;
    loop assigns t;
    ```c;
    ```;
    Looking at this linked list reversal problem, I need to generate loop invariants for the while loop that reverses a singly linked list.;
    */
    while (v) {
        t = v->next;
        v->next = w;
        w = v;
        v = t;
    }
    // @ assert p == \at(p,Pre);
    return w;
}