#include <limits.h>


/*@
  logic integer count_div(int n, integer lo, integer hi) =
    lo >= hi ? 0
             : count_div(n, lo, hi - 1) + ((n % (hi - 1)) == 0 ? 1 : 0);
*/

/*@requires number >= 0;
  assigns \nothing;
  ensures \result != \null;
  ensures (count_div(number, 1, number + 1) % 2 == 0) ==> \result != \null;
  ensures (count_div(number, 1, number + 1) % 2 != 0) ==> \result != \null;*/
const char * stub_A(int number);

/*@loop invariant result > 0 ==> c > 1;
		loop invariant result > 0 ==> \exists integer k; 1 <= k < c && number % k == 0;
		loop invariant result == 0 || result >= 1;
		loop invariant result == 0 || result > 0;
		loop invariant result == 0 ==> c == 1;
		loop invariant result == 0 ==> \forall integer k; 1 <= k < c ==> number % k != 0;
		loop invariant result <= c;
		loop invariant result <= c - 1;
		loop invariant result <= c - 1 || result == c;
		loop invariant result % 2 == 0 || result % 2 == 1;
		loop invariant c > 1 ==> result >= 1;
		loop invariant c > 1 ==> result >= 1 || result == 0;
		loop invariant c > 1 ==> result >= 0;
		loop invariant c > 1 ==> result <= number;
		loop invariant c > 1 ==> result <= c;
		loop invariant c > 1 ==> result <= c - 1;
		loop invariant c > 1 ==> \forall integer k; 1 <= k < c ==> (number % k == 0 ==> result >= 1);
		loop invariant c > 1 ==> \exists integer k; 1 <= k < c && number % k == 0 ==> result >= 0;
		loop invariant c == result + 1 || c > result;
		loop invariant c == 1 ==> result == 0;
		loop invariant c == 1 + result || c > result;
		loop invariant \forall integer k; 1 <= k < c ==> (number % k == 0 || number % k != 0);
		loop invariant \forall integer k; 1 <= k < c ==> (number % k == 0 ==> result >= 1);
		loop invariant \forall integer k; 1 <= k < c ==> (number % k == 0 ==> result >= 0);
		loop invariant \forall integer k; 1 <= k < c ==> (number % k != 0 || result >= 1);
		loop invariant \forall integer k; 1 <= k < c ==> (number % k != 0 || result >= 0);
		loop invariant \forall integer k; 1 <= k < c ==> (number % k != 0 ==> result >= 0);
		loop invariant \forall integer k; 1 <= k < c && number % k == 0 ==> result >= 1;
		loop invariant \forall integer k; 1 <= k < c && number % k != 0 ==> result >= 0;
		loop invariant \exists integer k; 1 <= k < c ==> number % k == 0;
		loop invariant \exists integer k; 1 <= k < c && number % k == 0 ==> result >= 1;
		loop invariant \exists integer k; 1 <= k < c && number % k == 0 ==> result >= 0;
		loop invariant \exists integer k; 1 <= k < c && number % k == 0 ==> result > 0;
		loop invariant 1 <= c;
		loop invariant 1 <= c - result;
		loop invariant 0 <= result;
		loop invariant 0 <= c;
		loop invariant 0 <= c - result;
		loop invariant 0 < c;
		loop invariant 0 < c || c <= number + 1;
		loop assigns result;
		loop assigns c;*/
const char * stub_B(int number);

/*@loop invariant result > 0 ==> c > 1;
		loop invariant result > 0 ==> \exists integer k; 1 <= k < c && number % k == 0;
		loop invariant result == 0 || result >= 1;
		loop invariant result == 0 || result > 0;
		loop invariant result == 0 ==> c == 1;
		loop invariant result == 0 ==> \forall integer k; 1 <= k < c ==> number % k != 0;
		loop invariant result <= c;
		loop invariant result <= c - 1;
		loop invariant result <= c - 1 || result == c;
		loop invariant result % 2 == 0 || result % 2 == 1;
		loop invariant c > 1 ==> result >= 1;
		loop invariant c > 1 ==> result >= 1 || result == 0;
		loop invariant c > 1 ==> result >= 0;
		loop invariant c > 1 ==> result <= number;
		loop invariant c > 1 ==> result <= c;
		loop invariant c > 1 ==> result <= c - 1;
		loop invariant c > 1 ==> \forall integer k; 1 <= k < c ==> (number % k == 0 ==> result >= 1);
		loop invariant c > 1 ==> \exists integer k; 1 <= k < c && number % k == 0 ==> result >= 0;
		loop invariant c == result + 1 || c > result;
		loop invariant c == 1 ==> result == 0;
		loop invariant c == 1 + result || c > result;
		loop invariant \forall integer k; 1 <= k < c ==> (number % k == 0 || number % k != 0);
		loop invariant \forall integer k; 1 <= k < c ==> (number % k == 0 ==> result >= 1);
		loop invariant \forall integer k; 1 <= k < c ==> (number % k == 0 ==> result >= 0);
		loop invariant \forall integer k; 1 <= k < c ==> (number % k != 0 || result >= 1);
		loop invariant \forall integer k; 1 <= k < c ==> (number % k != 0 || result >= 0);
		loop invariant \forall integer k; 1 <= k < c ==> (number % k != 0 ==> result >= 0);
		loop invariant \forall integer k; 1 <= k < c && number % k == 0 ==> result >= 1;
		loop invariant \forall integer k; 1 <= k < c && number % k != 0 ==> result >= 0;
		loop invariant \exists integer k; 1 <= k < c ==> number % k == 0;
		loop invariant \exists integer k; 1 <= k < c && number % k == 0 ==> result >= 1;
		loop invariant \exists integer k; 1 <= k < c && number % k == 0 ==> result >= 0;
		loop invariant \exists integer k; 1 <= k < c && number % k == 0 ==> result > 0;
		loop invariant 1 <= c;
		loop invariant 1 <= c - result;
		loop invariant 0 <= result;
		loop invariant 0 <= c;
		loop invariant 0 <= c - result;
		loop invariant 0 < c;
		loop invariant 0 < c || c <= number + 1;
		loop assigns result;
		loop assigns c;*/
const char * check_A_implies_B(int number) {
    return stub_A(number);
}

/*@requires number >= 0;
  assigns \nothing;
  ensures \result != \null;
  ensures (count_div(number, 1, number + 1) % 2 == 0) ==> \result != \null;
  ensures (count_div(number, 1, number + 1) % 2 != 0) ==> \result != \null;*/
const char * check_B_implies_A(int number) {
    return stub_B(number);
}
