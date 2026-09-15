#include <limits.h>

/*@ logic integer max2(integer x, integer y) = x >= y ? x : y; */
/*@ logic integer best_end(int* a, integer i) =
    i <= 0 ? 0 : max2(0, best_end(a, i - 1) + a[i - 1]); */
/*@ logic integer best_overall(int* a, integer i) =
    i <= 0 ? 0 : max2(best_overall(a, i - 1), best_end(a, i)); */

/*@ requires \valid(&a[0] + (0..a_len-1));
  requires size == 0;
  requires size <= a_len;
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  assigns \nothing;
  ensures size > 0 ==> \result <= size;
  ensures a_len == \old(a_len);
  ensures \forall integer k; 0 <= k < a_len ==> a[k] == \old(a[k]); */
int stub_A(int * a, int a_len, int size);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * a, int a_len, int size);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * a, int a_len, int size) {
    return stub_A(a, a_len, size);
}

/*@ requires \valid(&a[0] + (0..a_len-1));
  requires size == 0;
  requires size <= a_len;
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  assigns \nothing;
  ensures size > 0 ==> \result <= size;
  ensures a_len == \old(a_len);
  ensures \forall integer k; 0 <= k < a_len ==> a[k] == \old(a[k]); */
int check_B_implies_A(int * a, int a_len, int size) {
    return stub_B(a, a_len, size);
}
