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
    /*@ 
      loop invariant \valid(w) || w == \null;
      loop invariant \valid(v) || v == \null;
      loop invariant \forall struct sys_slist_t* n; 
        (\reach(p, n) && \before(p, n, v)) ==> (\reachable_from(w) || n == w || n == v);
      loop assigns w, v, t;
      loop variant \distance(v, \null);
    */
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