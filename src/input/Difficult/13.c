#include <stdlib.h>

void merge(int *a, int a_len, int *aux, int aux_len, int lo, int mid, int hi);
void iterativeMergesort(int *a, int a_len);
void iterativeMergesortWithoutCopy(int *a, int a_len);
void mergeWithoutCopy(int *from, int from_len, int *to, int to_len, int lo, int mid, int hi);
void recursiveMergesort(int *a, int a_len, int *aux, int aux_len, int lo, int hi);
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
