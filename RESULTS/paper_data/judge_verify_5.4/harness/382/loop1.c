#include <limits.h>

/*@ requires (0 <= max) && (max <= i) && (max == 0 || (1 <= max && max <= \at(n,Pre))) && (max == 0 || ((max % x) == y)) && (\forall integer k; 1 <= k < i && ((k % x) == y) ==> k <= max) && (\forall integer k; 1 <= k < i && ((k % x) == y) ==> k <= \at(n,Pre)) && (max == 0 || ((max % x) == y)) && (y == \at(y,Pre)) && (x == \at(x,Pre)) && (n == \at(n,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int i, int k, int n, int x, int y) {
    /*@ assert (max == 0 || max >= 1); */
    /*@ assert (max == 0 || max == i || max < i); */
    /*@ assert (max == 0 || max == i || (max % x) == y); */
    /*@ assert (max == 0 || max == i - 1 || max <= i); */
    /*@ assert (max == 0 || max <= n); */
    /*@ assert (max == 0 || max <= i); */
    /*@ assert (max == 0 || max <= i-1); */
    /*@ assert (max == 0 || max <= i - 1); */
    /*@ assert (max == 0 || max <= i + 1); */
    /*@ assert (max == 0 || max < i); */
    /*@ assert (max == 0 || max < i || max == i-1); */
    /*@ assert (max == 0 || max < i + 1); */
    /*@ assert (max == 0 || max % x == y); */
    /*@ assert (max == 0 || max % x == y || max == i); */
    /*@ assert (max == 0 || \forall integer k; 1 <= k < i ==> (k % x) != y || k <= max); */
    /*@ assert (max == 0 || \forall integer k; 1 <= k < i ==> ((k % x) == y ==> k <= max)); */
    /*@ assert (max == 0 || \forall integer k; 1 <= k < i && (k % x) == y ==> k <= max); */
    /*@ assert (max == 0 || \exists integer k; 1 <= k <= i && (k % x) == y && max == k); */
    /*@ assert (max == 0 || \exists integer k; 1 <= k < i && (k % x) == y && max == k); */
    /*@ assert (max == 0 || 1 <= max <= n); */
    /*@ assert (max == 0 || 1 <= max <= i); */
    /*@ assert (max == 0 || 0 <= max <= n); */
    /*@ assert (max == 0 || (max == i-1 || max < i)); */
    /*@ assert (max == 0 || (max == i || max < i)); */
    /*@ assert (max == 0 || (max == i - 1 || max <= i)); */
    /*@ assert (max == 0 || (max <= n)); */
    /*@ assert (max == 0 || (max <= i)); */
    /*@ assert (max == 0 || (max <= i - 1)); */
    /*@ assert (max == 0 || (max % x) == y); */
    /*@ assert (max == 0 || (max % x) == y || max == i); */
    /*@ assert (max == 0 || (max % x) == y || max == i - 1); */
    /*@ assert (max == 0 || (max % x == y)); */
    /*@ assert (max == 0 || (\forall integer k; 1 <= k < i ==> (k % x) != y || k <= max)); */
    /*@ assert (max == 0 || (\forall integer k; 1 <= k < i && (k % x) == y ==> k <= max)); */
    /*@ assert (max == 0 || (\exists integer k; 1 <= k <= i && (k % x) == y && max == k)); */
    /*@ assert (max == 0 || (\exists integer k; 1 <= k < i && (k % x) == y && max == k)); */
    /*@ assert (max == 0 || (1 <= max <= n)); */
    /*@ assert (max == 0 || (1 <= max <= i)); */
    /*@ assert (max == 0 || (1 <= max <= i && (max % x) == y)); */
    /*@ assert (max == 0 || (1 <= max < i && (max % x) == y)); */
    /*@ assert (max == 0 || (1 <= max && max <= i)); */
    /*@ assert (max == 0 || ((max % x) == y)); */
    /*@ assert (max <= i); */
    /*@ assert (max <= i-1); */
    /*@ assert (max <= i - 1); */
    /*@ assert (\forall integer k; 1 <= k <= i ==> max >= 0); */
    /*@ assert (\forall integer k; 1 <= k < i ==> max >= 0); */
    /*@ assert (\forall integer k; 1 <= k < i ==> k <= i); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (k % x) == y ==> max >= k); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (k % x) == y ==> k <= max); */
    /*@ assert (\forall integer k; 1 <= k < i ==> (k % x) != y || k <= max); */
    /*@ assert (\forall integer k; 1 <= k < i ==> ((k % x) == y ==> k <= max)); */
    /*@ assert (\forall integer k; 1 <= k < i ==> ((k % x) != y || k <= max)); */
    /*@ assert (\forall integer k; 1 <= k < i && (k % x) == y ==> max >= k); */
    /*@ assert (\forall integer k; 1 <= k < i && (k % x) == y ==> k <= max); */
    /*@ assert (\forall integer k; 1 <= k < i && (k % x) == y ==> k <= max || max == 0); */
    /*@ assert (\forall integer k; 1 <= k < i && (k % x == y) ==> max >= k); */
    /*@ assert (\exists integer k; 1 <= k <= i && (k % x) == y ==> max >= k); */
    /*@ assert (\exists integer k; 1 <= k < i && (k % x) == y ==> max == k); */
    /*@ assert (1 <= i); */
    /*@ assert (0 <= max); */
    /*@ assert (0 <= i); */
}

/*@ requires (max == 0 || max >= 1) && (max == 0 || max == i || max < i) && (max == 0 || max == i || (max % x) == y) && (max == 0 || max == i - 1 || max <= i) && (max == 0 || max <= n) && (max == 0 || max <= i) && (max == 0 || max <= i-1) && (max == 0 || max <= i - 1) && (max == 0 || max <= i + 1) && (max == 0 || max < i) && (max == 0 || max < i || max == i-1) && (max == 0 || max < i + 1) && (max == 0 || max % x == y) && (max == 0 || max % x == y || max == i) && (max == 0 || \forall integer k; 1 <= k < i ==> (k % x) != y || k <= max) && (max == 0 || \forall integer k; 1 <= k < i ==> ((k % x) == y ==> k <= max)) && (max == 0 || \forall integer k; 1 <= k < i && (k % x) == y ==> k <= max) && (max == 0 || \exists integer k; 1 <= k <= i && (k % x) == y && max == k) && (max == 0 || \exists integer k; 1 <= k < i && (k % x) == y && max == k) && (max == 0 || 1 <= max <= n) && (max == 0 || 1 <= max <= i) && (max == 0 || 0 <= max <= n) && (max == 0 || (max == i-1 || max < i)) && (max == 0 || (max == i || max < i)) && (max == 0 || (max == i - 1 || max <= i)) && (max == 0 || (max <= n)) && (max == 0 || (max <= i)) && (max == 0 || (max <= i - 1)) && (max == 0 || (max % x) == y) && (max == 0 || (max % x) == y || max == i) && (max == 0 || (max % x) == y || max == i - 1) && (max == 0 || (max % x == y)) && (max == 0 || (\forall integer k; 1 <= k < i ==> (k % x) != y || k <= max)) && (max == 0 || (\forall integer k; 1 <= k < i && (k % x) == y ==> k <= max)) && (max == 0 || (\exists integer k; 1 <= k <= i && (k % x) == y && max == k)) && (max == 0 || (\exists integer k; 1 <= k < i && (k % x) == y && max == k)) && (max == 0 || (1 <= max <= n)) && (max == 0 || (1 <= max <= i)) && (max == 0 || (1 <= max <= i && (max % x) == y)) && (max == 0 || (1 <= max < i && (max % x) == y)) && (max == 0 || (1 <= max && max <= i)) && (max == 0 || ((max % x) == y)) && (max <= i) && (max <= i-1) && (max <= i - 1) && (\forall integer k; 1 <= k <= i ==> max >= 0) && (\forall integer k; 1 <= k < i ==> max >= 0) && (\forall integer k; 1 <= k < i ==> k <= i) && (\forall integer k; 1 <= k < i ==> (k % x) == y ==> max >= k) && (\forall integer k; 1 <= k < i ==> (k % x) == y ==> k <= max) && (\forall integer k; 1 <= k < i ==> (k % x) != y || k <= max) && (\forall integer k; 1 <= k < i ==> ((k % x) == y ==> k <= max)) && (\forall integer k; 1 <= k < i ==> ((k % x) != y || k <= max)) && (\forall integer k; 1 <= k < i && (k % x) == y ==> max >= k) && (\forall integer k; 1 <= k < i && (k % x) == y ==> k <= max) && (\forall integer k; 1 <= k < i && (k % x) == y ==> k <= max || max == 0) && (\forall integer k; 1 <= k < i && (k % x == y) ==> max >= k) && (\exists integer k; 1 <= k <= i && (k % x) == y ==> max >= k) && (\exists integer k; 1 <= k < i && (k % x) == y ==> max == k) && (1 <= i) && (0 <= max) && (0 <= i);
    assigns \nothing;
*/
void check_B_implies_A(int i, int k, int n, int x, int y) {
    /*@ assert (0 <= max); */
    /*@ assert (max <= i); */
    /*@ assert (max == 0 || (1 <= max && max <= \at(n,Pre))); */
    /*@ assert (max == 0 || ((max % x) == y)); */
    /*@ assert (\forall integer k; 1 <= k < i && ((k % x) == y) ==> k <= max); */
    /*@ assert (\forall integer k; 1 <= k < i && ((k % x) == y) ==> k <= \at(n,Pre)); */
    /*@ assert (max == 0 || ((max % x) == y)); */
    /*@ assert (y == \at(y,Pre)); */
    /*@ assert (x == \at(x,Pre)); */
    /*@ assert (n == \at(n,Pre)); */
}
