#include <limits.h>


/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

  logic integer copy_count(int* src, int* dst, integer lo, integer hi) =
             : copy_count(src, dst, lo, hi - 1) + (dst[hi - 1] == src[hi - 1] ? 1 : 0);

/*@requires \valid(&b[0] + (0..b_len-1));
  requires \forall integer i; 0 <= i < b_len ==> 0 <= b[i] <= 100;
  requires b_len > 0;
  requires b_len < 100;
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  requires 0 <= iBegin <= iEnd <= a_len;
  requires iEnd <= b_len;
  assigns a[iBegin..iEnd-1];
  ensures \forall integer j; 0 <= j < a_len ==> (j < iBegin || j >= iEnd) ==> a[j] == \old(a[j]);*/
void stub_A(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len);

/*@loop invariant \forall integer u; 0 <= u < iBegin || k <= u < a_len ==> a[u] == a[u];
        loop invariant k == iBegin || k > iBegin;
        loop invariant k == iBegin + (k - iBegin);
        loop invariant k - iBegin == 0 || k - iBegin > 0;
        loop invariant iBegin <= k;
        loop invariant \forall integer u; k <= u < iEnd ==> a[u] == a[u];
        loop invariant \forall integer u; iEnd <= u < a_len ==> a[u] == a[u];
        loop invariant \forall integer u; iBegin <= u < iEnd ==> (u < k ==> a[u] == b[u]) || (u >= k ==> a[u] == a[u]);
        loop invariant \forall integer u; 0 <= u < iBegin || iEnd <= u < b_len ==> a[u] == a[u];
        loop invariant \forall integer u; 0 <= u < iBegin || iEnd <= u < a_len ==> a[u] == a[u];
        loop invariant \forall integer u; 0 <= u < iBegin ==> a[u] == a[u];
        loop invariant \forall integer u; 0 <= u < b_len ==> (u < k ==> a[u] == b[u]) || (u >= k ==> a[u] == a[u]);
        loop invariant \forall integer u; 0 <= u < b_len ==> (u < iBegin || u >= k ==> a[u] == a[u]);
        loop invariant \forall integer t; k <= t < iEnd ==> a[t] == a[t];
        loop invariant \forall integer t; iEnd <= t < a_len ==> a[t] == a[t];
        loop invariant \forall integer t; iBegin <= t < iEnd ==> (t < k ==> a[t] == b[t]) || (t >= k ==> a[t] == a[t]);
        loop invariant \forall integer t; 0 <= t < iBegin || iEnd <= t < a_len ==> a[t] == a[t];
        loop invariant \forall integer t; 0 <= t < iBegin ==> a[t] == a[t];
        loop invariant \forall integer t; 0 <= t < b_len ==> (t < iBegin || t >= k ==> a[t] == a[t]);
        loop invariant \forall integer j; k <= j < iEnd ==> a[j] == a[j];
        loop invariant \forall integer j; 0 <= j < iBegin ==> a[j] == a[j];
        loop invariant 0 <= k - iBegin;
        loop assigns k;
        loop assigns a[iBegin..iEnd-1];*/
void stub_B(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len);

/*@loop invariant \forall integer u; 0 <= u < iBegin || k <= u < a_len ==> a[u] == a[u];
        loop invariant k == iBegin || k > iBegin;
        loop invariant k == iBegin + (k - iBegin);
        loop invariant k - iBegin == 0 || k - iBegin > 0;
        loop invariant iBegin <= k;
        loop invariant \forall integer u; k <= u < iEnd ==> a[u] == a[u];
        loop invariant \forall integer u; iEnd <= u < a_len ==> a[u] == a[u];
        loop invariant \forall integer u; iBegin <= u < iEnd ==> (u < k ==> a[u] == b[u]) || (u >= k ==> a[u] == a[u]);
        loop invariant \forall integer u; 0 <= u < iBegin || iEnd <= u < b_len ==> a[u] == a[u];
        loop invariant \forall integer u; 0 <= u < iBegin || iEnd <= u < a_len ==> a[u] == a[u];
        loop invariant \forall integer u; 0 <= u < iBegin ==> a[u] == a[u];
        loop invariant \forall integer u; 0 <= u < b_len ==> (u < k ==> a[u] == b[u]) || (u >= k ==> a[u] == a[u]);
        loop invariant \forall integer u; 0 <= u < b_len ==> (u < iBegin || u >= k ==> a[u] == a[u]);
        loop invariant \forall integer t; k <= t < iEnd ==> a[t] == a[t];
        loop invariant \forall integer t; iEnd <= t < a_len ==> a[t] == a[t];
        loop invariant \forall integer t; iBegin <= t < iEnd ==> (t < k ==> a[t] == b[t]) || (t >= k ==> a[t] == a[t]);
        loop invariant \forall integer t; 0 <= t < iBegin || iEnd <= t < a_len ==> a[t] == a[t];
        loop invariant \forall integer t; 0 <= t < iBegin ==> a[t] == a[t];
        loop invariant \forall integer t; 0 <= t < b_len ==> (t < iBegin || t >= k ==> a[t] == a[t]);
        loop invariant \forall integer j; k <= j < iEnd ==> a[j] == a[j];
        loop invariant \forall integer j; 0 <= j < iBegin ==> a[j] == a[j];
        loop invariant 0 <= k - iBegin;
        loop assigns k;
        loop assigns a[iBegin..iEnd-1];*/
void check_A_implies_B(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len) {
    stub_A(b, b_len, iBegin, iEnd, a, a_len);
}

/*@requires \valid(&b[0] + (0..b_len-1));
  requires \forall integer i; 0 <= i < b_len ==> 0 <= b[i] <= 100;
  requires b_len > 0;
  requires b_len < 100;
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  requires 0 <= iBegin <= iEnd <= a_len;
  requires iEnd <= b_len;
  assigns a[iBegin..iEnd-1];
  ensures \forall integer j; 0 <= j < a_len ==> (j < iBegin || j >= iEnd) ==> a[j] == \old(a[j]);*/
void check_B_implies_A(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len) {
    stub_B(b, b_len, iBegin, iEnd, a, a_len);
}
