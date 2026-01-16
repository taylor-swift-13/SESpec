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
    loop invariant ((p == NULL) || (\exists struct sys_slist_t *q; q == p || q == \at(p, Pre)));
    loop invariant \forall struct sys_slist_t *q; (\exists struct sys_slist_t *r; r == \at(l, Pre) && (q == r || \exists int k; 0 <= k && (r + k) == q)) ==> (q != p);
    loop invariant \valid(l);
    loop assigns p;
    loop assigns \nothing;
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