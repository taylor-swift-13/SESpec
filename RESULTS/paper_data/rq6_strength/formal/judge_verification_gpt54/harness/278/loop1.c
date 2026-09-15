#include <limits.h>

/*@ logic integer min_prefix(int *a, integer lo, integer hi) =
    lo + 1 >= hi ? a[lo]
                 : (a[hi - 1] < min_prefix(a, lo, hi - 1) ? a[hi - 1] : min_prefix(a, lo, hi - 1)); */

/*@ requires (1 <= j <= args_len) && (tmp == min_prefix(args, 0, j)) && (ret >= 0) && ((j < args_len) ==> (ret >= 0)) && ((!(j < args_len)) ==> (tmp == min_prefix(args, 0, args_len))) && (\forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *args, int args_len, int j, int k, int ret, int tmp) {
    /*@ assert (ret == 0 || \exists integer k; 0 <= k < j && ret == args[k]); */
    /*@ assert (tmp >= 0 || tmp <= args[0]); */
    /*@ assert (tmp == args[j-1] || tmp <= args[j-1]); */
    /*@ assert (tmp == args[0] || \exists integer k; 0 <= k < j && tmp == args[k]); */
    /*@ assert (tmp == args[0] || (\exists integer k; 0 <= k < j && tmp == args[k])); */
    /*@ assert (tmp <= ret || ret == 0); */
    /*@ assert (tmp <= args[j-1]); */
    /*@ assert (tmp <= args[j-1] || ret >= tmp); */
    /*@ assert (tmp <= args[0]); */
    /*@ assert (tmp <= args[0] || tmp == args[0]); */
    /*@ assert (tmp <= args[0] || tmp <= ret); */
    /*@ assert (ret >= tmp || ret == 0); */
    /*@ assert (ret == 0 || tmp <= ret); */
    /*@ assert (ret == 0 || tmp <= args[0]); */
    /*@ assert (ret == 0 || ret >= tmp); */
    /*@ assert (ret == 0 || ret >= 0); */
    /*@ assert (ret == 0 ==> j >= 1); */
    /*@ assert (j == 1 || j > 0); */
    /*@ assert (j <= args_len || 0 <= j); */
    /*@ assert (\forall integer k; 0 <= k < j ==> tmp <= args[k]); */
    /*@ assert (\forall integer k; 0 <= k < j ==> tmp <= args[k] || ret >= tmp); */
    /*@ assert (\forall integer k; 0 <= k < j ==> tmp <= args[k] || ret >= args[k]); */
    /*@ assert (\forall integer k; 0 <= k < j ==> ret >= args[k] || tmp <= args[k]); */
    /*@ assert (\forall integer k; 0 <= k < j ==> ret >= 0); */
    /*@ assert (\forall integer k; 0 <= k < j ==> ret >= 0 || tmp <= args[k]); */
    /*@ assert (\forall integer k; 0 <= k < j ==> ret >= 0 || args[k] >= tmp); */
    /*@ assert (\forall integer k; 0 <= k < j ==> ret == 0 || ret >= 0); */
    /*@ assert (\forall integer k; 0 <= k < j ==> args[k] >= tmp); */
    /*@ assert (\forall integer k; 0 <= k < j ==> args[k] >= tmp || ret >= args[k]); */
    /*@ assert (\forall integer k; 0 <= k < j ==> args[k] >= ret || tmp <= args[k]); */
    /*@ assert (\exists integer k; 0 <= k < j && tmp == args[k]); */
    /*@ assert (\exists integer k; 0 <= k < j && args[k] == tmp); */
    /*@ assert (1 <= j); */
    /*@ assert (0 <= ret); */
    /*@ assert (0 <= ret || ret == 0); */
    /*@ assert (0 <= j); */
    /*@ assert (0 < j); */
}

/*@ requires (ret == 0 || \exists integer k; 0 <= k < j && ret == args[k]) && (tmp >= 0 || tmp <= args[0]) && (tmp == args[j-1] || tmp <= args[j-1]) && (tmp == args[0] || \exists integer k; 0 <= k < j && tmp == args[k]) && (tmp == args[0] || (\exists integer k; 0 <= k < j && tmp == args[k])) && (tmp <= ret || ret == 0) && (tmp <= args[j-1]) && (tmp <= args[j-1] || ret >= tmp) && (tmp <= args[0]) && (tmp <= args[0] || tmp == args[0]) && (tmp <= args[0] || tmp <= ret) && (ret >= tmp || ret == 0) && (ret == 0 || tmp <= ret) && (ret == 0 || tmp <= args[0]) && (ret == 0 || ret >= tmp) && (ret == 0 || ret >= 0) && (ret == 0 ==> j >= 1) && (j == 1 || j > 0) && (j <= args_len || 0 <= j) && (\forall integer k; 0 <= k < j ==> tmp <= args[k]) && (\forall integer k; 0 <= k < j ==> tmp <= args[k] || ret >= tmp) && (\forall integer k; 0 <= k < j ==> tmp <= args[k] || ret >= args[k]) && (\forall integer k; 0 <= k < j ==> ret >= args[k] || tmp <= args[k]) && (\forall integer k; 0 <= k < j ==> ret >= 0) && (\forall integer k; 0 <= k < j ==> ret >= 0 || tmp <= args[k]) && (\forall integer k; 0 <= k < j ==> ret >= 0 || args[k] >= tmp) && (\forall integer k; 0 <= k < j ==> ret == 0 || ret >= 0) && (\forall integer k; 0 <= k < j ==> args[k] >= tmp) && (\forall integer k; 0 <= k < j ==> args[k] >= tmp || ret >= args[k]) && (\forall integer k; 0 <= k < j ==> args[k] >= ret || tmp <= args[k]) && (\exists integer k; 0 <= k < j && tmp == args[k]) && (\exists integer k; 0 <= k < j && args[k] == tmp) && (1 <= j) && (0 <= ret) && (0 <= ret || ret == 0) && (0 <= j) && (0 < j);
    assigns \nothing;
*/
void check_B_implies_A(int *args, int args_len, int j, int k, int ret, int tmp) {
    /*@ assert (1 <= j <= args_len); */
    /*@ assert (tmp == min_prefix(args, 0, j)); */
    /*@ assert (ret >= 0); */
    /*@ assert ((j < args_len) ==> (ret >= 0)); */
    /*@ assert ((!(j < args_len)) ==> (tmp == min_prefix(args, 0, args_len))); */
    /*@ assert (\forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre)); */
}
