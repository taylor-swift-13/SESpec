#include <limits.h>


/*@ logic integer sum4(integer n) = n <= 0 ? 0 : sum4(n - 1) + n * n * n * n; */

/*@assigns \nothing;
  ensures \true;*/
int stub_A(int p);

/*@loop invariant even == 0 || even >= 0;
		loop invariant even == 0 || even > 0;
		loop invariant even == 0 ==> c == 1;
		loop invariant even <= even + 1;
		loop invariant even % 2 == 0;
		loop invariant even % 2 == 0 || even % 2 == 1;
		loop invariant c > 1 ==> even >= 0;
		loop invariant c > 1 ==> even > 0;
		loop invariant c == 1 || c > 1;
		loop invariant c == 1 || c <= p + 1;
		loop invariant c == 1 ==> even == 0;
		loop invariant c <= p+1 || 0 <= c;
		loop invariant c <= p + 1 || 0 <= c;
		loop invariant c <= p + 1 ==> even >= 0;
		loop invariant c <= p + 1 ==> even % 2 == 0;
		loop invariant c % 2 == 1 || c % 2 == 0;
		loop invariant c % 2 == 0 || c % 2 == 1;
		loop invariant \forall integer k; 1 <= k <= c ==> even >= 0;
		loop invariant \forall integer k; 1 <= k <= c ==> (2*k)*(2*k)*(2*k)*(2*k) >= 0;
		loop invariant \forall integer k; 1 <= k < c ==> even >= 0;
		loop invariant \forall integer k; 1 <= k < c ==> even >= (2*k)*(2*k);
		loop invariant \forall integer k; 1 <= k < c ==> even >= (2*k)*(2*k)*(2*k)*(2*k);
		loop invariant \forall integer k; 1 <= k < c ==> even <= even + (2*k)*(2*k)*(2*k)*(2*k);
		loop invariant \forall integer k; 1 <= k < c ==> even + (2*k)*(2*k)*(2*k)*(2*k) >= even;
		loop invariant \forall integer k; 1 <= k < c ==> even + (2*k)*(2*k) >= even;
		loop invariant \forall integer k; 1 <= k < c ==> even % 2 == 0;
		loop invariant \forall integer k; 1 <= k < c ==> (2*k)*(2*k)*(2*k)*(2*k) >= 0;
		loop invariant \forall integer k; 1 <= k < c ==> (2*k)*(2*k)*(2*k)*(2*k) >= (2*k)*(2*k);
		loop invariant \forall integer k; 1 <= k < c ==> (2*k)*(2*k)*(2*k)*(2*k) % 2 == 0;
		loop invariant \forall integer k; 1 <= k < c ==> (2*k)*(2*k) >= 0;
		loop invariant \forall integer k; 1 <= k < c ==> (2*k)*(2*k) <= even + (2*c)*(2*c);
		loop invariant \forall integer k; 1 <= k < c ==> (2*k)*(2*k) <= (2*c)*(2*c);
		loop invariant \forall integer k; 1 <= k < c ==> (2*k) * (2*k) >= 0;
		loop invariant \exists integer t; 1 <= t < c ==> even >= (2*t)*(2*t);
		loop invariant \exists integer t; 0 <= t < c ==> even >= (2*t)*(2*t);
		loop invariant \exists integer k; 1 <= k <= c ==> even >= 0;
		loop invariant \exists integer k; 1 <= k <= c ==> even >= (2*k)*(2*k)*(2*k)*(2*k);
		loop invariant \exists integer k; 1 <= k <= c ==> (2*k)*(2*k)*(2*k)*(2*k) >= 0;
		loop invariant \exists integer k; 1 <= k < c ==> even >= 0;
		loop invariant \exists integer k; 1 <= k < c ==> even >= (2*k)*(2*k);
		loop invariant \exists integer k; 1 <= k < c ==> even >= (2*k)*(2*k)*(2*k)*(2*k);
		loop invariant \exists integer k; 1 <= k < c ==> (2*k)*(2*k)*(2*k)*(2*k) >= 0;
		loop invariant \exists integer k; 1 <= k < c ==> (2*k)*(2*k) >= 0;
		loop invariant 1 <= c;
		loop invariant 0 <= even;
		loop invariant 0 <= c;
		loop invariant 0 < c;
		loop assigns even;
		loop assigns c;*/
int stub_B(int p);

/*@loop invariant even == 0 || even >= 0;
		loop invariant even == 0 || even > 0;
		loop invariant even == 0 ==> c == 1;
		loop invariant even <= even + 1;
		loop invariant even % 2 == 0;
		loop invariant even % 2 == 0 || even % 2 == 1;
		loop invariant c > 1 ==> even >= 0;
		loop invariant c > 1 ==> even > 0;
		loop invariant c == 1 || c > 1;
		loop invariant c == 1 || c <= p + 1;
		loop invariant c == 1 ==> even == 0;
		loop invariant c <= p+1 || 0 <= c;
		loop invariant c <= p + 1 || 0 <= c;
		loop invariant c <= p + 1 ==> even >= 0;
		loop invariant c <= p + 1 ==> even % 2 == 0;
		loop invariant c % 2 == 1 || c % 2 == 0;
		loop invariant c % 2 == 0 || c % 2 == 1;
		loop invariant \forall integer k; 1 <= k <= c ==> even >= 0;
		loop invariant \forall integer k; 1 <= k <= c ==> (2*k)*(2*k)*(2*k)*(2*k) >= 0;
		loop invariant \forall integer k; 1 <= k < c ==> even >= 0;
		loop invariant \forall integer k; 1 <= k < c ==> even >= (2*k)*(2*k);
		loop invariant \forall integer k; 1 <= k < c ==> even >= (2*k)*(2*k)*(2*k)*(2*k);
		loop invariant \forall integer k; 1 <= k < c ==> even <= even + (2*k)*(2*k)*(2*k)*(2*k);
		loop invariant \forall integer k; 1 <= k < c ==> even + (2*k)*(2*k)*(2*k)*(2*k) >= even;
		loop invariant \forall integer k; 1 <= k < c ==> even + (2*k)*(2*k) >= even;
		loop invariant \forall integer k; 1 <= k < c ==> even % 2 == 0;
		loop invariant \forall integer k; 1 <= k < c ==> (2*k)*(2*k)*(2*k)*(2*k) >= 0;
		loop invariant \forall integer k; 1 <= k < c ==> (2*k)*(2*k)*(2*k)*(2*k) >= (2*k)*(2*k);
		loop invariant \forall integer k; 1 <= k < c ==> (2*k)*(2*k)*(2*k)*(2*k) % 2 == 0;
		loop invariant \forall integer k; 1 <= k < c ==> (2*k)*(2*k) >= 0;
		loop invariant \forall integer k; 1 <= k < c ==> (2*k)*(2*k) <= even + (2*c)*(2*c);
		loop invariant \forall integer k; 1 <= k < c ==> (2*k)*(2*k) <= (2*c)*(2*c);
		loop invariant \forall integer k; 1 <= k < c ==> (2*k) * (2*k) >= 0;
		loop invariant \exists integer t; 1 <= t < c ==> even >= (2*t)*(2*t);
		loop invariant \exists integer t; 0 <= t < c ==> even >= (2*t)*(2*t);
		loop invariant \exists integer k; 1 <= k <= c ==> even >= 0;
		loop invariant \exists integer k; 1 <= k <= c ==> even >= (2*k)*(2*k)*(2*k)*(2*k);
		loop invariant \exists integer k; 1 <= k <= c ==> (2*k)*(2*k)*(2*k)*(2*k) >= 0;
		loop invariant \exists integer k; 1 <= k < c ==> even >= 0;
		loop invariant \exists integer k; 1 <= k < c ==> even >= (2*k)*(2*k);
		loop invariant \exists integer k; 1 <= k < c ==> even >= (2*k)*(2*k)*(2*k)*(2*k);
		loop invariant \exists integer k; 1 <= k < c ==> (2*k)*(2*k)*(2*k)*(2*k) >= 0;
		loop invariant \exists integer k; 1 <= k < c ==> (2*k)*(2*k) >= 0;
		loop invariant 1 <= c;
		loop invariant 0 <= even;
		loop invariant 0 <= c;
		loop invariant 0 < c;
		loop assigns even;
		loop assigns c;*/
int check_A_implies_B(int p) {
    return stub_A(p);
}

/*@assigns \nothing;
  ensures \true;*/
int check_B_implies_A(int p) {
    return stub_B(p);
}
