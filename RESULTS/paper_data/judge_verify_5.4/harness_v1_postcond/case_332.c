#include <limits.h>


/*@ logic integer prod10(integer a, integer b) =
      b < a ? 1 : (prod10(a, b - 1) * (b % 10)) % 10;
*/

/*@assigns \nothing;
  ensures (num == c) ==> \result == 1;
  ensures ((c - num) >= 5) ==> \result == 0;*/
int stub_A(int num, int c);

/*@loop invariant var == num + 1 ==> result == 1;
			loop invariant var <= c + 1 || result == 1;
			loop invariant var <= c + 1 || 0 <= result;
			loop invariant var <= c + 1 ==> result == result % 10;
			loop invariant var <= c + 1 ==> result <= 9;
			loop invariant var <= c + 1 ==> result < 10;
			loop invariant var <= c + 1 ==> result % 10 == result;
			loop invariant result == result % 10;
			loop invariant result == 1 || result == 0 || result <= 9;
			loop invariant result == 1 || result == 0 || result < 10;
			loop invariant result == 1 || result <= 9;
			loop invariant result == 1 || result < 10;
			loop invariant result == 0 || result == 1 || result <= 9;
			loop invariant result == 0 || result == 1 || result < 10;
			loop invariant result == 0 || result <= 9;
			loop invariant result == 0 || result < 10;
			loop invariant result == (result % 10);
			loop invariant result == ((result % 10));
			loop invariant result <= 9;
			loop invariant result < 10;
			loop invariant result % 10 == result;
			loop invariant num <= var;
			loop invariant num < var;
			loop invariant num < var || var <= c + 1;
			loop invariant num < var || result == 1;
			loop invariant num < var || result < 10;
			loop invariant num < var || 1 <= result;
			loop invariant num < var || 0 <= var;
			loop invariant num < var || 0 <= result;
			loop invariant num < var ==> result <= 9;
			loop invariant num < var ==> result < 10;
			loop invariant num < var ==> result % 10 == result;
			loop invariant num + 1 <= var;
			loop invariant \forall integer k; num + 1 <= k < var ==> result <= 9;
			loop invariant \forall integer k; num + 1 <= k < var ==> result < 10;
			loop invariant \forall integer k; num + 1 <= k < var ==> result % 10 == result;
			loop invariant \forall integer k; num + 1 <= k < var ==> k <= c;
			loop invariant \forall integer k; num + 1 <= k < var ==> k < c + 1;
			loop invariant \forall integer k; num + 1 <= k < var ==> 0 <= k - num;
			loop invariant 1 <= var - num;
			loop invariant 1 <= var - num || var == num + 1;
			loop invariant 1 <= result || var > num + 1;
			loop invariant 1 <= result || var <= c + 1;
			loop invariant 0 <= var - num;
			loop invariant 0 <= var - (num + 1);
			loop invariant 0 <= result || var <= c + 1;
			loop assigns var;
			loop assigns result;*/
int stub_B(int num, int c);

/*@loop invariant var == num + 1 ==> result == 1;
			loop invariant var <= c + 1 || result == 1;
			loop invariant var <= c + 1 || 0 <= result;
			loop invariant var <= c + 1 ==> result == result % 10;
			loop invariant var <= c + 1 ==> result <= 9;
			loop invariant var <= c + 1 ==> result < 10;
			loop invariant var <= c + 1 ==> result % 10 == result;
			loop invariant result == result % 10;
			loop invariant result == 1 || result == 0 || result <= 9;
			loop invariant result == 1 || result == 0 || result < 10;
			loop invariant result == 1 || result <= 9;
			loop invariant result == 1 || result < 10;
			loop invariant result == 0 || result == 1 || result <= 9;
			loop invariant result == 0 || result == 1 || result < 10;
			loop invariant result == 0 || result <= 9;
			loop invariant result == 0 || result < 10;
			loop invariant result == (result % 10);
			loop invariant result == ((result % 10));
			loop invariant result <= 9;
			loop invariant result < 10;
			loop invariant result % 10 == result;
			loop invariant num <= var;
			loop invariant num < var;
			loop invariant num < var || var <= c + 1;
			loop invariant num < var || result == 1;
			loop invariant num < var || result < 10;
			loop invariant num < var || 1 <= result;
			loop invariant num < var || 0 <= var;
			loop invariant num < var || 0 <= result;
			loop invariant num < var ==> result <= 9;
			loop invariant num < var ==> result < 10;
			loop invariant num < var ==> result % 10 == result;
			loop invariant num + 1 <= var;
			loop invariant \forall integer k; num + 1 <= k < var ==> result <= 9;
			loop invariant \forall integer k; num + 1 <= k < var ==> result < 10;
			loop invariant \forall integer k; num + 1 <= k < var ==> result % 10 == result;
			loop invariant \forall integer k; num + 1 <= k < var ==> k <= c;
			loop invariant \forall integer k; num + 1 <= k < var ==> k < c + 1;
			loop invariant \forall integer k; num + 1 <= k < var ==> 0 <= k - num;
			loop invariant 1 <= var - num;
			loop invariant 1 <= var - num || var == num + 1;
			loop invariant 1 <= result || var > num + 1;
			loop invariant 1 <= result || var <= c + 1;
			loop invariant 0 <= var - num;
			loop invariant 0 <= var - (num + 1);
			loop invariant 0 <= result || var <= c + 1;
			loop assigns var;
			loop assigns result;*/
int check_A_implies_B(int num, int c) {
    return stub_A(num, c);
}

/*@assigns \nothing;
  ensures (num == c) ==> \result == 1;
  ensures ((c - num) >= 5) ==> \result == 0;*/
int check_B_implies_A(int num, int c) {
    return stub_B(num, c);
}
