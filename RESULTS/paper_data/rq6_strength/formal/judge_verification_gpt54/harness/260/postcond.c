#include <limits.h>

/*@ requires array >= 0;
  requires \valid_read(args + (0 .. array - 1));
  requires \forall integer k; 0 <= k < array - 1 ==> args[k] < args[k + 1];
  assigns \nothing;
  ensures \result == -1 || (0 <= \result < array && args[\result] == \result);
  ensures \result != -1 ==> 0 <= \result < array;
  ensures \result != -1 ==> args[\result] == \result; */
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

/*@ requires array >= 0;
  requires \valid_read(args + (0 .. array - 1));
  requires \forall integer k; 0 <= k < array - 1 ==> args[k] < args[k + 1];
  assigns \nothing;
  ensures \result == -1 || (0 <= \result < array && args[\result] == \result);
  ensures \result != -1 ==> 0 <= \result < array;
  ensures \result != -1 ==> args[\result] == \result; */
int check_B_implies_A(int * args, int args_len, int array) {
    return stub_B(args, args_len, array);
}
