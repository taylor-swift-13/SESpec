#include <stdlib.h>

void foo28_helper4_c6(int *a, int a_len, int *aux, int aux_len, int lo, int mid, int hi);
void foo28_helper1_c6(int *a, int a_len);
void foo28_helper2_c6(int *a, int a_len);
void foo28_helper3_c6(int *from, int from_len, int *to, int to_len, int lo, int mid, int hi);
void foo28_helper5_c6(int *a, int a_len, int *aux, int aux_len, int lo, int hi);
void foo6(int *a, int a_len);

/*@
*/

/*@
  loop invariant lo <= k <= hi;
  loop invariant lo <= i <= mid;
  loop invariant mid <= j <= hi;
  loop invariant i + j == k + mid;
  loop assigns k, i, j, aux[lo .. hi - 1];
*/
for (int k = lo; k < hi; k++) {
    if (i == mid) aux[k] = a[j++];
    else if (j == hi) aux[k] = a[i++];
    else if (a[j] < a[i]) aux[k] = a[j++];
    else aux[k] = a[i++];
}

/*@ 
  loop invariant lo <= k <= hi;
  loop invariant \forall integer t; lo <= t < k ==> a[t] == aux[t];
  loop assigns k, a[lo .. hi - 1];
*/
for (int k = lo; k < hi; k++) a[k] = aux[k];


#include <stdlib.h>

void foo28_helper4_c6(int *a, int a_len, int *aux, int aux_len, int lo, int mid, int hi);
void foo28_helper1_c6(int *a, int a_len);
void foo28_helper2_c6(int *a, int a_len);
void foo28_helper3_c6(int *from, int from_len, int *to, int to_len, int lo, int mid, int hi);

/*@
  requires 0 <= a_len;
  requires 0 <= aux_len;
  requires \valid(a + (0 .. a_len - 1));
  requires \valid(aux + (0 .. aux_len - 1));
  requires 0 <= lo <= hi;
  requires hi <= a_len;
  requires hi <= aux_len;
  assigns a[lo .. hi - 1], aux[lo .. hi - 1];
  ensures \true;
*/
void foo28_helper5_c6(int *a, int a_len, int *aux, int aux_len, int lo, int hi);
void foo6(int *a, int a_len);

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