#include <limits.h>


/*@ logic integer divcount(integer n, integer i) =
      i <= 0 ? 0 : divcount(n, i - 1) + (n % i == 0 ? 1 : 0);
*/

/*@assigns \nothing;
  
  ensures \result >= 0;
  ensures \old(z) == 0 ==> \result == 0;*/
int stub_A(int num, int z);

/*@loop invariant result == 0 || result <= z + 1;
		loop invariant result > 0 ==> \exists integer k; 1 <= k < index && num % k == 0;
		loop invariant result == 0 || result >= 1;
		loop invariant result == 0 || result > 0;
		loop invariant result == 0 || result <= z;
		loop invariant result == 0 || result <= index;
		loop invariant result == 0 || result <= index - 1;
		loop invariant result == 0 ==> \forall integer k; 1 <= k < index ==> num % k != 0;
		loop invariant result <= z;
		loop invariant result <= z + 1;
		loop invariant result <= index;
		loop invariant result <= index - 1;
		loop invariant result <= index - 1 || result == index;
		loop invariant index <= z + 1;
		loop invariant \forall integer k; 1 <= k < index ==> (num % k == 0 || num % k != 0);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k == 0 ==> result >= 1);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k == 0 ==> result >= 0);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k == 0 ==> result <= index);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k != 0 || result >= 1);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k != 0 || result >= 0);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k != 0 || result <= index);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k != 0 ==> result >= 0);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k != 0 ==> result <= index);
		loop invariant \exists integer k; 1 <= k < index && num % k == 0 ==> result >= 1;
		loop invariant \exists integer k; 1 <= k < index && num % k == 0 ==> result >= 0;
		loop invariant \exists integer k; 1 <= k < index && num % k == 0 ==> result > 0;
		loop invariant 1 <= index;
		loop invariant 0 <= z;
		loop invariant 0 <= result;
		loop invariant 0 <= index;
		loop invariant 0 <= index - result;
		loop assigns result;
		loop assigns index;*/
int stub_B(int num, int z);

/*@loop invariant result == 0 || result <= z + 1;
		loop invariant result > 0 ==> \exists integer k; 1 <= k < index && num % k == 0;
		loop invariant result == 0 || result >= 1;
		loop invariant result == 0 || result > 0;
		loop invariant result == 0 || result <= z;
		loop invariant result == 0 || result <= index;
		loop invariant result == 0 || result <= index - 1;
		loop invariant result == 0 ==> \forall integer k; 1 <= k < index ==> num % k != 0;
		loop invariant result <= z;
		loop invariant result <= z + 1;
		loop invariant result <= index;
		loop invariant result <= index - 1;
		loop invariant result <= index - 1 || result == index;
		loop invariant index <= z + 1;
		loop invariant \forall integer k; 1 <= k < index ==> (num % k == 0 || num % k != 0);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k == 0 ==> result >= 1);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k == 0 ==> result >= 0);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k == 0 ==> result <= index);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k != 0 || result >= 1);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k != 0 || result >= 0);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k != 0 || result <= index);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k != 0 ==> result >= 0);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k != 0 ==> result <= index);
		loop invariant \exists integer k; 1 <= k < index && num % k == 0 ==> result >= 1;
		loop invariant \exists integer k; 1 <= k < index && num % k == 0 ==> result >= 0;
		loop invariant \exists integer k; 1 <= k < index && num % k == 0 ==> result > 0;
		loop invariant 1 <= index;
		loop invariant 0 <= z;
		loop invariant 0 <= result;
		loop invariant 0 <= index;
		loop invariant 0 <= index - result;
		loop assigns result;
		loop assigns index;*/
int check_A_implies_B(int num, int z) {
    return stub_A(num, z);
}

/*@assigns \nothing;
  
  ensures \result >= 0;
  ensures \old(z) == 0 ==> \result == 0;*/
int check_B_implies_A(int num, int z) {
    return stub_B(num, z);
}
