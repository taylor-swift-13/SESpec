#include <limits.h>

/*@ requires (2 <= c) && (0 <= result) && (result <= c - 2) && (\forall integer d; 2 <= d < c && number % d == 0 ==> result >= 1) && (\exists integer d; 2 <= d < c && number % d == 0 ==> result > 0) && ((c <= number / c) ==> (result >= 0)) && ((!(c <= number / c)) ==> (result >= 0));
    assigns \nothing;
*/
void check_A_implies_B(int c, int d, int k, int number) {
    /*@ assert (result > 0 ==> \exists integer k; 2 <= k < c ==> number % k == 0); */
    /*@ assert (\forall integer k; 2 <= k < c ==> number % k == 0 ==> result >= 1); */
    /*@ assert (result > 0 ==> \exists integer k; 2 <= k < c && number % k == 0); */
    /*@ assert (result == 0 || result >= 1); */
    /*@ assert (result == 0 || result > 0); */
    /*@ assert (result == 0 ==> \forall integer k; 2 <= k < c ==> number % k != 0); */
    /*@ assert (result <= c); */
    /*@ assert (result <= c - 2); */
    /*@ assert (result <= c - 2 ==> result >= 0); */
    /*@ assert (result <= c - 1); */
    /*@ assert (\forall integer k; 2 <= k < c ==> number % k != 0 || result >= 1); */
    /*@ assert (\forall integer k; 2 <= k < c ==> number % k != 0 ==> result >= 0); */
    /*@ assert (\forall integer k; 2 <= k < c ==> number % k != 0 ==> result == 0 || result >= 0); */
    /*@ assert (\forall integer k; 2 <= k < c ==> (number % k == 0 ==> result >= 1)); */
    /*@ assert (\forall integer k; 2 <= k < c ==> (number % k == 0 ==> result >= 0)); */
    /*@ assert (\forall integer k; 2 <= k < c ==> (number % k == 0 ==> result > 0)); */
    /*@ assert (\forall integer k; 2 <= k < c ==> (number % k != 0 || result >= 1)); */
    /*@ assert (\forall integer k; 2 <= k < c ==> (number % k != 0 || result >= 0)); */
    /*@ assert (\forall integer k; 2 <= k < c ==> (number % k != 0 ==> result >= 0)); */
    /*@ assert (\forall integer k; 2 <= k < c ==> (number % k != 0 ==> result == 0 || result >= 0)); */
    /*@ assert (\forall integer k; 2 <= k < c ==> (number % k != 0 ==> result == 0 || result > 0)); */
    /*@ assert (\forall integer k; 2 <= k < c && k <= number / k ==> (number % k == 0 ==> result >= 1)); */
    /*@ assert (\forall integer k; 2 <= k < c && k <= number / k ==> (number % k != 0 || result >= 1)); */
    /*@ assert (\exists integer k; 2 <= k < c && number % k == 0 ==> result >= 1); */
    /*@ assert (\exists integer k; 2 <= k < c && number % k == 0 ==> result > 0); */
    /*@ assert (2 <= c); */
    /*@ assert (0 <= result); */
}

/*@ requires (result > 0 ==> \exists integer k; 2 <= k < c ==> number % k == 0) && (\forall integer k; 2 <= k < c ==> number % k == 0 ==> result >= 1) && (result > 0 ==> \exists integer k; 2 <= k < c && number % k == 0) && (result == 0 || result >= 1) && (result == 0 || result > 0) && (result == 0 ==> \forall integer k; 2 <= k < c ==> number % k != 0) && (result <= c) && (result <= c - 2) && (result <= c - 2 ==> result >= 0) && (result <= c - 1) && (\forall integer k; 2 <= k < c ==> number % k != 0 || result >= 1) && (\forall integer k; 2 <= k < c ==> number % k != 0 ==> result >= 0) && (\forall integer k; 2 <= k < c ==> number % k != 0 ==> result == 0 || result >= 0) && (\forall integer k; 2 <= k < c ==> (number % k == 0 ==> result >= 1)) && (\forall integer k; 2 <= k < c ==> (number % k == 0 ==> result >= 0)) && (\forall integer k; 2 <= k < c ==> (number % k == 0 ==> result > 0)) && (\forall integer k; 2 <= k < c ==> (number % k != 0 || result >= 1)) && (\forall integer k; 2 <= k < c ==> (number % k != 0 || result >= 0)) && (\forall integer k; 2 <= k < c ==> (number % k != 0 ==> result >= 0)) && (\forall integer k; 2 <= k < c ==> (number % k != 0 ==> result == 0 || result >= 0)) && (\forall integer k; 2 <= k < c ==> (number % k != 0 ==> result == 0 || result > 0)) && (\forall integer k; 2 <= k < c && k <= number / k ==> (number % k == 0 ==> result >= 1)) && (\forall integer k; 2 <= k < c && k <= number / k ==> (number % k != 0 || result >= 1)) && (\exists integer k; 2 <= k < c && number % k == 0 ==> result >= 1) && (\exists integer k; 2 <= k < c && number % k == 0 ==> result > 0) && (2 <= c) && (0 <= result);
    assigns \nothing;
*/
void check_B_implies_A(int c, int d, int k, int number) {
    /*@ assert (2 <= c); */
    /*@ assert (0 <= result); */
    /*@ assert (result <= c - 2); */
    /*@ assert (\forall integer d; 2 <= d < c && number % d == 0 ==> result >= 1); */
    /*@ assert (\exists integer d; 2 <= d < c && number % d == 0 ==> result > 0); */
    /*@ assert ((c <= number / c) ==> (result >= 0)); */
    /*@ assert ((!(c <= number / c)) ==> (result >= 0)); */
}
