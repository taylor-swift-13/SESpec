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
    loop invariant p != NULL ==> p != \null;
    loop assigns p;
    */
    while (p) {
        p = p->next;
    }
    //@ assert l == \at(l,Pre);
    return l;
}