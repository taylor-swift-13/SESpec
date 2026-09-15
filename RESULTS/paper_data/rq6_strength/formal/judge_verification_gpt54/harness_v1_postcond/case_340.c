#include <limits.h>


/*@ logic integer count_divisors(integer n, integer z) =
      z <= 0 ? 0 :
      count_divisors(n, z - 1) + ((n % z) == 0 ? 1 : 0);
*/

/*@requires z >= 0;
  assigns \nothing;
  ensures z >= 0;
  ensures n == \old(n);
  
  ensures \result == count_divisors(n, (\old(z) >= 0 ? \old(z) : -\old(z)));
  ensures \result >= 0;
  ensures \result <= (\old(z) >= 0 ? \old(z) : -\old(z));*/
int stub_A(int n, int z);

/*@loop invariant \forall integer k; 1 <= k < loop ==> (n % k != 0 || result == result);
		loop invariant \forall integer i; 1 <= i < loop ==> (n % i == 0 || n % i != 0);
		loop invariant \forall integer i; 1 <= i < loop ==> (n % i == 0 ==> result >= 1);
		loop invariant \forall integer i; 1 <= i < loop ==> (n % i != 0 ==> result >= 0);
		loop invariant \exists integer k; 1 <= k < loop && n % k == 0 ==> result >= 0;
		loop invariant \exists integer k; 1 <= k < loop && n % k == 0 ==> result > 0;
		loop invariant result == 0 || result >= 1;
		loop invariant result == 0 || result > 0;
		loop invariant result <= z;
		loop invariant result <= loop;
		loop invariant result <= loop - 1;
		loop invariant loop <= z + 1;
		loop invariant \forall integer k; 1 <= k < loop ==> result >= 0;
		loop invariant \forall integer k; 1 <= k < loop ==> (n % k == 0 || n % k != 0);
		loop invariant \forall integer k; 1 <= k < loop ==> (n % k == 0 ==> result >= 1);
		loop invariant \forall integer k; 1 <= k < loop ==> (n % k == 0 ==> result >= 0);
		loop invariant \forall integer k; 1 <= k < loop ==> (n % k == 0 ==> result <= loop);
		loop invariant \forall integer k; 1 <= k < loop ==> (n % k == 0 ==> result <= loop - 1);
		loop invariant \forall integer k; 1 <= k < loop ==> (n % k != 0 || result >= 1);
		loop invariant \forall integer k; 1 <= k < loop ==> (n % k != 0 || result >= 0);
		loop invariant \forall integer k; 1 <= k < loop ==> (n % k != 0 || result <= loop);
		loop invariant \forall integer k; 1 <= k < loop ==> (n % k != 0 ==> result >= 0);
		loop invariant \forall integer k; 1 <= k < loop ==> (n % k != 0 ==> result == result);
		loop invariant \forall integer k; 1 <= k < loop ==> (n % k != 0 ==> result <= loop);
		loop invariant \forall integer k; 1 <= k < loop ==> (n % k != 0 ==> result <= loop - 1);
		loop invariant \forall integer k; 1 <= k < loop ==> ((n % k == 0) ==> result >= 1);
		loop invariant \forall integer k; 1 <= k < loop ==> ((n % k == 0) ==> result >= 0);
		loop invariant \forall integer k; 1 <= k < loop ==> ((n % k == 0) ==> result <= loop);
		loop invariant \forall integer k; 1 <= k < loop ==> ((n % k == 0) ==> result <= loop - 1);
		loop invariant \forall integer k; 1 <= k < loop ==> ((n % k != 0) || (result >= 0));
		loop invariant \forall integer i; 1 <= i < loop ==> (n % i != 0 || result >= 1);
		loop invariant \exists integer k; 1 <= k < loop && n % k == 0 ==> result >= 1;
		loop invariant 1 <= loop;
		loop invariant 0 <= z;
		loop invariant 0 <= result;
		loop invariant 0 <= loop;
		loop assigns result;
		loop assigns loop;*/
int stub_B(int n, int z);

/*@loop invariant \forall integer k; 1 <= k < loop ==> (n % k != 0 || result == result);
		loop invariant \forall integer i; 1 <= i < loop ==> (n % i == 0 || n % i != 0);
		loop invariant \forall integer i; 1 <= i < loop ==> (n % i == 0 ==> result >= 1);
		loop invariant \forall integer i; 1 <= i < loop ==> (n % i != 0 ==> result >= 0);
		loop invariant \exists integer k; 1 <= k < loop && n % k == 0 ==> result >= 0;
		loop invariant \exists integer k; 1 <= k < loop && n % k == 0 ==> result > 0;
		loop invariant result == 0 || result >= 1;
		loop invariant result == 0 || result > 0;
		loop invariant result <= z;
		loop invariant result <= loop;
		loop invariant result <= loop - 1;
		loop invariant loop <= z + 1;
		loop invariant \forall integer k; 1 <= k < loop ==> result >= 0;
		loop invariant \forall integer k; 1 <= k < loop ==> (n % k == 0 || n % k != 0);
		loop invariant \forall integer k; 1 <= k < loop ==> (n % k == 0 ==> result >= 1);
		loop invariant \forall integer k; 1 <= k < loop ==> (n % k == 0 ==> result >= 0);
		loop invariant \forall integer k; 1 <= k < loop ==> (n % k == 0 ==> result <= loop);
		loop invariant \forall integer k; 1 <= k < loop ==> (n % k == 0 ==> result <= loop - 1);
		loop invariant \forall integer k; 1 <= k < loop ==> (n % k != 0 || result >= 1);
		loop invariant \forall integer k; 1 <= k < loop ==> (n % k != 0 || result >= 0);
		loop invariant \forall integer k; 1 <= k < loop ==> (n % k != 0 || result <= loop);
		loop invariant \forall integer k; 1 <= k < loop ==> (n % k != 0 ==> result >= 0);
		loop invariant \forall integer k; 1 <= k < loop ==> (n % k != 0 ==> result == result);
		loop invariant \forall integer k; 1 <= k < loop ==> (n % k != 0 ==> result <= loop);
		loop invariant \forall integer k; 1 <= k < loop ==> (n % k != 0 ==> result <= loop - 1);
		loop invariant \forall integer k; 1 <= k < loop ==> ((n % k == 0) ==> result >= 1);
		loop invariant \forall integer k; 1 <= k < loop ==> ((n % k == 0) ==> result >= 0);
		loop invariant \forall integer k; 1 <= k < loop ==> ((n % k == 0) ==> result <= loop);
		loop invariant \forall integer k; 1 <= k < loop ==> ((n % k == 0) ==> result <= loop - 1);
		loop invariant \forall integer k; 1 <= k < loop ==> ((n % k != 0) || (result >= 0));
		loop invariant \forall integer i; 1 <= i < loop ==> (n % i != 0 || result >= 1);
		loop invariant \exists integer k; 1 <= k < loop && n % k == 0 ==> result >= 1;
		loop invariant 1 <= loop;
		loop invariant 0 <= z;
		loop invariant 0 <= result;
		loop invariant 0 <= loop;
		loop assigns result;
		loop assigns loop;*/
int check_A_implies_B(int n, int z) {
    return stub_A(n, z);
}

/*@requires z >= 0;
  assigns \nothing;
  ensures z >= 0;
  ensures n == \old(n);
  
  ensures \result == count_divisors(n, (\old(z) >= 0 ? \old(z) : -\old(z)));
  ensures \result >= 0;
  ensures \result <= (\old(z) >= 0 ? \old(z) : -\old(z));*/
int check_B_implies_A(int n, int z) {
    return stub_B(n, z);
}
