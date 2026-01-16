#include <stdlib.h>
//Glibc iter-twice

struct list_t {
    struct list_t *next;
};


struct list_t *main9(struct list_t *l)
{
    struct list_t *p;
    p = l;
    /*@
    loop invariant \valid(l);
    loop invariant \forall struct list_t* q; 
      (q == l || \exists struct list_t* r; r->next == q) ==> q != NULL;
    loop invariant \exists struct list_t* q; p == q || p == NULL;
    loop invariant \forall struct list_t* q; 
      (q == p || q == NULL) ==> \true;
    loop assigns p;
    */
    while (p) {
        p = p->next;
        if (p) {
          p = p -> next;
        }
      	else {
          return l;
        }
    }
    // @ assert l == \at(l,Pre);
    return l;
}