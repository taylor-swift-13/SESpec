#include <limits.h>
#include <stdlib.h>

/*@ logic integer fib295(integer n) =
      n <= 0 ? 2 :
      n == 1 ? 1 :
      fib295(n - 1) + fib295(n - 2); */

/*@ requires (2 <= l <= num + 1) && (result[0] == fib295(0)) && (result[1] == fib295(1)) && (l >= 2 ==> result[l - 1] == fib295(l - 1)) && (l >= 3 ==> result[l - 2] == fib295(l - 2));
    assigns \nothing;
*/
void check_A_implies_B(int k, int l, int num, int result_len) {
    /*@ assert (result_len == num + 1); */
    /*@ assert (result[1] == 1); */
    /*@ assert (result[0] == 2); */
    /*@ assert (result[0] == 2 && result[1] == 1); */
    /*@ assert (l == 2 ==> result[0] == 2 && result[1] == 1); */
    /*@ assert (\forall integer k; 2 <= k < l ==> result[k] >= result[k-2]); */
    /*@ assert (\forall integer k; 2 <= k < l ==> result[k] >= result[k-1]); */
    /*@ assert (\forall integer k; 2 <= k < l ==> result[k] >= result[k - 2]); */
    /*@ assert (\forall integer k; 2 <= k < l ==> result[k] >= result[k - 1]); */
    /*@ assert (\forall integer k; 2 <= k < l ==> result[k] >= 1); */
    /*@ assert (\forall integer k; 2 <= k < l ==> result[k] > result[k-2]); */
    /*@ assert (\forall integer k; 2 <= k < l ==> result[k] > result[k-1]); */
    /*@ assert (\forall integer k; 2 <= k < l ==> result[k] > result[k - 2]); */
    /*@ assert (\forall integer k; 2 <= k < l ==> result[k] > result[k - 1]); */
    /*@ assert (\forall integer k; 2 <= k < l ==> result[k] > 0); */
    /*@ assert (\forall integer k; 2 <= k < l ==> result[k] == result[k-1] + result[k-2]); */
    /*@ assert (\forall integer k; 2 <= k < l ==> result[k] == result[k - 1] + result[k - 2]); */
    /*@ assert (\forall integer k; 0 <= k < l ==> result[k] >= 1); */
    /*@ assert (\forall integer k; 0 <= k < l ==> result[k] >= 0); */
    /*@ assert (\forall integer k; 0 <= k < l ==> result[k] > 0); */
    /*@ assert (\forall integer k; 0 <= k < l ==> (k == 0 ==> result[k] == 2) && (k == 1 ==> result[k] == 1)); */
    /*@ assert (\forall integer k; 0 <= k < l ==> (k < 2 ==> ((k == 0 ==> result[k] == 2) && (k == 1 ==> result[k] == 1)))); */
    /*@ assert (\forall integer k; 0 <= k < l && k >= 2 ==> result[k] > 0); */
    /*@ assert (\forall integer k; 0 <= k < l && k >= 2 ==> result[k] == result[k-1] + result[k-2]); */
    /*@ assert (\forall integer k; 0 <= k < l && k >= 2 ==> result[k] == result[k - 1] + result[k - 2]); */
    /*@ assert (\forall integer k; 0 <= k < l && k <= num ==> result[k] >= 1); */
    /*@ assert (\forall integer k; 0 <= k < l && k <= num ==> result[k] >= 0); */
    /*@ assert (\forall integer k; 0 <= k < l && k <= num ==> result[k] > 0); */
    /*@ assert (\forall integer k; 0 <= k < l && k < result_len ==> result[k] >= 1); */
    /*@ assert (\forall integer k; 0 <= k < l && k < result_len ==> result[k] >= 0); */
    /*@ assert (\forall integer k; 0 <= k < l && k < result_len ==> result[k] > 0); */
    /*@ assert (\forall integer k; 0 <= k < l && k < 2 ==> (k == 0 ==> result[k] == 2) && (k == 1 ==> result[k] == 1)); */
    /*@ assert (\forall integer k; 0 <= k < l && k < 2 ==> ((k == 0 ==> result[k] == 2) && (k == 1 ==> result[k] == 1))); */
    /*@ assert (2 <= l); */
}

/*@ requires (result_len == num + 1) && (result[1] == 1) && (result[0] == 2) && (result[0] == 2 && result[1] == 1) && (l == 2 ==> result[0] == 2 && result[1] == 1) && (\forall integer k; 2 <= k < l ==> result[k] >= result[k-2]) && (\forall integer k; 2 <= k < l ==> result[k] >= result[k-1]) && (\forall integer k; 2 <= k < l ==> result[k] >= result[k - 2]) && (\forall integer k; 2 <= k < l ==> result[k] >= result[k - 1]) && (\forall integer k; 2 <= k < l ==> result[k] >= 1) && (\forall integer k; 2 <= k < l ==> result[k] > result[k-2]) && (\forall integer k; 2 <= k < l ==> result[k] > result[k-1]) && (\forall integer k; 2 <= k < l ==> result[k] > result[k - 2]) && (\forall integer k; 2 <= k < l ==> result[k] > result[k - 1]) && (\forall integer k; 2 <= k < l ==> result[k] > 0) && (\forall integer k; 2 <= k < l ==> result[k] == result[k-1] + result[k-2]) && (\forall integer k; 2 <= k < l ==> result[k] == result[k - 1] + result[k - 2]) && (\forall integer k; 0 <= k < l ==> result[k] >= 1) && (\forall integer k; 0 <= k < l ==> result[k] >= 0) && (\forall integer k; 0 <= k < l ==> result[k] > 0) && (\forall integer k; 0 <= k < l ==> (k == 0 ==> result[k] == 2) && (k == 1 ==> result[k] == 1)) && (\forall integer k; 0 <= k < l ==> (k < 2 ==> ((k == 0 ==> result[k] == 2) && (k == 1 ==> result[k] == 1)))) && (\forall integer k; 0 <= k < l && k >= 2 ==> result[k] > 0) && (\forall integer k; 0 <= k < l && k >= 2 ==> result[k] == result[k-1] + result[k-2]) && (\forall integer k; 0 <= k < l && k >= 2 ==> result[k] == result[k - 1] + result[k - 2]) && (\forall integer k; 0 <= k < l && k <= num ==> result[k] >= 1) && (\forall integer k; 0 <= k < l && k <= num ==> result[k] >= 0) && (\forall integer k; 0 <= k < l && k <= num ==> result[k] > 0) && (\forall integer k; 0 <= k < l && k < result_len ==> result[k] >= 1) && (\forall integer k; 0 <= k < l && k < result_len ==> result[k] >= 0) && (\forall integer k; 0 <= k < l && k < result_len ==> result[k] > 0) && (\forall integer k; 0 <= k < l && k < 2 ==> (k == 0 ==> result[k] == 2) && (k == 1 ==> result[k] == 1)) && (\forall integer k; 0 <= k < l && k < 2 ==> ((k == 0 ==> result[k] == 2) && (k == 1 ==> result[k] == 1))) && (2 <= l);
    assigns \nothing;
*/
void check_B_implies_A(int k, int l, int num, int result_len) {
    /*@ assert (2 <= l <= num + 1); */
    /*@ assert (result[0] == fib295(0)); */
    /*@ assert (result[1] == fib295(1)); */
    /*@ assert (l >= 2 ==> result[l - 1] == fib295(l - 1)); */
    /*@ assert (l >= 3 ==> result[l - 2] == fib295(l - 2)); */
}
