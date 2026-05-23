#include <limits.h>


/*@ predicate sorted_int_array;(int *a, integer n) =
      \forall integer i, j; 0 <= i <= j < n ==> a[i] <= a[j];
*/

/*@requires n >= 0;
    requires n <= args_len;
    requires \valid(args + (0 .. args_len - 1));
    requires sorted_int_array(args, n);
    assigns \nothing;
    ensures -1 <= \result < n;
    ensures \result >= 0 ==> args[\result] == Array;
    ensures \result == -1 ==> \true;
    ensures \result != -1 ==> \exists integer k; 0 <= k < n && args[k] == Array && \result == k;
    ensures \result == -1 ==> \true;
    ensures \result == -1 ==> \true;*/
int stub_A(int * args, int args_len, int Array, int n);

/*@loop invariant result != -1 ==> result >= i - 1;
		loop invariant result == -1 || result >= i;
		loop invariant result == -1 || result >= i - 1;
		loop invariant result == -1 || result >= 0;
		loop invariant result == -1 || result <= hi || result >= i;
		loop invariant result == -1 || result <= hi || i <= result;
		loop invariant result == -1 || result <= hi + 1 || result >= i - 1;
		loop invariant result == -1 || result < n;
		loop invariant result == -1 || result < i || result > hi;
		loop invariant result == -1 || result < i || hi < result;
		loop invariant result == -1 || i <= result;
		loop invariant result == -1 || i <= result || result <= hi;
		loop invariant result == -1 || i <= result <= n - 1;
		loop invariant result == -1 || i <= result + 1;
		loop invariant result == -1 || i - 1 <= result;
		loop invariant result == -1 || hi < result;
		loop invariant result == -1 || hi < result || result < i;
		loop invariant result == -1 || args[result] == Array;
		loop invariant result == -1 || 0 <= result < n;
		loop invariant result == -1 || (result >= 0 && result < n);
		loop invariant result == -1 || (i <= result <= n-1);
		loop invariant result == -1 || (i <= result <= n - 1);
		loop invariant result == -1 || (args[result] == Array && 0 <= result < n);
		loop invariant result == -1 || (0 <= result < n);
		loop invariant result == -1 || (0 <= result < n && args[result] == Array);
		loop invariant result != -1 ==> result < n;
		loop invariant result != -1 ==> result < i || result > hi;
		loop invariant result != -1 ==> i <= result;
		loop invariant result != -1 ==> i <= result <= n - 1;
		loop invariant result != -1 ==> hi < result;
		loop invariant result != -1 ==> hi < result || result < i;
		loop invariant result != -1 ==> args[result] == Array;
		loop invariant result != -1 ==> args[result] == Array && result < n;
		loop invariant result != -1 ==> args[result] == Array && 0 <= result < n;
		loop invariant result != -1 ==> 0 <= result < n;
		loop invariant hi < n;
		loop invariant 0 <= i;
		loop invariant -1 <= result;
		loop invariant -1 <= result < n || result == -1;
		loop invariant (result == -1) || (args[result] == Array);
		loop invariant (result == -1) || (0 <= result < n);
		loop assigns result;
		loop assigns i;
		loop assigns hi;*/
int stub_B(int * args, int args_len, int Array, int n);

/*@loop invariant result != -1 ==> result >= i - 1;
		loop invariant result == -1 || result >= i;
		loop invariant result == -1 || result >= i - 1;
		loop invariant result == -1 || result >= 0;
		loop invariant result == -1 || result <= hi || result >= i;
		loop invariant result == -1 || result <= hi || i <= result;
		loop invariant result == -1 || result <= hi + 1 || result >= i - 1;
		loop invariant result == -1 || result < n;
		loop invariant result == -1 || result < i || result > hi;
		loop invariant result == -1 || result < i || hi < result;
		loop invariant result == -1 || i <= result;
		loop invariant result == -1 || i <= result || result <= hi;
		loop invariant result == -1 || i <= result <= n - 1;
		loop invariant result == -1 || i <= result + 1;
		loop invariant result == -1 || i - 1 <= result;
		loop invariant result == -1 || hi < result;
		loop invariant result == -1 || hi < result || result < i;
		loop invariant result == -1 || args[result] == Array;
		loop invariant result == -1 || 0 <= result < n;
		loop invariant result == -1 || (result >= 0 && result < n);
		loop invariant result == -1 || (i <= result <= n-1);
		loop invariant result == -1 || (i <= result <= n - 1);
		loop invariant result == -1 || (args[result] == Array && 0 <= result < n);
		loop invariant result == -1 || (0 <= result < n);
		loop invariant result == -1 || (0 <= result < n && args[result] == Array);
		loop invariant result != -1 ==> result < n;
		loop invariant result != -1 ==> result < i || result > hi;
		loop invariant result != -1 ==> i <= result;
		loop invariant result != -1 ==> i <= result <= n - 1;
		loop invariant result != -1 ==> hi < result;
		loop invariant result != -1 ==> hi < result || result < i;
		loop invariant result != -1 ==> args[result] == Array;
		loop invariant result != -1 ==> args[result] == Array && result < n;
		loop invariant result != -1 ==> args[result] == Array && 0 <= result < n;
		loop invariant result != -1 ==> 0 <= result < n;
		loop invariant hi < n;
		loop invariant 0 <= i;
		loop invariant -1 <= result;
		loop invariant -1 <= result < n || result == -1;
		loop invariant (result == -1) || (args[result] == Array);
		loop invariant (result == -1) || (0 <= result < n);
		loop assigns result;
		loop assigns i;
		loop assigns hi;*/
int check_A_implies_B(int * args, int args_len, int Array, int n) {
    return stub_A(args, args_len, Array, n);
}

/*@requires n >= 0;
    requires n <= args_len;
    requires \valid(args + (0 .. args_len - 1));
    requires sorted_int_array(args, n);
    assigns \nothing;
    ensures -1 <= \result < n;
    ensures \result >= 0 ==> args[\result] == Array;
    ensures \result == -1 ==> \true;
    ensures \result != -1 ==> \exists integer k; 0 <= k < n && args[k] == Array && \result == k;
    ensures \result == -1 ==> \true;
    ensures \result == -1 ==> \true;*/
int check_B_implies_A(int * args, int args_len, int Array, int n) {
    return stub_B(args, args_len, Array, n);
}
