#include <stdlib.h>

void foo28_helper4_c6(int *a, int a_len, int *aux, int aux_len, int lo, int mid, int hi);
void foo28_helper1_c6(int *a, int a_len);
void foo28_helper2_c6(int *a, int a_len);
void foo28_helper3_c6(int *from, int from_len, int *to, int to_len, int lo, int mid, int hi);
void foo28_helper5_c6(int *a, int a_len, int *aux, int aux_len, int lo, int hi);
void foo6(int *a, int a_len);

/*@
  predicate lseg{L}(struct list* x, struct list* y) =
    x == y || (x != y && \valid(x) && \separated(x, y));
*/
/*@
  predicate listrep(struct list* head) = lseg(head, \null);
*/

/*@
  predicate aux_prefix_from_sources{L}(int *a, int *aux, integer lo, integer mid, integer i, integer j, integer k) =
    i >= lo && i <= mid && j >= mid && j <= k + mid &&
    (i - lo) + (j - mid) == k - lo &&
    (\forall integer t; lo <= t < k ==>
       (\exists integer p; (lo <= p < i || mid <= p < j) && aux[t] == a[p]));
*/
        
void foo28_helper4_c6(int *a, int a_len, int *aux, int aux_len, int lo, int mid, int hi) {
    if (mid >= a_len) return;
    if (hi > a_len) hi = a_len;
    int i = lo, j = mid;
    /*@
      loop invariant (i - lo) + (j - mid) == k - lo;
      loop assigns i, j, aux[k .. hi-1];
    */
    for (int k = lo; k < hi; k++) {
        if (i == mid) aux[k] = a[j++];
        else if (j == hi) aux[k] = a[i++];
        else if (a[j] < a[i]) aux[k] = a[j++];
        else aux[k] = a[i++];
    }
    for (int k = lo; k < hi; k++) a[k] = aux[k];
}

#include <stdlib.h>

void foo28_helper4_c6(int *a, int a_len, int *aux, int aux_len, int lo, int mid, int hi);
void foo28_helper1_c6(int *a, int a_len);
void foo28_helper2_c6(int *a, int a_len);
void foo28_helper3_c6(int *from, int from_len, int *to, int to_len, int lo, int mid, int hi);
void foo28_helper5_c6(int *a, int a_len, int *aux, int aux_len, int lo, int hi);
void foo6(int *a, int a_len);

/*@
  predicate lseg{L}(struct list* x, struct list* y) =
    x == y || (x != y && \valid(x) && \separated(x, y));
*/
/*@
  predicate listrep(struct list* head) = lseg(head, \null);
*/

/*@
  predicate aux_prefix_from_sources{L}(int *a, int *aux, integer lo, integer mid, integer i, integer j, integer k) =
    i >= lo && i <= mid && j >= mid && j <= k + mid &&
    (i - lo) + (j - mid) == k - lo &&
    (\forall integer t; lo <= t < k ==>
       (\exists integer p; (lo <= p < i || mid <= p < j) && aux[t] == a[p]));
*/
        
void foo28_helper4_c6(int *a, int a_len, int *aux, int aux_len, int lo, int mid, int hi) {
    if (mid >= a_len) return;
    if (hi > a_len) hi = a_len;
    int i = lo, j = mid;
    /*@
      loop invariant (i - lo) + (j - mid) == k - lo;
      loop assigns i, j, aux[k .. hi-1];
    */
    for (int k = lo; k < hi; k++) {
        if (i == mid) aux[k] = a[j++];
        else if (j == hi) aux[k] = a[i++];
        else if (a[j] < a[i]) aux[k] = a[j++];
        else aux[k] = a[i++];
    }
    for (int k = lo; k < hi; k++) a[k] = aux[k];
}


void foo28_helper5_c6(int *a, int a_len, int *aux, int aux_len, int lo, int hi) {
    if (hi - lo <= 1) return;
    int mid = lo + (hi - lo) / 2;
    foo28_helper5_c6(a, a_len, aux, aux_len, lo, mid);
    foo28_helper5_c6(a, a_len, aux, aux_len, mid, hi);
    foo28_helper4_c6(a, a_len, aux, aux_len, lo, mid, hi);
}


void foo6(int *a, int a_len) {
    int *aux = (int *)malloc(sizeof(int) * a_len);
    foo28_helper5_c6(a, a_len, aux, a_len, 0, a_len);
}