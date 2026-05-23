#include <limits.h>
#include <stdlib.h>

/*@ logic integer rec(integer n) =
      n == 0 ? 0 :
      n == 1 ? 1 :
      (2 * rec(n - 1) + rec(n - 2)) % 1000000000; */

/*@ requires (count >= 2) && (p[0] == 0) && (p[1] == 1) && (\forall integer k; 2 <= k < count ==> p[k] == (2 * p[k - 1] + p[k - 2]) % 1000000000);
    assigns \nothing;
*/
void check_A_implies_B(int count, int i, int k, int *p, int p_len, int seed) {
    /*@ assert (p_len == seed + 1); */
    /*@ assert (p[1] == 1); */
    /*@ assert (p[0] == 0); */
    /*@ assert (p[0] == 0 && p[1] == 1); */
    /*@ assert (\forall integer k; 2 <= k < count ==> p[k] == (2 * p[k - 1] + p[k - 2]) % 1000000000); */
    /*@ assert (\forall integer k; 2 <= k < count ==> p[k] == ((2 * p[k - 1] + p[k - 2]) % 1000000000)); */
    /*@ assert (\forall integer k; 2 <= k < count ==> 0 <= p[k] < 1000000000); */
    /*@ assert (\forall integer k; 0 <= k < count ==> p[k] >= 0); */
    /*@ assert (\forall integer k; 0 <= k < count ==> p[k] == p[k]); */
    /*@ assert (\forall integer k; 0 <= k < count ==> p[k] < 1000000000); */
    /*@ assert (\forall integer k; 0 <= k < count ==> 0 <= p[k] < 1000000000); */
    /*@ assert (\forall integer k; 0 <= k < count && k >= 2 ==> p[k] == (2 * p[k - 1] + p[k - 2]) % 1000000000); */
    /*@ assert (\forall integer k; 0 <= k < count && k < 2 ==> (k == 0 ==> p[k] == 0) && (k == 1 ==> p[k] == 1)); */
    /*@ assert (\forall integer k; 0 <= k < 2 ==> (k == 0 ==> p[k] == 0) && (k == 1 ==> p[k] == 1)); */
    /*@ assert (\forall integer i; 2 <= i < count ==> p[i] == (2 * p[i - 1] + p[i - 2]) % 1000000000); */
    /*@ assert (\forall integer i; 2 <= i < count ==> p[i] == ((2 * p[i-1] + p[i-2]) % 1000000000)); */
    /*@ assert (\forall integer i; 2 <= i < count ==> p[i] == ((2 * p[i - 1] + p[i - 2]) % 1000000000)); */
    /*@ assert (\forall integer i; 2 <= i < count ==> 0 <= p[i] < 1000000000); */
    /*@ assert (\forall integer i; 0 <= i < count ==> p[i] >= 0); */
    /*@ assert (\forall integer i; 0 <= i < count ==> p[i] == p[i]); */
    /*@ assert (\forall integer i; 0 <= i < count ==> p[i] < 1000000000); */
    /*@ assert (\forall integer i; 0 <= i < count ==> 0 <= p[i] < 1000000000); */
    /*@ assert (\forall integer i; 0 <= i < count && i < 2 ==> (i == 0 ==> p[i] == 0) && (i == 1 ==> p[i] == 1)); */
    /*@ assert (\forall integer i; 0 <= i < 2 ==> (i == 0 ==> p[i] == 0) && (i == 1 ==> p[i] == 1)); */
    /*@ assert (2 <= count); */
}

/*@ requires (p_len == seed + 1) && (p[1] == 1) && (p[0] == 0) && (p[0] == 0 && p[1] == 1) && (\forall integer k; 2 <= k < count ==> p[k] == (2 * p[k - 1] + p[k - 2]) % 1000000000) && (\forall integer k; 2 <= k < count ==> p[k] == ((2 * p[k - 1] + p[k - 2]) % 1000000000)) && (\forall integer k; 2 <= k < count ==> 0 <= p[k] < 1000000000) && (\forall integer k; 0 <= k < count ==> p[k] >= 0) && (\forall integer k; 0 <= k < count ==> p[k] == p[k]) && (\forall integer k; 0 <= k < count ==> p[k] < 1000000000) && (\forall integer k; 0 <= k < count ==> 0 <= p[k] < 1000000000) && (\forall integer k; 0 <= k < count && k >= 2 ==> p[k] == (2 * p[k - 1] + p[k - 2]) % 1000000000) && (\forall integer k; 0 <= k < count && k < 2 ==> (k == 0 ==> p[k] == 0) && (k == 1 ==> p[k] == 1)) && (\forall integer k; 0 <= k < 2 ==> (k == 0 ==> p[k] == 0) && (k == 1 ==> p[k] == 1)) && (\forall integer i; 2 <= i < count ==> p[i] == (2 * p[i - 1] + p[i - 2]) % 1000000000) && (\forall integer i; 2 <= i < count ==> p[i] == ((2 * p[i-1] + p[i-2]) % 1000000000)) && (\forall integer i; 2 <= i < count ==> p[i] == ((2 * p[i - 1] + p[i - 2]) % 1000000000)) && (\forall integer i; 2 <= i < count ==> 0 <= p[i] < 1000000000) && (\forall integer i; 0 <= i < count ==> p[i] >= 0) && (\forall integer i; 0 <= i < count ==> p[i] == p[i]) && (\forall integer i; 0 <= i < count ==> p[i] < 1000000000) && (\forall integer i; 0 <= i < count ==> 0 <= p[i] < 1000000000) && (\forall integer i; 0 <= i < count && i < 2 ==> (i == 0 ==> p[i] == 0) && (i == 1 ==> p[i] == 1)) && (\forall integer i; 0 <= i < 2 ==> (i == 0 ==> p[i] == 0) && (i == 1 ==> p[i] == 1)) && (2 <= count);
    assigns \nothing;
*/
void check_B_implies_A(int count, int i, int k, int *p, int p_len, int seed) {
    /*@ assert (count >= 2); */
    /*@ assert (p[0] == 0); */
    /*@ assert (p[1] == 1); */
    /*@ assert (\forall integer k; 2 <= k < count ==> p[k] == (2 * p[k - 1] + p[k - 2]) % 1000000000); */
}
