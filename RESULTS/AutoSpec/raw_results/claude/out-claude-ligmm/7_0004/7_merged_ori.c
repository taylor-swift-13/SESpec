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
    loop invariant \valid(w) || w == \null;
    loop invariant \valid(v) || v == \null;
    loop invariant \valid(p) || p == \null;
    loop invariant \forall struct SNnode* q;;
    /*@;
    (q == w || \linked_from(w, q));
    (\exists struct SNnode* r; (q == r && (r == p || \was_tail_of(r)))) == >;
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