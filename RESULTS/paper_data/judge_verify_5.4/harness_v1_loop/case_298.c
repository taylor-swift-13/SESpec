#include <limits.h>

/*@logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);*/

/*@ requires ((\at(leftElement,Pre) <= \at(rightElement,Pre)) ==> (((j == \at(rightElement,Pre))&&(i == \at(leftElement,Pre))&&(rightElement == \at(rightElement,Pre))&&(leftElement == \at(leftElement,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (leftElement <= i))) && ((\at(leftElement,Pre) <= \at(rightElement,Pre)) ==> (((j == \at(rightElement,Pre))&&(i == \at(leftElement,Pre))&&(rightElement == \at(rightElement,Pre))&&(leftElement == \at(leftElement,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (j <= rightElement))) && ((!(\at(leftElement,Pre) <= \at(rightElement,Pre))) ==> ((j == \at(rightElement,Pre))&&(i == \at(leftElement,Pre))&&(rightElement == \at(rightElement,Pre))&&(leftElement == \at(leftElement,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre)))) && (rightElement == \at(rightElement,Pre)) && (leftElement == \at(leftElement,Pre)) && (a_len == \at(a_len,Pre)) && (a == \at(a,Pre)) && (\forall integer k);
    assigns \nothing;
*/
void check_A_implies_B(int a, int a_len, int i, int j, int k, int leftElement, int rightElement) {
    /*@ assert (leftElement <= i) && (j <= rightElement); */
}

/*@ requires (leftElement <= i) && (j <= rightElement);
    assigns \nothing;
*/
void check_B_implies_A(int a, int a_len, int i, int j, int k, int leftElement, int rightElement) {
    /*@ assert ((\at(leftElement,Pre) <= \at(rightElement,Pre)) ==> (((j == \at(rightElement,Pre))&&(i == \at(leftElement,Pre))&&(rightElement == \at(rightElement,Pre))&&(leftElement == \at(leftElement,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (leftElement <= i))) && ((\at(leftElement,Pre) <= \at(rightElement,Pre)) ==> (((j == \at(rightElement,Pre))&&(i == \at(leftElement,Pre))&&(rightElement == \at(rightElement,Pre))&&(leftElement == \at(leftElement,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (j <= rightElement))) && ((!(\at(leftElement,Pre) <= \at(rightElement,Pre))) ==> ((j == \at(rightElement,Pre))&&(i == \at(leftElement,Pre))&&(rightElement == \at(rightElement,Pre))&&(leftElement == \at(leftElement,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre)))) && (rightElement == \at(rightElement,Pre)) && (leftElement == \at(leftElement,Pre)) && (a_len == \at(a_len,Pre)) && (a == \at(a,Pre)) && (\forall integer k); */
}
