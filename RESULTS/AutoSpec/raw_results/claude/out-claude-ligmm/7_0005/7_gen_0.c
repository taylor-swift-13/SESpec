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
    loop invariant \valid_read(v) || v == NULL;
    loop invariant \valid_read(w) || w == NULL;
    loop invariant \forall struct SNnode* q; (q != NULL && \reach(q, p)) ==> !\reach(q, v);
    loop invariant \reach(w, v) == 0;
    loop invariant \forall struct SNnode* q; \reach(q, w) ==> q != v;
    loop assigns v, w, t;
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