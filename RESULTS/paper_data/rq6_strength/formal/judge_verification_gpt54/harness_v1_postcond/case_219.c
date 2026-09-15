#include <limits.h>



/*@requires 0 <= args_len;
  requires 0 <= n <= args_len;
  requires \valid(args + (0 .. args_len - 1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires \forall integer i, j; 0 <= i < j < n ==> args[i] <= args[j];
  assigns \nothing;
  ensures \result == -1 || \result != -1;
  ensures \result != -1 ==> args[\result] == array;
  ensures \result == -1 ==> \forall integer i; 0 <= i < n ==> args[i] == args[i];
  ensures \result == -1 ==> \result == -1;*/
int stub_A(int * args, int args_len, int array, int n);

/*@loop invariant result == -1 || result <= hi || result >= ret;
		loop invariant result == -1 || array <= args[result];
		loop invariant result == -1 || args[result] <= array;
		loop invariant ret == 0 || ret > 0;
		loop invariant result == -1 || ret <= result;
		loop invariant result == -1 || ret <= result + 1;
		loop invariant result == -1 || ret <= n;
		loop invariant result == -1 || result >= ret - 1;
		loop invariant result == -1 || result < ret || result > hi;
		loop invariant result == -1 || hi < result;
		loop invariant result == -1 || hi < result || result <= hi;
		loop invariant result == -1 || hi < n;
		loop invariant result == -1 || args[result] == array;
		loop invariant result == -1 || \exists integer k; 0 <= k < n && args[k] == array;
		loop invariant result == -1 || \exists integer k; 0 <= k < n && args[k] == array && result == k;
		loop invariant result == -1 || 0 <= result < n;
		loop invariant result == -1 || 0 <= result && result < n;
		loop invariant result == -1 || (\exists integer k; ret <= k <= hi ==> args[k] == array);
		loop invariant result == -1 || (\exists integer k; 0 <= k < n && args[k] == array);
		loop invariant result == -1 || (\exists integer k; 0 <= k < n && args[k] == array && result == k);
		loop invariant result == -1 || (0 <= result < n);
		loop invariant result == -1 || (0 <= result < n && args[result] == array);
		loop invariant result == -1 || (0 <= result && result < n);
		loop invariant result != -1 ==> ret <= result;
		loop invariant result != -1 ==> ret <= result <= n - 1;
		loop invariant result != -1 ==> ret <= result + 1;
		loop invariant result != -1 ==> hi < result;
		loop invariant result != -1 ==> args[result] == array;
		loop invariant result != -1 ==> \exists integer k; 0 <= k < n && args[k] == array;
		loop invariant result != -1 ==> \exists integer k; 0 <= k < n && args[k] == array && result == k;
		loop invariant result != -1 ==> 0 <= ret;
		loop invariant result != -1 ==> 0 <= result < n;
		loop invariant result != -1 ==> 0 <= result < n && args[result] == array;
		loop invariant hi <= n-1;
		loop invariant hi <= n - 1;
		loop invariant hi < n;
		loop invariant 0 <= ret;
		loop invariant 0 <= ret || ret == 0;
		loop invariant -1 <= ret;
		loop invariant -1 <= result;
		loop invariant -1 <= result < n || result == -1;
		loop assigns ret;
		loop assigns result;
		loop assigns hi;*/
int stub_B(int * args, int args_len, int array, int n);

/*@loop invariant result == -1 || result <= hi || result >= ret;
		loop invariant result == -1 || array <= args[result];
		loop invariant result == -1 || args[result] <= array;
		loop invariant ret == 0 || ret > 0;
		loop invariant result == -1 || ret <= result;
		loop invariant result == -1 || ret <= result + 1;
		loop invariant result == -1 || ret <= n;
		loop invariant result == -1 || result >= ret - 1;
		loop invariant result == -1 || result < ret || result > hi;
		loop invariant result == -1 || hi < result;
		loop invariant result == -1 || hi < result || result <= hi;
		loop invariant result == -1 || hi < n;
		loop invariant result == -1 || args[result] == array;
		loop invariant result == -1 || \exists integer k; 0 <= k < n && args[k] == array;
		loop invariant result == -1 || \exists integer k; 0 <= k < n && args[k] == array && result == k;
		loop invariant result == -1 || 0 <= result < n;
		loop invariant result == -1 || 0 <= result && result < n;
		loop invariant result == -1 || (\exists integer k; ret <= k <= hi ==> args[k] == array);
		loop invariant result == -1 || (\exists integer k; 0 <= k < n && args[k] == array);
		loop invariant result == -1 || (\exists integer k; 0 <= k < n && args[k] == array && result == k);
		loop invariant result == -1 || (0 <= result < n);
		loop invariant result == -1 || (0 <= result < n && args[result] == array);
		loop invariant result == -1 || (0 <= result && result < n);
		loop invariant result != -1 ==> ret <= result;
		loop invariant result != -1 ==> ret <= result <= n - 1;
		loop invariant result != -1 ==> ret <= result + 1;
		loop invariant result != -1 ==> hi < result;
		loop invariant result != -1 ==> args[result] == array;
		loop invariant result != -1 ==> \exists integer k; 0 <= k < n && args[k] == array;
		loop invariant result != -1 ==> \exists integer k; 0 <= k < n && args[k] == array && result == k;
		loop invariant result != -1 ==> 0 <= ret;
		loop invariant result != -1 ==> 0 <= result < n;
		loop invariant result != -1 ==> 0 <= result < n && args[result] == array;
		loop invariant hi <= n-1;
		loop invariant hi <= n - 1;
		loop invariant hi < n;
		loop invariant 0 <= ret;
		loop invariant 0 <= ret || ret == 0;
		loop invariant -1 <= ret;
		loop invariant -1 <= result;
		loop invariant -1 <= result < n || result == -1;
		loop assigns ret;
		loop assigns result;
		loop assigns hi;*/
int check_A_implies_B(int * args, int args_len, int array, int n) {
    return stub_A(args, args_len, array, n);
}

/*@requires 0 <= args_len;
  requires 0 <= n <= args_len;
  requires \valid(args + (0 .. args_len - 1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires \forall integer i, j; 0 <= i < j < n ==> args[i] <= args[j];
  assigns \nothing;
  ensures \result == -1 || \result != -1;
  ensures \result != -1 ==> args[\result] == array;
  ensures \result == -1 ==> \forall integer i; 0 <= i < n ==> args[i] == args[i];
  ensures \result == -1 ==> \result == -1;*/
int check_B_implies_A(int * args, int args_len, int array, int n) {
    return stub_B(args, args_len, array, n);
}
