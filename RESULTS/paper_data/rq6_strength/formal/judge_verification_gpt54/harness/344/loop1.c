#include <limits.h>

/*@ requires (c >= l) && (0 <= ret) && (ret <= c - l) && (m == \at(m,Pre)) && (l == \at(l,Pre)) && (b == \at(b,Pre)) && (code == \at(code,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int b, int c, int code, int k, int l, int m, int ret) {
    /*@ assert (ret < b ==> \exists integer k; l <= k < c && k % code != 0 ==> ret >= 0); */
    /*@ assert (ret < b ==> 0 <= c - l - ret); */
    /*@ assert (ret > 0 ==> l <= c); */
    /*@ assert (ret > 0 ==> l < c); */
    /*@ assert (ret > 0 ==> c > l); */
    /*@ assert (ret > 0 ==> \exists integer k; l <= k < c && k % code != 0); */
    /*@ assert (ret == c - l ==> \forall integer k; l <= k < c ==> k % code != 0); */
    /*@ assert (ret == 0 || ret >= 1); */
    /*@ assert (ret == 0 || ret >= 0); */
    /*@ assert (ret == 0 || ret > 0); */
    /*@ assert (ret == 0 || ret <= c - l); */
    /*@ assert (ret == 0 || ret <= c - l + 1); */
    /*@ assert (ret == 0 || l <= c); */
    /*@ assert (ret == 0 || c > l); */
    /*@ assert (ret == 0 || c - l >= ret); */
    /*@ assert (ret == 0 || c - l >= ret - 1); */
    /*@ assert (ret == 0 || c - l - ret >= 0); */
    /*@ assert (ret == 0 || c - l - ret >= -1); */
    /*@ assert (ret == 0 || c - l - ret <= c - l); */
    /*@ assert (ret == 0 || \forall integer k; l <= k < c ==> (k % code == 0 || k % code != 0)); */
    /*@ assert (ret == 0 || \forall integer k; l <= k < c ==> (k % code != 0 ==> ret >= 1)); */
    /*@ assert (ret == 0 || \forall integer k; l <= k < c ==> (k % code != 0 ==> ret >= 0)); */
    /*@ assert (ret == 0 || \exists integer k; l <= k < c && k % code != 0); */
    /*@ assert (ret == 0 ==> \forall integer k; l <= k < c ==> k % code == 0); */
    /*@ assert (ret <= c - l); */
    /*@ assert (ret <= c - l + 1); */
    /*@ assert (ret < b ==> ret <= c - l); */
    /*@ assert (ret < b ==> ret <= c - l + 1); */
    /*@ assert (ret < b ==> ret <= b); */
    /*@ assert (ret < b ==> ret < c - l + 1); */
    /*@ assert (ret < b ==> ret < b); */
    /*@ assert (ret < b ==> l <= c); */
    /*@ assert (ret < b ==> c - l - ret >= 0); */
    /*@ assert (ret < b ==> \forall integer k; l <= k < c ==> (k % code == 0 || k % code != 0)); */
    /*@ assert (ret < b ==> \forall integer k; l <= k < c ==> (k % code != 0 ==> ret >= 1)); */
    /*@ assert (ret < b ==> \forall integer k; l <= k < c ==> (k % code != 0 ==> ret >= 0)); */
    /*@ assert (ret < b ==> \forall integer k; l <= k < c && k % code != 0 ==> ret >= 1); */
    /*@ assert (ret < b ==> \forall integer k; l <= k < c && k % code != 0 ==> ret >= 0); */
    /*@ assert (ret < b ==> \forall integer k; l <= k < c && k % code != 0 ==> ret < b); */
    /*@ assert (ret < b ==> \forall integer k; l <= k < c && k % code != 0 ==> k < c); */
    /*@ assert (ret < b ==> 0 <= ret); */
    /*@ assert (l <= c); */
    /*@ assert (c - l - ret >= 0 || ret == 0); */
    /*@ assert (c - l - ret <= c - l); */
    /*@ assert (\forall integer k; l <= k < c ==> (k % code == 0 || k % code != 0)); */
    /*@ assert (\forall integer k; l <= k < c ==> (k % code != 0 ==> ret >= 1)); */
    /*@ assert (\forall integer k; l <= k < c ==> (k % code != 0 ==> ret >= 0)); */
    /*@ assert (\forall integer k; l <= k < c && k % code != 0 ==> ret >= 1); */
    /*@ assert (\forall integer k; l <= k < c && k % code != 0 ==> ret >= 0); */
    /*@ assert (\forall integer k; l <= k < c && k % code != 0 ==> 0 <= ret); */
    /*@ assert (0 <= ret); */
    /*@ assert (0 <= c - l); */
    /*@ assert (0 <= c - l - ret); */
    /*@ assert (-1 <= c - l - ret); */
}

/*@ requires (ret < b ==> \exists integer k; l <= k < c && k % code != 0 ==> ret >= 0) && (ret < b ==> 0 <= c - l - ret) && (ret > 0 ==> l <= c) && (ret > 0 ==> l < c) && (ret > 0 ==> c > l) && (ret > 0 ==> \exists integer k; l <= k < c && k % code != 0) && (ret == c - l ==> \forall integer k; l <= k < c ==> k % code != 0) && (ret == 0 || ret >= 1) && (ret == 0 || ret >= 0) && (ret == 0 || ret > 0) && (ret == 0 || ret <= c - l) && (ret == 0 || ret <= c - l + 1) && (ret == 0 || l <= c) && (ret == 0 || c > l) && (ret == 0 || c - l >= ret) && (ret == 0 || c - l >= ret - 1) && (ret == 0 || c - l - ret >= 0) && (ret == 0 || c - l - ret >= -1) && (ret == 0 || c - l - ret <= c - l) && (ret == 0 || \forall integer k; l <= k < c ==> (k % code == 0 || k % code != 0)) && (ret == 0 || \forall integer k; l <= k < c ==> (k % code != 0 ==> ret >= 1)) && (ret == 0 || \forall integer k; l <= k < c ==> (k % code != 0 ==> ret >= 0)) && (ret == 0 || \exists integer k; l <= k < c && k % code != 0) && (ret == 0 ==> \forall integer k; l <= k < c ==> k % code == 0) && (ret <= c - l) && (ret <= c - l + 1) && (ret < b ==> ret <= c - l) && (ret < b ==> ret <= c - l + 1) && (ret < b ==> ret <= b) && (ret < b ==> ret < c - l + 1) && (ret < b ==> ret < b) && (ret < b ==> l <= c) && (ret < b ==> c - l - ret >= 0) && (ret < b ==> \forall integer k; l <= k < c ==> (k % code == 0 || k % code != 0)) && (ret < b ==> \forall integer k; l <= k < c ==> (k % code != 0 ==> ret >= 1)) && (ret < b ==> \forall integer k; l <= k < c ==> (k % code != 0 ==> ret >= 0)) && (ret < b ==> \forall integer k; l <= k < c && k % code != 0 ==> ret >= 1) && (ret < b ==> \forall integer k; l <= k < c && k % code != 0 ==> ret >= 0) && (ret < b ==> \forall integer k; l <= k < c && k % code != 0 ==> ret < b) && (ret < b ==> \forall integer k; l <= k < c && k % code != 0 ==> k < c) && (ret < b ==> 0 <= ret) && (l <= c) && (c - l - ret >= 0 || ret == 0) && (c - l - ret <= c - l) && (\forall integer k; l <= k < c ==> (k % code == 0 || k % code != 0)) && (\forall integer k; l <= k < c ==> (k % code != 0 ==> ret >= 1)) && (\forall integer k; l <= k < c ==> (k % code != 0 ==> ret >= 0)) && (\forall integer k; l <= k < c && k % code != 0 ==> ret >= 1) && (\forall integer k; l <= k < c && k % code != 0 ==> ret >= 0) && (\forall integer k; l <= k < c && k % code != 0 ==> 0 <= ret) && (0 <= ret) && (0 <= c - l) && (0 <= c - l - ret) && (-1 <= c - l - ret);
    assigns \nothing;
*/
void check_B_implies_A(int b, int c, int code, int k, int l, int m, int ret) {
    /*@ assert (c >= l); */
    /*@ assert (0 <= ret); */
    /*@ assert (ret <= c - l); */
    /*@ assert (m == \at(m,Pre)); */
    /*@ assert (l == \at(l,Pre)); */
    /*@ assert (b == \at(b,Pre)); */
    /*@ assert (code == \at(code,Pre)); */
}
