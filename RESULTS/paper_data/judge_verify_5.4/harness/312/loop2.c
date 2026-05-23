#include <limits.h>

/*@ requires (0 <= ret) && (1 <= c <= 2 * count + 1) && (ret <= (i - 1) * (2 * count) + (c - 1));
    assigns \nothing;
*/
void check_A_implies_B(int *c, int center, int *count, int *diameter, int *i, int *k, int ret) {
    /*@ assert (ret <= i * c || 0 <= c); */
    /*@ assert (i <= 2 * count + 1); */
    /*@ assert (i - 1 <= 2 * count); */
    /*@ assert (diameter == 2 * count); */
    /*@ assert (center == diameter * diameter); */
    /*@ assert (center == 4 * count * count); */
    /*@ assert (c <= 2 * count + 1); */
    /*@ assert (c - 1 <= 2 * count); */
    /*@ assert (c - 1 <= 2 * count || ret <= i * c); */
    /*@ assert (c - 1 <= 2 * count || ret <= i * (2 * count)); */
    /*@ assert (c - 1 <= 2 * count || ret <= i * (2 * count + 1)); */
    /*@ assert (c - 1 <= 2 * count || ret <= 4 * count * count); */
    /*@ assert (c - 1 <= 2 * count || 0 <= c); */
    /*@ assert (\forall integer k; 1 <= k < i ==> ret >= 0); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (k * k + i * i <= center ==> ret >= 1)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> k * k + i * i <= center ==> ret >= 0); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (k * k + i * i <= center ==> ret >= 1)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (k * k + i * i <= center ==> ret >= 0)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> (i * i + k * k <= center ==> ret >= 1)); */
    /*@ assert (\forall integer k; 1 <= k < c ==> ((i * i + k * k) <= center ==> ret >= 1)); */
    /*@ assert (1 <= i); */
    /*@ assert (1 <= c); */
    /*@ assert (0 <= ret); */
    /*@ assert (0 <= i); */
    /*@ assert (0 <= i || ret <= i * (2 * count)); */
    /*@ assert (0 <= i || ret <= (i - 1) * (2 * count)); */
    /*@ assert (0 <= i || ret <= (i - 1) * (2 * count + 1)); */
    /*@ assert (0 <= c); */
    /*@ assert (0 <= c || ret <= i * (2 * count)); */
    /*@ assert (0 <= c || ret <= i * (2 * count + 1)); */
    /*@ assert (0 <= c || ret <= 4 * count * count); */
    /*@ assert (0 < i); */
    /*@ assert (0 < c); */
}

/*@ requires (ret <= i * c || 0 <= c) && (i <= 2 * count + 1) && (i - 1 <= 2 * count) && (diameter == 2 * count) && (center == diameter * diameter) && (center == 4 * count * count) && (c <= 2 * count + 1) && (c - 1 <= 2 * count) && (c - 1 <= 2 * count || ret <= i * c) && (c - 1 <= 2 * count || ret <= i * (2 * count)) && (c - 1 <= 2 * count || ret <= i * (2 * count + 1)) && (c - 1 <= 2 * count || ret <= 4 * count * count) && (c - 1 <= 2 * count || 0 <= c) && (\forall integer k; 1 <= k < i ==> ret >= 0) && (\forall integer k; 1 <= k < i ==> (k * k + i * i <= center ==> ret >= 1)) && (\forall integer k; 1 <= k < c ==> k * k + i * i <= center ==> ret >= 0) && (\forall integer k; 1 <= k < c ==> (k * k + i * i <= center ==> ret >= 1)) && (\forall integer k; 1 <= k < c ==> (k * k + i * i <= center ==> ret >= 0)) && (\forall integer k; 1 <= k < c ==> (i * i + k * k <= center ==> ret >= 1)) && (\forall integer k; 1 <= k < c ==> ((i * i + k * k) <= center ==> ret >= 1)) && (1 <= i) && (1 <= c) && (0 <= ret) && (0 <= i) && (0 <= i || ret <= i * (2 * count)) && (0 <= i || ret <= (i - 1) * (2 * count)) && (0 <= i || ret <= (i - 1) * (2 * count + 1)) && (0 <= c) && (0 <= c || ret <= i * (2 * count)) && (0 <= c || ret <= i * (2 * count + 1)) && (0 <= c || ret <= 4 * count * count) && (0 < i) && (0 < c);
    assigns \nothing;
*/
void check_B_implies_A(int *c, int center, int *count, int *diameter, int *i, int *k, int ret) {
    /*@ assert (0 <= ret); */
    /*@ assert (1 <= c <= 2 * count + 1); */
    /*@ assert (ret <= (i - 1) * (2 * count) + (c - 1)); */
}
