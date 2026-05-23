#include <stdlib.h>

/*@ predicate sorted_range{L}(int *a, integer lo, integer hi) =
      \forall integer i,j; lo <= i <= j < hi ==> a[i] <= a[j];

    predicate permut_range{L1,L2}(int *a, integer lo, integer hi) =
      \forall integer v;
        (\numof integer k; lo <= k < hi && a[k] == v) ==
        (\numof integer k; lo <= k < hi && \at(a[k],L2) == v);
*/

/*@ requires a_len >= 0;
    requires aux_len >= 0;
    requires a_len == aux_len;
    requires \valid(a + (0 .. a_len-1));
    requires \valid(aux + (0 .. aux_len-1));
    requires 0 <= lo <= mid <= hi;
    assigns a[0 .. a_len-1], aux[0 .. aux_len-1];
*/
void merge(int *a, int a_len, int *aux, int aux_len, int lo, int mid, int hi);

/*@ requires a_len >= 0;
    requires \valid(a + (0 .. a_len-1));
    assigns a[0 .. a_len-1];
*/
void iterativeMergesort(int *a, int a_len);

/*@ requires a_len >= 0;
    requires \valid(a + (0 .. a_len-1));
    assigns a[0 .. a_len-1];
*/
void iterativeMergesortWithoutCopy(int *a, int a_len);

/*@ requires from_len >= 0;
    requires to_len >= 0;
    requires from_len == to_len;
    requires \valid(from + (0 .. from_len-1));
    requires \valid(to + (0 .. to_len-1));
    requires 0 <= lo <= mid <= hi;
    assigns to[0 .. to_len-1];
*/
void mergeWithoutCopy(int *from, int from_len, int *to, int to_len, int lo, int mid, int hi);

/*@ requires a_len >= 0;
    requires aux_len >= 0;
    requires a_len == aux_len;
    requires \valid(a + (0 .. a_len-1));
    requires \valid(aux + (0 .. aux_len-1));
    requires 0 <= lo <= hi <= a_len;
    assigns a[0 .. a_len-1], aux[0 .. aux_len-1];
*/
void recursiveMergesort(int *a, int a_len, int *aux, int aux_len, int lo, int hi);

/*@ requires a_len >= 0;
    requires \valid(a + (0 .. a_len-1));
    assigns a[0 .. a_len-1];
*/
void recursiveMergesort_2(int *a, int a_len);

void iterativeMergesort(int *a, int a_len) {
    int *aux = (int *)malloc(sizeof(int) * a_len);
    /*@ 
        loop invariant 1 <= blockSize;
        loop invariant blockSize <= (a_len == 0 ? 1 : a_len);
        loop assigns blockSize, aux, a[0 .. a_len-1], aux[0 .. a_len-1];
        loop variant (a_len <= blockSize) ? 0 : (a_len - blockSize);
    */
    for (int blockSize = 1; blockSize < a_len; blockSize *= 2)
        /*@
            loop invariant 0 <= start <= a_len;
            loop assigns start, a[0 .. a_len-1], aux[0 .. a_len-1];
            loop variant a_len - start;
        */
        for (int start = 0; start < a_len; start += 2 * blockSize)
            merge(a, a_len, aux, a_len, start, start + blockSize, start + 2 * blockSize);
}

void iterativeMergesortWithoutCopy(int *a, int a_len) {
    int *from = a;
    int from_len = a_len;
    int *to = (int *)malloc(sizeof(int) * a_len);
    int to_len = a_len;
    /*@
        loop invariant 1 <= blockSize;
        loop invariant blockSize <= (a_len == 0 ? 1 : a_len);
        loop invariant from_len == a_len && to_len == a_len;
        loop assigns blockSize, from, to, from_len, to_len, a[0 .. a_len-1], to[0 .. a_len-1];
        loop variant (a_len <= blockSize) ? 0 : (a_len - blockSize);
    */
    for (int blockSize = 1; blockSize < a_len; blockSize *= 2) {
        /*@
            loop invariant 0 <= start <= a_len;
            loop assigns start, to[0 .. a_len-1];
            loop variant a_len - start;
        */
        for (int start = 0; start < a_len; start += 2 * blockSize)
            mergeWithoutCopy(from, from_len, to, to_len, start, start + blockSize, start + 2 * blockSize);
        int *temp = from; from = to; to = temp;
    }
    if (a != from) /*@
        loop invariant 0 <= k <= a_len;
        loop assigns k, a[0 .. a_len-1];
        loop variant a_len - k;
    */
    for (int k = 0; k < a_len; k++) a[k] = from[k];
}

void mergeWithoutCopy(int *from, int from_len, int *to, int to_len, int lo, int mid, int hi) {
    if (mid > from_len) mid = from_len;
    if (hi > from_len) hi = from_len;
    int i = lo, j = mid;
    /*@
        loop invariant lo <= k <= hi;
        loop invariant lo <= i <= mid;
        loop invariant mid <= j <= hi;
        loop assigns k, i, j, to[0 .. to_len-1];
        loop variant hi - k;
    */
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
    /*@
        loop invariant lo <= k <= hi;
        loop invariant lo <= i <= mid;
        loop invariant mid <= j <= hi;
        loop assigns k, i, j, aux[0 .. aux_len-1];
        loop variant hi - k;
    */
    for (int k = lo; k < hi; k++) {
        if (i == mid) aux[k] = a[j++];
        else if (j == hi) aux[k] = a[i++];
        else if (a[j] < a[i]) aux[k] = a[j++];
        else aux[k] = a[i++];
    }
    /*@
        loop invariant lo <= k <= hi;
        loop assigns k, a[0 .. a_len-1];
        loop variant hi - k;
    */
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
