#include <stdlib.h>
// Zephyr slist merge

struct sys_slist_t {
    struct sys_slist_t *next;
};



struct sys_slist_t *main13(struct sys_slist_t *x , struct sys_slist_t *y)
{
    struct sys_slist_t *z, *t;
    if (x == 0) {
      return y; 
    }
    else {
      z = x;
      t = y;
    
      /*@
      loop invariant y == t || y != 0;
      loop invariant \valid(x);
      loop invariant \valid(y);
      loop invariant \valid(z);
      loop invariant \valid(t);
      loop assigns x->next, y->next, t, y, x;
      loop invariant \exists struct sys_slist_t* p; p == z;
      loop invariant z != NULL;
      loop assigns x, y, t;
      loop invariant y == t || y == NULL;
      */
      while (y) {
        t = y -> next;
        y -> next = x -> next;
        x -> next = y;
        if (y -> next == 0) {
          y -> next = t;
          return z;
        }
        else {
          x = y -> next;
          y = t;
        }
      }
      // @ assert y == t ;*/
      // @ assert x != 0;
    }
    
    return z;
}