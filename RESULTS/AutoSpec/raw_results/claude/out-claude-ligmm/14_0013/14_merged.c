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
    loop invariant \valid(p) || p == \null;
    loop invariant \reachable(w, w) && \reachable(v, v);
    loop invariant (\forall struct sys_slist_t* node;;
    \reachable(w, n) ==> !\reachable(v, n);
    \reachable(p, n) == (\reachable(w, n) || \reachable(v, n));
    ==> \mutable(node));
    (\exists struct sys_slist_t* curr; curr == v || curr == w);
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