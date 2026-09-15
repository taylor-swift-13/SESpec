#include <limits.h>


/*@ logic integer count_divs_checked(integer n, integer c) =
      c <= 1 ? 0 :
      count_divs_checked(n, c - 1) + (c <= n / c && n % c == 0 ? 1 : 0);
*/

/*@requires num >= 0;
  assigns \nothing;
  ensures num == 1 ==> \result == 1;
  ensures num != 1 ==> \result >= 0;
  ensures \result >= 0;
  ensures num != 1 ==> (\result == 0 ==> \true);*/
int stub_A(int num);

/*@loop invariant c >= 2 ==> result < c + 1;
		loop invariant result >= 0 && c >= 2;
		loop invariant result == 0 || result >= 1;
		loop invariant result == 0 || result > 0;
		loop invariant result <= c;
		loop invariant result <= c - 2;
		loop invariant result <= c - 2 || result == c - 1;
		loop invariant result <= c - 2 || result == 0;
		loop invariant result <= c - 2 + 1;
		loop invariant result <= c - 1;
		loop invariant result <= c - 1 || result == c;
		loop invariant result <= c - 1 || result == 0;
		loop invariant result < c;
		loop invariant result < c + 1;
		loop invariant c >= 2 ==> result >= 0;
		loop invariant c >= 2 ==> result <= c;
		loop invariant c >= 2 ==> result <= c - 1;
		loop invariant c >= 2 ==> result < c;
		loop invariant c >= 2 ==> 0 <= result;
		loop invariant c >= 2 && result >= 0;
		loop invariant \forall integer k; 2 <= k < c ==> num % k == 0 ==> result >= 1;
		loop invariant \forall integer k; 2 <= k < c ==> num % k == 0 ==> result >= 0;
		loop invariant \forall integer k; 2 <= k < c ==> num % k == 0 ==> result <= c;
		loop invariant \forall integer k; 2 <= k < c ==> num % k == 0 ==> result <= c - 1;
		loop invariant \forall integer k; 2 <= k < c ==> num % k != 0 || result >= 1;
		loop invariant \forall integer k; 2 <= k < c ==> num % k != 0 || result >= 0;
		loop invariant \forall integer k; 2 <= k < c ==> num % k != 0 ==> result >= 0;
		loop invariant \forall integer k; 2 <= k < c ==> num % k != 0 ==> result == 0 || result > 0;
		loop invariant \forall integer k; 2 <= k < c ==> (num % k == 0 ==> result >= 1);
		loop invariant \forall integer k; 2 <= k < c ==> (num % k == 0 ==> result >= 0);
		loop invariant \forall integer k; 2 <= k < c ==> (num % k == 0 ==> result > 0);
		loop invariant \forall integer k; 2 <= k < c ==> (num % k == 0 ==> result <= c);
		loop invariant \forall integer k; 2 <= k < c ==> (num % k == 0 ==> result <= c - 2);
		loop invariant \forall integer k; 2 <= k < c ==> (num % k == 0 ==> result <= c - 1);
		loop invariant \forall integer k; 2 <= k < c ==> (num % k != 0 || result >= 1);
		loop invariant \forall integer k; 2 <= k < c ==> (num % k != 0 || result >= 0);
		loop invariant \forall integer k; 2 <= k < c ==> (num % k != 0 || result > 0);
		loop invariant \forall integer k; 2 <= k < c ==> (num % k != 0 ==> result >= 0);
		loop invariant \forall integer k; 2 <= k < c && k <= num / k ==> num % k == 0 ==> result >= 0;
		loop invariant \forall integer k; 2 <= k < c && k <= num / k ==> num % k != 0 || result >= 0;
		loop invariant \forall integer k; 2 <= k < c && k <= num / k ==> (num % k == 0 ==> result >= 1);
		loop invariant \forall integer k; 2 <= k < c && k <= num / k ==> (num % k == 0 ==> result >= 0);
		loop invariant \forall integer k; 2 <= k < c && k <= num / k ==> (num % k == 0 ==> result > 0);
		loop invariant \forall integer k; 2 <= k < c && k <= num / k ==> (num % k == 0 ==> result <= c - 1);
		loop invariant \forall integer k; 2 <= k < c && k <= num / k ==> (num % k != 0) || (result > 0);
		loop invariant \forall integer k; 2 <= k < c && k <= num / k ==> (num % k != 0 || result >= 1);
		loop invariant \forall integer k; 2 <= k < c && k <= num / k ==> (num % k != 0 || result >= 0);
		loop invariant \forall integer k; 2 <= k < c && k <= num / k ==> (num % k != 0 || result > 0);
		loop invariant \exists integer k; 2 <= k < c && num % k == 0 ==> result >= 1;
		loop invariant \exists integer k; 2 <= k < c && num % k == 0 ==> result >= 0;
		loop invariant \exists integer k; 2 <= k < c && num % k == 0 ==> result > 0;
		loop invariant 2 <= c;
		loop invariant 2 <= c ==> result >= 0;
		loop invariant 2 <= c - result;
		loop invariant 1 <= c;
		loop invariant 1 <= c - result;
		loop invariant 0 <= result;
		loop invariant 0 <= result && result <= c;
		loop invariant 0 <= result && 2 <= c;
		loop invariant 0 <= result && 0 <= c;
		loop invariant 0 <= c - result;
		loop invariant 0 < c;
		loop assigns result;
		loop assigns c;*/
int stub_B(int num);

/*@loop invariant c >= 2 ==> result < c + 1;
		loop invariant result >= 0 && c >= 2;
		loop invariant result == 0 || result >= 1;
		loop invariant result == 0 || result > 0;
		loop invariant result <= c;
		loop invariant result <= c - 2;
		loop invariant result <= c - 2 || result == c - 1;
		loop invariant result <= c - 2 || result == 0;
		loop invariant result <= c - 2 + 1;
		loop invariant result <= c - 1;
		loop invariant result <= c - 1 || result == c;
		loop invariant result <= c - 1 || result == 0;
		loop invariant result < c;
		loop invariant result < c + 1;
		loop invariant c >= 2 ==> result >= 0;
		loop invariant c >= 2 ==> result <= c;
		loop invariant c >= 2 ==> result <= c - 1;
		loop invariant c >= 2 ==> result < c;
		loop invariant c >= 2 ==> 0 <= result;
		loop invariant c >= 2 && result >= 0;
		loop invariant \forall integer k; 2 <= k < c ==> num % k == 0 ==> result >= 1;
		loop invariant \forall integer k; 2 <= k < c ==> num % k == 0 ==> result >= 0;
		loop invariant \forall integer k; 2 <= k < c ==> num % k == 0 ==> result <= c;
		loop invariant \forall integer k; 2 <= k < c ==> num % k == 0 ==> result <= c - 1;
		loop invariant \forall integer k; 2 <= k < c ==> num % k != 0 || result >= 1;
		loop invariant \forall integer k; 2 <= k < c ==> num % k != 0 || result >= 0;
		loop invariant \forall integer k; 2 <= k < c ==> num % k != 0 ==> result >= 0;
		loop invariant \forall integer k; 2 <= k < c ==> num % k != 0 ==> result == 0 || result > 0;
		loop invariant \forall integer k; 2 <= k < c ==> (num % k == 0 ==> result >= 1);
		loop invariant \forall integer k; 2 <= k < c ==> (num % k == 0 ==> result >= 0);
		loop invariant \forall integer k; 2 <= k < c ==> (num % k == 0 ==> result > 0);
		loop invariant \forall integer k; 2 <= k < c ==> (num % k == 0 ==> result <= c);
		loop invariant \forall integer k; 2 <= k < c ==> (num % k == 0 ==> result <= c - 2);
		loop invariant \forall integer k; 2 <= k < c ==> (num % k == 0 ==> result <= c - 1);
		loop invariant \forall integer k; 2 <= k < c ==> (num % k != 0 || result >= 1);
		loop invariant \forall integer k; 2 <= k < c ==> (num % k != 0 || result >= 0);
		loop invariant \forall integer k; 2 <= k < c ==> (num % k != 0 || result > 0);
		loop invariant \forall integer k; 2 <= k < c ==> (num % k != 0 ==> result >= 0);
		loop invariant \forall integer k; 2 <= k < c && k <= num / k ==> num % k == 0 ==> result >= 0;
		loop invariant \forall integer k; 2 <= k < c && k <= num / k ==> num % k != 0 || result >= 0;
		loop invariant \forall integer k; 2 <= k < c && k <= num / k ==> (num % k == 0 ==> result >= 1);
		loop invariant \forall integer k; 2 <= k < c && k <= num / k ==> (num % k == 0 ==> result >= 0);
		loop invariant \forall integer k; 2 <= k < c && k <= num / k ==> (num % k == 0 ==> result > 0);
		loop invariant \forall integer k; 2 <= k < c && k <= num / k ==> (num % k == 0 ==> result <= c - 1);
		loop invariant \forall integer k; 2 <= k < c && k <= num / k ==> (num % k != 0) || (result > 0);
		loop invariant \forall integer k; 2 <= k < c && k <= num / k ==> (num % k != 0 || result >= 1);
		loop invariant \forall integer k; 2 <= k < c && k <= num / k ==> (num % k != 0 || result >= 0);
		loop invariant \forall integer k; 2 <= k < c && k <= num / k ==> (num % k != 0 || result > 0);
		loop invariant \exists integer k; 2 <= k < c && num % k == 0 ==> result >= 1;
		loop invariant \exists integer k; 2 <= k < c && num % k == 0 ==> result >= 0;
		loop invariant \exists integer k; 2 <= k < c && num % k == 0 ==> result > 0;
		loop invariant 2 <= c;
		loop invariant 2 <= c ==> result >= 0;
		loop invariant 2 <= c - result;
		loop invariant 1 <= c;
		loop invariant 1 <= c - result;
		loop invariant 0 <= result;
		loop invariant 0 <= result && result <= c;
		loop invariant 0 <= result && 2 <= c;
		loop invariant 0 <= result && 0 <= c;
		loop invariant 0 <= c - result;
		loop invariant 0 < c;
		loop assigns result;
		loop assigns c;*/
int check_A_implies_B(int num) {
    return stub_A(num);
}

/*@requires num >= 0;
  assigns \nothing;
  ensures num == 1 ==> \result == 1;
  ensures num != 1 ==> \result >= 0;
  ensures \result >= 0;
  ensures num != 1 ==> (\result == 0 ==> \true);*/
int check_B_implies_A(int num) {
    return stub_B(num);
}
