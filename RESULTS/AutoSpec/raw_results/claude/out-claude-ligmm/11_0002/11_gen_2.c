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