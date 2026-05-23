#include <limits.h>

/*@logic integer minp(int* a, integer lo, integer hi) =
    hi <= lo ? 0 :
    (hi == lo + 1 ? a[lo] :
     (minp(a, lo, hi - 1) <= a[hi - 1] ? minp(a, lo, hi - 1) : a[hi - 1]));*/

/*@ requires (1 <= j <= arg_len) && (ret == minp(arg, 0, j)) && (\forall integer k) && (0 <= g) && (\exists integer k) && ((j < arg_len) ==> (ret == minp(arg, 0, j))) && ((!(j < arg_len)) ==> (ret == minp(arg, 0, arg_len))) && (\forall integer k);
    assigns \nothing;
*/
void check_A_implies_B(int *arg, int arg_len, int *g, int *j, int *k, int *ret) {
    /*@ assert (ret == arg[0] || ret == arg[j-1] || \exists integer k) && (ret == arg[0] || ret == arg[j-1] || (\exists integer k) && (ret == arg[0] || \exists integer k) && (ret == arg[0] || \exists integer k) && (ret == arg[0] || (\exists integer k) && (ret == arg[0] || (\exists integer k) && (ret <= g || g == 0) && (ret <= arg[0]) && (ret <= arg[0] || ret == arg[0]) && (ret <= arg[0] || ret <= g) && (g >= ret || g == 0) && (g == 0 || ret <= g) && (g == 0 || ret <= g || ret == arg[0]) && (g == 0 || ret <= arg[0]) && (g == 0 || g >= ret) && (g == 0 || g >= 0) && (g == 0 || g == ret || \exists integer k) && (g == 0 || \exists integer k) && (g == 0 || \exists integer k) && (g == 0 || (\exists integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (1 <= j) && (0 <= j) && (0 <= g); */
}

/*@ requires (ret == arg[0] || ret == arg[j-1] || \exists integer k) && (ret == arg[0] || ret == arg[j-1] || (\exists integer k) && (ret == arg[0] || \exists integer k) && (ret == arg[0] || \exists integer k) && (ret == arg[0] || (\exists integer k) && (ret == arg[0] || (\exists integer k) && (ret <= g || g == 0) && (ret <= arg[0]) && (ret <= arg[0] || ret == arg[0]) && (ret <= arg[0] || ret <= g) && (g >= ret || g == 0) && (g == 0 || ret <= g) && (g == 0 || ret <= g || ret == arg[0]) && (g == 0 || ret <= arg[0]) && (g == 0 || g >= ret) && (g == 0 || g >= 0) && (g == 0 || g == ret || \exists integer k) && (g == 0 || \exists integer k) && (g == 0 || \exists integer k) && (g == 0 || (\exists integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (1 <= j) && (0 <= j) && (0 <= g);
    assigns \nothing;
*/
void check_B_implies_A(int *arg, int arg_len, int *g, int *j, int *k, int *ret) {
    /*@ assert (1 <= j <= arg_len) && (ret == minp(arg, 0, j)) && (\forall integer k) && (0 <= g) && (\exists integer k) && ((j < arg_len) ==> (ret == minp(arg, 0, j))) && ((!(j < arg_len)) ==> (ret == minp(arg, 0, arg_len))) && (\forall integer k); */
}
