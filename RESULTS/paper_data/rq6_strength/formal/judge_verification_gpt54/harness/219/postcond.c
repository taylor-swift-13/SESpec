#include <limits.h>

/*@ requires 0 <= args_len;
  requires 0 <= n <= args_len;
  requires \valid(args + (0 .. args_len - 1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires \forall integer i, j; 0 <= i < j < n ==> args[i] <= args[j];
  assigns \nothing;
  ensures \result == -1 || \result != -1;
  ensures \result != -1 ==> args[\result] == array;
  ensures \result == -1 ==> \forall integer i; 0 <= i < n ==> args[i] == args[i];
  ensures \result == -1 ==> \result == -1; */
int stub_A(int * args, int args_len, int array, int n);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * args, int args_len, int array, int n);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * args, int args_len, int array, int n) {
    return stub_A(args, args_len, array, n);
}

/*@ requires 0 <= args_len;
  requires 0 <= n <= args_len;
  requires \valid(args + (0 .. args_len - 1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires \forall integer i, j; 0 <= i < j < n ==> args[i] <= args[j];
  assigns \nothing;
  ensures \result == -1 || \result != -1;
  ensures \result != -1 ==> args[\result] == array;
  ensures \result == -1 ==> \forall integer i; 0 <= i < n ==> args[i] == args[i];
  ensures \result == -1 ==> \result == -1; */
int check_B_implies_A(int * args, int args_len, int array, int n) {
    return stub_B(args, args_len, array, n);
}
