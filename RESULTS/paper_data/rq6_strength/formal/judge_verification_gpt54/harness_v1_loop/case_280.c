#include <limits.h>

/*@logic integer count_div(int n, integer lo, integer hi) =
    lo >= hi ? 0
             : count_div(n, lo, hi - 1) + ((n % (hi - 1)) == 0 ? 1 : 0);*/

/*@ requires (1 <= c) && (c <= number + 1) && (number == \at(number, Pre)) && (0 <= result <= c - 1) && (result == count_div(number, 1, c)) && (\forall integer k) && (\forall integer k) && ((c > number) ==> (result == count_div(number, 1, number + 1))) && ((c > number) ==> (number == \at(number, Pre)));
    assigns \nothing;
*/
void check_A_implies_B(int c, int k, int number) {
    /*@ assert (result > 0 ==> c > 1) && (result > 0 ==> \exists integer k) && (result == 0 || result >= 1) && (result == 0 || result > 0) && (result == 0 ==> c == 1) && (result == 0 ==> \forall integer k) && (result <= c) && (result <= c - 1) && (result <= c - 1 || result == c) && (result % 2 == 0 || result % 2 == 1) && (c > 1 ==> result >= 1) && (c > 1 ==> result >= 1 || result == 0) && (c > 1 ==> result >= 0) && (c > 1 ==> result <= number) && (c > 1 ==> result <= c) && (c > 1 ==> result <= c - 1) && (c > 1 ==> \forall integer k) && (c > 1 ==> \exists integer k) && (c == result + 1 || c > result) && (c == 1 ==> result == 0) && (c == 1 + result || c > result) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (1 <= c) && (1 <= c - result) && (0 <= result) && (0 <= c) && (0 <= c - result) && (0 < c) && (0 < c || c <= number + 1); */
}

/*@ requires (result > 0 ==> c > 1) && (result > 0 ==> \exists integer k) && (result == 0 || result >= 1) && (result == 0 || result > 0) && (result == 0 ==> c == 1) && (result == 0 ==> \forall integer k) && (result <= c) && (result <= c - 1) && (result <= c - 1 || result == c) && (result % 2 == 0 || result % 2 == 1) && (c > 1 ==> result >= 1) && (c > 1 ==> result >= 1 || result == 0) && (c > 1 ==> result >= 0) && (c > 1 ==> result <= number) && (c > 1 ==> result <= c) && (c > 1 ==> result <= c - 1) && (c > 1 ==> \forall integer k) && (c > 1 ==> \exists integer k) && (c == result + 1 || c > result) && (c == 1 ==> result == 0) && (c == 1 + result || c > result) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (\exists integer k) && (1 <= c) && (1 <= c - result) && (0 <= result) && (0 <= c) && (0 <= c - result) && (0 < c) && (0 < c || c <= number + 1);
    assigns \nothing;
*/
void check_B_implies_A(int c, int k, int number) {
    /*@ assert (1 <= c) && (c <= number + 1) && (number == \at(number, Pre)) && (0 <= result <= c - 1) && (result == count_div(number, 1, c)) && (\forall integer k) && (\forall integer k) && ((c > number) ==> (result == count_div(number, 1, number + 1))) && ((c > number) ==> (number == \at(number, Pre))); */
}
