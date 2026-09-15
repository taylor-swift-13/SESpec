#include <stdlib.h>

void foo28_helper4_c6(int *a, int a_len, int *aux, int aux_len, int lo, int mid, int hi);
void foo28_helper1_c6(int *a, int a_len);
void foo28_helper2_c6(int *a, int a_len);
void foo28_helper3_c6(int *from, int from_len, int *to, int to_len, int lo, int mid, int hi);
void foo28_helper5_c6(int *a, int a_len, int *aux, int aux_len, int lo, int hi);
void foo6(int *a, int a_len);

生成响应失败: Connection error.
#include <stdlib.h>

void foo28_helper4_c6(int *a, int a_len, int *aux, int aux_len, int lo, int mid, int hi);
void foo28_helper1_c6(int *a, int a_len);
void foo28_helper2_c6(int *a, int a_len);
void foo28_helper3_c6(int *from, int from_len, int *to, int to_len, int lo, int mid, int hi);
void foo28_helper5_c6(int *a, int a_len, int *aux, int aux_len, int lo, int hi);
void foo6(int *a, int a_len);

生成响应失败: Connection error.


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