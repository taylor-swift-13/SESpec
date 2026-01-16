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
    loop invariant \valid(w);
    loop invariant \valid(v);
    loop invariant \forall struct SNnode* n; 
      (\reachable(p, n) && !\reachable(v, n)) ==> \reachable(w, n);
    loop invariant \union_chain(w, v) == \union_chain(p);
    loop invariant \disjoint_chain(w, v);
    loop assigns w, t, v;
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