// Linked-list traversal: walk to the last cell, then splice. The right
// invariants are SHAPE claims — `listrep(t)`, `listrep(u)`, `lseg(x, t)`
// — built from `lseg` (cell-to-cell separated reachability) and
// `listrep` (reachable from head to NULL). All three predicates carry
// the `{L}` label so they remain well-formed under labels.

#include <stdlib.h>

struct list {
  struct list *tail;
};

/*@
  predicate lseg{L}(struct list* x, struct list* y) =
    x == y || (x != y && \valid(x) && \separated(x, y) && lseg{L}(x->tail, y));
*/

/*@
  predicate listrep(struct list* head) = lseg(head, NULL);
*/

/*@
predicate disjoint(struct list* x, struct list* y) =
    \separated(x, y) &&
    \forall struct list* p, struct list* q;
      lseg(x,p) && lseg(y,q) ==> \separated(p,q);
*/

/*@
  requires listrep(x) && listrep(y);
  requires disjoint(x, y);
  ensures listrep(\result);
*/
struct list * append(struct list *x, struct list *y) {
  struct list *t, *u;

  if (x == NULL) {
    return y;
  } else {
    t = x;
    u = t->tail;

    /*@
      loop invariant u == t->tail;
      loop invariant listrep(t);          
      loop invariant listrep(u);            
      loop invariant listrep(y);     
      loop invariant lseg(x, t);           
    */
    while (u != NULL) {
      t = u;
      u = t->tail;
    }
    t->tail = y;
    return x;
  }
}
