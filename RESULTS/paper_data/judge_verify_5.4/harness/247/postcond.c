#include <limits.h>

/*@ logic integer count_gt(int* a, integer x, integer lo, integer hi) =
      lo >= hi ? 0 :
      count_gt(a, x, lo, hi - 1) + (a[hi - 1] > x ? 1 : 0); */
/*@ logic integer invcount_upto(int* a, integer i, integer n) =
      i >= n ? 0 :
      count_gt(a, a[i], i + 1, n) + invcount_upto(a, i + 1, n); */

/*@ requires \valid(&indices[0] + (0..indices_len-1));
  requires 0 <= num <= indices_len;
  requires \forall integer i; 0 <= i < indices_len ==> 0 <= indices[i] <= 100;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result >= 0;
  ensures \result >= 0; */
int stub_A(int * indices, int indices_len, int num);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * indices, int indices_len, int num);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * indices, int indices_len, int num) {
    return stub_A(indices, indices_len, num);
}

/*@ requires \valid(&indices[0] + (0..indices_len-1));
  requires 0 <= num <= indices_len;
  requires \forall integer i; 0 <= i < indices_len ==> 0 <= indices[i] <= 100;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result >= 0;
  ensures \result >= 0; */
int check_B_implies_A(int * indices, int indices_len, int num) {
    return stub_B(indices, indices_len, num);
}
