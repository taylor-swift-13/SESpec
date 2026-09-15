#include <limits.h>

/*@ requires args_len >= 0;
  requires \valid_read(args + (0..args_len-1));
  requires \forall integer i, j; 0 <= i <= j < args_len ==> args[i] <= args[j];
  requires \forall integer i, j; 0 <= i < j < args_len ==> args[i] < args[j];
  assigns \nothing;
  ensures 0 <= \result <= args_len;
  ensures (\exists integer k; 0 <= k < args_len && args[k] == array) ==> 0 <= \result <= args_len;
  ensures (\forall integer k; 0 <= k < args_len ==> args[k] != array) ==> 0 <= \result <= args_len; */
int stub_A(int * args, int args_len, int array);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * args, int args_len, int array);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * args, int args_len, int array) {
    return stub_A(args, args_len, array);
}

/*@ requires args_len >= 0;
  requires \valid_read(args + (0..args_len-1));
  requires \forall integer i, j; 0 <= i <= j < args_len ==> args[i] <= args[j];
  requires \forall integer i, j; 0 <= i < j < args_len ==> args[i] < args[j];
  assigns \nothing;
  ensures 0 <= \result <= args_len;
  ensures (\exists integer k; 0 <= k < args_len && args[k] == array) ==> 0 <= \result <= args_len;
  ensures (\forall integer k; 0 <= k < args_len ==> args[k] != array) ==> 0 <= \result <= args_len; */
int check_B_implies_A(int * args, int args_len, int array) {
    return stub_B(args, args_len, array);
}
