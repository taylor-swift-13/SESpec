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
    node != w && node != v ==> \exists struct sys_slist_t *orig; orig == node;
    loop invariant w != NULL ==> (\forall struct sys_slist_t *n; n != w ==> n != v);
    loop invariant \forall struct sys_slist_t *node;;
    loop invariant \exists struct sys_slist_t *cur; cur == v || cur == w || cur == t;
    loop invariant (\forall struct sys_slist_t *node;;
    (node- > next == (node == w ? \null : prev)));
    (node == curr || \exists struct sys_slist_t *prev; prev == w && curr == v)) == >;
    (\exists struct sys_slist_t *curr;;
    loop invariant (\exists struct sys_slist_t *x; x == w);
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