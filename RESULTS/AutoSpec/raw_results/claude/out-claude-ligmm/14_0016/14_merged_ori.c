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
    n in reversed list segment w ==> n->next points to previous node or NULL);
    loop invariant \forall struct sys_slist_t* node;;
    loop invariant \exists struct sys_slist_t* cur;;
    loop invariant (\forall struct sys_slist_t* n;;
    cur == v + w + t (disjoint segments);
    /*@;
    );
    (node in reversed prefix w) || (node in remaining suffix v);
    (node in original list before reversal) ==> (;
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