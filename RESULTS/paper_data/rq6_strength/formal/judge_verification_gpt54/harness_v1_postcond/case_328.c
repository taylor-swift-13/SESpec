#include <limits.h>


/*@ logic integer sum_cubes(integer n) =
      n <= 0 ? 0 : sum_cubes(n - 1) + n * n * n;
*/

/*@requires 0 <= diff <= 1;
  assigns \nothing;
  ensures \result == \result;*/
int stub_A(int diff);

/*@loop invariant diff < 0 ==> c == 1;
		loop invariant result >= max || c <= diff + 1;
		loop invariant result == 0 || result > 0;
		loop invariant result == (c - 1) * c * (2 * c - 1) * (c - 1) / 4 || result >= 0;
		loop invariant result - max >= 0 || c <= diff + 1;
		loop invariant max == c * (c - 1) / 2;
		loop invariant max == (c - 1) * c / 2;
		loop invariant max <= result || c <= diff + 1;
		loop invariant max <= c * (c - 1) / 2;
		loop invariant diff >= 0 ==> result >= 0;
		loop invariant diff >= 0 ==> max >= 0;
		loop invariant diff >= 0 ==> max <= c * (c - 1) / 2;
		loop invariant diff >= 0 ==> c >= 1;
		loop invariant diff >= 0 ==> c <= diff + 1;
		loop invariant \forall integer k; 1 <= k < c ==> max >= k;
		loop invariant \exists integer k; 0 <= k < c && result >= k * k * k;
		loop invariant \exists integer k; 0 <= k < c && max == k * (k + 1) / 2;
		loop invariant 1 <= c;
		loop invariant 0 <= result;
		loop invariant 0 <= result - max || c <= diff + 1;
		loop invariant 0 <= max;
		loop invariant 0 <= c;
		loop assigns result;
		loop assigns max;
		loop assigns c;*/
int stub_B(int diff);

/*@loop invariant diff < 0 ==> c == 1;
		loop invariant result >= max || c <= diff + 1;
		loop invariant result == 0 || result > 0;
		loop invariant result == (c - 1) * c * (2 * c - 1) * (c - 1) / 4 || result >= 0;
		loop invariant result - max >= 0 || c <= diff + 1;
		loop invariant max == c * (c - 1) / 2;
		loop invariant max == (c - 1) * c / 2;
		loop invariant max <= result || c <= diff + 1;
		loop invariant max <= c * (c - 1) / 2;
		loop invariant diff >= 0 ==> result >= 0;
		loop invariant diff >= 0 ==> max >= 0;
		loop invariant diff >= 0 ==> max <= c * (c - 1) / 2;
		loop invariant diff >= 0 ==> c >= 1;
		loop invariant diff >= 0 ==> c <= diff + 1;
		loop invariant \forall integer k; 1 <= k < c ==> max >= k;
		loop invariant \exists integer k; 0 <= k < c && result >= k * k * k;
		loop invariant \exists integer k; 0 <= k < c && max == k * (k + 1) / 2;
		loop invariant 1 <= c;
		loop invariant 0 <= result;
		loop invariant 0 <= result - max || c <= diff + 1;
		loop invariant 0 <= max;
		loop invariant 0 <= c;
		loop assigns result;
		loop assigns max;
		loop assigns c;*/
int check_A_implies_B(int diff) {
    return stub_A(diff);
}

/*@requires 0 <= diff <= 1;
  assigns \nothing;
  ensures \result == \result;*/
int check_B_implies_A(int diff) {
    return stub_B(diff);
}
