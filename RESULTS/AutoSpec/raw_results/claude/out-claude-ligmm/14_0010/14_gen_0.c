//Zephyr slist rev
#include <stdlib.h>
struct sys_slist_t {
    struct sys_slist_t *next;
};


struct sys_slist_t *main14(struct sys_slist_t *p)
{
    struct sys_slist_t *w, *t, *v;
    w = 0;
    v = p;
    /*@
    /*@ 
      loop invariant (\exists struct sys_slist_t* curr; curr == v);
      loop invariant w == \at(p, Pre) && (\forall struct sys_slist_t* node; 
                        (node != NULL && node != v) ==> 
                        (node->next == \at(node->next, Pre) || node->next == w));
      loop invariant \forall struct sys_slist_t* node; 
                        node != NULL && node != v ==> \at(node->next, Pre) != NULL;
      loop assigns w, v, t;
    */
    */
    while (v) {
        t = v->next;
        v->next = w;
        w = v;
        v = t;
    }
    // @ assert p == \at(p,Pre);
    return w;
}