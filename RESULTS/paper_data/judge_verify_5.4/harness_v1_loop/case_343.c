#include <limits.h>

/*@logic integer count_nondiv(integer code, integer l, integer i) =
      i < l ? 0 : count_nondiv(code, l, i - 1) + (i % code != 0 ? 1 : 0);*/

/*@ requires (0 <= ret) && (l <= loop) && (ret == count_nondiv(code, l, loop - 1)) && (ret <= loop - l) && (code == \at(code,Pre)) && (b == \at(b,Pre)) && (c == \at(c,Pre)) && (l == \at(l,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int b, int c, int code, int k, int l, int ret) {
    /*@ assert (ret > 0 ==> loop > l) && (ret > 0 ==> l < loop) && (ret > 0 ==> \exists integer k) && (ret > 0 ==> \exists integer k) && (ret == 0 || ret >= 1) && (ret == 0 || ret > 0) && (ret == 0 || ret == 1 || ret > 1) && (ret == 0 ==> loop == l || \forall integer k) && (ret == 0 ==> \forall integer k) && (ret == 0 ==> \forall integer k) && (ret <= loop - l) && (ret <= loop - l + 1) && (ret <= b ==> ret <= loop - l) && (ret <= b ==> ret <= loop - l + 1) && (ret < b ==> ret >= 0) && (ret < b ==> ret <= loop - l) && (ret < b ==> ret <= b) && (ret < b ==> ret < loop - l + 1) && (ret < b ==> ret < b + 1) && (ret < b ==> loop == l + ret || loop > l) && (ret < b ==> \forall integer k) && (ret < b ==> \forall integer k) && (ret < b ==> \forall integer k) && (loop == l ==> ret == 0) && (loop == l + ret || loop > l) && (l <= loop) && (l <= loop - ret) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (0 <= ret); */
}

/*@ requires (ret > 0 ==> loop > l) && (ret > 0 ==> l < loop) && (ret > 0 ==> \exists integer k) && (ret > 0 ==> \exists integer k) && (ret == 0 || ret >= 1) && (ret == 0 || ret > 0) && (ret == 0 || ret == 1 || ret > 1) && (ret == 0 ==> loop == l || \forall integer k) && (ret == 0 ==> \forall integer k) && (ret == 0 ==> \forall integer k) && (ret <= loop - l) && (ret <= loop - l + 1) && (ret <= b ==> ret <= loop - l) && (ret <= b ==> ret <= loop - l + 1) && (ret < b ==> ret >= 0) && (ret < b ==> ret <= loop - l) && (ret < b ==> ret <= b) && (ret < b ==> ret < loop - l + 1) && (ret < b ==> ret < b + 1) && (ret < b ==> loop == l + ret || loop > l) && (ret < b ==> \forall integer k) && (ret < b ==> \forall integer k) && (ret < b ==> \forall integer k) && (loop == l ==> ret == 0) && (loop == l + ret || loop > l) && (l <= loop) && (l <= loop - ret) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (0 <= ret);
    assigns \nothing;
*/
void check_B_implies_A(int b, int c, int code, int k, int l, int ret) {
    /*@ assert (0 <= ret) && (l <= loop) && (ret == count_nondiv(code, l, loop - 1)) && (ret <= loop - l) && (code == \at(code,Pre)) && (b == \at(b,Pre)) && (c == \at(c,Pre)) && (l == \at(l,Pre)); */
}
