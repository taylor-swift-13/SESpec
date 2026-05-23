#include <stdlib.h>

void foo28_helper4_c6(int *a, int a_len, int *aux, int aux_len, int lo, int mid, int hi);
void foo28_helper1_c6(int *a, int a_len);
void foo28_helper2_c6(int *a, int a_len);
void foo28_helper3_c6(int *from, int from_len, int *to, int to_len, int lo, int mid, int hi);
void foo28_helper5_c6(int *a, int a_len, int *aux, int aux_len, int lo, int hi);
void foo6(int *a, int a_len);

/*@
  logic boolean is_sorted(int* arr, integer lo, integer hi) =
    \forall integer k; lo <= k < hi - 1 ==> arr[k] <= arr[k + 1];

  logic boolean is_permutation(int* arr1, int* arr2, integer lo, integer hi) =
    \forall integer v; 
      (\sum integer k; lo <= k < hi && arr1[k] == v ? 1 : 0) ==
      (\sum integer k; lo <= k < hi && arr2[k] == v ? 1 : 0);
*/

/*@
  requires \valid(a + (0..a_len-1));
  requires \valid(aux + (0..aux_len-1));
  requires 0 <= lo <= mid <= hi <= a_len;
  requires aux_len >= a_len;
  assigns aux[lo..hi-1], a[lo..hi-1];
  ensures is_sorted(a, lo, hi);
  ensures is_permutation(\old(a), a, lo, hi);
  ensures \forall integer k; lo <= k < hi ==> a[k] == aux[k];
*/
void foo28_helper4_c6(int *a, int a_len, int *aux, int aux_len, int lo, int mid, int hi) {
    if (mid >= a_len) return;
    if (hi > a_len) hi = a_len;
    int i = lo, j = mid;

    /*@
      loop invariant lo <= i <= mid;
      loop invariant mid <= j <= hi;
      loop invariant lo <= k <= hi;
      loop invariant \forall integer x; lo <= x < k ==> aux[x] == 
        (x < i ? a[x] : (x < j ? a[j - (mid - i)] : a[i + (x - j)]));
      loop invariant is_sorted(aux, lo, k);
      loop invariant is_permutation(a, aux, lo, k);
      loop assigns i, j, aux[lo..hi-1];
    */
    for (int k = lo; k < hi; k++) {
        if (i == mid) aux[k] = a[j++];
        else if (j == hi) aux[k] = a[i++];
        else if (a[j] < a[i]) aux[k] = a[j++];
        else aux[k] = a[i++];
    }

    /*@
      loop invariant lo <= k <= hi;
      loop invariant \forall integer x; lo <= x < k ==> a[x] == aux[x];
      loop assigns a[lo..hi-1];
    */
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
  requires \valid(a + (0 .. a_len - 1)) && \valid(aux + (0 .. aux_len - 1));
  requires 0 <= lo < hi <= a_len;
  assigns a[lo .. hi-1], aux[lo .. hi-1];
  ensures hi - lo <= 1 ==> \true;
  ensures hi - lo > 1 ==> \true;
*/
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