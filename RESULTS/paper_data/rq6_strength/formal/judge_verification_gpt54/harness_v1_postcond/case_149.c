#include <limits.h>



/*@assigns \nothing;
  ensures \result == 0 <==> (\exists integer k; 2 <= k <= a / 2 && a % k == 0);
  ensures \result == 1 <==> (\forall integer k; 2 <= k <= a / 2 ==> a % k != 0);
  ensures \result == 0 || \result == 1;
  ensures a == \old(a);*/
int stub_A(int a);

/*@loop invariant a > 1 ==> i == 2 || \forall integer k; 2 <= k < i ==> a % k != 0;
		loop invariant mid == a / 2;
		loop invariant mid == a / 2 && i >= 2;
		loop invariant mid == a / 2 && 2 <= i;
		loop invariant i >= 2 && mid == a / 2;
		loop invariant i > 2 ==> \forall integer k; 2 <= k < i ==> a % k != 0;
		loop invariant i == 2 || i > 2;
		loop invariant i == 2 || a % 2 != 0;
		loop invariant i == 2 || \forall integer k; 2 <= k < i ==> a % k != 0;
		loop invariant i == 2 || (i > 2 && \forall integer k; 2 <= k < i ==> a % k != 0);
		loop invariant i == 2 || (2 <= i && \forall integer k; 2 <= k < i ==> a % k != 0);
		loop invariant i % 2 == 0 || i % 2 == 1;
		loop invariant a >= 0 ==> mid >= 0;
		loop invariant a >= 0 ==> mid == a / 2;
		loop invariant a > 1 ==> mid >= 1;
		loop invariant a > 1 ==> mid == a / 2;
		loop invariant a > 1 ==> i >= 2;
		loop invariant a > 1 ==> i >= 2 && i <= mid + 1;
		loop invariant a > 1 ==> i > 1;
		loop invariant a > 1 ==> i == 2 || i > 2;
		loop invariant a > 1 ==> i == 2 || (2 <= i && \forall integer k; 2 <= k < i ==> a % k != 0);
		loop invariant a > 1 ==> i <= mid + 1;
		loop invariant a > 1 ==> i <= mid + 1 && mid == a / 2;
		loop invariant a > 1 ==> i <= a / 2 + 1;
		loop invariant a > 1 ==> i % 2 == 0 || i % 2 == 1;
		loop invariant a > 1 ==> a % 2 != 0 || i == 2;
		loop invariant a > 1 ==> \forall integer k; 2 <= k < i ==> a % k != 0;
		loop invariant a > 1 ==> 2 <= i;
		loop invariant a > 1 ==> 2 <= i <= mid + 1;
		loop invariant a > 1 ==> 2 <= i <= a / 2 + 1;
		loop invariant a > 1 ==> (i == 2 || i > 2);
		loop invariant a == a;
		loop invariant a % i != 0 ==> \forall integer k; 2 <= k < i ==> a % k != 0;
		loop invariant a % 2 != 0 || i == 2;
		loop invariant a % 2 != 0 ==> i >= 2;
		loop invariant a % 2 != 0 ==> i == 2 || i > 2;
		loop invariant a % 2 != 0 ==> i == 2 || \forall integer k; 2 <= k < i ==> a % k != 0;
		loop invariant \forall integer k; 2 <= k < i ==> a % k != 0;
		loop invariant \forall integer k; 2 <= k < i ==> a % k != 0 || i == 2;
		loop invariant \forall integer k; 2 <= k < i ==> a % k != 0 && mid == a / 2;
		loop invariant \forall integer k; 2 <= k < i ==> a % k != 0 && i >= 2;
		loop invariant \forall integer k; 2 <= k < i ==> a % k != 0 && i <= mid + 1;
		loop invariant \forall integer k; 2 <= k < i ==> (a % k != 0) || (k == i);
		loop invariant 2 <= i;
		loop invariant (i > 2) ==> \forall integer k; 2 <= k < i ==> a % k != 0;
		loop assigns i;*/
int stub_B(int a);

/*@loop invariant a > 1 ==> i == 2 || \forall integer k; 2 <= k < i ==> a % k != 0;
		loop invariant mid == a / 2;
		loop invariant mid == a / 2 && i >= 2;
		loop invariant mid == a / 2 && 2 <= i;
		loop invariant i >= 2 && mid == a / 2;
		loop invariant i > 2 ==> \forall integer k; 2 <= k < i ==> a % k != 0;
		loop invariant i == 2 || i > 2;
		loop invariant i == 2 || a % 2 != 0;
		loop invariant i == 2 || \forall integer k; 2 <= k < i ==> a % k != 0;
		loop invariant i == 2 || (i > 2 && \forall integer k; 2 <= k < i ==> a % k != 0);
		loop invariant i == 2 || (2 <= i && \forall integer k; 2 <= k < i ==> a % k != 0);
		loop invariant i % 2 == 0 || i % 2 == 1;
		loop invariant a >= 0 ==> mid >= 0;
		loop invariant a >= 0 ==> mid == a / 2;
		loop invariant a > 1 ==> mid >= 1;
		loop invariant a > 1 ==> mid == a / 2;
		loop invariant a > 1 ==> i >= 2;
		loop invariant a > 1 ==> i >= 2 && i <= mid + 1;
		loop invariant a > 1 ==> i > 1;
		loop invariant a > 1 ==> i == 2 || i > 2;
		loop invariant a > 1 ==> i == 2 || (2 <= i && \forall integer k; 2 <= k < i ==> a % k != 0);
		loop invariant a > 1 ==> i <= mid + 1;
		loop invariant a > 1 ==> i <= mid + 1 && mid == a / 2;
		loop invariant a > 1 ==> i <= a / 2 + 1;
		loop invariant a > 1 ==> i % 2 == 0 || i % 2 == 1;
		loop invariant a > 1 ==> a % 2 != 0 || i == 2;
		loop invariant a > 1 ==> \forall integer k; 2 <= k < i ==> a % k != 0;
		loop invariant a > 1 ==> 2 <= i;
		loop invariant a > 1 ==> 2 <= i <= mid + 1;
		loop invariant a > 1 ==> 2 <= i <= a / 2 + 1;
		loop invariant a > 1 ==> (i == 2 || i > 2);
		loop invariant a == a;
		loop invariant a % i != 0 ==> \forall integer k; 2 <= k < i ==> a % k != 0;
		loop invariant a % 2 != 0 || i == 2;
		loop invariant a % 2 != 0 ==> i >= 2;
		loop invariant a % 2 != 0 ==> i == 2 || i > 2;
		loop invariant a % 2 != 0 ==> i == 2 || \forall integer k; 2 <= k < i ==> a % k != 0;
		loop invariant \forall integer k; 2 <= k < i ==> a % k != 0;
		loop invariant \forall integer k; 2 <= k < i ==> a % k != 0 || i == 2;
		loop invariant \forall integer k; 2 <= k < i ==> a % k != 0 && mid == a / 2;
		loop invariant \forall integer k; 2 <= k < i ==> a % k != 0 && i >= 2;
		loop invariant \forall integer k; 2 <= k < i ==> a % k != 0 && i <= mid + 1;
		loop invariant \forall integer k; 2 <= k < i ==> (a % k != 0) || (k == i);
		loop invariant 2 <= i;
		loop invariant (i > 2) ==> \forall integer k; 2 <= k < i ==> a % k != 0;
		loop assigns i;*/
int check_A_implies_B(int a) {
    return stub_A(a);
}

/*@assigns \nothing;
  ensures \result == 0 <==> (\exists integer k; 2 <= k <= a / 2 && a % k == 0);
  ensures \result == 1 <==> (\forall integer k; 2 <= k <= a / 2 ==> a % k != 0);
  ensures \result == 0 || \result == 1;
  ensures a == \old(a);*/
int check_B_implies_A(int a) {
    return stub_B(a);
}
