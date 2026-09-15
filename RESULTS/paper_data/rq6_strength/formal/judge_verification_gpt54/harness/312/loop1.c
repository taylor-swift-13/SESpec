#include <limits.h>

/*@ requires (count == \at(count,Pre)) && (diameter == 2 * \at(count,Pre)) && (center == 2 * \at(count,Pre) * (2 * \at(count,Pre))) && (1 <= i) && (0 <= ret) && (ret <= (i - 1) * (2 * \at(count,Pre))) && ((i <= 2 * \at(count,Pre)) ==> (ret >= 0)) && ((i <= 2 * \at(count,Pre)) ==> (ret <= (i - 1) * (2 * \at(count,Pre)))) && ((!(i <= 2 * \at(count,Pre))) ==> (ret <= (2 * \at(count,Pre)) * (2 * \at(count,Pre))));
    assigns \nothing;
*/
void check_A_implies_B(int center, int *count, int *diameter, int *i, int *k, int ret) {
    /*@ assert (ret <= (i - 1) * (2 * count + 1) || 0 <= ret); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (k * k <= center ==> ret >= 0)); */
    /*@ assert (0 <= count || ret <= (i - 1) * (2 * count)); */
    /*@ assert (0 <= count || ret <= (i - 1) * (2 * count + 1)); */
    /*@ assert (diameter == 2 * count); */
    /*@ assert (center == diameter * diameter); */
    /*@ assert (center == 4 * count * count); */
    /*@ assert (\forall integer k; 1 <= k < i ==> ret >= 0); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (k * k + i * i <= center ==> ret >= 1)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (k * k + (2 * count) * (2 * count) >= center)); */
    /*@ assert (1 <= i); */
    /*@ assert (0 <= ret); */
    /*@ assert (0 <= i); */
}

/*@ requires (ret <= (i - 1) * (2 * count + 1) || 0 <= ret) && (\forall integer k; 1 <= k < i ==> (k * k <= center ==> ret >= 0)) && (0 <= count || ret <= (i - 1) * (2 * count)) && (0 <= count || ret <= (i - 1) * (2 * count + 1)) && (diameter == 2 * count) && (center == diameter * diameter) && (center == 4 * count * count) && (\forall integer k; 1 <= k < i ==> ret >= 0) && (\forall integer k; 1 <= k < i ==> (k * k + i * i <= center ==> ret >= 1)) && (\forall integer k; 1 <= k < i ==> (k * k + (2 * count) * (2 * count) >= center)) && (1 <= i) && (0 <= ret) && (0 <= i);
    assigns \nothing;
*/
void check_B_implies_A(int center, int *count, int *diameter, int *i, int *k, int ret) {
    /*@ assert (count == \at(count,Pre)); */
    /*@ assert (diameter == 2 * \at(count,Pre)); */
    /*@ assert (center == 2 * \at(count,Pre) * (2 * \at(count,Pre))); */
    /*@ assert (1 <= i); */
    /*@ assert (0 <= ret); */
    /*@ assert (ret <= (i - 1) * (2 * \at(count,Pre))); */
    /*@ assert ((i <= 2 * \at(count,Pre)) ==> (ret >= 0)); */
    /*@ assert ((i <= 2 * \at(count,Pre)) ==> (ret <= (i - 1) * (2 * \at(count,Pre)))); */
    /*@ assert ((!(i <= 2 * \at(count,Pre))) ==> (ret <= (2 * \at(count,Pre)) * (2 * \at(count,Pre)))); */
}
