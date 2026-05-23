#include <limits.h>
#include <stdlib.h>

/*@ requires (2 <= p <= c + 1) && (j_len == c + 1) && (j[0] == 2) && (j[1] == 1) && (\forall integer k; 2 <= k < p ==> j[k] == j[k - 1] + 2 * j[k - 2]) && (j[p - 1] >= 1) && (j[p - 2] >= 1) && (\exists integer k; 0 <= k < p && j[k] == 1);
    assigns \nothing;
*/
void check_A_implies_B(int c, int *j, int j_len, int k, int p) {
    /*@ assert (p == 2 || j[p - 1] > 0); */
    /*@ assert (\forall integer k; 2 <= k < p ==> j[k] > j[k - 1] || j[k] > j[k - 2]); */
    /*@ assert (p == 2 || \forall integer k; 2 <= k < p ==> j[k] == j[k - 1] + 2 * j[k - 2]); */
    /*@ assert (j_len == c + 1); */
    /*@ assert (j[1] == 1); */
    /*@ assert (j[0] == 2); */
    /*@ assert (j[0] == 2 && j[1] == 1); */
    /*@ assert (\forall integer k; 2 <= k < p ==> j[k] >= j[k-2]); */
    /*@ assert (\forall integer k; 2 <= k < p ==> j[k] >= j[k-2] && j[k] >= j[k-1]); */
    /*@ assert (\forall integer k; 2 <= k < p ==> j[k] >= j[k-1]); */
    /*@ assert (\forall integer k; 2 <= k < p ==> j[k] >= j[k-1] && j[k] >= j[k-2]); */
    /*@ assert (\forall integer k; 2 <= k < p ==> j[k] >= j[k - 2]); */
    /*@ assert (\forall integer k; 2 <= k < p ==> j[k] >= j[k - 2] && j[k] >= j[k - 1]); */
    /*@ assert (\forall integer k; 2 <= k < p ==> j[k] >= j[k - 1]); */
    /*@ assert (\forall integer k; 2 <= k < p ==> j[k] >= j[k - 1] && j[k] >= j[k - 2]); */
    /*@ assert (\forall integer k; 2 <= k < p ==> j[k] > j[k - 2]); */
    /*@ assert (\forall integer k; 2 <= k < p ==> j[k] > j[k - 1]); */
    /*@ assert (\forall integer k; 2 <= k < p ==> j[k] > 0); */
    /*@ assert (\forall integer k; 2 <= k < p ==> j[k] == j[k-1] + 2 * j[k-2]); */
    /*@ assert (\forall integer k; 2 <= k < p ==> j[k] == j[k - 1] + 2 * j[k - 2]); */
    /*@ assert (\forall integer k; 0 <= k < p ==> j[k] >= 1); */
    /*@ assert (\forall integer k; 0 <= k < p ==> j[k] >= 1 || k == 1); */
    /*@ assert (\forall integer k; 0 <= k < p ==> j[k] >= 0); */
    /*@ assert (\forall integer k; 0 <= k < p ==> j[k] > 0); */
    /*@ assert (\forall integer k; 0 <= k < p ==> j[k] == 0 || j[k] >= 1); */
    /*@ assert (\forall integer k; 0 <= k < p ==> j[k] == 0 || j[k] > 0); */
    /*@ assert (\forall integer k; 0 <= k < p ==> j[k] != 0); */
    /*@ assert (\forall integer k; 0 <= k < p ==> (k == 1 ==> j[k] == 1)); */
    /*@ assert (\forall integer k; 0 <= k < p ==> (k == 0 ==> j[k] == 2)); */
    /*@ assert (\forall integer k; 0 <= k < p ==> (k == 0 ==> j[k] == 2) && (k == 1 ==> j[k] == 1)); */
    /*@ assert (\forall integer k; 0 <= k < 2 ==> j[k] > 0); */
    /*@ assert (\forall integer k; 0 <= k < 2 ==> j[k] == (k == 0 ? 2 : 1)); */
    /*@ assert (2 <= p); */
    /*@ assert (0 <= p); */
}

/*@ requires (p == 2 || j[p - 1] > 0) && (\forall integer k; 2 <= k < p ==> j[k] > j[k - 1] || j[k] > j[k - 2]) && (p == 2 || \forall integer k; 2 <= k < p ==> j[k] == j[k - 1] + 2 * j[k - 2]) && (j_len == c + 1) && (j[1] == 1) && (j[0] == 2) && (j[0] == 2 && j[1] == 1) && (\forall integer k; 2 <= k < p ==> j[k] >= j[k-2]) && (\forall integer k; 2 <= k < p ==> j[k] >= j[k-2] && j[k] >= j[k-1]) && (\forall integer k; 2 <= k < p ==> j[k] >= j[k-1]) && (\forall integer k; 2 <= k < p ==> j[k] >= j[k-1] && j[k] >= j[k-2]) && (\forall integer k; 2 <= k < p ==> j[k] >= j[k - 2]) && (\forall integer k; 2 <= k < p ==> j[k] >= j[k - 2] && j[k] >= j[k - 1]) && (\forall integer k; 2 <= k < p ==> j[k] >= j[k - 1]) && (\forall integer k; 2 <= k < p ==> j[k] >= j[k - 1] && j[k] >= j[k - 2]) && (\forall integer k; 2 <= k < p ==> j[k] > j[k - 2]) && (\forall integer k; 2 <= k < p ==> j[k] > j[k - 1]) && (\forall integer k; 2 <= k < p ==> j[k] > 0) && (\forall integer k; 2 <= k < p ==> j[k] == j[k-1] + 2 * j[k-2]) && (\forall integer k; 2 <= k < p ==> j[k] == j[k - 1] + 2 * j[k - 2]) && (\forall integer k; 0 <= k < p ==> j[k] >= 1) && (\forall integer k; 0 <= k < p ==> j[k] >= 1 || k == 1) && (\forall integer k; 0 <= k < p ==> j[k] >= 0) && (\forall integer k; 0 <= k < p ==> j[k] > 0) && (\forall integer k; 0 <= k < p ==> j[k] == 0 || j[k] >= 1) && (\forall integer k; 0 <= k < p ==> j[k] == 0 || j[k] > 0) && (\forall integer k; 0 <= k < p ==> j[k] != 0) && (\forall integer k; 0 <= k < p ==> (k == 1 ==> j[k] == 1)) && (\forall integer k; 0 <= k < p ==> (k == 0 ==> j[k] == 2)) && (\forall integer k; 0 <= k < p ==> (k == 0 ==> j[k] == 2) && (k == 1 ==> j[k] == 1)) && (\forall integer k; 0 <= k < 2 ==> j[k] > 0) && (\forall integer k; 0 <= k < 2 ==> j[k] == (k == 0 ? 2 : 1)) && (2 <= p) && (0 <= p);
    assigns \nothing;
*/
void check_B_implies_A(int c, int *j, int j_len, int k, int p) {
    /*@ assert (2 <= p <= c + 1); */
    /*@ assert (j_len == c + 1); */
    /*@ assert (j[0] == 2); */
    /*@ assert (j[1] == 1); */
    /*@ assert (\forall integer k; 2 <= k < p ==> j[k] == j[k - 1] + 2 * j[k - 2]); */
    /*@ assert (j[p - 1] >= 1); */
    /*@ assert (j[p - 2] >= 1); */
    /*@ assert (\exists integer k; 0 <= k < p && j[k] == 1); */
}
