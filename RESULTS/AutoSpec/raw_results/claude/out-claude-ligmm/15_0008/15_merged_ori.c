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
    loop assigns w;
    loop assigns v;
    loop assigns v->next;
    loop assigns t;
    \forall struct sys_slist_t* n; n != v ==> (n == w || n->next == w || n == t || n->next == t);
    \exists struct sys_slist_t* mid;;
    \exists struct sys_slist_t* mid; v == mid || v- > next == mid) &&;
    (w == \at(q, Pre) ||;
    (v == p ||;
    (\forall struct sys_slist_t* n; \at(q, Pre) == w || n == w || n- > next == w)) &&;
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