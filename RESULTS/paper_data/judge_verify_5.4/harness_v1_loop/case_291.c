#include <limits.h>
#include <stdlib.h>

/*@ requires (2 <= p <= c + 1) && (j_len == c + 1) && (j[0] == 2) && (j[1] == 1) && (\forall integer k) && (j[p - 1] >= 1) && (j[p - 2] >= 1) && (\exists integer k);
    assigns \nothing;
*/
void check_A_implies_B(int c, int *j, int j_len, int k, int *p) {
    /*@ assert (p == 2 || j[p - 1] > 0) && (\forall integer k) && (p == 2 || \forall integer k) && (j_len == c + 1) && (j[1] == 1) && (j[0] == 2) && (j[0] == 2 && j[1] == 1) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (2 <= p) && (0 <= p); */
}

/*@ requires (p == 2 || j[p - 1] > 0) && (\forall integer k) && (p == 2 || \forall integer k) && (j_len == c + 1) && (j[1] == 1) && (j[0] == 2) && (j[0] == 2 && j[1] == 1) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (2 <= p) && (0 <= p);
    assigns \nothing;
*/
void check_B_implies_A(int c, int *j, int j_len, int k, int *p) {
    /*@ assert (2 <= p <= c + 1) && (j_len == c + 1) && (j[0] == 2) && (j[1] == 1) && (\forall integer k) && (j[p - 1] >= 1) && (j[p - 2] >= 1) && (\exists integer k); */
}
