#include <stdlib.h>
//Glibc iter

struct list_t {
    struct list_t *next;
};


struct list_t *main8(struct list_t *l)
{
    struct list_t *p;
    p = l;
    /*@
    */
    while (p) {
        p = p->next;
    }
    // @ assert l == \at(l,Pre);
    return l;
}