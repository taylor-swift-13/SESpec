#include <limits.h>


/*@ logic integer leading_digit(integer n) =
      n < 10 ? n : leading_digit(n / 10); */
/*@ logic integer fact(integer n) =
      n <= 1 ? 1 : n * fact(n - 1); */

/*@requires num == 1;
  assigns \nothing;
  ensures 0 <= \result <= 9;
  ensures \result >= 0;*/
int stub_A(int num);

/*@loop invariant first <= 1 || 0 <= first;
		loop invariant result >= 0 && result <= 9;
		loop invariant result == 0 || result >= 1;
		loop invariant result == 0 || result >= 0;
		loop invariant result == 0 || result > 0;
		loop invariant result == 0 || result < 10;
		loop invariant result == 0 || result % 10 == result;
		loop invariant result == 0 || (result >= 0 && result < 10);
		loop invariant result == 0 || (\exists integer k; 0 <= k < 10 && result == k);
		loop invariant result == 0 || (0 <= result && result < 10);
		loop invariant result <= 9;
		loop invariant result < 10;
		loop invariant result < 10 && result >= 0;
		loop invariant result % 10 == result;
		loop invariant first >= 0 ==> result == 0 || result > 0;
		loop invariant first >= 0 ==> result == 0 || (\exists integer k; 0 <= k < 10 && result == k);
		loop invariant first >= 0 ==> result <= 9;
		loop invariant first >= 0 ==> result < 10;
		loop invariant first >= 0 ==> 0 <= result <= 9;
		loop invariant first >= 0 ==> 0 <= result < 10;
		loop invariant first > 0 ==> result >= 0;
		loop invariant first > 0 ==> result >= 0 && result < 10;
		loop invariant first > 0 ==> result == first % 10 || result < 10;
		loop invariant first > 0 ==> result < 10;
		loop invariant first > 0 ==> 0 <= result;
		loop invariant first > 0 ==> 0 <= result <= 9;
		loop invariant first > 0 ==> 0 <= result < 10;
		loop invariant first == 0 || result >= 0;
		loop invariant first == 0 || result < 10;
		loop invariant first == 0 || first > 0;
		loop invariant first == 0 || 0 <= result <= 9;
		loop invariant first == 0 ==> result == 0 || result < 10;
		loop invariant first == 0 ==> result < 10;
		loop invariant first <= num || first > num;
		loop invariant first < 10 || first >= 10;
		loop invariant first % 10 == first - 10 * (first / 10);
		loop invariant first % 10 < 10;
		loop invariant 0 <= result;
		loop invariant 0 <= first;
		loop invariant 0 <= first % 10;
		loop assigns result;
		loop assigns first;*/
int stub_B(int num);

/*@loop invariant first <= 1 || 0 <= first;
		loop invariant result >= 0 && result <= 9;
		loop invariant result == 0 || result >= 1;
		loop invariant result == 0 || result >= 0;
		loop invariant result == 0 || result > 0;
		loop invariant result == 0 || result < 10;
		loop invariant result == 0 || result % 10 == result;
		loop invariant result == 0 || (result >= 0 && result < 10);
		loop invariant result == 0 || (\exists integer k; 0 <= k < 10 && result == k);
		loop invariant result == 0 || (0 <= result && result < 10);
		loop invariant result <= 9;
		loop invariant result < 10;
		loop invariant result < 10 && result >= 0;
		loop invariant result % 10 == result;
		loop invariant first >= 0 ==> result == 0 || result > 0;
		loop invariant first >= 0 ==> result == 0 || (\exists integer k; 0 <= k < 10 && result == k);
		loop invariant first >= 0 ==> result <= 9;
		loop invariant first >= 0 ==> result < 10;
		loop invariant first >= 0 ==> 0 <= result <= 9;
		loop invariant first >= 0 ==> 0 <= result < 10;
		loop invariant first > 0 ==> result >= 0;
		loop invariant first > 0 ==> result >= 0 && result < 10;
		loop invariant first > 0 ==> result == first % 10 || result < 10;
		loop invariant first > 0 ==> result < 10;
		loop invariant first > 0 ==> 0 <= result;
		loop invariant first > 0 ==> 0 <= result <= 9;
		loop invariant first > 0 ==> 0 <= result < 10;
		loop invariant first == 0 || result >= 0;
		loop invariant first == 0 || result < 10;
		loop invariant first == 0 || first > 0;
		loop invariant first == 0 || 0 <= result <= 9;
		loop invariant first == 0 ==> result == 0 || result < 10;
		loop invariant first == 0 ==> result < 10;
		loop invariant first <= num || first > num;
		loop invariant first < 10 || first >= 10;
		loop invariant first % 10 == first - 10 * (first / 10);
		loop invariant first % 10 < 10;
		loop invariant 0 <= result;
		loop invariant 0 <= first;
		loop invariant 0 <= first % 10;
		loop assigns result;
		loop assigns first;*/
int check_A_implies_B(int num) {
    return stub_A(num);
}

/*@requires num == 1;
  assigns \nothing;
  ensures 0 <= \result <= 9;
  ensures \result >= 0;*/
int check_B_implies_A(int num) {
    return stub_B(num);
}
