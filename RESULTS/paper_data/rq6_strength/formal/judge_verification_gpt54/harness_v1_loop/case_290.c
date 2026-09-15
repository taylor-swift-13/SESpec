#include <limits.h>
#include <stdlib.h>

/*@logic integer recN(int* N, integer i) =
      i <= 0 ? 2 :
      i == 1 ? 1 :
      recN(N, i - 1) + 2 * recN(N, i - 2);*/

/*@ requires (2 <= p) && (N[0] == 2) && (N[1] == 1) && (\forall integer k);
    assigns \nothing;
*/
void check_A_implies_B(int *N, int N_len, int c, int i, int k, int *p) {
    /*@ assert (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer i) && (\forall integer i) && (\forall integer i) && (\forall integer i) && (\forall integer i) && (\forall integer i) && (\forall integer i) && (\forall integer i) && (N_len == c + 1) && (N[1] == 1) && (N[0] == 2) && (N[0] == 2 && N[1] == 1) && (2 <= p) && (0 <= p) && (0 <= p - 2) && (0 < N[p - 2]) && (0 < N[p - 1]); */
}

/*@ requires (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer i) && (\forall integer i) && (\forall integer i) && (\forall integer i) && (\forall integer i) && (\forall integer i) && (\forall integer i) && (\forall integer i) && (N_len == c + 1) && (N[1] == 1) && (N[0] == 2) && (N[0] == 2 && N[1] == 1) && (2 <= p) && (0 <= p) && (0 <= p - 2) && (0 < N[p - 2]) && (0 < N[p - 1]);
    assigns \nothing;
*/
void check_B_implies_A(int *N, int N_len, int c, int i, int k, int *p) {
    /*@ assert (2 <= p) && (N[0] == 2) && (N[1] == 1) && (\forall integer k); */
}
