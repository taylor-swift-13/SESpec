#include <limits.h>

/*@ logic integer max_prefix(int *args, integer lo, integer hi) =
    lo >= hi ? args[lo] :
    (max_prefix(args, lo, hi - 1) > args[hi - 1] ? max_prefix(args, lo, hi - 1) : args[hi - 1]); */

/*@ requires (args_len == \at(args_len,Pre)) && (args == \at(args,Pre)) && (\forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre)) && ((j < \at(args_len,Pre)) ==> (args_len == \at(args_len,Pre))) && ((j < \at(args_len,Pre)) ==> (args == \at(args,Pre))) && ((!(j < \at(args_len,Pre))) ==> (args_len == \at(args_len,Pre) && args == \at(args,Pre)));
    assigns \nothing;
*/
void check_A_implies_B(int *args, int args_len, int g, int j, int k, int ret) {
    /*@ assert (ret == args[0] || ret == args[j-1] || (\exists integer k; 0 <= k < j && ret == args[k])); */
    /*@ assert (ret == args[0] || (\exists integer k; 1 <= k < j && ret == args[k])); */
    /*@ assert (ret == args[0] || (\exists integer k; 0 <= k < j && ret == args[k])); */
    /*@ assert (ret <= args[j-1]); */
    /*@ assert (ret <= args[0]); */
    /*@ assert (ret <= args[0] || ret == args[0]); */
    /*@ assert (ret <= args[0] || ret <= args[j-1]); */
    /*@ assert (j == 0 || j > 0); */
    /*@ assert (g >= ret || g == 0); */
    /*@ assert (g == 0 || g >= ret); */
    /*@ assert (g == 0 || g == ret || g >= ret); */
    /*@ assert (\forall integer k; 0 <= k < j ==> ret <= args[k]); */
    /*@ assert (\forall integer k; 0 <= k < j ==> ret <= args[k] || ret == args[k]); */
    /*@ assert (\forall integer k; 0 <= k < j ==> ret <= args[k] || ret == args[0]); */
    /*@ assert (\forall integer k; 0 <= k < j ==> ret <= args[k] || ret <= args[0]); */
    /*@ assert (\forall integer k; 0 <= k < j ==> args[k] >= ret); */
    /*@ assert (\exists integer k; 0 <= k < j && ret == args[k]); */
    /*@ assert (1 <= j); */
    /*@ assert (1 <= j || j == 0); */
    /*@ assert (0 <= j); */
    /*@ assert (0 <= g); */
}

/*@ requires (ret == args[0] || ret == args[j-1] || (\exists integer k; 0 <= k < j && ret == args[k])) && (ret == args[0] || (\exists integer k; 1 <= k < j && ret == args[k])) && (ret == args[0] || (\exists integer k; 0 <= k < j && ret == args[k])) && (ret <= args[j-1]) && (ret <= args[0]) && (ret <= args[0] || ret == args[0]) && (ret <= args[0] || ret <= args[j-1]) && (j == 0 || j > 0) && (g >= ret || g == 0) && (g == 0 || g >= ret) && (g == 0 || g == ret || g >= ret) && (\forall integer k; 0 <= k < j ==> ret <= args[k]) && (\forall integer k; 0 <= k < j ==> ret <= args[k] || ret == args[k]) && (\forall integer k; 0 <= k < j ==> ret <= args[k] || ret == args[0]) && (\forall integer k; 0 <= k < j ==> ret <= args[k] || ret <= args[0]) && (\forall integer k; 0 <= k < j ==> args[k] >= ret) && (\exists integer k; 0 <= k < j && ret == args[k]) && (1 <= j) && (1 <= j || j == 0) && (0 <= j) && (0 <= g);
    assigns \nothing;
*/
void check_B_implies_A(int *args, int args_len, int g, int j, int k, int ret) {
    /*@ assert (args_len == \at(args_len,Pre)); */
    /*@ assert (args == \at(args,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre)); */
    /*@ assert ((j < \at(args_len,Pre)) ==> (args_len == \at(args_len,Pre))); */
    /*@ assert ((j < \at(args_len,Pre)) ==> (args == \at(args,Pre))); */
    /*@ assert ((!(j < \at(args_len,Pre))) ==> (args_len == \at(args_len,Pre) && args == \at(args,Pre))); */
}
