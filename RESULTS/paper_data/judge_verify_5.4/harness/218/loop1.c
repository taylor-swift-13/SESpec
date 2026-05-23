#include <limits.h>

/*@ predicate sorted_int_array{L}(int *a, integer n) =
      \forall integer i, j; */

/*@ requires (0 <= i <= n) && (-1 <= hi < n) && (i <= hi + 1) && (result == -1 || 0 <= result < n) && (result == -1 || hi < result) && (result == -1 || args[result] == Array) && (n == \at(n,Pre)) && (Array == \at(Array,Pre)) && (args_len == \at(args_len,Pre)) && (args == \at(args,Pre)) && (\forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre)) && (n == \at(n,Pre)) && (Array == \at(Array,Pre)) && (args_len == \at(args_len,Pre)) && (args == \at(args,Pre)) && (\forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre));
    assigns \nothing;
*/
void check_A_implies_B(int Array, int *args, int args_len, int hi, int i, int k, int n) {
    /*@ assert (result != -1 ==> result >= i - 1); */
    /*@ assert (result == -1 || result >= i); */
    /*@ assert (result == -1 || result >= i - 1); */
    /*@ assert (result == -1 || result >= 0); */
    /*@ assert (result == -1 || result <= hi || result >= i); */
    /*@ assert (result == -1 || result <= hi || i <= result); */
    /*@ assert (result == -1 || result <= hi + 1 || result >= i - 1); */
    /*@ assert (result == -1 || result < n); */
    /*@ assert (result == -1 || result < i || result > hi); */
    /*@ assert (result == -1 || result < i || hi < result); */
    /*@ assert (result == -1 || i <= result); */
    /*@ assert (result == -1 || i <= result || result <= hi); */
    /*@ assert (result == -1 || i <= result <= n - 1); */
    /*@ assert (result == -1 || i <= result + 1); */
    /*@ assert (result == -1 || i - 1 <= result); */
    /*@ assert (result == -1 || hi < result); */
    /*@ assert (result == -1 || hi < result || result < i); */
    /*@ assert (result == -1 || args[result] == Array); */
    /*@ assert (result == -1 || 0 <= result < n); */
    /*@ assert (result == -1 || (result >= 0 && result < n)); */
    /*@ assert (result == -1 || (i <= result <= n-1)); */
    /*@ assert (result == -1 || (i <= result <= n - 1)); */
    /*@ assert (result == -1 || (args[result] == Array && 0 <= result < n)); */
    /*@ assert (result == -1 || (0 <= result < n)); */
    /*@ assert (result == -1 || (0 <= result < n && args[result] == Array)); */
    /*@ assert (result != -1 ==> result < n); */
    /*@ assert (result != -1 ==> result < i || result > hi); */
    /*@ assert (result != -1 ==> i <= result); */
    /*@ assert (result != -1 ==> i <= result <= n - 1); */
    /*@ assert (result != -1 ==> hi < result); */
    /*@ assert (result != -1 ==> hi < result || result < i); */
    /*@ assert (result != -1 ==> args[result] == Array); */
    /*@ assert (result != -1 ==> args[result] == Array && result < n); */
    /*@ assert (result != -1 ==> args[result] == Array && 0 <= result < n); */
    /*@ assert (result != -1 ==> 0 <= result < n); */
    /*@ assert (hi < n); */
    /*@ assert (0 <= i); */
    /*@ assert (-1 <= result); */
    /*@ assert (-1 <= result < n || result == -1); */
    /*@ assert ((result == -1) || (args[result] == Array)); */
    /*@ assert ((result == -1) || (0 <= result < n)); */
}

/*@ requires (result != -1 ==> result >= i - 1) && (result == -1 || result >= i) && (result == -1 || result >= i - 1) && (result == -1 || result >= 0) && (result == -1 || result <= hi || result >= i) && (result == -1 || result <= hi || i <= result) && (result == -1 || result <= hi + 1 || result >= i - 1) && (result == -1 || result < n) && (result == -1 || result < i || result > hi) && (result == -1 || result < i || hi < result) && (result == -1 || i <= result) && (result == -1 || i <= result || result <= hi) && (result == -1 || i <= result <= n - 1) && (result == -1 || i <= result + 1) && (result == -1 || i - 1 <= result) && (result == -1 || hi < result) && (result == -1 || hi < result || result < i) && (result == -1 || args[result] == Array) && (result == -1 || 0 <= result < n) && (result == -1 || (result >= 0 && result < n)) && (result == -1 || (i <= result <= n-1)) && (result == -1 || (i <= result <= n - 1)) && (result == -1 || (args[result] == Array && 0 <= result < n)) && (result == -1 || (0 <= result < n)) && (result == -1 || (0 <= result < n && args[result] == Array)) && (result != -1 ==> result < n) && (result != -1 ==> result < i || result > hi) && (result != -1 ==> i <= result) && (result != -1 ==> i <= result <= n - 1) && (result != -1 ==> hi < result) && (result != -1 ==> hi < result || result < i) && (result != -1 ==> args[result] == Array) && (result != -1 ==> args[result] == Array && result < n) && (result != -1 ==> args[result] == Array && 0 <= result < n) && (result != -1 ==> 0 <= result < n) && (hi < n) && (0 <= i) && (-1 <= result) && (-1 <= result < n || result == -1) && ((result == -1) || (args[result] == Array)) && ((result == -1) || (0 <= result < n));
    assigns \nothing;
*/
void check_B_implies_A(int Array, int *args, int args_len, int hi, int i, int k, int n) {
    /*@ assert (0 <= i <= n); */
    /*@ assert (-1 <= hi < n); */
    /*@ assert (i <= hi + 1); */
    /*@ assert (result == -1 || 0 <= result < n); */
    /*@ assert (result == -1 || hi < result); */
    /*@ assert (result == -1 || args[result] == Array); */
    /*@ assert (n == \at(n,Pre)); */
    /*@ assert (Array == \at(Array,Pre)); */
    /*@ assert (args_len == \at(args_len,Pre)); */
    /*@ assert (args == \at(args,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre)); */
    /*@ assert (n == \at(n,Pre)); */
    /*@ assert (Array == \at(Array,Pre)); */
    /*@ assert (args_len == \at(args_len,Pre)); */
    /*@ assert (args == \at(args,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre)); */
}
