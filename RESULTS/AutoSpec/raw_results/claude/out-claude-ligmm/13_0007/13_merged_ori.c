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
      loop invariant y != NULL ? 1 : 0;
      loop invariant y != NULL ==> z != NULL;
      loop invariant \valid(y);
      loop invariant \valid(x);
      loop invariant \valid(t);
      loop invariant \forall struct sys_slist_t* p;;
      loop assigns y;
      loop assigns x;
      loop assigns t;
      \valid(p- > next);
      /*@;
      (p != NULL && p != y && p != x && p != t) == >;
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