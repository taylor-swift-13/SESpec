#include <limits.h>

/*@ logic integer minp(int* a, integer lo, integer hi) =
    hi <= lo ? 0 :
    (hi == lo + 1 ? a[lo] :
     (minp(a, lo, hi - 1) <= a[hi - 1] ? minp(a, lo, hi - 1) : a[hi - 1])); */

/*@ requires (1 <= j <= arg_len) && (ret == minp(arg, 0, j)) && (\forall integer k; 0 <= k < j ==> ret <= arg[k]) && (0 <= g) && (\exists integer k; 0 <= k < arg_len && ret == arg[k]) && ((j < arg_len) ==> (ret == minp(arg, 0, j))) && ((!(j < arg_len)) ==> (ret == minp(arg, 0, arg_len))) && (\forall integer k; 0 <= k < arg_len ==> arg[k] == \at(arg[k], Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *arg, int arg_len, int g, int j, int k, int ret) {
    /*@ assert (ret == arg[0] || ret == arg[j-1] || \exists integer k; 0 <= k < j && ret == arg[k]); */
    /*@ assert (ret == arg[0] || ret == arg[j-1] || (\exists integer k; 0 <= k < j && ret == arg[k])); */
    /*@ assert (ret == arg[0] || \exists integer k; 1 <= k < j && ret == arg[k]); */
    /*@ assert (ret == arg[0] || \exists integer k; 0 <= k < j && ret == arg[k]); */
    /*@ assert (ret == arg[0] || (\exists integer k; 1 <= k < j && ret == arg[k])); */
    /*@ assert (ret == arg[0] || (\exists integer k; 0 <= k < j && ret == arg[k])); */
    /*@ assert (ret <= g || g == 0); */
    /*@ assert (ret <= arg[0]); */
    /*@ assert (ret <= arg[0] || ret == arg[0]); */
    /*@ assert (ret <= arg[0] || ret <= g); */
    /*@ assert (g >= ret || g == 0); */
    /*@ assert (g == 0 || ret <= g); */
    /*@ assert (g == 0 || ret <= g || ret == arg[0]); */
    /*@ assert (g == 0 || ret <= arg[0]); */
    /*@ assert (g == 0 || g >= ret); */
    /*@ assert (g == 0 || g >= 0); */
    /*@ assert (g == 0 || g == ret || \exists integer k; 0 <= k < j && g == arg[k]); */
    /*@ assert (g == 0 || \exists integer k; 0 <= k < j && g >= arg[k]); */
    /*@ assert (g == 0 || \exists integer k; 0 <= k < j && g == arg[k]); */
    /*@ assert (g == 0 || (\exists integer k; 0 <= k < j && g == arg[k])); */
    /*@ assert (\forall integer k; 1 <= k < j ==> ret <= arg[k]); */
    /*@ assert (\forall integer k; 1 <= k < j ==> ret <= arg[k] || ret == arg[k]); */
    /*@ assert (\forall integer k; 0 <= k < j ==> ret <= arg[k]); */
    /*@ assert (\forall integer k; 0 <= k < j ==> ret <= arg[k] || ret == arg[k]); */
    /*@ assert (\forall integer k; 0 <= k < j ==> ret <= arg[k] || g >= arg[k]); */
    /*@ assert (\forall integer k; 0 <= k < j ==> g >= ret || g == 0); */
    /*@ assert (\forall integer k; 0 <= k < j ==> g >= 0); */
    /*@ assert (\forall integer k; 0 <= k < j ==> g == 0 || g >= ret); */
    /*@ assert (\forall integer k; 0 <= k < j ==> arg[k] >= ret); */
    /*@ assert (\forall integer k; 0 <= k < j ==> arg[k] >= ret || arg[k] == ret); */
    /*@ assert (\exists integer k; 0 <= k < j && ret == arg[k]); */
    /*@ assert (\exists integer k; 0 <= k < j && ret == arg[k] || ret == arg[0]); */
    /*@ assert (\exists integer k; 0 <= k < j && g == arg[k] || g == 0); */
    /*@ assert (\exists integer k; 0 <= k < j && arg[k] == ret); */
    /*@ assert (\exists integer k; 0 <= k < j && (g == arg[k] || ret == arg[k])); */
    /*@ assert (1 <= j); */
    /*@ assert (0 <= j); */
    /*@ assert (0 <= g); */
}

/*@ requires (ret == arg[0] || ret == arg[j-1] || \exists integer k; 0 <= k < j && ret == arg[k]) && (ret == arg[0] || ret == arg[j-1] || (\exists integer k; 0 <= k < j && ret == arg[k])) && (ret == arg[0] || \exists integer k; 1 <= k < j && ret == arg[k]) && (ret == arg[0] || \exists integer k; 0 <= k < j && ret == arg[k]) && (ret == arg[0] || (\exists integer k; 1 <= k < j && ret == arg[k])) && (ret == arg[0] || (\exists integer k; 0 <= k < j && ret == arg[k])) && (ret <= g || g == 0) && (ret <= arg[0]) && (ret <= arg[0] || ret == arg[0]) && (ret <= arg[0] || ret <= g) && (g >= ret || g == 0) && (g == 0 || ret <= g) && (g == 0 || ret <= g || ret == arg[0]) && (g == 0 || ret <= arg[0]) && (g == 0 || g >= ret) && (g == 0 || g >= 0) && (g == 0 || g == ret || \exists integer k; 0 <= k < j && g == arg[k]) && (g == 0 || \exists integer k; 0 <= k < j && g >= arg[k]) && (g == 0 || \exists integer k; 0 <= k < j && g == arg[k]) && (g == 0 || (\exists integer k; 0 <= k < j && g == arg[k])) && (\forall integer k; 1 <= k < j ==> ret <= arg[k]) && (\forall integer k; 1 <= k < j ==> ret <= arg[k] || ret == arg[k]) && (\forall integer k; 0 <= k < j ==> ret <= arg[k]) && (\forall integer k; 0 <= k < j ==> ret <= arg[k] || ret == arg[k]) && (\forall integer k; 0 <= k < j ==> ret <= arg[k] || g >= arg[k]) && (\forall integer k; 0 <= k < j ==> g >= ret || g == 0) && (\forall integer k; 0 <= k < j ==> g >= 0) && (\forall integer k; 0 <= k < j ==> g == 0 || g >= ret) && (\forall integer k; 0 <= k < j ==> arg[k] >= ret) && (\forall integer k; 0 <= k < j ==> arg[k] >= ret || arg[k] == ret) && (\exists integer k; 0 <= k < j && ret == arg[k]) && (\exists integer k; 0 <= k < j && ret == arg[k] || ret == arg[0]) && (\exists integer k; 0 <= k < j && g == arg[k] || g == 0) && (\exists integer k; 0 <= k < j && arg[k] == ret) && (\exists integer k; 0 <= k < j && (g == arg[k] || ret == arg[k])) && (1 <= j) && (0 <= j) && (0 <= g);
    assigns \nothing;
*/
void check_B_implies_A(int *arg, int arg_len, int g, int j, int k, int ret) {
    /*@ assert (1 <= j <= arg_len); */
    /*@ assert (ret == minp(arg, 0, j)); */
    /*@ assert (\forall integer k; 0 <= k < j ==> ret <= arg[k]); */
    /*@ assert (0 <= g); */
    /*@ assert (\exists integer k; 0 <= k < arg_len && ret == arg[k]); */
    /*@ assert ((j < arg_len) ==> (ret == minp(arg, 0, j))); */
    /*@ assert ((!(j < arg_len)) ==> (ret == minp(arg, 0, arg_len))); */
    /*@ assert (\forall integer k; 0 <= k < arg_len ==> arg[k] == \at(arg[k], Pre)); */
}
