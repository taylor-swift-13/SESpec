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
    loop invariant w != NULL ==> \exists struct sys_slist_t* u; u == w && (\forall struct sys_slist_t* node; node != NULL && node != u ==> node != w);
    loop invariant \forall struct sys_slist_t* node; (node == w || node == v) ==> (node == \at(node, Pre) || node->next == w);
    loop invariant (w == \at(q,Pre) || \exists struct sys_slist_t* u; u == v || u == w);
    */
    while (v) {
      t = v->next;
      v->next = w;
      w = v;
      v = t;
    }
    //@ assert p == \at(p,Pre);
    //@ assert q == \at(q,Pre);
    return w;
}