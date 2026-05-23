#include <limits.h>
#include <stdlib.h>

/*@ logic integer fib(integer n) =
      n <= 1 ? n : fib(n - 1) + fib(n - 2); */

/*@ requires (2 <= l) && (result[0] == 2) && (result[1] == 1);
    assigns \nothing;
*/
void check_A_implies_B(int k, int l, int result_len, int seed) {
    /*@ assert (result_len == seed + 1); */
    /*@ assert (result[1] == 1); */
    /*@ assert (result[0] == 2); */
    /*@ assert (result[0] == 2 && result[1] == 1); */
    /*@ assert (\forall integer k; 2 <= k < l ==> result[k] >= result[k-2]); */
    /*@ assert (\forall integer k; 2 <= k < l ==> result[k] >= result[k-1]); */
    /*@ assert (\forall integer k; 2 <= k < l ==> result[k] >= result[k-1] || result[k] >= result[k-2]); */
    /*@ assert (\forall integer k; 2 <= k < l ==> result[k] >= result[k - 2]); */
    /*@ assert (\forall integer k; 2 <= k < l ==> result[k] >= result[k - 2] && result[k] >= result[k - 1]); */
    /*@ assert (\forall integer k; 2 <= k < l ==> result[k] >= result[k - 1]); */
    /*@ assert (\forall integer k; 2 <= k < l ==> result[k] >= result[k - 1] || result[k] >= result[k - 2]); */
    /*@ assert (\forall integer k; 2 <= k < l ==> result[k] >= result[k - 1] && result[k] >= result[k - 2]); */
    /*@ assert (\forall integer k; 2 <= k < l ==> result[k] >= 2); */
    /*@ assert (\forall integer k; 2 <= k < l ==> result[k] >= 1); */
    /*@ assert (\forall integer k; 2 <= k < l ==> result[k] > result[k-2]); */
    /*@ assert (\forall integer k; 2 <= k < l ==> result[k] > result[k-1]); */
    /*@ assert (\forall integer k; 2 <= k < l ==> result[k] > 0); */
    /*@ assert (\forall integer k; 2 <= k < l ==> result[k] == result[k-1] + result[k-2]); */
    /*@ assert (\forall integer k; 2 <= k < l ==> result[k] == result[k - 1] + result[k - 2]); */
    /*@ assert (\forall integer k; 0 <= k < l ==> result[k] >= 1); */
    /*@ assert (\forall integer k; 0 <= k < l ==> result[k] >= 0); */
    /*@ assert (\forall integer k; 0 <= k < l ==> result[k] > 0); */
    /*@ assert (\forall integer k; 0 <= k < l ==> (k >= 2 ==> result[k] >= result[k - 2])); */
    /*@ assert (\forall integer k; 0 <= k < l ==> (k >= 2 ==> result[k] > 0)); */
    /*@ assert (\forall integer k; 0 <= k < l ==> (k >= 2 ==> result[k] == result[k - 1] + result[k - 2])); */
    /*@ assert (\forall integer k; 0 <= k < l ==> (k == 1 ==> result[k] == 1)); */
    /*@ assert (\forall integer k; 0 <= k < l ==> (k == 0 ? result[k] == 2 : (k == 1 ? result[k] == 1 : result[k] > result[k-1]))); */
    /*@ assert (\forall integer k; 0 <= k < l ==> (k == 0 ? result[k] == 2 : (k == 1 ? result[k] == 1 : result[k] > 0))); */
    /*@ assert (\forall integer k; 0 <= k < l ==> (k == 0 ? result[k] == 2 : (k == 1 ? result[k] == 1 : result[k] == result[k-1] + result[k-2]))); */
    /*@ assert (\forall integer k; 0 <= k < l ==> (k == 0 ? result[k] == 2 : (k == 1 ? result[k] == 1 : result[k] == result[k - 1] + result[k - 2]))); */
    /*@ assert (\forall integer k; 0 <= k < l ==> (k == 0 ==> result[k] == 2)); */
    /*@ assert (\forall integer k; 0 <= k < l ==> (k < 2 || result[k] >= result[k-2])); */
    /*@ assert (\forall integer k; 0 <= k < l ==> (k < 2 || result[k] >= result[k-1])); */
    /*@ assert (\forall integer k; 0 <= k < l ==> (k < 2 || result[k] >= result[k - 2])); */
    /*@ assert (\forall integer k; 0 <= k < l ==> (k < 2 || result[k] >= result[k - 1])); */
    /*@ assert (\forall integer k; 0 <= k < l ==> (k < 2 || result[k] >= 1)); */
    /*@ assert (\forall integer k; 0 <= k < l ==> (k < 2 || result[k] > 0)); */
    /*@ assert (\forall integer k; 0 <= k < l ==> (k < 2 || result[k] == result[k - 1] + result[k - 2])); */
    /*@ assert (\forall integer k; 0 <= k < l && k >= 2 ==> result[k] == result[k - 1] + result[k - 2]); */
    /*@ assert (\forall integer k; 0 <= k < l && k < result_len ==> result[k] >= result[k - 1] || k < 2); */
    /*@ assert (\forall integer k; 0 <= k < l && k < result_len ==> result[k] >= 1); */
    /*@ assert (\forall integer k; 0 <= k < l && k < result_len ==> result[k] > 0); */
    /*@ assert (\forall integer k; 0 <= k < l && k < result_len ==> result[k] == (k == 0 ? 2 : (k == 1 ? 1 : result[k-1] + result[k-2]))); */
    /*@ assert (\forall integer k; 0 <= k < l && k < result_len ==> (k == 0 ? result[k] == 2 : (k == 1 ? result[k] == 1 : result[k] == result[k-1] + result[k-2]))); */
    /*@ assert (\forall integer k; 0 <= k < l && k < result_len ==> (k < 2 || result[k] == result[k - 1] + result[k - 2])); */
    /*@ assert (\forall integer k; 0 <= k < l && k < 2 ==> result[k] == (k == 0 ? 2 : 1)); */
    /*@ assert (\forall integer k; 0 <= k < 2 ==> result[k] == (k == 0 ? 2 : 1)); */
    /*@ assert (2 <= l); */
}

/*@ requires (result_len == seed + 1) && (result[1] == 1) && (result[0] == 2) && (result[0] == 2 && result[1] == 1) && (\forall integer k; 2 <= k < l ==> result[k] >= result[k-2]) && (\forall integer k; 2 <= k < l ==> result[k] >= result[k-1]) && (\forall integer k; 2 <= k < l ==> result[k] >= result[k-1] || result[k] >= result[k-2]) && (\forall integer k; 2 <= k < l ==> result[k] >= result[k - 2]) && (\forall integer k; 2 <= k < l ==> result[k] >= result[k - 2] && result[k] >= result[k - 1]) && (\forall integer k; 2 <= k < l ==> result[k] >= result[k - 1]) && (\forall integer k; 2 <= k < l ==> result[k] >= result[k - 1] || result[k] >= result[k - 2]) && (\forall integer k; 2 <= k < l ==> result[k] >= result[k - 1] && result[k] >= result[k - 2]) && (\forall integer k; 2 <= k < l ==> result[k] >= 2) && (\forall integer k; 2 <= k < l ==> result[k] >= 1) && (\forall integer k; 2 <= k < l ==> result[k] > result[k-2]) && (\forall integer k; 2 <= k < l ==> result[k] > result[k-1]) && (\forall integer k; 2 <= k < l ==> result[k] > 0) && (\forall integer k; 2 <= k < l ==> result[k] == result[k-1] + result[k-2]) && (\forall integer k; 2 <= k < l ==> result[k] == result[k - 1] + result[k - 2]) && (\forall integer k; 0 <= k < l ==> result[k] >= 1) && (\forall integer k; 0 <= k < l ==> result[k] >= 0) && (\forall integer k; 0 <= k < l ==> result[k] > 0) && (\forall integer k; 0 <= k < l ==> (k >= 2 ==> result[k] >= result[k - 2])) && (\forall integer k; 0 <= k < l ==> (k >= 2 ==> result[k] > 0)) && (\forall integer k; 0 <= k < l ==> (k >= 2 ==> result[k] == result[k - 1] + result[k - 2])) && (\forall integer k; 0 <= k < l ==> (k == 1 ==> result[k] == 1)) && (\forall integer k; 0 <= k < l ==> (k == 0 ? result[k] == 2 : (k == 1 ? result[k] == 1 : result[k] > result[k-1]))) && (\forall integer k; 0 <= k < l ==> (k == 0 ? result[k] == 2 : (k == 1 ? result[k] == 1 : result[k] > 0))) && (\forall integer k; 0 <= k < l ==> (k == 0 ? result[k] == 2 : (k == 1 ? result[k] == 1 : result[k] == result[k-1] + result[k-2]))) && (\forall integer k; 0 <= k < l ==> (k == 0 ? result[k] == 2 : (k == 1 ? result[k] == 1 : result[k] == result[k - 1] + result[k - 2]))) && (\forall integer k; 0 <= k < l ==> (k == 0 ==> result[k] == 2)) && (\forall integer k; 0 <= k < l ==> (k < 2 || result[k] >= result[k-2])) && (\forall integer k; 0 <= k < l ==> (k < 2 || result[k] >= result[k-1])) && (\forall integer k; 0 <= k < l ==> (k < 2 || result[k] >= result[k - 2])) && (\forall integer k; 0 <= k < l ==> (k < 2 || result[k] >= result[k - 1])) && (\forall integer k; 0 <= k < l ==> (k < 2 || result[k] >= 1)) && (\forall integer k; 0 <= k < l ==> (k < 2 || result[k] > 0)) && (\forall integer k; 0 <= k < l ==> (k < 2 || result[k] == result[k - 1] + result[k - 2])) && (\forall integer k; 0 <= k < l && k >= 2 ==> result[k] == result[k - 1] + result[k - 2]) && (\forall integer k; 0 <= k < l && k < result_len ==> result[k] >= result[k - 1] || k < 2) && (\forall integer k; 0 <= k < l && k < result_len ==> result[k] >= 1) && (\forall integer k; 0 <= k < l && k < result_len ==> result[k] > 0) && (\forall integer k; 0 <= k < l && k < result_len ==> result[k] == (k == 0 ? 2 : (k == 1 ? 1 : result[k-1] + result[k-2]))) && (\forall integer k; 0 <= k < l && k < result_len ==> (k == 0 ? result[k] == 2 : (k == 1 ? result[k] == 1 : result[k] == result[k-1] + result[k-2]))) && (\forall integer k; 0 <= k < l && k < result_len ==> (k < 2 || result[k] == result[k - 1] + result[k - 2])) && (\forall integer k; 0 <= k < l && k < 2 ==> result[k] == (k == 0 ? 2 : 1)) && (\forall integer k; 0 <= k < 2 ==> result[k] == (k == 0 ? 2 : 1)) && (2 <= l);
    assigns \nothing;
*/
void check_B_implies_A(int k, int l, int result_len, int seed) {
    /*@ assert (2 <= l); */
    /*@ assert (result[0] == 2); */
    /*@ assert (result[1] == 1); */
}
