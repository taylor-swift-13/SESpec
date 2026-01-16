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
    loop invariant v;
    loop invariant \valid(w);
    loop invariant \valid(v) || v == \null;
    loop invariant \forall struct sys_slist_t* n;;
    /*@;
    (x == p && n == x) ||;
    (n == w || n == v || n == t || n == \null);
    (\exists struct sys_slist_t* y; y- > next == n && y == x)) == >;
    (\exists struct sys_slist_t* x;;
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