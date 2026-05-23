#include <limits.h>
#include <stdlib.h>

/*@ requires (p >= 2) && (r[0] == 0) && (r[1] == 1) && (\forall integer k; 2 <= k < p ==> r[k] == r[k - 1] + 2 * r[k - 2]);
    assigns \nothing;
*/
void check_A_implies_B(int j, int k, int p, int *r, int r_len) {
    /*@ assert (\forall integer k; 2 <= k < p ==> r[k] >= r[k - 2]); */
    /*@ assert (r_len == j + 1); */
    /*@ assert (r[p - 2] <= r[p - 1]); */
    /*@ assert (r[1] == 1); */
    /*@ assert (r[0] == 0); */
    /*@ assert (r[0] == 0 && r[1] == 1); */
    /*@ assert (p == 2 || r[p-1] == r[p-2] + 2 * r[p-3]); */
    /*@ assert (p == 2 || r[p - 1] >= r[p - 2]); */
    /*@ assert (p == 2 || r[p - 1] == r[p - 2] + 2 * r[p - 3]); */
    /*@ assert (\forall integer k; 2 <= k < p ==> r[k] >= r[k - 1]); */
    /*@ assert (\forall integer k; 2 <= k < p ==> r[k] >= 0); */
    /*@ assert (\forall integer k; 2 <= k < p ==> r[k] == r[k-1] + 2 * r[k-2]); */
    /*@ assert (\forall integer k; 2 <= k < p ==> r[k] == r[k - 1] + 2 * r[k - 2]); */
    /*@ assert (\forall integer k; 1 <= k < p ==> r[k] >= r[k - 1]); */
    /*@ assert (\forall integer k; 0 <= k < p ==> r[k] >= 0); */
    /*@ assert (\forall integer k; 0 <= k < p ==> r[k] == (k == 0 ? 0 : (k == 1 ? 1 : r[k-1] + 2 * r[k-2]))); */
    /*@ assert (\forall integer k; 0 <= k < p ==> r[k] == (k == 0 ? 0 : (k == 1 ? 1 : r[k - 1] + 2 * r[k - 2]))); */
    /*@ assert (\forall integer k; 0 <= k < p ==> (k == 0 ? r[k] == 0 : (k == 1 ? r[k] == 1 : r[k] >= r[k - 2]))); */
    /*@ assert (\forall integer k; 0 <= k < p ==> (k == 0 ? r[k] == 0 : (k == 1 ? r[k] == 1 : r[k] >= r[k - 1]))); */
    /*@ assert (\forall integer k; 0 <= k < p ==> (k == 0 ? r[k] == 0 : (k == 1 ? r[k] == 1 : r[k] == r[k-1] + 2 * r[k-2]))); */
    /*@ assert (\forall integer k; 0 <= k < p ==> (k == 0 ? r[k] == 0 : (k == 1 ? r[k] == 1 : r[k] == r[k - 1] + 2 * r[k - 2]))); */
    /*@ assert (\forall integer k; 0 <= k < p ==> (k == 0 ==> r[k] == 0) && (k == 1 ==> r[k] == 1)); */
    /*@ assert (\forall integer k; 0 <= k < p ==> (k < 2 || r[k] >= r[k - 2])); */
    /*@ assert (\forall integer k; 0 <= k < p ==> (k < 2 || r[k] >= r[k - 1])); */
    /*@ assert (\forall integer k; 0 <= k < p ==> (k < 2 || r[k] == r[k - 1] + 2 * r[k - 2])); */
    /*@ assert (2 <= p); */
    /*@ assert (0 <= r[p - 1]); */
    /*@ assert (0 <= p); */
}

/*@ requires (\forall integer k; 2 <= k < p ==> r[k] >= r[k - 2]) && (r_len == j + 1) && (r[p - 2] <= r[p - 1]) && (r[1] == 1) && (r[0] == 0) && (r[0] == 0 && r[1] == 1) && (p == 2 || r[p-1] == r[p-2] + 2 * r[p-3]) && (p == 2 || r[p - 1] >= r[p - 2]) && (p == 2 || r[p - 1] == r[p - 2] + 2 * r[p - 3]) && (\forall integer k; 2 <= k < p ==> r[k] >= r[k - 1]) && (\forall integer k; 2 <= k < p ==> r[k] >= 0) && (\forall integer k; 2 <= k < p ==> r[k] == r[k-1] + 2 * r[k-2]) && (\forall integer k; 2 <= k < p ==> r[k] == r[k - 1] + 2 * r[k - 2]) && (\forall integer k; 1 <= k < p ==> r[k] >= r[k - 1]) && (\forall integer k; 0 <= k < p ==> r[k] >= 0) && (\forall integer k; 0 <= k < p ==> r[k] == (k == 0 ? 0 : (k == 1 ? 1 : r[k-1] + 2 * r[k-2]))) && (\forall integer k; 0 <= k < p ==> r[k] == (k == 0 ? 0 : (k == 1 ? 1 : r[k - 1] + 2 * r[k - 2]))) && (\forall integer k; 0 <= k < p ==> (k == 0 ? r[k] == 0 : (k == 1 ? r[k] == 1 : r[k] >= r[k - 2]))) && (\forall integer k; 0 <= k < p ==> (k == 0 ? r[k] == 0 : (k == 1 ? r[k] == 1 : r[k] >= r[k - 1]))) && (\forall integer k; 0 <= k < p ==> (k == 0 ? r[k] == 0 : (k == 1 ? r[k] == 1 : r[k] == r[k-1] + 2 * r[k-2]))) && (\forall integer k; 0 <= k < p ==> (k == 0 ? r[k] == 0 : (k == 1 ? r[k] == 1 : r[k] == r[k - 1] + 2 * r[k - 2]))) && (\forall integer k; 0 <= k < p ==> (k == 0 ==> r[k] == 0) && (k == 1 ==> r[k] == 1)) && (\forall integer k; 0 <= k < p ==> (k < 2 || r[k] >= r[k - 2])) && (\forall integer k; 0 <= k < p ==> (k < 2 || r[k] >= r[k - 1])) && (\forall integer k; 0 <= k < p ==> (k < 2 || r[k] == r[k - 1] + 2 * r[k - 2])) && (2 <= p) && (0 <= r[p - 1]) && (0 <= p);
    assigns \nothing;
*/
void check_B_implies_A(int j, int k, int p, int *r, int r_len) {
    /*@ assert (p >= 2); */
    /*@ assert (r[0] == 0); */
    /*@ assert (r[1] == 1); */
    /*@ assert (\forall integer k; 2 <= k < p ==> r[k] == r[k - 1] + 2 * r[k - 2]); */
}
