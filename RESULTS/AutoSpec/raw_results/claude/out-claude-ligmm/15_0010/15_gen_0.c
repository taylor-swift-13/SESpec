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
    loop invariant \valid(w);
    loop invariant \valid(v) || v == \null;
    loop invariant \forall struct sys_slist_t* node; 
        (\exists struct sys_slist_t* cur; (cur == w || cur == v) && \reachable(cur, node)) ==> \reachable(w, node);
    loop invariant \forall struct sys_slist_t* node; \reachable(p, node) ==> (node == v || \reachable(w, node) || \reachable(v, node));
    loop invariant \forall struct sys_slist_t* node; \reachable(q, node) ==> \reachable(w, node) || node == w;
    loop invariant \forall struct sys_slist_t* node; !\reachable(v, node) ==> \reachable(w, node) || !\reachable(p, node);
    loop assigns w, v, t;
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