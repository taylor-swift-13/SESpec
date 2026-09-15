#include <limits.h>


/*@
  logic integer divcount(integer n, integer d) =
    d <= 0 ? 0 : divcount(n, d - 1) + ((d != 0 && n % d == 0) ? 1 : 0);
*/

/*@assigns \nothing;
  
  ensures \result >= 0;
  ensures \result <= (\old(z) < 0 ? -\old(z) : \old(z));
  ensures \old(z) >= 0 ==> \result == divcount(num, \old(z));
  ensures \old(z) < 0 ==> \result == divcount(num, -\old(z));*/
int stub_A(int num, int z);

/*@loop invariant result == 0 || result >= 1;
		loop invariant result == 0 || result >= 0;
		loop invariant result == 0 || result > 0;
		loop invariant result <= z;
		loop invariant result <= z + 1;
		loop invariant result <= loop;
		loop invariant result <= loop - 1;
		loop invariant result <= loop - 1 || result == loop;
		loop invariant result <= loop - 1 || result == loop - 1;
		loop invariant loop <= z + 1;
		loop invariant loop - result <= z + 1;
		loop invariant loop - result <= loop;
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k == 0 || num % k != 0);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k == 0 ==> result >= 1);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k == 0 ==> result >= 0);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k == 0 ==> result <= loop);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k == 0 ==> result <= loop - 1);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k != 0 || result >= 1);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k != 0 || result >= 0);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k != 0 || result == result);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k != 0 || result == 0 || result > 0);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k != 0 || result <= loop);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k != 0 || result <= loop - 1);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k != 0 ==> result >= 0);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k != 0 ==> result == result);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k != 0 ==> result == 0 || result > 0);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k != 0 ==> result <= loop);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k != 0 ==> result <= loop - 1);
		loop invariant \forall integer i; 1 <= i < loop ==> (num % i == 0 || num % i != 0);
		loop invariant \forall integer i; 1 <= i < loop ==> (num % i == 0 ==> result >= 1);
		loop invariant \forall integer i; 1 <= i < loop ==> (num % i != 0 || result == 0 || result > 0);
		loop invariant \forall integer i; 1 <= i < loop ==> (num % i != 0 || result <= loop - 1);
		loop invariant \forall integer i; 1 <= i < loop ==> (num % i != 0 ==> result >= 0);
		loop invariant \forall integer i; 1 <= i < loop ==> (num % i != 0 ==> result <= loop - 1);
		loop invariant \exists integer k; 1 <= k <= loop && num % k == 0 ==> result >= 0;
		loop invariant \exists integer k; 1 <= k <= loop && num % k == 0 ==> result > 0;
		loop invariant \exists integer k; 1 <= k < loop ==> (num % k == 0);
		loop invariant \exists integer k; 1 <= k < loop && num % k == 0 ==> result >= 1;
		loop invariant \exists integer k; 1 <= k < loop && num % k == 0 ==> result >= 0;
		loop invariant \exists integer k; 1 <= k < loop && num % k == 0 ==> result > 0;
		loop invariant 1 <= loop;
		loop invariant 1 <= loop - result;
		loop invariant 0 <= result;
		loop invariant 0 <= loop;
		loop invariant 0 <= loop - result;
		loop invariant 0 < loop;
		loop assigns result;
		loop assigns loop;*/
int stub_B(int num, int z);

/*@loop invariant result == 0 || result >= 1;
		loop invariant result == 0 || result >= 0;
		loop invariant result == 0 || result > 0;
		loop invariant result <= z;
		loop invariant result <= z + 1;
		loop invariant result <= loop;
		loop invariant result <= loop - 1;
		loop invariant result <= loop - 1 || result == loop;
		loop invariant result <= loop - 1 || result == loop - 1;
		loop invariant loop <= z + 1;
		loop invariant loop - result <= z + 1;
		loop invariant loop - result <= loop;
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k == 0 || num % k != 0);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k == 0 ==> result >= 1);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k == 0 ==> result >= 0);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k == 0 ==> result <= loop);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k == 0 ==> result <= loop - 1);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k != 0 || result >= 1);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k != 0 || result >= 0);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k != 0 || result == result);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k != 0 || result == 0 || result > 0);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k != 0 || result <= loop);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k != 0 || result <= loop - 1);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k != 0 ==> result >= 0);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k != 0 ==> result == result);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k != 0 ==> result == 0 || result > 0);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k != 0 ==> result <= loop);
		loop invariant \forall integer k; 1 <= k < loop ==> (num % k != 0 ==> result <= loop - 1);
		loop invariant \forall integer i; 1 <= i < loop ==> (num % i == 0 || num % i != 0);
		loop invariant \forall integer i; 1 <= i < loop ==> (num % i == 0 ==> result >= 1);
		loop invariant \forall integer i; 1 <= i < loop ==> (num % i != 0 || result == 0 || result > 0);
		loop invariant \forall integer i; 1 <= i < loop ==> (num % i != 0 || result <= loop - 1);
		loop invariant \forall integer i; 1 <= i < loop ==> (num % i != 0 ==> result >= 0);
		loop invariant \forall integer i; 1 <= i < loop ==> (num % i != 0 ==> result <= loop - 1);
		loop invariant \exists integer k; 1 <= k <= loop && num % k == 0 ==> result >= 0;
		loop invariant \exists integer k; 1 <= k <= loop && num % k == 0 ==> result > 0;
		loop invariant \exists integer k; 1 <= k < loop ==> (num % k == 0);
		loop invariant \exists integer k; 1 <= k < loop && num % k == 0 ==> result >= 1;
		loop invariant \exists integer k; 1 <= k < loop && num % k == 0 ==> result >= 0;
		loop invariant \exists integer k; 1 <= k < loop && num % k == 0 ==> result > 0;
		loop invariant 1 <= loop;
		loop invariant 1 <= loop - result;
		loop invariant 0 <= result;
		loop invariant 0 <= loop;
		loop invariant 0 <= loop - result;
		loop invariant 0 < loop;
		loop assigns result;
		loop assigns loop;*/
int check_A_implies_B(int num, int z) {
    return stub_A(num, z);
}

/*@assigns \nothing;
  
  ensures \result >= 0;
  ensures \result <= (\old(z) < 0 ? -\old(z) : \old(z));
  ensures \old(z) >= 0 ==> \result == divcount(num, \old(z));
  ensures \old(z) < 0 ==> \result == divcount(num, -\old(z));*/
int check_B_implies_A(int num, int z) {
    return stub_B(num, z);
}
