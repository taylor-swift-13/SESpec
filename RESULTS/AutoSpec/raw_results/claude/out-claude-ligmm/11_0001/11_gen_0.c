#include <stdlib.h>
//Zephyr slist itertwice

struct sys_slist_t {
    struct sys_slist_t *next;
};


struct sys_slist_t *main11(struct sys_slist_t *l)
{
    struct sys_slist_t *p;
    p = l;
   
    /*@
    /*@ 
      loop invariant \valid(l) && \valid(p) || p == \null;
      loop invariant (\forall struct sys_slist_t* q; 
                        (q == l || \exists struct sys_slist_t* r; r == l && (q == r || q == r->next || ...)) 
                        ==> \valid(q));
      loop assigns p;
      loop variant p == \null ? 0 : 1; 
    */
    */
    while (p) {
        p = p->next;
        if (p) {
          p = p -> next;
        }
    }
    // @ assert l == \at(l,Pre);
    return l;
}