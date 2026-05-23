#include <limits.h>

/*@ logic integer max_prefix(int *args, integer lo, integer hi) =
    lo >= hi ? args[lo] :
    (max_prefix(args, lo, hi - 1) > args[hi - 1] ? max_prefix(args, lo, hi - 1) : args[hi - 1]); */

/*@ requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  assigns \nothing;
  ensures args_len == \old(args_len);
  ensures args == \old(args); */
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

/*@ requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  assigns \nothing;
  ensures args_len == \old(args_len);
  ensures args == \old(args); */
int check_B_implies_A(int * args, int args_len) {
    return stub_B(args, args_len);
}
