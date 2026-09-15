#include <limits.h>


/*@
  logic integer divcount(integer n, integer low, integer high) =
    low >= high ? 0 : ((low != 0 && n % low == 0) ? 1 : 0) + divcount(n, low + 1, high);
*/

/*@requires num >= 0;
  assigns \nothing;
  
  ensures \true;
  ensures \true;*/
const char * stub_A(int num);

/*@loop invariant result >= 0 && result <= c;
		loop invariant result >= 0 && c >= 1;
		loop invariant result == 0 || result >= 1;
		loop invariant result == 0 || result > 0;
		loop invariant result == 0 || result == 1 || result > 1;
		loop invariant result == 0 || result <= c;
		loop invariant result <= num || result <= c - 1 + 1;
		loop invariant result <= num || result <= c + 1;
		loop invariant result <= num || 0 <= c;
		loop invariant result <= c;
		loop invariant result <= c - 1;
		loop invariant result <= c - 1 + 1;
		loop invariant result <= c + 1;
		loop invariant result <= c && result >= 0;
		loop invariant result <= c && c >= 1;
		loop invariant result <= c && 0 <= result;
		loop invariant result <= c && 0 <= c;
		loop invariant result < c - 1 + 1;
		loop invariant result < c + 1;
		loop invariant result - c <= 0;
		loop invariant result % 2 == result % 2;
		loop invariant result % 2 == c % 2 || result % 2 != c % 2;
		loop invariant result % 2 == 0 || result % 2 == 1;
		loop invariant c >= 1 ==> result >= 0;
		loop invariant c >= 1 ==> result <= c;
		loop invariant c >= 1 && result >= 0;
		loop invariant c <= num + 1 || result <= c - 1 + 1;
		loop invariant c <= num + 1 || result <= c + 1;
		loop invariant c - result <= num || result <= c + 1;
		loop invariant c - result <= num || 0 <= c;
		loop invariant \forall integer k; 1 <= k < c ==> (num % k == 0 ==> result >= 1);
		loop invariant \forall integer k; 1 <= k < c ==> (num % k == 0 ==> result >= 0);
		loop invariant \forall integer k; 1 <= k < c ==> (num % k == 0 ==> result <= c);
		loop invariant \forall integer k; 1 <= k < c ==> (num % k != 0 || result >= 0);
		loop invariant \forall integer k; 1 <= k < c ==> (num % k != 0 || result <= c);
		loop invariant \forall integer k; 1 <= k < c ==> (num % k != 0 ==> result >= 0);
		loop invariant \forall integer k; 1 <= k < c ==> (num % k != 0 ==> result <= c);
		loop invariant \forall integer k; 1 <= k < c ==> (num % k != 0 ==> result <= c + 1);
		loop invariant \forall integer k; 1 <= k < c && num % k == 0 ==> result >= 1;
		loop invariant \forall integer k; 1 <= k < c && num % k == 0 ==> result >= 0;
		loop invariant \forall integer k; 1 <= k < c && num % k != 0 ==> result >= 0;
		loop invariant 1 <= c;
		loop invariant 1 <= c || result == 0;
		loop invariant 1 <= c - result;
		loop invariant 0 <= result;
		loop invariant 0 <= result && result <= c;
		loop invariant 0 <= result && 0 <= c;
		loop invariant 0 <= c;
		loop invariant 0 <= c || result <= c + 1;
		loop invariant 0 <= c || c <= num + 1;
		loop invariant 0 <= c - result;
		loop invariant 0 < c;
		loop invariant (result % 2 == 0) || (result % 2 == 1);
		loop assigns result;
		loop assigns c;*/
const char * stub_B(int num);

/*@loop invariant result >= 0 && result <= c;
		loop invariant result >= 0 && c >= 1;
		loop invariant result == 0 || result >= 1;
		loop invariant result == 0 || result > 0;
		loop invariant result == 0 || result == 1 || result > 1;
		loop invariant result == 0 || result <= c;
		loop invariant result <= num || result <= c - 1 + 1;
		loop invariant result <= num || result <= c + 1;
		loop invariant result <= num || 0 <= c;
		loop invariant result <= c;
		loop invariant result <= c - 1;
		loop invariant result <= c - 1 + 1;
		loop invariant result <= c + 1;
		loop invariant result <= c && result >= 0;
		loop invariant result <= c && c >= 1;
		loop invariant result <= c && 0 <= result;
		loop invariant result <= c && 0 <= c;
		loop invariant result < c - 1 + 1;
		loop invariant result < c + 1;
		loop invariant result - c <= 0;
		loop invariant result % 2 == result % 2;
		loop invariant result % 2 == c % 2 || result % 2 != c % 2;
		loop invariant result % 2 == 0 || result % 2 == 1;
		loop invariant c >= 1 ==> result >= 0;
		loop invariant c >= 1 ==> result <= c;
		loop invariant c >= 1 && result >= 0;
		loop invariant c <= num + 1 || result <= c - 1 + 1;
		loop invariant c <= num + 1 || result <= c + 1;
		loop invariant c - result <= num || result <= c + 1;
		loop invariant c - result <= num || 0 <= c;
		loop invariant \forall integer k; 1 <= k < c ==> (num % k == 0 ==> result >= 1);
		loop invariant \forall integer k; 1 <= k < c ==> (num % k == 0 ==> result >= 0);
		loop invariant \forall integer k; 1 <= k < c ==> (num % k == 0 ==> result <= c);
		loop invariant \forall integer k; 1 <= k < c ==> (num % k != 0 || result >= 0);
		loop invariant \forall integer k; 1 <= k < c ==> (num % k != 0 || result <= c);
		loop invariant \forall integer k; 1 <= k < c ==> (num % k != 0 ==> result >= 0);
		loop invariant \forall integer k; 1 <= k < c ==> (num % k != 0 ==> result <= c);
		loop invariant \forall integer k; 1 <= k < c ==> (num % k != 0 ==> result <= c + 1);
		loop invariant \forall integer k; 1 <= k < c && num % k == 0 ==> result >= 1;
		loop invariant \forall integer k; 1 <= k < c && num % k == 0 ==> result >= 0;
		loop invariant \forall integer k; 1 <= k < c && num % k != 0 ==> result >= 0;
		loop invariant 1 <= c;
		loop invariant 1 <= c || result == 0;
		loop invariant 1 <= c - result;
		loop invariant 0 <= result;
		loop invariant 0 <= result && result <= c;
		loop invariant 0 <= result && 0 <= c;
		loop invariant 0 <= c;
		loop invariant 0 <= c || result <= c + 1;
		loop invariant 0 <= c || c <= num + 1;
		loop invariant 0 <= c - result;
		loop invariant 0 < c;
		loop invariant (result % 2 == 0) || (result % 2 == 1);
		loop assigns result;
		loop assigns c;*/
const char * check_A_implies_B(int num) {
    return stub_A(num);
}

/*@requires num >= 0;
  assigns \nothing;
  
  ensures \true;
  ensures \true;*/
const char * check_B_implies_A(int num) {
    return stub_B(num);
}
