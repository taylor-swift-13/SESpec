//Zephyr slist rev
#include <stdlib.h>
struct sys_slist_t {
    struct sys_slist_t *next;
};


struct sys_slist_t *main14(struct sys_slist_t *p)
{
    struct sys_slist_t *w, *t, *v;
    w = 0;
    v = p;
    /*@
    p == old_p;
    loop invariant \valid(p) || p == \null;
    loop invariant \let old_p = \at(p, Pre);;
    loop invariant \forall struct sys_slist_t* n;;
    \reachable(w, n) ==> !\reachable(v, n);
    \reachable(p, n) <==> \reachable(w, n) || \reachable(v, n);
    /*@;
    */
    while (v) {
        t = v->next;
        v->next = w;
        w = v;
        v = t;
    }
    // @ assert p == \at(p,Pre);
    return w;
}