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
      loop invariant y == t || y == \null;
      loop invariant \valid(z);
      loop invariant \valid(y) || y == \null;
      loop invariant \valid(x);
      loop invariant \separated(z, y);
      loop invariant \forall struct sys_slist_t* n; n != \null && n != y ==> \reachable(z, n);
      loop invariant \forall struct sys_slist_t* n; n != \null && n != x ==> \reachable(z, n);
      loop invariant \forall struct sys_slist_t* n; \reachable(z, n) ==> n != y || n == t;
      loop invariant z == \at(x, Pre);
      loop invariant x != 0;
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