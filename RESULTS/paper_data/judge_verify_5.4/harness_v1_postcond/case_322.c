#include <limits.h>



/*@assigns \nothing;
   ensures (\old(x) > \old(y)) ==> \true;
   ensures (\old(x) <= \old(y)) ==> (x == \old(x) && y == \old(y));
   ensures (\old(x) <= 0 || \old(y) <= 0) ==> \true;
   ensures (\old(x) > 0 && \old(y) > 0) ==> \result >= 1;
   ensures (\old(x) > 0 && \old(y) > 0) ==> \true;
   ensures (\old(x) > 0 && \old(y) > 0) ==> \true;
   ensures \result == \old(x) * \old(y) || \result < \old(x) * \old(y) || \result > \old(x) * \old(y);*/
int stub_A(int x, int y);

/*@loop invariant \forall integer k; 1 <= k < i ==> (!(x % k == 0 && y % k == 0) || k <= gcd);
        loop invariant y > 0 ==> gcd <= y;
        loop invariant y % gcd == 0;
        loop invariant y % gcd == 0 || gcd == 1;
        loop invariant x > 0 ==> y > 0;
        loop invariant x > 0 ==> gcd >= 1;
        loop invariant x > 0 ==> gcd <= x;
        loop invariant x <= y;
        loop invariant x <= y || y <= x;
        loop invariant x % gcd == 0;
        loop invariant x % gcd == 0 || y % gcd == 0;
        loop invariant x % gcd == 0 || gcd == 1;
        loop invariant x % gcd == 0 && y % gcd == 0;
        loop invariant i <= x + 1 || 0 < gcd;
        loop invariant gcd == 1 || y % gcd == 0;
        loop invariant gcd == 1 || x % gcd == 0;
        loop invariant gcd == 1 || x % gcd == 0 || y % gcd == 0;
        loop invariant gcd == 1 || gcd >= 1;
        loop invariant gcd == 1 || gcd == i - 1 || gcd <= i;
        loop invariant gcd == 1 || gcd <= y;
        loop invariant gcd == 1 || gcd <= x;
        loop invariant gcd == 1 || gcd <= x && gcd <= y;
        loop invariant gcd == 1 || gcd <= i;
        loop invariant gcd == 1 || gcd <= i - 1;
        loop invariant gcd == 1 || gcd % 1 == 0;
        loop invariant gcd == 1 || \forall integer k; 1 <= k < i ==> (x % k == 0 && y % k == 0 ==> k <= gcd);
        loop invariant gcd == 1 || \forall integer k; 1 <= k < i ==> ((x % k == 0 && y % k == 0) ==> k <= gcd);
        loop invariant gcd == 1 || \forall integer k; 1 <= k < i ==> (!(x % k == 0 && y % k == 0) || k <= gcd);
        loop invariant gcd == 1 || \exists integer k; 1 <= k < i && x % k == 0 && y % k == 0 && gcd == k;
        loop invariant gcd == 1 || 1 <= gcd;
        loop invariant gcd == 1 || 1 <= gcd <= y;
        loop invariant gcd == 1 || 1 <= gcd <= x;
        loop invariant gcd == 1 || 1 <= gcd <= i;
        loop invariant gcd == 1 || 1 <= gcd <= i - 1;
        loop invariant gcd == 1 || (x % gcd == 0 && y % gcd == 0);
        loop invariant gcd == 1 || (\forall integer k; 1 <= k < i ==> (x % k == 0 && y % k == 0 ==> k <= gcd));
        loop invariant gcd == 1 || (\forall integer k; 1 <= k < i ==> ((x % k == 0 && y % k == 0) ==> k <= gcd));
        loop invariant gcd == 1 || (\forall integer k; 1 <= k < i ==> !(x % k == 0 && y % k == 0) || k <= gcd);
        loop invariant gcd == 1 || (\exists integer k; 1 <= k <= i && x % k == 0 && y % k == 0 && gcd == k);
        loop invariant gcd == 1 || (\exists integer k; 1 <= k < i && x % k == 0 && y % k == 0 && gcd == k);
        loop invariant gcd == 1 || (1 <= gcd <= x);
        loop invariant gcd == 1 || (1 <= gcd <= i);
        loop invariant gcd == 1 || (1 <= gcd <= i - 1);
        loop invariant gcd <= y || gcd == 1;
        loop invariant gcd <= x || gcd == 1;
        loop invariant gcd <= i;
        loop invariant gcd <= i || gcd == 1;
        loop invariant gcd <= i - 1 || gcd == 1;
        loop invariant \forall integer k; 1 <= k < i ==> (x % k == 0 ==> x % gcd == 0);
        loop invariant \forall integer k; 1 <= k < i ==> (x % k == 0 && y % k == 0 ==> k <= gcd);
        loop invariant \forall integer k; 1 <= k < i ==> ((x % k == 0 && y % k == 0) ==> k <= gcd);
        loop invariant \forall integer k; 1 <= k < i ==> !(x % k == 0 && y % k == 0) || k <= gcd;
        loop invariant \forall integer k; 1 <= k < i && x % k == 0 && y % k == 0 ==> k <= gcd;
        loop invariant \exists integer k; 1 <= k <= i && x % k == 0 && y % k == 0 && gcd == k;
        loop invariant 1 <= i;
        loop invariant 1 <= gcd;
        loop invariant 1 <= gcd <= i - 1 || gcd == 1;
        loop invariant 0 <= gcd;
        loop invariant 0 < gcd;
        loop invariant 0 < gcd || gcd <= x;
        loop assigns i;
        loop assigns gcd;*/
int stub_B(int x, int y);

/*@loop invariant \forall integer k; 1 <= k < i ==> (!(x % k == 0 && y % k == 0) || k <= gcd);
        loop invariant y > 0 ==> gcd <= y;
        loop invariant y % gcd == 0;
        loop invariant y % gcd == 0 || gcd == 1;
        loop invariant x > 0 ==> y > 0;
        loop invariant x > 0 ==> gcd >= 1;
        loop invariant x > 0 ==> gcd <= x;
        loop invariant x <= y;
        loop invariant x <= y || y <= x;
        loop invariant x % gcd == 0;
        loop invariant x % gcd == 0 || y % gcd == 0;
        loop invariant x % gcd == 0 || gcd == 1;
        loop invariant x % gcd == 0 && y % gcd == 0;
        loop invariant i <= x + 1 || 0 < gcd;
        loop invariant gcd == 1 || y % gcd == 0;
        loop invariant gcd == 1 || x % gcd == 0;
        loop invariant gcd == 1 || x % gcd == 0 || y % gcd == 0;
        loop invariant gcd == 1 || gcd >= 1;
        loop invariant gcd == 1 || gcd == i - 1 || gcd <= i;
        loop invariant gcd == 1 || gcd <= y;
        loop invariant gcd == 1 || gcd <= x;
        loop invariant gcd == 1 || gcd <= x && gcd <= y;
        loop invariant gcd == 1 || gcd <= i;
        loop invariant gcd == 1 || gcd <= i - 1;
        loop invariant gcd == 1 || gcd % 1 == 0;
        loop invariant gcd == 1 || \forall integer k; 1 <= k < i ==> (x % k == 0 && y % k == 0 ==> k <= gcd);
        loop invariant gcd == 1 || \forall integer k; 1 <= k < i ==> ((x % k == 0 && y % k == 0) ==> k <= gcd);
        loop invariant gcd == 1 || \forall integer k; 1 <= k < i ==> (!(x % k == 0 && y % k == 0) || k <= gcd);
        loop invariant gcd == 1 || \exists integer k; 1 <= k < i && x % k == 0 && y % k == 0 && gcd == k;
        loop invariant gcd == 1 || 1 <= gcd;
        loop invariant gcd == 1 || 1 <= gcd <= y;
        loop invariant gcd == 1 || 1 <= gcd <= x;
        loop invariant gcd == 1 || 1 <= gcd <= i;
        loop invariant gcd == 1 || 1 <= gcd <= i - 1;
        loop invariant gcd == 1 || (x % gcd == 0 && y % gcd == 0);
        loop invariant gcd == 1 || (\forall integer k; 1 <= k < i ==> (x % k == 0 && y % k == 0 ==> k <= gcd));
        loop invariant gcd == 1 || (\forall integer k; 1 <= k < i ==> ((x % k == 0 && y % k == 0) ==> k <= gcd));
        loop invariant gcd == 1 || (\forall integer k; 1 <= k < i ==> !(x % k == 0 && y % k == 0) || k <= gcd);
        loop invariant gcd == 1 || (\exists integer k; 1 <= k <= i && x % k == 0 && y % k == 0 && gcd == k);
        loop invariant gcd == 1 || (\exists integer k; 1 <= k < i && x % k == 0 && y % k == 0 && gcd == k);
        loop invariant gcd == 1 || (1 <= gcd <= x);
        loop invariant gcd == 1 || (1 <= gcd <= i);
        loop invariant gcd == 1 || (1 <= gcd <= i - 1);
        loop invariant gcd <= y || gcd == 1;
        loop invariant gcd <= x || gcd == 1;
        loop invariant gcd <= i;
        loop invariant gcd <= i || gcd == 1;
        loop invariant gcd <= i - 1 || gcd == 1;
        loop invariant \forall integer k; 1 <= k < i ==> (x % k == 0 ==> x % gcd == 0);
        loop invariant \forall integer k; 1 <= k < i ==> (x % k == 0 && y % k == 0 ==> k <= gcd);
        loop invariant \forall integer k; 1 <= k < i ==> ((x % k == 0 && y % k == 0) ==> k <= gcd);
        loop invariant \forall integer k; 1 <= k < i ==> !(x % k == 0 && y % k == 0) || k <= gcd;
        loop invariant \forall integer k; 1 <= k < i && x % k == 0 && y % k == 0 ==> k <= gcd;
        loop invariant \exists integer k; 1 <= k <= i && x % k == 0 && y % k == 0 && gcd == k;
        loop invariant 1 <= i;
        loop invariant 1 <= gcd;
        loop invariant 1 <= gcd <= i - 1 || gcd == 1;
        loop invariant 0 <= gcd;
        loop invariant 0 < gcd;
        loop invariant 0 < gcd || gcd <= x;
        loop assigns i;
        loop assigns gcd;*/
int check_A_implies_B(int x, int y) {
    return stub_A(x, y);
}

/*@assigns \nothing;
   ensures (\old(x) > \old(y)) ==> \true;
   ensures (\old(x) <= \old(y)) ==> (x == \old(x) && y == \old(y));
   ensures (\old(x) <= 0 || \old(y) <= 0) ==> \true;
   ensures (\old(x) > 0 && \old(y) > 0) ==> \result >= 1;
   ensures (\old(x) > 0 && \old(y) > 0) ==> \true;
   ensures (\old(x) > 0 && \old(y) > 0) ==> \true;
   ensures \result == \old(x) * \old(y) || \result < \old(x) * \old(y) || \result > \old(x) * \old(y);*/
int check_B_implies_A(int x, int y) {
    return stub_B(x, y);
}
