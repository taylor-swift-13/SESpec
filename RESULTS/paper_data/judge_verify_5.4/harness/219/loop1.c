#include <limits.h>

/*@ requires (n == \at(n,Pre)) && (array == \at(array,Pre)) && (args_len == \at(args_len,Pre)) && (args == \at(args,Pre)) && (\forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre)) && ((result != -1) ==> args[result] == array) && ((ret <= hi) ==> (0 <= ret <= hi + 1)) && ((ret == 0) || (ret > 0)) && ((hi == n - 1) || (hi < n - 1)) && ((0 <= n - 1) ==> (((result == -1)&&(hi == \at(n,Pre) - 1)&&(ret == 0)&&(n == \at(n,Pre))&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || ((result != -1) ==> args[result] == array))) && ((0 <= n - 1) ==> (0 <= ret <= hi + 1));
    assigns \nothing;
*/
void check_A_implies_B(int *args, int args_len, int array, int hi, int k, int n, int ret) {
    /*@ assert (result == -1 || result <= hi || result >= ret); */
    /*@ assert (result == -1 || array <= args[result]); */
    /*@ assert (result == -1 || args[result] <= array); */
    /*@ assert (ret == 0 || ret > 0); */
    /*@ assert (result == -1 || ret <= result); */
    /*@ assert (result == -1 || ret <= result + 1); */
    /*@ assert (result == -1 || ret <= n); */
    /*@ assert (result == -1 || result >= ret - 1); */
    /*@ assert (result == -1 || result < ret || result > hi); */
    /*@ assert (result == -1 || hi < result); */
    /*@ assert (result == -1 || hi < result || result <= hi); */
    /*@ assert (result == -1 || hi < n); */
    /*@ assert (result == -1 || args[result] == array); */
    /*@ assert (result == -1 || \exists integer k; 0 <= k < n && args[k] == array); */
    /*@ assert (result == -1 || \exists integer k; 0 <= k < n && args[k] == array && result == k); */
    /*@ assert (result == -1 || 0 <= result < n); */
    /*@ assert (result == -1 || 0 <= result && result < n); */
    /*@ assert (result == -1 || (\exists integer k; ret <= k <= hi ==> args[k] == array)); */
    /*@ assert (result == -1 || (\exists integer k; 0 <= k < n && args[k] == array)); */
    /*@ assert (result == -1 || (\exists integer k; 0 <= k < n && args[k] == array && result == k)); */
    /*@ assert (result == -1 || (0 <= result < n)); */
    /*@ assert (result == -1 || (0 <= result < n && args[result] == array)); */
    /*@ assert (result == -1 || (0 <= result && result < n)); */
    /*@ assert (result != -1 ==> ret <= result); */
    /*@ assert (result != -1 ==> ret <= result <= n - 1); */
    /*@ assert (result != -1 ==> ret <= result + 1); */
    /*@ assert (result != -1 ==> hi < result); */
    /*@ assert (result != -1 ==> args[result] == array); */
    /*@ assert (result != -1 ==> \exists integer k; 0 <= k < n && args[k] == array); */
    /*@ assert (result != -1 ==> \exists integer k; 0 <= k < n && args[k] == array && result == k); */
    /*@ assert (result != -1 ==> 0 <= ret); */
    /*@ assert (result != -1 ==> 0 <= result < n); */
    /*@ assert (result != -1 ==> 0 <= result < n && args[result] == array); */
    /*@ assert (hi <= n-1); */
    /*@ assert (hi <= n - 1); */
    /*@ assert (hi < n); */
    /*@ assert (0 <= ret); */
    /*@ assert (0 <= ret || ret == 0); */
    /*@ assert (-1 <= ret); */
    /*@ assert (-1 <= result); */
    /*@ assert (-1 <= result < n || result == -1); */
}

/*@ requires (result == -1 || result <= hi || result >= ret) && (result == -1 || array <= args[result]) && (result == -1 || args[result] <= array) && (ret == 0 || ret > 0) && (result == -1 || ret <= result) && (result == -1 || ret <= result + 1) && (result == -1 || ret <= n) && (result == -1 || result >= ret - 1) && (result == -1 || result < ret || result > hi) && (result == -1 || hi < result) && (result == -1 || hi < result || result <= hi) && (result == -1 || hi < n) && (result == -1 || args[result] == array) && (result == -1 || \exists integer k; 0 <= k < n && args[k] == array) && (result == -1 || \exists integer k; 0 <= k < n && args[k] == array && result == k) && (result == -1 || 0 <= result < n) && (result == -1 || 0 <= result && result < n) && (result == -1 || (\exists integer k; ret <= k <= hi ==> args[k] == array)) && (result == -1 || (\exists integer k; 0 <= k < n && args[k] == array)) && (result == -1 || (\exists integer k; 0 <= k < n && args[k] == array && result == k)) && (result == -1 || (0 <= result < n)) && (result == -1 || (0 <= result < n && args[result] == array)) && (result == -1 || (0 <= result && result < n)) && (result != -1 ==> ret <= result) && (result != -1 ==> ret <= result <= n - 1) && (result != -1 ==> ret <= result + 1) && (result != -1 ==> hi < result) && (result != -1 ==> args[result] == array) && (result != -1 ==> \exists integer k; 0 <= k < n && args[k] == array) && (result != -1 ==> \exists integer k; 0 <= k < n && args[k] == array && result == k) && (result != -1 ==> 0 <= ret) && (result != -1 ==> 0 <= result < n) && (result != -1 ==> 0 <= result < n && args[result] == array) && (hi <= n-1) && (hi <= n - 1) && (hi < n) && (0 <= ret) && (0 <= ret || ret == 0) && (-1 <= ret) && (-1 <= result) && (-1 <= result < n || result == -1);
    assigns \nothing;
*/
void check_B_implies_A(int *args, int args_len, int array, int hi, int k, int n, int ret) {
    /*@ assert (n == \at(n,Pre)); */
    /*@ assert (array == \at(array,Pre)); */
    /*@ assert (args_len == \at(args_len,Pre)); */
    /*@ assert (args == \at(args,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre)); */
    /*@ assert ((result != -1) ==> args[result] == array); */
    /*@ assert ((ret <= hi) ==> (0 <= ret <= hi + 1)); */
    /*@ assert ((ret == 0) || (ret > 0)); */
    /*@ assert ((hi == n - 1) || (hi < n - 1)); */
    /*@ assert ((0 <= n - 1) ==> (((result == -1)&&(hi == \at(n,Pre) - 1)&&(ret == 0)&&(n == \at(n,Pre))&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || ((result != -1) ==> args[result] == array))); */
    /*@ assert ((0 <= n - 1) ==> (0 <= ret <= hi + 1)); */
}
