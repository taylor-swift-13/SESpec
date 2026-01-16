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
    loop invariant \valid(w) || w == NULL;
    loop invariant \valid(v) || v == NULL;
    loop invariant \valid(t) || t == NULL;
    loop invariant \forall struct sys_slist_t* node;
    loop invariant \forall struct sys_slist_t* n;;
    \forall struct sys_slist_t* n; (n == w || n == v || n == t) ==> n != NULL;
    /*@;
    (node == w || node == v || node == t || node == p || node == NULL));
    (\exists struct sys_slist_t* q; p == q || q- > next != NULL) == >;
    (\exists struct sys_slist_t* curr; (node == curr || \exists struct sys_slist_t* nxt; curr- > next == nxt) &&;
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