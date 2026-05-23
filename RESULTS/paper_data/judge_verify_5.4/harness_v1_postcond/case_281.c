#include <limits.h>


/*@
  logic integer count_divisors_upto(integer num, integer n) =
    n <= 0 ? 0 :
    count_divisors_upto(num, n - 1) + (n <= num && num % n == 0 ? 1 : 0);
*/

/*@assigns \nothing;*/
const char * stub_A(int num);

/*@loop invariant result >= 0 && result <= index;
		loop invariant result >= 0 && result <= index - 1;
		loop invariant result >= 0 && index >= 1;
		loop invariant result == 0 || result >= 1;
		loop invariant result == 0 || result >= 0;
		loop invariant result == 0 || result > 0;
		loop invariant result <= index;
		loop invariant result <= index - 1;
		loop invariant result <= index - 1 + 1;
		loop invariant result <= index + 1;
		loop invariant result < index;
		loop invariant result - index <= 0;
		loop invariant result % 2 == result % 2;
		loop invariant result % 2 == 0 || result % 2 == 1;
		loop invariant index == result || index > result;
		loop invariant index == result + 1 || index > result;
		loop invariant index - result <= index;
		loop invariant \forall integer k; 1 <= k < index ==> num % k != 0 || result >= 1;
		loop invariant \forall integer k; 1 <= k < index ==> (num % k == 0 || num % k != 0);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k == 0 ==> result >= 1);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k == 0 ==> result >= 0);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k == 0 ==> result <= index);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k == 0 ==> result <= index - 1);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k != 0 || result >= 1);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k != 0 || result >= 0);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k != 0 || result <= index);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k != 0 || result <= index - 1);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k != 0 ==> result >= 0);
		loop invariant \forall integer k; 1 <= k < index && num % k == 0 ==> result >= 1;
		loop invariant \exists integer k; 1 <= k < index && num % k == 0 ==> result >= 1;
		loop invariant \exists integer k; 1 <= k < index && num % k == 0 ==> result >= 0;
		loop invariant 1 <= index;
		loop invariant 1 <= index - result;
		loop invariant 0 <= result;
		loop invariant 0 <= index;
		loop invariant 0 <= index - result;
		loop invariant 0 < index;
		loop assigns result;
		loop assigns index;*/
const char * stub_B(int num);

/*@loop invariant result >= 0 && result <= index;
		loop invariant result >= 0 && result <= index - 1;
		loop invariant result >= 0 && index >= 1;
		loop invariant result == 0 || result >= 1;
		loop invariant result == 0 || result >= 0;
		loop invariant result == 0 || result > 0;
		loop invariant result <= index;
		loop invariant result <= index - 1;
		loop invariant result <= index - 1 + 1;
		loop invariant result <= index + 1;
		loop invariant result < index;
		loop invariant result - index <= 0;
		loop invariant result % 2 == result % 2;
		loop invariant result % 2 == 0 || result % 2 == 1;
		loop invariant index == result || index > result;
		loop invariant index == result + 1 || index > result;
		loop invariant index - result <= index;
		loop invariant \forall integer k; 1 <= k < index ==> num % k != 0 || result >= 1;
		loop invariant \forall integer k; 1 <= k < index ==> (num % k == 0 || num % k != 0);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k == 0 ==> result >= 1);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k == 0 ==> result >= 0);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k == 0 ==> result <= index);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k == 0 ==> result <= index - 1);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k != 0 || result >= 1);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k != 0 || result >= 0);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k != 0 || result <= index);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k != 0 || result <= index - 1);
		loop invariant \forall integer k; 1 <= k < index ==> (num % k != 0 ==> result >= 0);
		loop invariant \forall integer k; 1 <= k < index && num % k == 0 ==> result >= 1;
		loop invariant \exists integer k; 1 <= k < index && num % k == 0 ==> result >= 1;
		loop invariant \exists integer k; 1 <= k < index && num % k == 0 ==> result >= 0;
		loop invariant 1 <= index;
		loop invariant 1 <= index - result;
		loop invariant 0 <= result;
		loop invariant 0 <= index;
		loop invariant 0 <= index - result;
		loop invariant 0 < index;
		loop assigns result;
		loop assigns index;*/
const char * check_A_implies_B(int num) {
    return stub_A(num);
}

/*@assigns \nothing;*/
const char * check_B_implies_A(int num) {
    return stub_B(num);
}
