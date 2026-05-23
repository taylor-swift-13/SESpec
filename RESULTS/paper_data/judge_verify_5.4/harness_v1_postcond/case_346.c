#include <limits.h>


/*@
predicate divides(integer a, integer b) = a != 0 && b % a == 0;
*/

/*@assigns \nothing;
ensures \result >= 0;*/
int stub_A(int n);

/*@loop invariant n > 0 || max == 0;
            loop invariant n == 0 || n >= 1;
            loop invariant max == 0 || n >= 1;
            loop invariant max == 0 || n > 0;
            loop invariant max == 0 || max >= 2;
            loop invariant max == 0 || max <= n || max <= i;
            loop invariant max == 0 || max <= i;
            loop invariant max == 0 || max % i == 0 || max <= i;
            loop invariant max == 0 || max % 2 == 0 || max >= 2;
            loop invariant max == 0 || \forall integer d; 2 <= d < i ==> n % d != 0 || max >= d;
            loop invariant max == 0 || \forall integer d; 2 <= d < i ==> (n % d != 0 || max >= d);
            loop invariant max == 0 || \exists integer k; 2 <= k <= i && max == k;
            loop invariant max == 0 || (\forall integer d; 2 <= d < i ==> n % d != 0 || max >= d);
            loop invariant max == 0 || (\exists integer k; 2 <= k <= i && max == k);
            loop invariant max <= i;
            loop invariant \forall integer k; 2 <= k < i ==> n % k != 0 || max >= k;
            loop invariant \forall integer d; 2 <= d < i ==> n % d == 0 ==> max >= d;
            loop invariant \forall integer d; 2 <= d < i ==> n % d != 0 || max >= d;
            loop invariant \forall integer d; 2 <= d < i ==> (n % d == 0 ==> max >= d);
            loop invariant \forall integer d; 2 <= d < i ==> (n % d != 0 || max >= d);
            loop invariant 2 <= i;
            loop invariant 1 <= n;
            loop invariant 1 <= i;
            loop invariant 0 <= n;
            loop invariant 0 <= max;
            loop invariant 0 <= i;
            loop invariant 0 < n;
            loop invariant 0 < i;
            loop assigns n;
            loop assigns max;*/
int stub_B(int n);

/*@loop invariant n > 0 || max == 0;
            loop invariant n == 0 || n >= 1;
            loop invariant max == 0 || n >= 1;
            loop invariant max == 0 || n > 0;
            loop invariant max == 0 || max >= 2;
            loop invariant max == 0 || max <= n || max <= i;
            loop invariant max == 0 || max <= i;
            loop invariant max == 0 || max % i == 0 || max <= i;
            loop invariant max == 0 || max % 2 == 0 || max >= 2;
            loop invariant max == 0 || \forall integer d; 2 <= d < i ==> n % d != 0 || max >= d;
            loop invariant max == 0 || \forall integer d; 2 <= d < i ==> (n % d != 0 || max >= d);
            loop invariant max == 0 || \exists integer k; 2 <= k <= i && max == k;
            loop invariant max == 0 || (\forall integer d; 2 <= d < i ==> n % d != 0 || max >= d);
            loop invariant max == 0 || (\exists integer k; 2 <= k <= i && max == k);
            loop invariant max <= i;
            loop invariant \forall integer k; 2 <= k < i ==> n % k != 0 || max >= k;
            loop invariant \forall integer d; 2 <= d < i ==> n % d == 0 ==> max >= d;
            loop invariant \forall integer d; 2 <= d < i ==> n % d != 0 || max >= d;
            loop invariant \forall integer d; 2 <= d < i ==> (n % d == 0 ==> max >= d);
            loop invariant \forall integer d; 2 <= d < i ==> (n % d != 0 || max >= d);
            loop invariant 2 <= i;
            loop invariant 1 <= n;
            loop invariant 1 <= i;
            loop invariant 0 <= n;
            loop invariant 0 <= max;
            loop invariant 0 <= i;
            loop invariant 0 < n;
            loop invariant 0 < i;
            loop assigns n;
            loop assigns max;*/
int check_A_implies_B(int n) {
    return stub_A(n);
}

/*@assigns \nothing;
ensures \result >= 0;*/
int check_B_implies_A(int n) {
    return stub_B(n);
}
