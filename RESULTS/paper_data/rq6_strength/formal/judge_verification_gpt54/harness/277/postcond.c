#include <limits.h>

/*@ logic integer minp(int* a, integer lo, integer hi) =
    hi <= lo ? 0 :
    (hi == lo + 1 ? a[lo] :
     (minp(a, lo, hi - 1) <= a[hi - 1] ? minp(a, lo, hi - 1) : a[hi - 1])); */

/*@ requires arg_len >= 1;
  requires \valid_read(arg + (0 .. arg_len - 1));
  assigns \nothing;
  ensures \result >= 0;
  ensures arg_len == 1 ==> \result >= 0;
  ensures arg_len > 1 ==> \result >= 0;
  ensures \forall integer k; 0 <= k < arg_len ==> arg[k] == \at(arg[k], Pre);
  ensures \result == 0 ==> arg_len >= 1; */
int stub_A(int * arg, int arg_len);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * arg, int arg_len);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * arg, int arg_len) {
    return stub_A(arg, arg_len);
}

/*@ requires arg_len >= 1;
  requires \valid_read(arg + (0 .. arg_len - 1));
  assigns \nothing;
  ensures \result >= 0;
  ensures arg_len == 1 ==> \result >= 0;
  ensures arg_len > 1 ==> \result >= 0;
  ensures \forall integer k; 0 <= k < arg_len ==> arg[k] == \at(arg[k], Pre);
  ensures \result == 0 ==> arg_len >= 1; */
int check_B_implies_A(int * arg, int arg_len) {
    return stub_B(arg, arg_len);
}
