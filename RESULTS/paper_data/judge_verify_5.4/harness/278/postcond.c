#include <limits.h>

/*@ logic integer min_prefix(int *a, integer lo, integer hi) =
    lo + 1 >= hi ? a[lo]
                 : (a[hi - 1] < min_prefix(a, lo, hi - 1) ? a[hi - 1] : min_prefix(a, lo, hi - 1)); */

/*@ requires args_len >= 1;
  requires \valid_read(args + (0 .. args_len - 1));
  assigns \nothing;
  ensures \forall integer k; 0 <= k < args_len ==> args[k] == \old(args[k]);
  ensures \result >= 0;
  ensures args_len <= 1 ==> \result >= 0;
  ensures args_len > 1 && (\forall integer j; 1 <= j < args_len ==> args[j] <= \at(args[j - 1], Pre)) ==> \result >= 0;
  ensures \result >= 0;
  ensures \result >= 0; */
int stub_A(int * args, int args_len);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * args, int args_len);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * args, int args_len) {
    return stub_A(args, args_len);
}

/*@ requires args_len >= 1;
  requires \valid_read(args + (0 .. args_len - 1));
  assigns \nothing;
  ensures \forall integer k; 0 <= k < args_len ==> args[k] == \old(args[k]);
  ensures \result >= 0;
  ensures args_len <= 1 ==> \result >= 0;
  ensures args_len > 1 && (\forall integer j; 1 <= j < args_len ==> args[j] <= \at(args[j - 1], Pre)) ==> \result >= 0;
  ensures \result >= 0;
  ensures \result >= 0; */
int check_B_implies_A(int * args, int args_len) {
    return stub_B(args, args_len);
}
