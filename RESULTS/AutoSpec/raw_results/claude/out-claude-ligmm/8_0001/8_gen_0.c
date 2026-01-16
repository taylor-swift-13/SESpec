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
    /*@ 
      loop invariant p != NULL ==> \exists struct list_t* q; 
          q == p && (\forall struct list_t* r; r != q ==> \at(l, Pre) != NULL);
      loop invariant p == NULL || \valid(p);
      loop assigns p;
      loop variant \at(l, Pre) != NULL ? (size_t)(intptr_t)p : 0;
    */
    */
    while (p) {
        p = p->next;
    }
    // @ assert l == \at(l,Pre);
    return l;
}