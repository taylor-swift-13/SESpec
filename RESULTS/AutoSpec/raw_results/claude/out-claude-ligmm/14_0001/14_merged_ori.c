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
    loop invariant \valid_read(v) || v == \null;
    loop invariant \valid(w) || w == \null;
    loop invariant \reachset(p, Pre) == \reachset(w) \union \reachset(v);
    loop invariant \forall struct sys_slist_t* node;;
    loop assigns w;
    loop assigns v;
    loop assigns t;
    /*@;
    (prev == 0 && node == v) || (prev- > next == node && \reachset(p, Pre)(prev)));
    (node != 0 && \reachset(w) (node)) ==> \reachset(w) (node);
    (node != 0 && \reachset(p, Pre)(node)) == >;
    (\exists struct sys_slist_t* prev;;
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