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
    //@ assert l == \at(l,Pre);
    return l;
}