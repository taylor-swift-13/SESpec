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
      loop invariant z == \at(x, Pre);
      loop invariant y == 0 || \valid(y);
      loop invariant x != 0;
      loop invariant t == \at(y, Pre) || t == \at(y- > next, Pre);
      loop invariant \valid(y);
      loop invariant \valid(x);
      loop invariant \forall struct sys_slist_t *p; \reach(z, p) ==> \valid(p);
      loop assigns z;
      loop assigns y;
      loop assigns x;
      loop assigns t;
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