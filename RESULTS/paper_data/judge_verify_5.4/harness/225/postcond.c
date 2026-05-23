#include <limits.h>

/*@ requires args_len > 0;
  requires 0 <= array <= args_len;
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  assigns \nothing;
  ensures array <= 1 ==> \result == 1;
  ensures array > 1 ==> 1 <= \result;
  ensures array > 1 ==> \forall integer k; 1 <= k < \result ==> args[k - 1] == k;
  ensures array > 1 && \result < array ==> args[\result - 1] != \result;
  ensures array > 1 && \result == array ==> \forall integer k; 1 <= k < array ==> args[k - 1] == k;
  ensures \result == 1 || array > 1; */
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

/*@ requires args_len > 0;
  requires 0 <= array <= args_len;
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  assigns \nothing;
  ensures array <= 1 ==> \result == 1;
  ensures array > 1 ==> 1 <= \result;
  ensures array > 1 ==> \forall integer k; 1 <= k < \result ==> args[k - 1] == k;
  ensures array > 1 && \result < array ==> args[\result - 1] != \result;
  ensures array > 1 && \result == array ==> \forall integer k; 1 <= k < array ==> args[k - 1] == k;
  ensures \result == 1 || array > 1; */
int check_B_implies_A(int * args, int args_len, int array) {
    return stub_B(args, args_len, array);
}
