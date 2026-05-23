#include <limits.h>

/*@ logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0); */
/*@ logic integer copy_count(int* src, int* dst, integer lo, integer hi) =
    lo >= hi ? 0
             : copy_count(src, dst, lo, hi - 1) + (dst[hi - 1] == src[hi - 1] ? 1 : 0); */

/*@ requires \valid(&b[0] + (0..b_len-1));
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
  ensures \forall integer j; 0 <= j < a_len ==> (j < iBegin || j >= iEnd) ==> a[j] == \old(a[j]); */
void stub_A(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
void stub_B(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
void check_A_implies_B(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len) {
    stub_A(b, b_len, iBegin, iEnd, a, a_len);
}

/*@ requires \valid(&b[0] + (0..b_len-1));
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
  ensures \forall integer j; 0 <= j < a_len ==> (j < iBegin || j >= iEnd) ==> a[j] == \old(a[j]); */
void check_B_implies_A(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len) {
    stub_B(b, b_len, iBegin, iEnd, a, a_len);
}
