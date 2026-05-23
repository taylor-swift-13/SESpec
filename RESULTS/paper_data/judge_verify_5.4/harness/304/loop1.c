#include <limits.h>
#include <stdlib.h>

/*@ logic integer pell_rec(integer k) =
      k <= 0 ? 0 :
      k == 1 ? 1 :
      (2 * pell_rec(k - 1) + pell_rec(k - 2)) % 1000000000; */

/*@ requires (2 <= i <= n + 1) && (pell[i - 1] == pell_rec(i - 1)) && (pell[i - 2] == pell_rec(i - 2)) && (\forall integer k; 0 <= k < i ==> pell[k] == pell_rec(k));
    assigns \nothing;
*/
void check_A_implies_B(int i, int k, int n, int *pell, int pell_len) {
    /*@ assert (pell_len == n + 1); */
    /*@ assert (pell[1] == 1); */
    /*@ assert (pell[0] == 0); */
    /*@ assert (pell[0] == 0 && pell[1] == 1); */
    /*@ assert (i == 2 || pell[i - 1] == (2 * pell[i - 2] + pell[i - 3]) % 1000000000); */
    /*@ assert (i == 2 || pell[i - 1] == ((2 * pell[i - 2] + pell[i - 3]) % 1000000000)); */
    /*@ assert (i == 2 ==> pell[0] == 0 && pell[1] == 1); */
    /*@ assert (i == 2 ==> (pell[0] == 0 && pell[1] == 1)); */
    /*@ assert (i <= n + 1 || 0 <= i); */
    /*@ assert (\forall integer k; 2 <= k < i ==> pell[k] >= 0); */
    /*@ assert (\forall integer k; 2 <= k < i ==> pell[k] == (2 * pell[k - 1] + pell[k - 2]) % 1000000000); */
    /*@ assert (\forall integer k; 2 <= k < i ==> pell[k] == ((2 * pell[k - 1] + pell[k - 2]) % 1000000000)); */
    /*@ assert (\forall integer k; 0 <= k < i ==> pell[k] >= 0); */
    /*@ assert (\forall integer k; 0 <= k < i ==> pell[k] == 0 || pell[k] > 0); */
    /*@ assert (\forall integer k; 0 <= k < i ==> pell[k] < 1000000000); */
    /*@ assert (\forall integer k; 0 <= k < i ==> 0 <= pell[k] < 1000000000); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k == 1 ==> pell[k] == 1)); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k == 0 ==> pell[k] == 0)); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k == 0 ==> pell[k] == 0) && (k == 1 ==> pell[k] == 1)); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k < 2 || pell[k] >= 0)); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k < 2 || pell[k] == ((2 * pell[k - 1] + pell[k - 2]) % 1000000000))); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k < 2 || pell[k] < 1000000000)); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k < 2 || 0 <= pell[k] < 1000000000)); */
    /*@ assert (\forall integer k; 0 <= k < i ==> (k < 2 || (0 <= pell[k] < 1000000000))); */
    /*@ assert (2 <= i); */
    /*@ assert (1 < i); */
    /*@ assert (0 <= i); */
    /*@ assert (0 < i); */
    /*@ assert (0 < i); */
    /*@ assert (0 < i); */
    /*@ assert (0 < i); */
    /*@ assert (0 < i); */
    /*@ assert (0 < i); */
    /*@ assert (0 < i); */
    /*@ assert (0 < i); */
    /*@ assert (0 < i); */
    /*@ assert (0 < i); */
    /*@ assert (0 < i); */
    /*@ assert (0 < i); */
}

/*@ requires (pell_len == n + 1) && (pell[1] == 1) && (pell[0] == 0) && (pell[0] == 0 && pell[1] == 1) && (i == 2 || pell[i - 1] == (2 * pell[i - 2] + pell[i - 3]) % 1000000000) && (i == 2 || pell[i - 1] == ((2 * pell[i - 2] + pell[i - 3]) % 1000000000)) && (i == 2 ==> pell[0] == 0 && pell[1] == 1) && (i == 2 ==> (pell[0] == 0 && pell[1] == 1)) && (i <= n + 1 || 0 <= i) && (\forall integer k; 2 <= k < i ==> pell[k] >= 0) && (\forall integer k; 2 <= k < i ==> pell[k] == (2 * pell[k - 1] + pell[k - 2]) % 1000000000) && (\forall integer k; 2 <= k < i ==> pell[k] == ((2 * pell[k - 1] + pell[k - 2]) % 1000000000)) && (\forall integer k; 0 <= k < i ==> pell[k] >= 0) && (\forall integer k; 0 <= k < i ==> pell[k] == 0 || pell[k] > 0) && (\forall integer k; 0 <= k < i ==> pell[k] < 1000000000) && (\forall integer k; 0 <= k < i ==> 0 <= pell[k] < 1000000000) && (\forall integer k; 0 <= k < i ==> (k == 1 ==> pell[k] == 1)) && (\forall integer k; 0 <= k < i ==> (k == 0 ==> pell[k] == 0)) && (\forall integer k; 0 <= k < i ==> (k == 0 ==> pell[k] == 0) && (k == 1 ==> pell[k] == 1)) && (\forall integer k; 0 <= k < i ==> (k < 2 || pell[k] >= 0)) && (\forall integer k; 0 <= k < i ==> (k < 2 || pell[k] == ((2 * pell[k - 1] + pell[k - 2]) % 1000000000))) && (\forall integer k; 0 <= k < i ==> (k < 2 || pell[k] < 1000000000)) && (\forall integer k; 0 <= k < i ==> (k < 2 || 0 <= pell[k] < 1000000000)) && (\forall integer k; 0 <= k < i ==> (k < 2 || (0 <= pell[k] < 1000000000))) && (2 <= i) && (1 < i) && (0 <= i) && (0 < i) && (0 < i) && (0 < i) && (0 < i) && (0 < i) && (0 < i) && (0 < i) && (0 < i) && (0 < i) && (0 < i) && (0 < i) && (0 < i);
    assigns \nothing;
*/
void check_B_implies_A(int i, int k, int n, int *pell, int pell_len) {
    /*@ assert (2 <= i <= n + 1); */
    /*@ assert (pell[i - 1] == pell_rec(i - 1)); */
    /*@ assert (pell[i - 2] == pell_rec(i - 2)); */
    /*@ assert (\forall integer k; 0 <= k < i ==> pell[k] == pell_rec(k)); */
}
