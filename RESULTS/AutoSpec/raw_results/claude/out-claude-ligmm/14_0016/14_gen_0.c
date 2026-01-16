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
        cur == v + w + t (disjoint segments);
      loop invariant \forall struct sys_slist_t* node; 
        (node in original list before reversal) ==> (
          (node in reversed prefix w) || (node in remaining suffix v)
        );
      loop invariant (\forall struct sys_slist_t* n; 
        n in reversed list segment w ==> n->next points to previous node or NULL);
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