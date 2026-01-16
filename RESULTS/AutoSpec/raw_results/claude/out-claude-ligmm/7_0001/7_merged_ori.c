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
    loop invariant \valid_read(w) || w == \null;
    loop invariant \valid_read(v) || v == \null;
    loop invariant \valid_read(p) || p == \null;
    loop invariant \separated(w, v);
    loop invariant \forall struct SNnode* n;;
    loop invariant \forall struct SNnode* n; \reach(w, tail) && \reach(p, tail) && \reach(v, tail);
    loop invariant \false == (v == p && w != \null);
    loop assigns w;
    loop assigns v;
    loop assigns v->tail;
    loop assigns t;
    (n == w || n == v || n == t);
    (n == w || \at(n,Pre) == v || n == t) == >;
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