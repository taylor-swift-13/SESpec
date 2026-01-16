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
      loop invariant \valid(p) || p == \null;
      loop invariant \forall struct sys_slist_t* q; 
        ( (q != 0 && q != v && q != w && \reachable(p, q)) ==> 
          \reachable(w, q) || \reachable(v, q) );
      loop invariant \separated(w, v);
      loop assigns w, v, t;
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