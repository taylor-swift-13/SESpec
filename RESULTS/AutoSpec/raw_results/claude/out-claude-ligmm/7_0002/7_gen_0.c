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
    loop invariant \valid_chain(v);
    loop invariant \valid_chain(w);
    loop invariant \forall struct SNnode* n; reachable_from(p, n) && !reachable_from(v, n) ==> reachable_from(w, n);
    loop invariant \reachable(w) && \reachable(v);
    loop assigns w, v, t;
      
    // Note: \valid_chain and reachable_from are common ACSL predicates for linked lists; if not predefined, you can define appropriate predicates to express validity and reachability.
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