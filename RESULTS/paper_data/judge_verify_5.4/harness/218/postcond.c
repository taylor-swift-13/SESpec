#include <limits.h>

/*@ predicate sorted_int_array{L}(int *a, integer n) =
      \forall integer i, j; */

/*@ requires n >= 0;
    requires n <= args_len;
    requires \valid(args + (0 .. args_len - 1));
    requires sorted_int_array(args, n);
    assigns \nothing;
    ensures -1 <= \result < n;
    ensures \result >= 0 ==> args[\result] == Array;
    ensures \result == -1 ==> \true;
    ensures \result != -1 ==> \exists integer k; 0 <= k < n && args[k] == Array && \result == k;
    ensures \result == -1 ==> \true;
    ensures \result == -1 ==> \true; */
int stub_A(int * args, int args_len, int Array, int n);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * args, int args_len, int Array, int n);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * args, int args_len, int Array, int n) {
    return stub_A(args, args_len, Array, n);
}

/*@ requires n >= 0;
    requires n <= args_len;
    requires \valid(args + (0 .. args_len - 1));
    requires sorted_int_array(args, n);
    assigns \nothing;
    ensures -1 <= \result < n;
    ensures \result >= 0 ==> args[\result] == Array;
    ensures \result == -1 ==> \true;
    ensures \result != -1 ==> \exists integer k; 0 <= k < n && args[k] == Array && \result == k;
    ensures \result == -1 ==> \true;
    ensures \result == -1 ==> \true; */
int check_B_implies_A(int * args, int args_len, int Array, int n) {
    return stub_B(args, args_len, Array, n);
}
