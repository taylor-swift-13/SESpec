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
      loop invariant (\forall struct sys_slist_t *node; 
        (\exists struct sys_slist_t *curr; curr == node && 
          (\at(node, Pre) == curr || \at(node, Pre) == curr->next)));
      loop invariant (\exists struct sys_slist_t *x; x == w);
      loop assigns w, t, v;
      loop variant v;
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