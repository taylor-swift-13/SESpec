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
    loop invariant \valid(p) && \valid(q);
    loop invariant \forall struct sys_slist_t* node; \at(node,Pre) != \null ==> 
      ((\exists struct sys_slist_t* curr; curr == v && node == curr) || 
       (\exists struct sys_slist_t* curr; curr == w && node == curr) || 
       (\exists struct sys_slist_t* curr; curr == t && node == curr) || 
       node != \at(node,Pre)->next));
    loop invariant \exists struct sys_slist_t* curr; curr == v || curr == w || curr == t;
    loop invariant \forall struct sys_slist_t* n; n != \null ==> (n->next != n);
    loop assigns v, w, t;
    loop assigns v->next, w->next, t->next;
    loop invariant pointer_separation: v != w && v != t && w != t;
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