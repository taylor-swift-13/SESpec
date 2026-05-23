#include <limits.h>


/*@
  logic integer count_nondiv(integer code, integer l, integer u) =
    u < l ? 0 :
    count_nondiv(code, l, u - 1) + ((u % code != 0) ? 1 : 0);
*/

/*@loop invariant c >= l;
          loop invariant 0 <= result;
          loop invariant result == count_nondiv(code, l, c - 1);
          loop invariant 0 <= result <= c - l;
          loop invariant result == 0 || (\exists integer i; l <= i < c && i % code != 0);
          loop invariant m == \at(m,Pre);
          loop invariant l == \at(l,Pre);
          loop invariant b == \at(b,Pre);
          loop invariant code == \at(code,Pre);
          loop invariant (c > m) ==> (result == count_nondiv(code, l, m));
          loop assigns c, result;*/
int stub_A(int code, int b, int l, int m);

/*@loop invariant result > 0 ==> l <= c;
		loop invariant result > 0 ==> l < c;
		loop invariant result > 0 ==> c > l;
		loop invariant result > 0 ==> \exists integer k; l <= k < c && k % code != 0;
		loop invariant result > 0 ==> \exists integer i; l <= i < c && i % code != 0;
		loop invariant result == c - l ==> \forall integer k; l <= k < c ==> k % code != 0;
		loop invariant result == c - l ==> \forall integer i; l <= i < c ==> i % code != 0;
		loop invariant result == 0 || result >= 0;
		loop invariant result == 0 || result > 0;
		loop invariant result == 0 ==> \forall integer k; l <= k < c ==> k % code == 0;
		loop invariant result == 0 ==> \forall integer i; l <= i < c ==> i % code == 0;
		loop invariant result <= c - l;
		loop invariant result <= c - l + 1;
		loop invariant result < b ==> result <= c - l;
		loop invariant result < b ==> result <= c - l + 1;
		loop invariant result < b ==> result <= b;
		loop invariant result < b ==> result < c - l + 1;
		loop invariant result < b ==> result < b;
		loop invariant result < b ==> \forall integer k; l <= k < c ==> (k % code == 0 || k % code != 0);
		loop invariant result < b ==> \forall integer i; l <= i < c ==> (i % code == 0 || result >= 0);
		loop invariant result < b ==> \forall integer i; l <= i < c ==> (i % code == 0 || result > 0);
		loop invariant result < b ==> \forall integer i; l <= i < c ==> (i % code == 0 || i % code != 0);
		loop invariant result < b ==> \forall integer i; l <= i < c ==> (i % code != 0 ==> result >= 1);
		loop invariant result < b ==> \forall integer i; l <= i < c ==> (i % code != 0 ==> result >= 0);
		loop invariant result < b ==> \forall integer i; l <= i < c ==> (i % code != 0 ==> result > 0);
		loop invariant result < b ==> \exists integer t; l <= t < c && t % code != 0 ==> result > 0;
		loop invariant l <= c;
		loop invariant \forall integer t; l <= t < c && t % code != 0 ==> result >= 1;
		loop invariant \forall integer k; l <= k < c ==> (k % code == 0 || result >= 1);
		loop invariant \forall integer k; l <= k < c ==> (k % code == 0 || k % code != 0);
		loop invariant \forall integer k; l <= k < c ==> (k % code == 0 ==> result >= 0);
		loop invariant \forall integer k; l <= k < c ==> (k % code == 0 ==> result <= c - l);
		loop invariant \forall integer k; l <= k < c ==> (k % code != 0 ==> result >= 1);
		loop invariant \forall integer k; l <= k < c ==> (k % code != 0 ==> result >= 0);
		loop invariant \forall integer i; l <= i < c ==> i <= m;
		loop invariant \forall integer i; l <= i < c ==> (i % code == 0 || result >= 0);
		loop invariant \forall integer i; l <= i < c ==> (i % code == 0 || result > 0);
		loop invariant \forall integer i; l <= i < c ==> (i % code == 0 || i % code != 0);
		loop invariant \forall integer i; l <= i < c ==> (i % code == 0 ==> result >= 0);
		loop invariant \forall integer i; l <= i < c ==> (i % code == 0 ==> result <= c - l);
		loop invariant \forall integer i; l <= i < c ==> (i % code != 0 ==> result >= 1);
		loop invariant \forall integer i; l <= i < c ==> (i % code != 0 ==> result >= 0);
		loop invariant \forall integer i; l <= i < c ==> (i % code != 0 ==> result > 0);
		loop invariant \exists integer t; l <= t <= c ==> t % code != 0;
		loop invariant \exists integer t; l <= t < c ==> t % code != 0;
		loop invariant \exists integer t; l <= t < c && t % code != 0 ==> result >= 1;
		loop invariant \exists integer t; l <= t < c && t % code != 0 ==> result >= 0;
		loop invariant \exists integer t; l <= t < c && t % code != 0 ==> result > 0;
		loop invariant 0 <= result;
		loop invariant 0 <= c - l - result;
		loop assigns result;
		loop assigns c;*/
int stub_B(int code, int b, int l, int m);

/*@loop invariant result > 0 ==> l <= c;
		loop invariant result > 0 ==> l < c;
		loop invariant result > 0 ==> c > l;
		loop invariant result > 0 ==> \exists integer k; l <= k < c && k % code != 0;
		loop invariant result > 0 ==> \exists integer i; l <= i < c && i % code != 0;
		loop invariant result == c - l ==> \forall integer k; l <= k < c ==> k % code != 0;
		loop invariant result == c - l ==> \forall integer i; l <= i < c ==> i % code != 0;
		loop invariant result == 0 || result >= 0;
		loop invariant result == 0 || result > 0;
		loop invariant result == 0 ==> \forall integer k; l <= k < c ==> k % code == 0;
		loop invariant result == 0 ==> \forall integer i; l <= i < c ==> i % code == 0;
		loop invariant result <= c - l;
		loop invariant result <= c - l + 1;
		loop invariant result < b ==> result <= c - l;
		loop invariant result < b ==> result <= c - l + 1;
		loop invariant result < b ==> result <= b;
		loop invariant result < b ==> result < c - l + 1;
		loop invariant result < b ==> result < b;
		loop invariant result < b ==> \forall integer k; l <= k < c ==> (k % code == 0 || k % code != 0);
		loop invariant result < b ==> \forall integer i; l <= i < c ==> (i % code == 0 || result >= 0);
		loop invariant result < b ==> \forall integer i; l <= i < c ==> (i % code == 0 || result > 0);
		loop invariant result < b ==> \forall integer i; l <= i < c ==> (i % code == 0 || i % code != 0);
		loop invariant result < b ==> \forall integer i; l <= i < c ==> (i % code != 0 ==> result >= 1);
		loop invariant result < b ==> \forall integer i; l <= i < c ==> (i % code != 0 ==> result >= 0);
		loop invariant result < b ==> \forall integer i; l <= i < c ==> (i % code != 0 ==> result > 0);
		loop invariant result < b ==> \exists integer t; l <= t < c && t % code != 0 ==> result > 0;
		loop invariant l <= c;
		loop invariant \forall integer t; l <= t < c && t % code != 0 ==> result >= 1;
		loop invariant \forall integer k; l <= k < c ==> (k % code == 0 || result >= 1);
		loop invariant \forall integer k; l <= k < c ==> (k % code == 0 || k % code != 0);
		loop invariant \forall integer k; l <= k < c ==> (k % code == 0 ==> result >= 0);
		loop invariant \forall integer k; l <= k < c ==> (k % code == 0 ==> result <= c - l);
		loop invariant \forall integer k; l <= k < c ==> (k % code != 0 ==> result >= 1);
		loop invariant \forall integer k; l <= k < c ==> (k % code != 0 ==> result >= 0);
		loop invariant \forall integer i; l <= i < c ==> i <= m;
		loop invariant \forall integer i; l <= i < c ==> (i % code == 0 || result >= 0);
		loop invariant \forall integer i; l <= i < c ==> (i % code == 0 || result > 0);
		loop invariant \forall integer i; l <= i < c ==> (i % code == 0 || i % code != 0);
		loop invariant \forall integer i; l <= i < c ==> (i % code == 0 ==> result >= 0);
		loop invariant \forall integer i; l <= i < c ==> (i % code == 0 ==> result <= c - l);
		loop invariant \forall integer i; l <= i < c ==> (i % code != 0 ==> result >= 1);
		loop invariant \forall integer i; l <= i < c ==> (i % code != 0 ==> result >= 0);
		loop invariant \forall integer i; l <= i < c ==> (i % code != 0 ==> result > 0);
		loop invariant \exists integer t; l <= t <= c ==> t % code != 0;
		loop invariant \exists integer t; l <= t < c ==> t % code != 0;
		loop invariant \exists integer t; l <= t < c && t % code != 0 ==> result >= 1;
		loop invariant \exists integer t; l <= t < c && t % code != 0 ==> result >= 0;
		loop invariant \exists integer t; l <= t < c && t % code != 0 ==> result > 0;
		loop invariant 0 <= result;
		loop invariant 0 <= c - l - result;
		loop assigns result;
		loop assigns c;*/
int check_A_implies_B(int code, int b, int l, int m) {
    return stub_A(code, b, l, m);
}

/*@loop invariant c >= l;
          loop invariant 0 <= result;
          loop invariant result == count_nondiv(code, l, c - 1);
          loop invariant 0 <= result <= c - l;
          loop invariant result == 0 || (\exists integer i; l <= i < c && i % code != 0);
          loop invariant m == \at(m,Pre);
          loop invariant l == \at(l,Pre);
          loop invariant b == \at(b,Pre);
          loop invariant code == \at(code,Pre);
          loop invariant (c > m) ==> (result == count_nondiv(code, l, m));
          loop assigns c, result;*/
int check_B_implies_A(int code, int b, int l, int m) {
    return stub_B(code, b, l, m);
}
