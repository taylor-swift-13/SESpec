#include <stdlib.h>
//Zephyr slist rev_append
struct sys_slist_t {
    struct sys_slist_t *next;
};


struct sys_slist_t *main15(struct sys_slist_t *p, struct sys_slist_t *q)
{
    struct sys_slist_t *w, *t, *v;
    w = q;
    v = p;
   
    /*@
    loop invariant;
    loop invariant \valid(w) || w == NULL;
    loop invariant \valid(v) || v == NULL;
    loop invariant \valid(t) || t == NULL;
    loop assigns w;
    loop assigns v;
    loop assigns v->next;
    loop assigns t;
    (node == p || node == q) == >;
    (cur == w || cur == v || cur == t) &&;
    (\forall struct sys_slist_t *node;;
    (\exists struct sys_slist_t *cur;;
    (\exists int flag; flag == 0 || flag == 1) ));;
    */
    while (v) {
      t = v->next;
      v->next = w;
      w = v;
      v = t;
    }
    // @ assert p == \at(p,Pre);
    // @ assert q == \at(q,Pre);
    return w;
}