#include <limits.h>


/*@
  logic integer count_mod5(integer x) =
    x <= 0 ? 0 : count_mod5(x - 1) + ((((x - 1) % 5) == 0) ? 1 : 0);

  logic integer count_mod4(integer x) =
    x <= 0 ? 0 : count_mod4(x - 1) + ((((x - 1) % 4) == 0 && ((x - 1) % 5) != 0) ? 1 : 0);

  logic integer count_mod3(integer x) =
    x <= 0 ? 0 : count_mod3(x - 1) + ((((x - 1) % 3) == 0 && ((x - 1) % 5) != 0 && ((x - 1) % 4) != 0) ? 1 : 0);

  logic integer count_mod2(integer x) =
    x <= 0 ? 0 : count_mod2(x - 1) + ((((x - 1) % 2) == 0 && ((x - 1) % 5) != 0 && ((x - 1) % 4) != 0 && ((x - 1) % 3) != 0) ? 1 : 0);
*/

/*@loop invariant 0 <= l <= n;
      loop invariant 0 <= j <= l;
      loop invariant 0 <= i <= l;
      loop invariant 0 <= k <= l;
      loop invariant 0 <= v4 <= l;
      loop invariant 0 <= v3 <= l;
      loop invariant n == \at(n,Pre);
      loop invariant l + j + i + k + v4 + v3 >= l;
      loop invariant j == count_mod2(l);
      loop invariant i == count_mod3(l);
      loop invariant v4 == count_mod4(l);
      loop invariant v3 == count_mod5(l);
      loop invariant k + j + i + v4 + v3 == l;
      loop invariant \forall integer t; 0 <= t < l && t % 5 == 0 ==> v3 >= 1;
      loop invariant \forall integer t; 0 <= t < l && t % 4 == 0 && t % 5 != 0 ==> v4 >= 1;
      loop invariant \forall integer t; 0 <= t < l && t % 3 == 0 && t % 5 != 0 && t % 4 != 0 ==> i >= 1;
      loop invariant \forall integer t; 0 <= t < l && t % 2 == 0 && t % 5 != 0 && t % 4 != 0 && t % 3 != 0 ==> j >= 1;
      loop assigns v3, v4, i, j, k, l;*/
void stub_A(unsigned int n);

/*@loop invariant v3 >= 0 && v4 >= 0 && i >= 0 && j >= 0 && k >= 0;
    loop invariant l <= n;
    loop invariant k == l - v3 - v4 - i - j;
    loop invariant i + j + k + v3 + v4 == l;
    loop invariant 0 <= v4;
    loop invariant 0 <= v3;
    loop invariant 0 <= l;
    loop invariant 0 <= k;
    loop invariant 0 <= j;
    loop invariant 0 <= i;
    loop assigns v4;
    loop assigns v3;
    loop assigns l;
    loop assigns k;
    loop assigns j;
    loop assigns i;*/
void stub_B(unsigned int n);

/*@loop invariant v3 >= 0 && v4 >= 0 && i >= 0 && j >= 0 && k >= 0;
    loop invariant l <= n;
    loop invariant k == l - v3 - v4 - i - j;
    loop invariant i + j + k + v3 + v4 == l;
    loop invariant 0 <= v4;
    loop invariant 0 <= v3;
    loop invariant 0 <= l;
    loop invariant 0 <= k;
    loop invariant 0 <= j;
    loop invariant 0 <= i;
    loop assigns v4;
    loop assigns v3;
    loop assigns l;
    loop assigns k;
    loop assigns j;
    loop assigns i;*/
void check_A_implies_B(unsigned int n) {
    stub_A(n);
}

/*@loop invariant 0 <= l <= n;
      loop invariant 0 <= j <= l;
      loop invariant 0 <= i <= l;
      loop invariant 0 <= k <= l;
      loop invariant 0 <= v4 <= l;
      loop invariant 0 <= v3 <= l;
      loop invariant n == \at(n,Pre);
      loop invariant l + j + i + k + v4 + v3 >= l;
      loop invariant j == count_mod2(l);
      loop invariant i == count_mod3(l);
      loop invariant v4 == count_mod4(l);
      loop invariant v3 == count_mod5(l);
      loop invariant k + j + i + v4 + v3 == l;
      loop invariant \forall integer t; 0 <= t < l && t % 5 == 0 ==> v3 >= 1;
      loop invariant \forall integer t; 0 <= t < l && t % 4 == 0 && t % 5 != 0 ==> v4 >= 1;
      loop invariant \forall integer t; 0 <= t < l && t % 3 == 0 && t % 5 != 0 && t % 4 != 0 ==> i >= 1;
      loop invariant \forall integer t; 0 <= t < l && t % 2 == 0 && t % 5 != 0 && t % 4 != 0 && t % 3 != 0 ==> j >= 1;
      loop assigns v3, v4, i, j, k, l;*/
void check_B_implies_A(unsigned int n) {
    stub_B(n);
}
