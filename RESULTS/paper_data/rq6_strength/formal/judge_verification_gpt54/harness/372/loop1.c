#include <limits.h>

/*@ requires (div >= 0) && (num == \at(num,Pre)) && ((c <= \at(num,Pre)) ==> (div <= c - 1));
    assigns \nothing;
*/
void check_A_implies_B(int c, int div, int k, int num) {
    /*@ assert (div == 0 || div >= 1); */
    /*@ assert (div == 0 || div >= 0); */
    /*@ assert (div == 0 || div > 0); */
    /*@ assert (div == 0 ==> c == 1); */
    /*@ assert (div <= c); */
    /*@ assert (div <= c - 1); */
    /*@ assert (div <= c - 1 + 1); */
    /*@ assert (c == div || c > div); */
    /*@ assert (c == div + 1 || c > div); */
    /*@ assert (c == 1 ==> div == 0); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (num % k == 0 ==> div >= 1)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (num % k == 0 ==> div >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (num % k == 0 ==> div <= c)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (num % k != 0 || div >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (num % k != 0 || div <= c)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (num % k != 0 ==> div >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (num % k != 0 ==> div <= c)); */
    /*@ assert (\exists integer k; 1 <= k < c && num % k == 0 ==> div >= 1); */
    /*@ assert (\exists integer k; 1 <= k < c && num % k == 0 ==> div >= 0); */
    /*@ assert (\exists integer k; 1 <= k < c && num % k == 0 ==> div > 0); */
    /*@ assert (1 <= c); */
    /*@ assert (1 <= c - div); */
    /*@ assert (0 <= div); */
    /*@ assert (0 <= c); */
    /*@ assert (0 <= c - div); */
    /*@ assert (0 < c); */
}

/*@ requires (div == 0 || div >= 1) && (div == 0 || div >= 0) && (div == 0 || div > 0) && (div == 0 ==> c == 1) && (div <= c) && (div <= c - 1) && (div <= c - 1 + 1) && (c == div || c > div) && (c == div + 1 || c > div) && (c == 1 ==> div == 0) && (\forall integer k; 1 <= k < c ==> (num % k == 0 ==> div >= 1)) && (\forall integer k; 1 <= k < c ==> (num % k == 0 ==> div >= 0)) && (\forall integer k; 1 <= k < c ==> (num % k == 0 ==> div <= c)) && (\forall integer k; 1 <= k < c ==> (num % k != 0 || div >= 0)) && (\forall integer k; 1 <= k < c ==> (num % k != 0 || div <= c)) && (\forall integer k; 1 <= k < c ==> (num % k != 0 ==> div >= 0)) && (\forall integer k; 1 <= k < c ==> (num % k != 0 ==> div <= c)) && (\exists integer k; 1 <= k < c && num % k == 0 ==> div >= 1) && (\exists integer k; 1 <= k < c && num % k == 0 ==> div >= 0) && (\exists integer k; 1 <= k < c && num % k == 0 ==> div > 0) && (1 <= c) && (1 <= c - div) && (0 <= div) && (0 <= c) && (0 <= c - div) && (0 < c);
    assigns \nothing;
*/
void check_B_implies_A(int c, int div, int k, int num) {
    /*@ assert (div >= 0); */
    /*@ assert (num == \at(num,Pre)); */
    /*@ assert ((c <= \at(num,Pre)) ==> (div <= c - 1)); */
}
