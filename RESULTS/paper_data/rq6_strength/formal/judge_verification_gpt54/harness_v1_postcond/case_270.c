#include <limits.h>
#include <stdlib.h>


/*@ logic integer foo270_seq(integer m, integer count) =
      count == 2 ? m * m :
      count > 2 ? ((m - 1) * (foo270_seq(m, count - 1) + foo270_seq(m, count - 2))) % 1000000007 :
      1;
*/

/*@requires count == 2;
  
  
  ensures count == 2 ==> \result == m * m;
  ensures count > 2 ==> \result == ((m - 1) * (foo270_seq(m, count - 1) + foo270_seq(m, count - 2))) % 1000000007;*/
int stub_A(int count, int m);

/*@loop invariant 3 <= d ==> 0 <= d - 3;
		loop invariant w == 1000000007;
		loop invariant w == 1000000007 && div_len == count + 1;
		loop invariant div_len == count + 1;
		loop invariant div_len == count + 1 && w == 1000000007;
		loop invariant div[2] == m * m;
		loop invariant div[1] == m;
		loop invariant div[0] == 1;
		loop invariant div[0] == 1 && div[1] == m && div[2] == m * m;
		loop invariant d >= 3 ==> div_len == count + 1;
		loop invariant d >= 3 ==> div[0] == 1 && div[1] == m && div[2] == m * m;
		loop invariant count >= 2 ==> div[0] == 1 && div[1] == m && div[2] == m * m;
		loop invariant count + 1 == div_len;
		loop invariant \forall integer k; 0 <= k < d ==> div[k] == div[k];
		loop invariant \forall integer k; 0 <= k < d ==> div[k] == (k == 0 ? 1 : (k == 1 ? m : (k == 2 ? m * m : div[k])));
		loop invariant \forall integer k; 0 <= k < d ==> (k == 2 ==> div[k] == m * m);
		loop invariant \forall integer k; 0 <= k < d ==> (k == 1 ==> div[k] == m);
		loop invariant \forall integer k; 0 <= k < d ==> (k == 0 ? div[k] == 1 : (k == 1 ? div[k] == m : (k == 2 ? div[k] == m * m : 1)));
		loop invariant \forall integer k; 0 <= k < d ==> (k == 0 ==> div[k] == 1);
		loop invariant \forall integer k; 0 <= k < d ==> (k < 3 ==> div[k] == (k == 0 ? 1 : (k == 1 ? m : m * m)));
		loop invariant \forall integer k; 0 <= k < d ==> (k < 3 ==> (k == 0 ? div[k] == 1 : (k == 1 ? div[k] == m : div[k] == m * m)));
		loop invariant \forall integer k; 0 <= k < d && k <= count ==> (k == 0 ? div[k] == 1 : (k == 1 ? div[k] == m : (k == 2 ? div[k] == m * m : 1)));
		loop invariant \forall integer k; 0 <= k < d && k <= 2 ==> div[k] == (k == 0 ? 1 : (k == 1 ? m : m * m));
		loop invariant \forall integer k; 0 <= k < d && k < count + 1 ==> div[k] == (k == 0 ? 1 : (k == 1 ? m : (k == 2 ? m * m : div[k])));
		loop invariant \forall integer k; 0 <= k < d && k < 3 ==> div[k] == (k == 0 ? 1 : (k == 1 ? m : m * m));
		loop invariant \forall integer k; 0 <= k < d && k < 3 ==> (k == 2 ==> div[k] == m * m);
		loop invariant \forall integer k; 0 <= k < d && k < 3 ==> (k == 1 ==> div[k] == m);
		loop invariant \forall integer k; 0 <= k < d && k < 3 ==> (k == 0 ==> div[k] == 1);
		loop invariant \forall integer k; 0 <= k < 3 ==> div[k] == (k == 0 ? 1 : (k == 1 ? m : m * m));
		loop invariant 3 <= d;
		loop invariant 3 <= d ==> div[2] == m * m;
		loop invariant 3 <= d ==> div[1] == m;
		loop invariant 3 <= d ==> div[0] == 1;
		loop invariant 2 <= d - 1;
		loop invariant 2 < d;
		loop invariant 1 <= w;
		loop invariant 0 <= d;
		loop invariant 0 <= d ==> div_len == count + 1;
		loop invariant 0 <= d - 3;
		loop invariant 0 < w;
		loop assigns div[3..count];
		loop assigns div[0..count];
		loop assigns d;*/
int stub_B(int count, int m);

/*@loop invariant 3 <= d ==> 0 <= d - 3;
		loop invariant w == 1000000007;
		loop invariant w == 1000000007 && div_len == count + 1;
		loop invariant div_len == count + 1;
		loop invariant div_len == count + 1 && w == 1000000007;
		loop invariant div[2] == m * m;
		loop invariant div[1] == m;
		loop invariant div[0] == 1;
		loop invariant div[0] == 1 && div[1] == m && div[2] == m * m;
		loop invariant d >= 3 ==> div_len == count + 1;
		loop invariant d >= 3 ==> div[0] == 1 && div[1] == m && div[2] == m * m;
		loop invariant count >= 2 ==> div[0] == 1 && div[1] == m && div[2] == m * m;
		loop invariant count + 1 == div_len;
		loop invariant \forall integer k; 0 <= k < d ==> div[k] == div[k];
		loop invariant \forall integer k; 0 <= k < d ==> div[k] == (k == 0 ? 1 : (k == 1 ? m : (k == 2 ? m * m : div[k])));
		loop invariant \forall integer k; 0 <= k < d ==> (k == 2 ==> div[k] == m * m);
		loop invariant \forall integer k; 0 <= k < d ==> (k == 1 ==> div[k] == m);
		loop invariant \forall integer k; 0 <= k < d ==> (k == 0 ? div[k] == 1 : (k == 1 ? div[k] == m : (k == 2 ? div[k] == m * m : 1)));
		loop invariant \forall integer k; 0 <= k < d ==> (k == 0 ==> div[k] == 1);
		loop invariant \forall integer k; 0 <= k < d ==> (k < 3 ==> div[k] == (k == 0 ? 1 : (k == 1 ? m : m * m)));
		loop invariant \forall integer k; 0 <= k < d ==> (k < 3 ==> (k == 0 ? div[k] == 1 : (k == 1 ? div[k] == m : div[k] == m * m)));
		loop invariant \forall integer k; 0 <= k < d && k <= count ==> (k == 0 ? div[k] == 1 : (k == 1 ? div[k] == m : (k == 2 ? div[k] == m * m : 1)));
		loop invariant \forall integer k; 0 <= k < d && k <= 2 ==> div[k] == (k == 0 ? 1 : (k == 1 ? m : m * m));
		loop invariant \forall integer k; 0 <= k < d && k < count + 1 ==> div[k] == (k == 0 ? 1 : (k == 1 ? m : (k == 2 ? m * m : div[k])));
		loop invariant \forall integer k; 0 <= k < d && k < 3 ==> div[k] == (k == 0 ? 1 : (k == 1 ? m : m * m));
		loop invariant \forall integer k; 0 <= k < d && k < 3 ==> (k == 2 ==> div[k] == m * m);
		loop invariant \forall integer k; 0 <= k < d && k < 3 ==> (k == 1 ==> div[k] == m);
		loop invariant \forall integer k; 0 <= k < d && k < 3 ==> (k == 0 ==> div[k] == 1);
		loop invariant \forall integer k; 0 <= k < 3 ==> div[k] == (k == 0 ? 1 : (k == 1 ? m : m * m));
		loop invariant 3 <= d;
		loop invariant 3 <= d ==> div[2] == m * m;
		loop invariant 3 <= d ==> div[1] == m;
		loop invariant 3 <= d ==> div[0] == 1;
		loop invariant 2 <= d - 1;
		loop invariant 2 < d;
		loop invariant 1 <= w;
		loop invariant 0 <= d;
		loop invariant 0 <= d ==> div_len == count + 1;
		loop invariant 0 <= d - 3;
		loop invariant 0 < w;
		loop assigns div[3..count];
		loop assigns div[0..count];
		loop assigns d;*/
int check_A_implies_B(int count, int m) {
    return stub_A(count, m);
}

/*@requires count == 2;
  
  
  ensures count == 2 ==> \result == m * m;
  ensures count > 2 ==> \result == ((m - 1) * (foo270_seq(m, count - 1) + foo270_seq(m, count - 2))) % 1000000007;*/
int check_B_implies_A(int count, int m) {
    return stub_B(count, m);
}
