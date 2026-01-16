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
      loop invariant z == x || z == NULL;
      loop invariant y == t || y == NULL;
      loop invariant \valid(y) || y == NULL;
      loop invariant \valid(x) || x == NULL;
      loop invariant \separated(x, y);
      loop invariant \forall struct sys_slist_t* n; n != NULL ==> n->next != NULL || n->next == NULL;
      (n == z || n == t) ==> (\valid(n) || n == NULL);
      loop invariant y == t || y != NULL;
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