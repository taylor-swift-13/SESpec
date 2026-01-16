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
      loop invariant \exists struct sys_slist_t* curr; curr == v;
      loop invariant \forall struct sys_slist_t* n; (
        (n != 0 && n != v && \old(p) != 0) ==> 
        (   (\reach(\old(p), n) && \reachable_in_chain(w, n)) ||
            (!\reach(\old(p), n) && !\reachable_in_chain(w, n))
        )
      );
      loop invariant \disjoint(\from(v), \from(w));
      loop assigns v, w, t;
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