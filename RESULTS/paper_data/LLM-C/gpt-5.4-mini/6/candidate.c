#include <stdlib.h>

/*@
  requires a_len >= 0;
  requires a_len == 0 || \valid(a + (0 .. a_len-1));
  requires a_len == 0 || \valid(aux + (0 .. aux_len-1));
  assigns aux[lo .. hi-1], a[lo .. hi-1];
  behavior empty:
    assumes hi <= lo;
    assigns \nothing;
    ensures \true;
  behavior non_empty:
    assumes hi > lo;
    assumes 0 <= lo <= mid <= hi;
    assumes hi <= a_len;
    assumes hi <= aux_len;
    ensures \true;
  complete behaviors;
  disjoint behaviors;
*/
void merge(int *a, int a_len, int *aux, int aux_len, int lo, int mid, int hi);

/*@
  requires a_len >= 0;
  requires a_len == 0 || \valid(a + (0 .. a_len-1));
  assigns a[0 .. a_len-1], \nothing;
*/
void iterativeMergesort(int *a, int a_len);

/*@
  requires a_len >= 0;
  requires a_len == 0 || \valid(a + (0 .. a_len-1));
  assigns a[0 .. a_len-1], \nothing;
*/
void iterativeMergesortWithoutCopy(int *a, int a_len);

/*@
  requires from_len >= 0;
  requires to_len >= 0;
  requires from_len == 0 || \valid_read(from + (0 .. from_len-1));
  requires to_len == 0 || \valid(to + (0 .. to_len-1));
  assigns to[lo .. hi-1];
*/
void mergeWithoutCopy(int *from, int from_len, int *to, int to_len, int lo, int mid, int hi);

/*@
  requires a_len >= 0;
  requires aux_len >= 0;
  requires a_len == 0 || \valid(a + (0 .. a_len-1));
  requires aux_len == 0 || \valid(aux + (0 .. aux_len-1));
  requires 0 <= lo <= hi <= a_len;
  assigns a[lo .. hi-1], aux[lo .. hi-1];
*/
void recursiveMergesort(int *a, int a_len, int *aux, int aux_len, int lo, int hi);

/*@
  requires a_len >= 0;
  requires a_len == 0 || \valid(a + (0 .. a_len-1));
  assigns a[0 .. a_len-1], \nothing;
*/
void recursiveMergesort_2(int *a, int a_len);

void iterativeMergesort(int *a, int a_len) {
    int *aux = (int *)malloc(sizeof(int) * a_len);
    for (int blockSize = 1; blockSize < a_len; blockSize *= 2)
        for (int start = 0; start < a_len; start += 2 * blockSize)
            merge(a, a_len, aux, a_len, start, start + blockSize, start + 2 * blockSize);
}

void iterativeMergesortWithoutCopy(int *a, int a_len) {
    int *from = a;
    int from_len = a_len;
    int *to = (int *)malloc(sizeof(int) * a_len);
    int to_len = a_len;
    for (int blockSize = 1; blockSize < a_len; blockSize *= 2) {
        for (int start = 0; start < a_len; start += 2 * blockSize)
            mergeWithoutCopy(from, from_len, to, to_len, start, start + blockSize, start + 2 * blockSize);
        int *temp = from; from = to; to = temp;
    }
    if (a != from) for (int k = 0; k < a_len; k++) a[k] = from[k];
}

void mergeWithoutCopy(int *from, int from_len, int *to, int to_len, int lo, int mid, int hi) {
    if (mid > from_len) mid = from_len;
    if (hi > from_len) hi = from_len;
    int i = lo, j = mid;
    for (int k = lo; k < hi; k++) {
        if (i == mid) to[k] = from[j++];
        else if (j == hi) to[k] = from[i++];
        else if (from[j] < from[i]) to[k] = from[j++];
        else to[k] = from[i++];
    }
}

void merge(int *a, int a_len, int *aux, int aux_len, int lo, int mid, int hi) {
    if (mid >= a_len) return;
    if (hi > a_len) hi = a_len;
    int i = lo, j = mid;
    for (int k = lo; k < hi; k++) {
        if (i == mid) aux[k] = a[j++];
        else if (j == hi) aux[k] = a[i++];
        else if (a[j] < a[i]) aux[k] = a[j++];
        else aux[k] = a[i++];
    }
    for (int k = lo; k < hi; k++) a[k] = aux[k];
}

void recursiveMergesort(int *a, int a_len, int *aux, int aux_len, int lo, int hi) {
    if (hi - lo <= 1) return;
    int mid = lo + (hi - lo) / 2;
    recursiveMergesort(a, a_len, aux, aux_len, lo, mid);
    recursiveMergesort(a, a_len, aux, aux_len, mid, hi);
    merge(a, a_len, aux, aux_len, lo, mid, hi);
}

void recursiveMergesort_2(int *a, int a_len) {
    int *aux = (int *)malloc(sizeof(int) * a_len);
    recursiveMergesort(a, a_len, aux, a_len, 0, a_len);
}
