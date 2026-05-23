#include <stdlib.h>

void foo28_helper4_c6(int *a, int a_len, int *aux, int aux_len, int lo, int mid, int hi);
void foo28_helper1_c6(int *a, int a_len);
void foo28_helper2_c6(int *a, int a_len);
void foo28_helper3_c6(int *from, int from_len, int *to, int to_len, int lo, int mid, int hi);
void foo28_helper5_c6(int *a, int a_len, int *aux, int aux_len, int lo, int hi);
void foo28_c6(int *a, int a_len);

/*@ logic integer arrsum(int* a, integer lo, integer hi) =
    lo >= hi ? 0 : a[lo] + arrsum(a, lo + 1, hi);
*/

/*@ 
  predicate arrslice_eq(int* x, integer x_lo, integer x_hi,
                        int* y, integer y_lo, integer y_hi) =
    x_hi < x_lo ? \true :
      (\forall integer t; 0 <= t <= x_hi - x_lo ==> x[x_lo + t] == y[y_lo + t]);
*/

void foo28_helper4_c6(int *a, int a_len, int *aux, int aux_len, int lo, int mid, int hi) {
    if (mid >= a_len) return;
    if (hi > a_len) hi = a_len;
    int i = lo, j = mid;
    /*@
      loop invariant k >= lo;
      loop invariant i >= lo;
      loop invariant j >= mid;
      loop invariant k - lo >= i - lo;
      loop invariant k - lo >= j - mid;
      loop assigns k, i, j, aux[lo..hi-1];
    */
    for (int k = lo; k < hi; k++) {
        if (i == mid) aux[k] = a[j++];
        else if (j == hi) aux[k] = a[i++];
        else if (a[j] < a[i]) aux[k] = a[j++];
        else aux[k] = a[i++];
    }
    /*@
      loop invariant k >= lo;
      loop assigns k, a[lo..hi-1];
    */
    for (int k = lo; k < hi; k++) a[k] = aux[k];
}

#include <stdlib.h>

void foo28_helper4_c6(int *a, int a_len, int *aux, int aux_len, int lo, int mid, int hi);
void foo28_helper1_c6(int *a, int a_len);
void foo28_helper2_c6(int *a, int a_len);
void foo28_helper3_c6(int *from, int from_len, int *to, int to_len, int lo, int mid, int hi);
void foo28_helper5_c6(int *a, int a_len, int *aux, int aux_len, int lo, int hi);
void foo28_c6(int *a, int a_len);


void foo28_helper5_c6(int *a, int a_len, int *aux, int aux_len, int lo, int hi) {
    if (hi - lo <= 1) return;
    int mid = lo + (hi - lo) / 2;
    foo28_helper5_c6(a, a_len, aux, aux_len, lo, mid);
    foo28_helper5_c6(a, a_len, aux, aux_len, mid, hi);
    foo28_helper4_c6(a, a_len, aux, aux_len, lo, mid, hi);
}


void foo28_c6(int *a, int a_len) {
    int *aux = (int *)malloc(sizeof(int) * a_len);
    foo28_helper5_c6(a, a_len, aux, a_len, 0, a_len);
}