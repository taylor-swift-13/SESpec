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
    loop invariant 
      \exists struct sys_slist_t* curr; v == curr && 
      \forall struct sys_slist_t* node; 
        (\from p; \reachable(p, node)) ==>
        ((\reachable(node, v) && \reachable(w, node)) || node == w || node == v);
    loop assigns v, w, t;
    loop invariant \valid(w) || w == q || w == NULL;
    loop invariant \valid(v) || v == NULL;
    loop assigns v, w, t;
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