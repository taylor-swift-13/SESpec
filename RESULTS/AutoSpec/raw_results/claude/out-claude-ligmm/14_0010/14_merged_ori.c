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
    node != NULL && node != v ==> \at(node->next, Pre) != NULL;
    loop invariant w == \at(p, Pre) && (\forall struct sys_slist_t* node;;
    loop invariant \forall struct sys_slist_t* node;;
    loop invariant (\exists struct sys_slist_t* curr; curr == v);
    /*@;
    (node- > next == \at(node- > next, Pre) || node- > next == w));
    (node != NULL && node != v) == >;
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