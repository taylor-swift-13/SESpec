#include <limits.h>


/*@
  logic integer fact(integer n) = n <= 1 ? 1 : n * fact(n - 1);
*/

/*@assigns \nothing;
  ensures \result >= 0;
  ensures \result <= 9;
  
  ensures number <= 1 ==> \result >= 0;*/
int stub_A(int number);

/*@loop invariant result == first % 10 || result >= 0;
		loop invariant result == 0 || result % 10 == result;
		loop invariant first == 0 || first >= 0;
		loop invariant first <= 1 || first > 0;
		loop invariant result == 0 || result >= 0;
		loop invariant result == 0 || result < 10;
		loop invariant result == 0 || \exists integer k; 0 <= k < 10 && result == k;
		loop invariant result == 0 || 0 <= result < 10;
		loop invariant result == 0 || (0 <= result < 10);
		loop invariant result <= 9;
		loop invariant result < 10;
		loop invariant result % 10 == result;
		loop invariant first >= 0 ==> result >= 0;
		loop invariant first >= 0 ==> result < 10;
		loop invariant first >= 0 ==> 0 <= result < 10;
		loop invariant first > 0 || result >= 0;
		loop invariant first > 0 || result < 10;
		loop invariant first > 0 || 0 <= result < 10;
		loop invariant first > 0 ==> result >= 0;
		loop invariant first > 0 ==> result == first % 10 || result >= 0;
		loop invariant first > 0 ==> result == first % 10 || result < 10;
		loop invariant first > 0 ==> result < 10;
		loop invariant first > 0 ==> 0 <= result < 10;
		loop invariant first > 0 ==> 0 <= first % 10 < 10;
		loop invariant first == 0 || result >= 0;
		loop invariant first == 0 || result < 10;
		loop invariant first == 0 || result % 10 == result;
		loop invariant first == 0 || first >= 1;
		loop invariant first == 0 || first > 0;
		loop invariant first == 0 || 0 <= result;
		loop invariant first == 0 || 0 <= result < 10;
		loop invariant first == 0 || 0 <= first % 10 < 10;
		loop invariant first == 0 ==> result == 0 || result < 10;
		loop invariant first == 0 ==> result == 0 || 0 <= result < 10;
		loop invariant first == 0 ==> result < 10;
		loop invariant first == 0 ==> 0 <= result < 10;
		loop invariant first <= first;
		loop invariant first <= 1 || result < 10;
		loop invariant first < 10 || result < 10;
		loop invariant first / 10 <= first;
		loop invariant first % 10 == first || first % 10 < 10;
		loop invariant first % 10 < 10;
		loop invariant \forall integer k; 0 <= k < 10 ==> result != 10 + k;
		loop invariant \exists integer k; 0 <= k <= 9 && result == k;
		loop invariant \exists integer k; 0 <= k < 10 && result == k;
		loop invariant 0 <= result;
		loop invariant 0 <= first;
		loop invariant 0 <= first / 10;
		loop invariant 0 <= first % 10;
		loop assigns result;
		loop assigns first;*/
int stub_B(int number);

/*@loop invariant result == first % 10 || result >= 0;
		loop invariant result == 0 || result % 10 == result;
		loop invariant first == 0 || first >= 0;
		loop invariant first <= 1 || first > 0;
		loop invariant result == 0 || result >= 0;
		loop invariant result == 0 || result < 10;
		loop invariant result == 0 || \exists integer k; 0 <= k < 10 && result == k;
		loop invariant result == 0 || 0 <= result < 10;
		loop invariant result == 0 || (0 <= result < 10);
		loop invariant result <= 9;
		loop invariant result < 10;
		loop invariant result % 10 == result;
		loop invariant first >= 0 ==> result >= 0;
		loop invariant first >= 0 ==> result < 10;
		loop invariant first >= 0 ==> 0 <= result < 10;
		loop invariant first > 0 || result >= 0;
		loop invariant first > 0 || result < 10;
		loop invariant first > 0 || 0 <= result < 10;
		loop invariant first > 0 ==> result >= 0;
		loop invariant first > 0 ==> result == first % 10 || result >= 0;
		loop invariant first > 0 ==> result == first % 10 || result < 10;
		loop invariant first > 0 ==> result < 10;
		loop invariant first > 0 ==> 0 <= result < 10;
		loop invariant first > 0 ==> 0 <= first % 10 < 10;
		loop invariant first == 0 || result >= 0;
		loop invariant first == 0 || result < 10;
		loop invariant first == 0 || result % 10 == result;
		loop invariant first == 0 || first >= 1;
		loop invariant first == 0 || first > 0;
		loop invariant first == 0 || 0 <= result;
		loop invariant first == 0 || 0 <= result < 10;
		loop invariant first == 0 || 0 <= first % 10 < 10;
		loop invariant first == 0 ==> result == 0 || result < 10;
		loop invariant first == 0 ==> result == 0 || 0 <= result < 10;
		loop invariant first == 0 ==> result < 10;
		loop invariant first == 0 ==> 0 <= result < 10;
		loop invariant first <= first;
		loop invariant first <= 1 || result < 10;
		loop invariant first < 10 || result < 10;
		loop invariant first / 10 <= first;
		loop invariant first % 10 == first || first % 10 < 10;
		loop invariant first % 10 < 10;
		loop invariant \forall integer k; 0 <= k < 10 ==> result != 10 + k;
		loop invariant \exists integer k; 0 <= k <= 9 && result == k;
		loop invariant \exists integer k; 0 <= k < 10 && result == k;
		loop invariant 0 <= result;
		loop invariant 0 <= first;
		loop invariant 0 <= first / 10;
		loop invariant 0 <= first % 10;
		loop assigns result;
		loop assigns first;*/
int check_A_implies_B(int number) {
    return stub_A(number);
}

/*@assigns \nothing;
  ensures \result >= 0;
  ensures \result <= 9;
  
  ensures number <= 1 ==> \result >= 0;*/
int check_B_implies_A(int number) {
    return stub_B(number);
}
