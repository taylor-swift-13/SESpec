#include <limits.h>


/*@
  logic integer cube_sum(integer n) =
    n <= 0 ? 0 : cube_sum(n - 1) + n * n * n;
*/

  logic integer sum_upto(integer n) =
    n <= 0 ? 0 : sum_upto(n - 1) + n;

/*@requires diff >= 0;
  assigns \nothing;*/
int stub_A(int diff);

/*@loop invariant ret >= max || j <= diff + 1;
		loop invariant ret >= 0 && max >= 0;
		loop invariant ret == \sum(1, j-1, \lambda integer k; k*k*k) || ret >= 0;
		loop invariant ret == \sum(1, j-1, \lambda integer k; k) || ret >= 0;
		loop invariant ret == 0 || ret > 0;
		loop invariant ret == (j-1) * j / 2 || ret >= 0;
		loop invariant ret == (j-1) * j * (2*j-1) * (j-1) / 4 || ret >= 0;
		loop invariant ret == (j - 1) * j * (j - 1) * j / 4 || ret >= 0;
		loop invariant ret == (j - 1) * j * (2*j - 1) * (j - 1) / 4 || ret >= 0;
		loop invariant ret == ((j - 1) * j) / 2 || ret >= 0;
		loop invariant ret == ((j - 1) * j / 2) || ret >= 0;
		loop invariant ret == ((j - 1) * j * (2*j - 1) * (j - 1)) / 4 || ret >= 0;
		loop invariant ret - max >= 0 || j <= diff + 1;
		loop invariant max == \sum(1, j-1, \lambda integer k; k) || max >= 0;
		loop invariant max == 0 || max > 0;
		loop invariant max == (j - 1) * j / 2 || max >= 0;
		loop invariant max == ((j - 1) * j) / 2 || max >= 0;
		loop invariant max == ((j - 1) * j / 2) || max >= 0;
		loop invariant max <= ret || j <= diff + 1;
		loop invariant j <= diff + 1 || ret >= 0;
		loop invariant j <= diff + 1 || max >= 0;
		loop invariant j <= diff + 1 || max <= ret;
		loop invariant j <= diff + 1 || 0 <= ret - max;
		loop invariant \forall integer k; 1 <= k < j ==> max >= k;
		loop invariant \forall integer k; 1 <= k < j ==> max >= k - 1;
		loop invariant \exists integer k; 1 <= k < j ==> ret >= k;
		loop invariant 1 <= j;
		loop invariant 1 <= j || j == 1;
		loop invariant 0 <= ret;
		loop invariant 0 <= ret - max || j <= diff + 1;
		loop invariant 0 <= max;
		loop invariant 0 <= j;
		loop assigns ret;
		loop assigns max;
		loop assigns j;*/
int stub_B(int diff);

/*@loop invariant ret >= max || j <= diff + 1;
		loop invariant ret >= 0 && max >= 0;
		loop invariant ret == \sum(1, j-1, \lambda integer k; k*k*k) || ret >= 0;
		loop invariant ret == \sum(1, j-1, \lambda integer k; k) || ret >= 0;
		loop invariant ret == 0 || ret > 0;
		loop invariant ret == (j-1) * j / 2 || ret >= 0;
		loop invariant ret == (j-1) * j * (2*j-1) * (j-1) / 4 || ret >= 0;
		loop invariant ret == (j - 1) * j * (j - 1) * j / 4 || ret >= 0;
		loop invariant ret == (j - 1) * j * (2*j - 1) * (j - 1) / 4 || ret >= 0;
		loop invariant ret == ((j - 1) * j) / 2 || ret >= 0;
		loop invariant ret == ((j - 1) * j / 2) || ret >= 0;
		loop invariant ret == ((j - 1) * j * (2*j - 1) * (j - 1)) / 4 || ret >= 0;
		loop invariant ret - max >= 0 || j <= diff + 1;
		loop invariant max == \sum(1, j-1, \lambda integer k; k) || max >= 0;
		loop invariant max == 0 || max > 0;
		loop invariant max == (j - 1) * j / 2 || max >= 0;
		loop invariant max == ((j - 1) * j) / 2 || max >= 0;
		loop invariant max == ((j - 1) * j / 2) || max >= 0;
		loop invariant max <= ret || j <= diff + 1;
		loop invariant j <= diff + 1 || ret >= 0;
		loop invariant j <= diff + 1 || max >= 0;
		loop invariant j <= diff + 1 || max <= ret;
		loop invariant j <= diff + 1 || 0 <= ret - max;
		loop invariant \forall integer k; 1 <= k < j ==> max >= k;
		loop invariant \forall integer k; 1 <= k < j ==> max >= k - 1;
		loop invariant \exists integer k; 1 <= k < j ==> ret >= k;
		loop invariant 1 <= j;
		loop invariant 1 <= j || j == 1;
		loop invariant 0 <= ret;
		loop invariant 0 <= ret - max || j <= diff + 1;
		loop invariant 0 <= max;
		loop invariant 0 <= j;
		loop assigns ret;
		loop assigns max;
		loop assigns j;*/
int check_A_implies_B(int diff) {
    return stub_A(diff);
}

/*@requires diff >= 0;
  assigns \nothing;*/
int check_B_implies_A(int diff) {
    return stub_B(diff);
}
