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
    loop invariant \valid(p) || p == NULL;
    loop invariant \forall struct SNnode* node; reachable_from(p, node) ==> \exists struct SNnode* prev; reachable_from(w, prev) || prev == NULL;
    loop invariant \forall struct SNnode* node; reachable_from(w, node) ==> node->tail points to previous node in reversed segment;
    loop invariant \at(p, Pre) == p;
    loop invariant (w == NULL || \valid(w));
    loop assigns w, v, t;
    loop assigns v->tail;
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