#include <limits.h>

/*@logic integer min_prefix(int *a, integer lo, integer hi) =
    lo + 1 >= hi ? a[lo]
                 : (a[hi - 1] < min_prefix(a, lo, hi - 1) ? a[hi - 1] : min_prefix(a, lo, hi - 1));*/

/*@ requires (1 <= j <= args_len) && (tmp == min_prefix(args, 0, j)) && (ret >= 0) && ((j < args_len) ==> (ret >= 0)) && ((!(j < args_len)) ==> (tmp == min_prefix(args, 0, args_len))) && (\forall integer k);
    assigns \nothing;
*/
void check_A_implies_B(int *args, int args_len, int *j, int *k, int *ret, int *tmp) {
    /*@ assert (ret == 0 || \exists integer k) && (tmp >= 0 || tmp <= args[0]) && (tmp == args[j-1] || tmp <= args[j-1]) && (tmp == args[0] || \exists integer k) && (tmp == args[0] || (\exists integer k) && (tmp <= ret || ret == 0) && (tmp <= args[j-1]) && (tmp <= args[j-1] || ret >= tmp) && (tmp <= args[0]) && (tmp <= args[0] || tmp == args[0]) && (tmp <= args[0] || tmp <= ret) && (ret >= tmp || ret == 0) && (ret == 0 || tmp <= ret) && (ret == 0 || tmp <= args[0]) && (ret == 0 || ret >= tmp) && (ret == 0 || ret >= 0) && (ret == 0 ==> j >= 1) && (j == 1 || j > 0) && (j <= args_len || 0 <= j) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (1 <= j) && (0 <= ret) && (0 <= ret || ret == 0) && (0 <= j) && (0 < j); */
}

/*@ requires (ret == 0 || \exists integer k) && (tmp >= 0 || tmp <= args[0]) && (tmp == args[j-1] || tmp <= args[j-1]) && (tmp == args[0] || \exists integer k) && (tmp == args[0] || (\exists integer k) && (tmp <= ret || ret == 0) && (tmp <= args[j-1]) && (tmp <= args[j-1] || ret >= tmp) && (tmp <= args[0]) && (tmp <= args[0] || tmp == args[0]) && (tmp <= args[0] || tmp <= ret) && (ret >= tmp || ret == 0) && (ret == 0 || tmp <= ret) && (ret == 0 || tmp <= args[0]) && (ret == 0 || ret >= tmp) && (ret == 0 || ret >= 0) && (ret == 0 ==> j >= 1) && (j == 1 || j > 0) && (j <= args_len || 0 <= j) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (1 <= j) && (0 <= ret) && (0 <= ret || ret == 0) && (0 <= j) && (0 < j);
    assigns \nothing;
*/
void check_B_implies_A(int *args, int args_len, int *j, int *k, int *ret, int *tmp) {
    /*@ assert (1 <= j <= args_len) && (tmp == min_prefix(args, 0, j)) && (ret >= 0) && ((j < args_len) ==> (ret >= 0)) && ((!(j < args_len)) ==> (tmp == min_prefix(args, 0, args_len))) && (\forall integer k); */
}
