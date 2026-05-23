#include <limits.h>

/*@ logic integer count_odd(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : count_odd(a, lo, hi - 1) + ((a[hi - 1] % 2) != 0 ? 1 : 0); */
/*@ logic integer selected_odd(int* a, integer lo, integer hi, integer cnt) =
    lo >= hi ? 0 :
    (((a[lo] % 2) != 0) ?
      ((((cnt + 1) % 2) != 0) ? a[lo] : selected_odd(a, lo + 1, hi, cnt + 1)) :
      selected_odd(a, lo + 1, hi, cnt)); */
/*@ logic integer last_odd(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : ((a[hi - 1] % 2) != 0 ? a[hi - 1] : last_odd(a, lo, hi - 1)); */

/*@ requires \valid(&ints[0] + (0..ints_len-1));
  requires \forall integer i; 0 <= i < ints_len ==> 0 <= ints[i] <= 100;
  requires 0 <= array <= ints_len;
  assigns \nothing;
  ensures array <= 0 ==> \result == 0; */
int stub_A(int * ints, int ints_len, int array);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * ints, int ints_len, int array);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * ints, int ints_len, int array) {
    return stub_A(ints, ints_len, array);
}

/*@ requires \valid(&ints[0] + (0..ints_len-1));
  requires \forall integer i; 0 <= i < ints_len ==> 0 <= ints[i] <= 100;
  requires 0 <= array <= ints_len;
  assigns \nothing;
  ensures array <= 0 ==> \result == 0; */
int check_B_implies_A(int * ints, int ints_len, int array) {
    return stub_B(ints, ints_len, array);
}
