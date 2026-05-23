#include <stdlib.h>

/*@
    requires \valid(a + (0 .. a_len-1));
    requires 0 <= lo <= mid <= hi;
    requires \valid(aux + (0 .. aux_len-1));
    requires aux_len >= hi;
    requires a_len >= hi;
    assigns aux[lo .. hi-1], a[lo .. hi-1];
    ensures \forall integer k; 0 <= k < lo || hi <= k < a_len ==> a[k] == \old(a[k]);
    ensures \forall integer i,j; lo <= i < j < hi ==> a[i] <= a[j];
    ensures \forall integer i; lo <= i < hi ==>
                (\exists integer j; lo <= j < hi && a[i] == \old(a[j]));
    ensures \forall integer j; lo <= j < hi ==>
                (\exists integer i; lo <= i < hi && a[i] == \old(a[j]));
*/
void merge(int *a, int a_len, int *aux, int aux_len, int lo, int mid, int hi) {
    if (mid >= a_len) return;
    if (hi > a_len) hi = a_len;
    int i = lo, j = mid;
    /*@
        loop invariant lo <= i <= mid;
        loop invariant mid <= j <= hi;
        loop invariant lo <= k <= hi;
        loop invariant \forall integer t; lo <= t < k ==> 
            (\exists integer p; lo <= p < hi && aux[t] == \old(a[p]));
        loop assigns i, j, k, aux[lo .. hi-1];
    */
    for (int k = lo; k < hi; k++) {
        if (i == mid) aux[k] = a[j++];
        else if (j == hi) aux[k] = a[i++];
        else if (a[j] < a[i]) aux[k] = a[j++];
        else aux[k] = a[i++];
    }
    for (int k = lo; k < hi; k++) a[k] = aux[k];
}

/*@
    requires \valid(a + (0 .. a_len-1));
    requires 0 <= a_len;
    assigns a[0 .. a_len-1];
    ensures \forall integer i,j; 0 <= i < j < a_len ==> a[i] <= a[j];
    ensures \forall integer i; 0 <= i < a_len ==>
                (\exists integer j; 0 <= j < a_len && a[i] == \old(a[j]));
*/
void iterativeMergesort(int *a, int a_len) {
    int *aux = (int *)malloc(sizeof(int) * a_len);
    for (int blockSize = 1; blockSize < a_len; blockSize *= 2)
        for (int start = 0; start < a_len; start += 2 * blockSize)
            merge(a, a_len, aux, a_len, start, start + blockSize, start + 2 * blockSize);
}

/*@
    requires \valid(from + (0 .. from_len-1));
    requires \valid(to + (0 .. to_len-1));
    requires 0 <= lo <= hi;
    requires from_len >= lo;
    requires to_len >= hi;
    assigns to[lo .. hi-1];
    ensures \forall integer k; 0 <= k < lo || hi <= k < to_len ==> to[k] == \old(to[k]);
    ensures \forall integer i,j; lo <= i < j < hi ==> to[i] <= to[j];
    ensures \forall integer i; lo <= i < hi ==>
                (\exists integer j; lo <= j < hi && to[i] == \old(from[j]));
    ensures \forall integer j; lo <= j < hi ==>
                (\exists integer i; lo <= i < hi && to[i] == \old(from[j]));
*/
void mergeWithoutCopy(int *from, int from_len, int *to, int to_len, int lo, int mid, int hi) {
    if (mid > from_len) mid = from_len;
    if (hi > from_len) hi = from_len;
    int i = lo, j = mid;
    /*@
        loop invariant lo <= i <= mid;
        loop invariant mid <= j <= hi;
        loop invariant lo <= k <= hi;
        loop invariant \forall integer t; lo <= t < k ==> 
            (\exists integer p; lo <= p < hi && to[t] == \old(from[p]));
        loop assigns i, j, k, to[lo .. hi-1];
    */
    for (int k = lo; k < hi; k++) {
        if (i == mid) to[k] = from[j++];
        else if (j == hi) to[k] = from[i++];
        else if (from[j] < from[i]) to[k] = from[j++];
        else to[k] = from[i++];
    }
}

/*@
    requires \valid(a + (0 .. a_len-1));
    requires \valid(aux + (0 .. aux_len-1));
    requires 0 <= lo <= hi <= a_len;
    requires aux_len >= a_len;
    assigns a[lo .. hi-1], aux[lo .. hi-1];
    ensures \forall integer k; 0 <= k < lo || hi <= k < a_len ==> a[k] == \old(a[k]);
    ensures \forall integer i,j; lo <= i < j < hi ==> a[i] <= a[j];
    ensures \forall integer i; lo <= i < hi ==>
                (\exists integer j; lo <= j < hi && a[i] == \old(a[j]));
    ensures \forall integer j; lo <= j < hi ==>
                (\exists integer i; lo <= i < hi && a[i] == \old(a[j]));
*/
void recursiveMergesort(int *a, int a_len, int *aux, int aux_len, int lo, int hi) {
    if (hi - lo <= 1) return;
    int mid = lo + (hi - lo) / 2;
    recursiveMergesort(a, a_len, aux, aux_len, lo, mid);
    recursiveMergesort(a, a_len, aux, aux_len, mid, hi);
    merge(a, a_len, aux, aux_len, lo, mid, hi);
}

/*@
    requires \valid(a + (0 .. a_len-1));
    requires 0 <= a_len;
    assigns a[0 .. a_len-1];
    ensures \forall integer i,j; 0 <= i < j < a_len ==> a[i] <= a[j];
    ensures \forall integer i; 0 <= i < a_len ==>
                (\exists integer j; 0 <= j < a_len && a[i] == \old(a[j]));
*/
void recursiveMergesort_2(int *a, int a_len) {
    int *aux = (int *)malloc(sizeof(int) * a_len);
    recursiveMergesort(a, a_len, aux, a_len, 0, a_len);
}
