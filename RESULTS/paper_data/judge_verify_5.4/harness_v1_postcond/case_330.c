#include <limits.h>


/*@
  logic integer cube_sum(integer n) =
    n <= 0 ? 0 : cube_sum(n - 1) + n * n * n;
*/

  logic integer tri_sum(integer n) =
    n <= 0 ? 0 : tri_sum(n - 1) + n;

/*@requires diff >= 0;
  assigns \nothing;
  ensures \result == cube_sum(diff) - tri_sum(diff);
  ensures cube_sum(diff) >= 0;
  ensures tri_sum(diff) >= 0;
  ensures diff == 0 ==> \result == 0;*/
int stub_A(int diff);

/*@loop invariant diff >= 0 ==> 0 <= j <= diff + 1;
		loop invariant result >= max || j <= diff + 1;
		loop invariant result >= 0 && max >= 0;
		loop invariant result == 0 || result > 0;
		loop invariant max == 0 || max > 0;
		loop invariant max == (j - 1) * j / 2;
		loop invariant max == (j * (j - 1)) / 2;
		loop invariant max == ((j - 1) * j) / 2;
		loop invariant max <= result || j <= diff + 1;
		loop invariant max <= result || j - 1 <= diff;
		loop invariant j == 1 || j > 1;
		loop invariant j <= diff + 1 || max <= result;
		loop invariant j - 1 <= diff || max <= result;
		loop invariant diff >= 0 ==> result >= 0;
		loop invariant diff >= 0 ==> result >= 0 && max >= 0;
		loop invariant diff >= 0 ==> max >= 0;
		loop invariant diff >= 0 ==> j >= 1;
		loop invariant diff >= 0 ==> j >= 1 && j <= diff + 1;
		loop invariant diff >= 0 ==> j <= diff + 1;
		loop invariant diff >= 0 ==> j - 1 <= diff;
		loop invariant diff >= 0 ==> 1 <= j;
		loop invariant diff >= 0 ==> 1 <= j <= diff + 1;
		loop invariant diff < 0 ==> j == 1;
		loop invariant \forall integer k; 1 <= k < j ==> result >= 0;
		loop invariant \forall integer k; 1 <= k < j ==> result >= 0 && max >= 0;
		loop invariant \forall integer k; 1 <= k < j ==> max >= 0;
		loop invariant 1 <= j;
		loop invariant 0 <= result;
		loop invariant 0 <= result && 0 <= max;
		loop invariant 0 <= max;
		loop invariant 0 <= j;
		loop assigns result;
		loop assigns max;
		loop assigns j;*/
int stub_B(int diff);

/*@loop invariant diff >= 0 ==> 0 <= j <= diff + 1;
		loop invariant result >= max || j <= diff + 1;
		loop invariant result >= 0 && max >= 0;
		loop invariant result == 0 || result > 0;
		loop invariant max == 0 || max > 0;
		loop invariant max == (j - 1) * j / 2;
		loop invariant max == (j * (j - 1)) / 2;
		loop invariant max == ((j - 1) * j) / 2;
		loop invariant max <= result || j <= diff + 1;
		loop invariant max <= result || j - 1 <= diff;
		loop invariant j == 1 || j > 1;
		loop invariant j <= diff + 1 || max <= result;
		loop invariant j - 1 <= diff || max <= result;
		loop invariant diff >= 0 ==> result >= 0;
		loop invariant diff >= 0 ==> result >= 0 && max >= 0;
		loop invariant diff >= 0 ==> max >= 0;
		loop invariant diff >= 0 ==> j >= 1;
		loop invariant diff >= 0 ==> j >= 1 && j <= diff + 1;
		loop invariant diff >= 0 ==> j <= diff + 1;
		loop invariant diff >= 0 ==> j - 1 <= diff;
		loop invariant diff >= 0 ==> 1 <= j;
		loop invariant diff >= 0 ==> 1 <= j <= diff + 1;
		loop invariant diff < 0 ==> j == 1;
		loop invariant \forall integer k; 1 <= k < j ==> result >= 0;
		loop invariant \forall integer k; 1 <= k < j ==> result >= 0 && max >= 0;
		loop invariant \forall integer k; 1 <= k < j ==> max >= 0;
		loop invariant 1 <= j;
		loop invariant 0 <= result;
		loop invariant 0 <= result && 0 <= max;
		loop invariant 0 <= max;
		loop invariant 0 <= j;
		loop assigns result;
		loop assigns max;
		loop assigns j;*/
int check_A_implies_B(int diff) {
    return stub_A(diff);
}

/*@requires diff >= 0;
  assigns \nothing;
  ensures \result == cube_sum(diff) - tri_sum(diff);
  ensures cube_sum(diff) >= 0;
  ensures tri_sum(diff) >= 0;
  ensures diff == 0 ==> \result == 0;*/
int check_B_implies_A(int diff) {
    return stub_B(diff);
}
