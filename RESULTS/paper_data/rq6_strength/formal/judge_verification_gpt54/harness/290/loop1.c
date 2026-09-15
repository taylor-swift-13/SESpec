#include <limits.h>
#include <stdlib.h>

/*@ logic integer recN(int* N, integer i) =
      i <= 0 ? 2 :
      i == 1 ? 1 :
      recN(N, i - 1) + 2 * recN(N, i - 2); */

/*@ requires (2 <= p) && (N[0] == 2) && (N[1] == 1) && (\forall integer k; 2 <= k < p ==> N[k] == N[k - 1] + 2 * N[k - 2]);
    assigns \nothing;
*/
void check_A_implies_B(int *N, int N_len, int c, int i, int k, int p) {
    /*@ assert (\forall integer k; 2 <= k < p ==> N[k] >= N[k - 2]); */
    /*@ assert (\forall integer k; 2 <= k < p ==> N[k] >= N[k - 1]); */
    /*@ assert (\forall integer k; 2 <= k < p ==> N[k] >= 2 * N[k - 2]); */
    /*@ assert (\forall integer k; 2 <= k < p ==> N[k] > N[k - 1]); */
    /*@ assert (\forall integer k; 2 <= k < p ==> N[k] == N[k - 1] + 2 * N[k - 2]); */
    /*@ assert (\forall integer k; 0 <= k < p ==> N[k] >= 1); */
    /*@ assert (\forall integer k; 0 <= k < p ==> N[k] >= 0); */
    /*@ assert (\forall integer k; 0 <= k < p ==> N[k] > 0); */
    /*@ assert (\forall integer k; 0 <= k < p ==> N[k] == (k == 0 ? 2 : (k == 1 ? 1 : N[k]))); */
    /*@ assert (\forall integer k; 0 <= k < p ==> N[k] != 0); */
    /*@ assert (\forall integer k; 0 <= k < p ==> (k >= 2 ==> N[k] == N[k - 1] + 2 * N[k - 2])); */
    /*@ assert (\forall integer k; 0 <= k < p ==> (k == 1 ==> N[k] == 1)); */
    /*@ assert (\forall integer k; 0 <= k < p ==> (k == 0 ==> N[k] == 2)); */
    /*@ assert (\forall integer k; 0 <= k < 2 ==> N[k] == (k == 0 ? 2 : 1)); */
    /*@ assert (\forall integer i; 2 <= i < p ==> N[i] >= N[i - 2]); */
    /*@ assert (\forall integer i; 2 <= i < p ==> N[i] >= N[i - 1]); */
    /*@ assert (\forall integer i; 2 <= i < p ==> N[i] == N[i - 1] + 2 * N[i - 2]); */
    /*@ assert (\forall integer i; 0 <= i < p ==> N[i] >= 1); */
    /*@ assert (\forall integer i; 0 <= i < p ==> N[i] >= 0); */
    /*@ assert (\forall integer i; 0 <= i < p ==> N[i] > 0); */
    /*@ assert (\forall integer i; 0 <= i < p ==> N[i] != 0); */
    /*@ assert (\forall integer i; 0 <= i < 2 ==> N[i] == (i == 0 ? 2 : 1)); */
    /*@ assert (N_len == c + 1); */
    /*@ assert (N[1] == 1); */
    /*@ assert (N[0] == 2); */
    /*@ assert (N[0] == 2 && N[1] == 1); */
    /*@ assert (2 <= p); */
    /*@ assert (0 <= p); */
    /*@ assert (0 <= p - 2); */
    /*@ assert (0 < N[p - 2]); */
    /*@ assert (0 < N[p - 1]); */
}

/*@ requires (\forall integer k; 2 <= k < p ==> N[k] >= N[k - 2]) && (\forall integer k; 2 <= k < p ==> N[k] >= N[k - 1]) && (\forall integer k; 2 <= k < p ==> N[k] >= 2 * N[k - 2]) && (\forall integer k; 2 <= k < p ==> N[k] > N[k - 1]) && (\forall integer k; 2 <= k < p ==> N[k] == N[k - 1] + 2 * N[k - 2]) && (\forall integer k; 0 <= k < p ==> N[k] >= 1) && (\forall integer k; 0 <= k < p ==> N[k] >= 0) && (\forall integer k; 0 <= k < p ==> N[k] > 0) && (\forall integer k; 0 <= k < p ==> N[k] == (k == 0 ? 2 : (k == 1 ? 1 : N[k]))) && (\forall integer k; 0 <= k < p ==> N[k] != 0) && (\forall integer k; 0 <= k < p ==> (k >= 2 ==> N[k] == N[k - 1] + 2 * N[k - 2])) && (\forall integer k; 0 <= k < p ==> (k == 1 ==> N[k] == 1)) && (\forall integer k; 0 <= k < p ==> (k == 0 ==> N[k] == 2)) && (\forall integer k; 0 <= k < 2 ==> N[k] == (k == 0 ? 2 : 1)) && (\forall integer i; 2 <= i < p ==> N[i] >= N[i - 2]) && (\forall integer i; 2 <= i < p ==> N[i] >= N[i - 1]) && (\forall integer i; 2 <= i < p ==> N[i] == N[i - 1] + 2 * N[i - 2]) && (\forall integer i; 0 <= i < p ==> N[i] >= 1) && (\forall integer i; 0 <= i < p ==> N[i] >= 0) && (\forall integer i; 0 <= i < p ==> N[i] > 0) && (\forall integer i; 0 <= i < p ==> N[i] != 0) && (\forall integer i; 0 <= i < 2 ==> N[i] == (i == 0 ? 2 : 1)) && (N_len == c + 1) && (N[1] == 1) && (N[0] == 2) && (N[0] == 2 && N[1] == 1) && (2 <= p) && (0 <= p) && (0 <= p - 2) && (0 < N[p - 2]) && (0 < N[p - 1]);
    assigns \nothing;
*/
void check_B_implies_A(int *N, int N_len, int c, int i, int k, int p) {
    /*@ assert (2 <= p); */
    /*@ assert (N[0] == 2); */
    /*@ assert (N[1] == 1); */
    /*@ assert (\forall integer k; 2 <= k < p ==> N[k] == N[k - 1] + 2 * N[k - 2]); */
}
