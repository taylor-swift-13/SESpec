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
    loop invariant \valid_read(p);
    loop invariant \forall struct SNnode *q; \reach(p, tail) ==> (\at(q, Pre) == q || \at(q->tail, Pre) == q->tail);
    loop invariant \reach(w, tail) && \reach(v, tail) && \reach(t, tail);
    loop invariant \forall struct SNnode *n; \reach(p, tail) ==> (n == w || \reach(w, tail) || \reach(v, tail) || \reach(t, tail));
    loop invariant \separation(\reach(w, tail), \reach(v, tail));
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