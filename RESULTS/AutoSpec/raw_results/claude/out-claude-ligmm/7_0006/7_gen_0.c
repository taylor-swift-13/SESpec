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
    loop invariant \valid(p) && \valid(w) && \valid(v) || (w == \null && v == \null);
    loop invariant \forall struct SNnode* n; n != w && n != v ==> \old(n->tail) == n->tail || n == p;
    loop invariant \forall struct SNnode* n; n == w ==> \reachable(n, w);
    loop invariant \forall struct SNnode* n; n == v ==> \reachable(n, v);
    loop invariant \forall struct SNnode* n; \reachable(p, n) == (\reachable(w, n) || \reachable(v, n) || \reachable(t, n));
    loop assigns w, v, t;
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