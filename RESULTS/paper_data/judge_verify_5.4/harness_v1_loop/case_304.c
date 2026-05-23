#include <limits.h>
#include <stdlib.h>

/*@logic integer pell_rec(integer k) =
      k <= 0 ? 0 :
      k == 1 ? 1 :
      (2 * pell_rec(k - 1) + pell_rec(k - 2)) % 1000000000;*/

/*@ requires (2 <= i <= n + 1) && (pell[i - 1] == pell_rec(i - 1)) && (pell[i - 2] == pell_rec(i - 2)) && (\forall integer k);
    assigns \nothing;
*/
void check_A_implies_B(int *i, int k, int n, int *pell, int pell_len) {
    /*@ assert (pell_len == n + 1) && (pell[1] == 1) && (pell[0] == 0) && (pell[0] == 0 && pell[1] == 1) && (i == 2 || pell[i - 1] == (2 * pell[i - 2] + pell[i - 3]) % 1000000000) && (i == 2 || pell[i - 1] == ((2 * pell[i - 2] + pell[i - 3]) % 1000000000)) && (i == 2 ==> pell[0] == 0 && pell[1] == 1) && (i == 2 ==> (pell[0] == 0 && pell[1] == 1)) && (i <= n + 1 || 0 <= i) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (2 <= i) && (1 < i) && (0 <= i) && (0 < i) && (0 < i) && (0 < i) && (0 < i) && (0 < i) && (0 < i) && (0 < i) && (0 < i) && (0 < i) && (0 < i) && (0 < i) && (0 < i); */
}

/*@ requires (pell_len == n + 1) && (pell[1] == 1) && (pell[0] == 0) && (pell[0] == 0 && pell[1] == 1) && (i == 2 || pell[i - 1] == (2 * pell[i - 2] + pell[i - 3]) % 1000000000) && (i == 2 || pell[i - 1] == ((2 * pell[i - 2] + pell[i - 3]) % 1000000000)) && (i == 2 ==> pell[0] == 0 && pell[1] == 1) && (i == 2 ==> (pell[0] == 0 && pell[1] == 1)) && (i <= n + 1 || 0 <= i) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (2 <= i) && (1 < i) && (0 <= i) && (0 < i) && (0 < i) && (0 < i) && (0 < i) && (0 < i) && (0 < i) && (0 < i) && (0 < i) && (0 < i) && (0 < i) && (0 < i) && (0 < i);
    assigns \nothing;
*/
void check_B_implies_A(int *i, int k, int n, int *pell, int pell_len) {
    /*@ assert (2 <= i <= n + 1) && (pell[i - 1] == pell_rec(i - 1)) && (pell[i - 2] == pell_rec(i - 2)) && (\forall integer k); */
}
