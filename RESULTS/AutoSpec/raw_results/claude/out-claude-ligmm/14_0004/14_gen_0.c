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
      loop invariant \exists struct sys_slist_t* cur; 
        (w == cur) &&
        (\forall struct sys_slist_t* node; 
           (node != 0 && \reach(prev, node)) ==> 
           (\reach(p, node) && 
            \reach(node, v) == 0));
      loop invariant \valid(w);
      loop invariant \valid(v) || v == 0;
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