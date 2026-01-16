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
      loop invariant (\exists struct sys_slist_t* q; q == p || q == NULL);
      loop invariant (\forall struct sys_slist_t* q; 
          (\text{reachable from } l \text{ by following next pointers, stepping by 2}) 
          ==> (p == q || p == q->next || p == NULL));
      loop assigns p;
      loop variant \text{(distance in list from p to end)};
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