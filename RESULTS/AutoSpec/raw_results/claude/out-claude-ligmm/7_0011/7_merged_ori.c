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
    loop invariant \valid(p);
    loop invariant \reachable(w, w);
    loop invariant \reachable(v, v) || v == \null;
    loop invariant \forall struct SNnode* n;;
    loop invariant \forall struct SNnode* n; \reachable(w, n) ==> \rarrow(n, w);
    loop invariant \forall struct SNnode* n; \reachable(v, n) ==> \rarrow(n, v);
    ( \reachable(p, n) <==> (\reachable(w, n) || \reachable(v, n) || \reachable(t, n)) );
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