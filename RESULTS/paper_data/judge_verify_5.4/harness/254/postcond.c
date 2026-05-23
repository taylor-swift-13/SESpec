#include <limits.h>

/*@ logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0); */

/*@ requires \valid(&array[0] + (0..array_len-1));
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  requires array_len > 0;
  requires array_len < 100;
  requires start <= end;
  requires start >= 0;
  requires end < array_len;
  assigns \nothing;
  ensures \at(start, Pre) <= \at(end, Pre) ==> \at(start, Pre) <= \result <= \at(end, Pre) + 1;
  ensures \at(start, Pre) > \at(end, Pre) ==> \result == \at(start, Pre); */
int stub_A(int * array, int array_len, int start, int end);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * array, int array_len, int start, int end);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * array, int array_len, int start, int end) {
    return stub_A(array, array_len, start, end);
}

/*@ requires \valid(&array[0] + (0..array_len-1));
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  requires array_len > 0;
  requires array_len < 100;
  requires start <= end;
  requires start >= 0;
  requires end < array_len;
  assigns \nothing;
  ensures \at(start, Pre) <= \at(end, Pre) ==> \at(start, Pre) <= \result <= \at(end, Pre) + 1;
  ensures \at(start, Pre) > \at(end, Pre) ==> \result == \at(start, Pre); */
int check_B_implies_A(int * array, int array_len, int start, int end) {
    return stub_B(array, array_len, start, end);
}
