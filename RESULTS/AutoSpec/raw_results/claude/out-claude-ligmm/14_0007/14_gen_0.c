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
    loop invariant w != NULL || w == NULL;
    loop invariant \forall struct sys_slist_t* node; node != NULL ==> (node != v && node != w && node != t) || node == v || node == w || node == t;
    loop invariant \forall struct sys_slist_t* node; node != NULL ==> (node == w) || (node != w);
    loop invariant v == \at(v,Pre) || v == t || v == w;
    loop invariant \exists struct sys_slist_t *cur; cur == v || cur == w || cur == t;
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