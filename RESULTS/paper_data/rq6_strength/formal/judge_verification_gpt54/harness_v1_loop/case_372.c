#include <limits.h>

/*@ requires (div >= 0) && (num == \at(num,Pre)) && ((c <= \at(num,Pre)) ==> (div <= c - 1));
    assigns \nothing;
*/
void check_A_implies_B(int c, int div, int k, int num) {
    /*@ assert (div == 0 || div >= 1) && (div == 0 || div >= 0) && (div == 0 || div > 0) && (div == 0 ==> c == 1) && (div <= c) && (div <= c - 1) && (div <= c - 1 + 1) && (c == div || c > div) && (c == div + 1 || c > div) && (c == 1 ==> div == 0) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (1 <= c) && (1 <= c - div) && (0 <= div) && (0 <= c) && (0 <= c - div) && (0 < c); */
}

/*@ requires (div == 0 || div >= 1) && (div == 0 || div >= 0) && (div == 0 || div > 0) && (div == 0 ==> c == 1) && (div <= c) && (div <= c - 1) && (div <= c - 1 + 1) && (c == div || c > div) && (c == div + 1 || c > div) && (c == 1 ==> div == 0) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (1 <= c) && (1 <= c - div) && (0 <= div) && (0 <= c) && (0 <= c - div) && (0 < c);
    assigns \nothing;
*/
void check_B_implies_A(int c, int div, int k, int num) {
    /*@ assert (div >= 0) && (num == \at(num,Pre)) && ((c <= \at(num,Pre)) ==> (div <= c - 1)); */
}
