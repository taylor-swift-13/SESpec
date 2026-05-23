#include <limits.h>

/*@ logic integer count_nondiv(integer code, integer l, integer i) =
      i < l ? 0 : count_nondiv(code, l, i - 1) + (i % code != 0 ? 1 : 0); */

/*@ requires (0 <= ret) && (l <= loop) && (ret == count_nondiv(code, l, loop - 1)) && (ret <= loop - l) && (code == \at(code,Pre)) && (b == \at(b,Pre)) && (c == \at(c,Pre)) && (l == \at(l,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int b, int c, int code, int k, int l, int ret) {
    /*@ assert (ret > 0 ==> loop > l); */
    /*@ assert (ret > 0 ==> l < loop); */
    /*@ assert (ret > 0 ==> \exists integer k; l <= k < loop ==> k % code != 0); */
    /*@ assert (ret > 0 ==> \exists integer k; l <= k < loop && k % code != 0); */
    /*@ assert (ret == 0 || ret >= 1); */
    /*@ assert (ret == 0 || ret > 0); */
    /*@ assert (ret == 0 || ret == 1 || ret > 1); */
    /*@ assert (ret == 0 ==> loop == l || \forall integer k; l <= k < loop ==> k % code == 0); */
    /*@ assert (ret == 0 ==> \forall integer k; l <= k < loop ==> k % code == 0); */
    /*@ assert (ret == 0 ==> \forall integer k; l <= k < loop && k % code == 0 ==> 1 == 1); */
    /*@ assert (ret <= loop - l); */
    /*@ assert (ret <= loop - l + 1); */
    /*@ assert (ret <= b ==> ret <= loop - l); */
    /*@ assert (ret <= b ==> ret <= loop - l + 1); */
    /*@ assert (ret < b ==> ret >= 0); */
    /*@ assert (ret < b ==> ret <= loop - l); */
    /*@ assert (ret < b ==> ret <= b); */
    /*@ assert (ret < b ==> ret < loop - l + 1); */
    /*@ assert (ret < b ==> ret < b + 1); */
    /*@ assert (ret < b ==> loop == l + ret || loop > l); */
    /*@ assert (ret < b ==> \forall integer k; l <= k < loop && k % code != 0 ==> ret >= 1); */
    /*@ assert (ret < b ==> \forall integer k; l <= k < loop && k % code != 0 ==> ret >= 0); */
    /*@ assert (ret < b ==> \forall integer k; l <= k < loop && k % code != 0 ==> ret < b); */
    /*@ assert (loop == l ==> ret == 0); */
    /*@ assert (loop == l + ret || loop > l); */
    /*@ assert (l <= loop); */
    /*@ assert (l <= loop - ret); */
    /*@ assert (\forall integer k; l <= k < loop ==> (k % code == 0 || k % code != 0)); */
    /*@ assert (\forall integer k; l <= k < loop ==> (k % code == 0 ==> ret >= 0)); */
    /*@ assert (\forall integer k; l <= k < loop ==> (k % code != 0 ==> ret >= 1)); */
    /*@ assert (\forall integer k; l <= k < loop ==> (k % code != 0 ==> ret > 0)); */
    /*@ assert (\forall integer k; l <= k < loop && k % code == 0 ==> ret >= 0); */
    /*@ assert (\forall integer k; l <= k < loop && k % code != 0 ==> ret >= 1); */
    /*@ assert (\forall integer k; l <= k < loop && k % code != 0 ==> ret >= 0); */
    /*@ assert (\forall integer k; l <= k < loop && k % code != 0 ==> ret > 0); */
    /*@ assert (\exists integer k; l <= k < loop ==> k % code != 0 || ret == 0); */
    /*@ assert (\exists integer k; l <= k < loop ==> (k % code != 0 ==> ret >= 1)); */
    /*@ assert (0 <= ret); */
}

/*@ requires (ret > 0 ==> loop > l) && (ret > 0 ==> l < loop) && (ret > 0 ==> \exists integer k; l <= k < loop ==> k % code != 0) && (ret > 0 ==> \exists integer k; l <= k < loop && k % code != 0) && (ret == 0 || ret >= 1) && (ret == 0 || ret > 0) && (ret == 0 || ret == 1 || ret > 1) && (ret == 0 ==> loop == l || \forall integer k; l <= k < loop ==> k % code == 0) && (ret == 0 ==> \forall integer k; l <= k < loop ==> k % code == 0) && (ret == 0 ==> \forall integer k; l <= k < loop && k % code == 0 ==> 1 == 1) && (ret <= loop - l) && (ret <= loop - l + 1) && (ret <= b ==> ret <= loop - l) && (ret <= b ==> ret <= loop - l + 1) && (ret < b ==> ret >= 0) && (ret < b ==> ret <= loop - l) && (ret < b ==> ret <= b) && (ret < b ==> ret < loop - l + 1) && (ret < b ==> ret < b + 1) && (ret < b ==> loop == l + ret || loop > l) && (ret < b ==> \forall integer k; l <= k < loop && k % code != 0 ==> ret >= 1) && (ret < b ==> \forall integer k; l <= k < loop && k % code != 0 ==> ret >= 0) && (ret < b ==> \forall integer k; l <= k < loop && k % code != 0 ==> ret < b) && (loop == l ==> ret == 0) && (loop == l + ret || loop > l) && (l <= loop) && (l <= loop - ret) && (\forall integer k; l <= k < loop ==> (k % code == 0 || k % code != 0)) && (\forall integer k; l <= k < loop ==> (k % code == 0 ==> ret >= 0)) && (\forall integer k; l <= k < loop ==> (k % code != 0 ==> ret >= 1)) && (\forall integer k; l <= k < loop ==> (k % code != 0 ==> ret > 0)) && (\forall integer k; l <= k < loop && k % code == 0 ==> ret >= 0) && (\forall integer k; l <= k < loop && k % code != 0 ==> ret >= 1) && (\forall integer k; l <= k < loop && k % code != 0 ==> ret >= 0) && (\forall integer k; l <= k < loop && k % code != 0 ==> ret > 0) && (\exists integer k; l <= k < loop ==> k % code != 0 || ret == 0) && (\exists integer k; l <= k < loop ==> (k % code != 0 ==> ret >= 1)) && (0 <= ret);
    assigns \nothing;
*/
void check_B_implies_A(int b, int c, int code, int k, int l, int ret) {
    /*@ assert (0 <= ret); */
    /*@ assert (l <= loop); */
    /*@ assert (ret == count_nondiv(code, l, loop - 1)); */
    /*@ assert (ret <= loop - l); */
    /*@ assert (code == \at(code,Pre)); */
    /*@ assert (b == \at(b,Pre)); */
    /*@ assert (c == \at(c,Pre)); */
    /*@ assert (l == \at(l,Pre)); */
}
