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
    loop invariant \valid_read(p) || p == \null;
    loop invariant \valid_read(w) || w == \null;
    loop invariant \valid_read(v) || v == \null;
    loop invariant \forall struct SNnode* n; 
      (n == w || \at(n,Pre) == v || n == t) ==> 
      (n == w || n == v || n == t);
    loop invariant \forall struct SNnode* n; \reach(w, tail) && \reach(p, tail) && \reach(v, tail);
    loop invariant \separated(w, v);
    loop invariant \false == (v == p && w != \null);
    loop assigns w, v, t;
    loop assigns v->tail, w, t;
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