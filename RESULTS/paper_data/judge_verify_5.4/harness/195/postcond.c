#include <limits.h>

/*@ logic integer sum(int* a, integer lo, integer hi) =
    lo >= hi ? 0 : sum(a, lo, hi - 1) + a[hi - 1]; */

/*@ requires array >= 0;
  requires array <= 0;
  requires array == 0;
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  assigns \nothing;
  ensures \result >= 0; */
int stub_A(int * a, int a_len, int array);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * a, int a_len, int array);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * a, int a_len, int array) {
    return stub_A(a, a_len, array);
}

/*@ requires array >= 0;
  requires array <= 0;
  requires array == 0;
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  assigns \nothing;
  ensures \result >= 0; */
int check_B_implies_A(int * a, int a_len, int array) {
    return stub_B(a, a_len, array);
}
