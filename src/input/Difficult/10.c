#include <stdlib.h>

void foo28_helper1(int * a, int a_len);
void foo28_helper2(int * a, int a_len);
void foo28_helper3(int * from, int from_len, int * to, int to_len, int lo, int mid, int hi);
void foo28_helper4(int * a, int a_len, int * aux, int aux_len, int lo, int mid, int hi);
void foo28_helper5(int * a, int a_len, int * aux, int aux_len, int lo, int hi);
void foo28(int * a, int a_len);

void foo28_helper1(int * a, int a_len) {

    int *aux = (int *)malloc(sizeof(int) * (a_len));
int aux_len = a_len;
    for (int blockSize = 1; blockSize < a_len; blockSize *= 2)
      for (int start = 0; start < a_len; start += 2 * blockSize)
        foo28_helper4(a, a_len, aux, aux_len, start, start + blockSize, start + 2 * blockSize);
}

void foo28_helper2(int * a, int a_len) {

    int *from = a;
    int from_len = a_len;
    int *to = (int *)malloc(sizeof(int) * (a_len));
    int to_len = a_len;
    for (int blockSize = 1; blockSize < a_len; blockSize *= 2) {
      for (int start = 0; start < a_len; start += 2 * blockSize)
        foo28_helper3(from, from_len, to, to_len, start, start + blockSize, start + 2 * blockSize);
      int *temp = from;
      from = to;
      to = temp;
      int temp_len = from_len;
      from_len = to_len;
      to_len = temp_len;
    }
    if (a != from)

      for (int k = 0; k < a_len; k++) a[k] = from[k];
}

void foo28_helper3(int * from, int from_len, int * to, int to_len, int lo, int mid, int hi) {

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

void foo28_helper4(int * a, int a_len, int * aux, int aux_len, int lo, int mid, int hi) {

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

void foo28_helper5(int * a, int a_len, int * aux, int aux_len, int lo, int hi) {

    if (hi - lo <= 1) return;

    int mid = lo + (hi - lo) / 2;
    foo28_helper5(a, a_len, aux, aux_len, lo, mid);
    foo28_helper5(a, a_len, aux, aux_len, mid, hi);

    foo28_helper4(a, a_len, aux, aux_len, lo, mid, hi);
}

void foo28(int * a, int a_len) {

    int n = a_len;
    int *aux = (int *)malloc(sizeof(int) * (n));
int aux_len = n;
    foo28_helper5(a, a_len, aux, aux_len, 0, n);
}
