#include <limits.h>

/*@ requires (\forall integer k; 2 <= k < i ==> a % k != 0) && (\forall integer k; 2 <= k < i ==> k <= mid) && (mid < 2 || i <= mid + 1) && (i > mid ==> \forall integer k; 2 <= k <= mid ==> a % k != 0) && ((2 <= \at(a,Pre) / 2) ==> (\forall integer k; 2 <= k < i ==> a % k != 0)) && ((2 <= \at(a,Pre) / 2) ==> (2 <= i)) && ((!(2 <= \at(a,Pre) / 2)) ==> ((mid == \at(a,Pre) / 2)&&(i == 2)&&(a == \at(a,Pre)))) && (mid == \at(a,Pre) / 2) && (a == \at(a,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int a, int i, int k, int mid) {
    /*@ assert (a > 1 ==> i == 2 || \forall integer k; 2 <= k < i ==> a % k != 0); */
    /*@ assert (mid == a / 2); */
    /*@ assert (mid == a / 2 && i >= 2); */
    /*@ assert (mid == a / 2 && 2 <= i); */
    /*@ assert (i >= 2 && mid == a / 2); */
    /*@ assert (i > 2 ==> \forall integer k; 2 <= k < i ==> a % k != 0); */
    /*@ assert (i == 2 || i > 2); */
    /*@ assert (i == 2 || a % 2 != 0); */
    /*@ assert (i == 2 || \forall integer k; 2 <= k < i ==> a % k != 0); */
    /*@ assert (i == 2 || (i > 2 && \forall integer k; 2 <= k < i ==> a % k != 0)); */
    /*@ assert (i == 2 || (2 <= i && \forall integer k; 2 <= k < i ==> a % k != 0)); */
    /*@ assert (i % 2 == 0 || i % 2 == 1); */
    /*@ assert (a >= 0 ==> mid >= 0); */
    /*@ assert (a >= 0 ==> mid == a / 2); */
    /*@ assert (a > 1 ==> mid >= 1); */
    /*@ assert (a > 1 ==> mid == a / 2); */
    /*@ assert (a > 1 ==> i >= 2); */
    /*@ assert (a > 1 ==> i >= 2 && i <= mid + 1); */
    /*@ assert (a > 1 ==> i > 1); */
    /*@ assert (a > 1 ==> i == 2 || i > 2); */
    /*@ assert (a > 1 ==> i == 2 || (2 <= i && \forall integer k; 2 <= k < i ==> a % k != 0)); */
    /*@ assert (a > 1 ==> i <= mid + 1); */
    /*@ assert (a > 1 ==> i <= mid + 1 && mid == a / 2); */
    /*@ assert (a > 1 ==> i <= a / 2 + 1); */
    /*@ assert (a > 1 ==> i % 2 == 0 || i % 2 == 1); */
    /*@ assert (a > 1 ==> a % 2 != 0 || i == 2); */
    /*@ assert (a > 1 ==> \forall integer k; 2 <= k < i ==> a % k != 0); */
    /*@ assert (a > 1 ==> 2 <= i); */
    /*@ assert (a > 1 ==> 2 <= i <= mid + 1); */
    /*@ assert (a > 1 ==> 2 <= i <= a / 2 + 1); */
    /*@ assert (a > 1 ==> (i == 2 || i > 2)); */
    /*@ assert (a == a); */
    /*@ assert (a % i != 0 ==> \forall integer k; 2 <= k < i ==> a % k != 0); */
    /*@ assert (a % 2 != 0 || i == 2); */
    /*@ assert (a % 2 != 0 ==> i >= 2); */
    /*@ assert (a % 2 != 0 ==> i == 2 || i > 2); */
    /*@ assert (a % 2 != 0 ==> i == 2 || \forall integer k; 2 <= k < i ==> a % k != 0); */
    /*@ assert (\forall integer k; 2 <= k < i ==> a % k != 0); */
    /*@ assert (\forall integer k; 2 <= k < i ==> a % k != 0 || i == 2); */
    /*@ assert (\forall integer k; 2 <= k < i ==> a % k != 0 && mid == a / 2); */
    /*@ assert (\forall integer k; 2 <= k < i ==> a % k != 0 && i >= 2); */
    /*@ assert (\forall integer k; 2 <= k < i ==> a % k != 0 && i <= mid + 1); */
    /*@ assert (\forall integer k; 2 <= k < i ==> (a % k != 0) || (k == i)); */
    /*@ assert (2 <= i); */
    /*@ assert ((i > 2) ==> \forall integer k; 2 <= k < i ==> a % k != 0); */
}

/*@ requires (a > 1 ==> i == 2 || \forall integer k; 2 <= k < i ==> a % k != 0) && (mid == a / 2) && (mid == a / 2 && i >= 2) && (mid == a / 2 && 2 <= i) && (i >= 2 && mid == a / 2) && (i > 2 ==> \forall integer k; 2 <= k < i ==> a % k != 0) && (i == 2 || i > 2) && (i == 2 || a % 2 != 0) && (i == 2 || \forall integer k; 2 <= k < i ==> a % k != 0) && (i == 2 || (i > 2 && \forall integer k; 2 <= k < i ==> a % k != 0)) && (i == 2 || (2 <= i && \forall integer k; 2 <= k < i ==> a % k != 0)) && (i % 2 == 0 || i % 2 == 1) && (a >= 0 ==> mid >= 0) && (a >= 0 ==> mid == a / 2) && (a > 1 ==> mid >= 1) && (a > 1 ==> mid == a / 2) && (a > 1 ==> i >= 2) && (a > 1 ==> i >= 2 && i <= mid + 1) && (a > 1 ==> i > 1) && (a > 1 ==> i == 2 || i > 2) && (a > 1 ==> i == 2 || (2 <= i && \forall integer k; 2 <= k < i ==> a % k != 0)) && (a > 1 ==> i <= mid + 1) && (a > 1 ==> i <= mid + 1 && mid == a / 2) && (a > 1 ==> i <= a / 2 + 1) && (a > 1 ==> i % 2 == 0 || i % 2 == 1) && (a > 1 ==> a % 2 != 0 || i == 2) && (a > 1 ==> \forall integer k; 2 <= k < i ==> a % k != 0) && (a > 1 ==> 2 <= i) && (a > 1 ==> 2 <= i <= mid + 1) && (a > 1 ==> 2 <= i <= a / 2 + 1) && (a > 1 ==> (i == 2 || i > 2)) && (a == a) && (a % i != 0 ==> \forall integer k; 2 <= k < i ==> a % k != 0) && (a % 2 != 0 || i == 2) && (a % 2 != 0 ==> i >= 2) && (a % 2 != 0 ==> i == 2 || i > 2) && (a % 2 != 0 ==> i == 2 || \forall integer k; 2 <= k < i ==> a % k != 0) && (\forall integer k; 2 <= k < i ==> a % k != 0) && (\forall integer k; 2 <= k < i ==> a % k != 0 || i == 2) && (\forall integer k; 2 <= k < i ==> a % k != 0 && mid == a / 2) && (\forall integer k; 2 <= k < i ==> a % k != 0 && i >= 2) && (\forall integer k; 2 <= k < i ==> a % k != 0 && i <= mid + 1) && (\forall integer k; 2 <= k < i ==> (a % k != 0) || (k == i)) && (2 <= i) && ((i > 2) ==> \forall integer k; 2 <= k < i ==> a % k != 0);
    assigns \nothing;
*/
void check_B_implies_A(int a, int i, int k, int mid) {
    /*@ assert (\forall integer k; 2 <= k < i ==> a % k != 0); */
    /*@ assert (\forall integer k; 2 <= k < i ==> k <= mid); */
    /*@ assert (mid < 2 || i <= mid + 1); */
    /*@ assert (i > mid ==> \forall integer k; 2 <= k <= mid ==> a % k != 0); */
    /*@ assert ((2 <= \at(a,Pre) / 2) ==> (\forall integer k; 2 <= k < i ==> a % k != 0)); */
    /*@ assert ((2 <= \at(a,Pre) / 2) ==> (2 <= i)); */
    /*@ assert ((!(2 <= \at(a,Pre) / 2)) ==> ((mid == \at(a,Pre) / 2)&&(i == 2)&&(a == \at(a,Pre)))); */
    /*@ assert (mid == \at(a,Pre) / 2); */
    /*@ assert (a == \at(a,Pre)); */
}
