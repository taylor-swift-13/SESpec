#include <limits.h>
#include <stdlib.h>


/*@ logic integer fib(integer n) =
      n <= 1 ? n : fib(n - 1) + fib(n - 2);
*/

/*@requires seed >= 1;*/
int stub_A(int seed);

/*@loop invariant result_len == seed + 1;
		loop invariant result[1] == 1;
		loop invariant result[0] == 2;
		loop invariant result[0] == 2 && result[1] == 1;
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= result[k-2];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= result[k-1];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= result[k-1] || result[k] >= result[k-2];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= result[k - 2];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= result[k - 2] && result[k] >= result[k - 1];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= result[k - 1];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= result[k - 1] || result[k] >= result[k - 2];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= result[k - 1] && result[k] >= result[k - 2];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= 2;
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= 1;
		loop invariant \forall integer k; 2 <= k < l ==> result[k] > result[k-2];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] > result[k-1];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] > 0;
		loop invariant \forall integer k; 2 <= k < l ==> result[k] == result[k-1] + result[k-2];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] == result[k - 1] + result[k - 2];
		loop invariant \forall integer k; 0 <= k < l ==> result[k] >= 1;
		loop invariant \forall integer k; 0 <= k < l ==> result[k] >= 0;
		loop invariant \forall integer k; 0 <= k < l ==> result[k] > 0;
		loop invariant \forall integer k; 0 <= k < l ==> (k >= 2 ==> result[k] >= result[k - 2]);
		loop invariant \forall integer k; 0 <= k < l ==> (k >= 2 ==> result[k] > 0);
		loop invariant \forall integer k; 0 <= k < l ==> (k >= 2 ==> result[k] == result[k - 1] + result[k - 2]);
		loop invariant \forall integer k; 0 <= k < l ==> (k == 1 ==> result[k] == 1);
		loop invariant \forall integer k; 0 <= k < l ==> (k == 0 ? result[k] == 2 : (k == 1 ? result[k] == 1 : result[k] > result[k-1]));
		loop invariant \forall integer k; 0 <= k < l ==> (k == 0 ? result[k] == 2 : (k == 1 ? result[k] == 1 : result[k] > 0));
		loop invariant \forall integer k; 0 <= k < l ==> (k == 0 ? result[k] == 2 : (k == 1 ? result[k] == 1 : result[k] == result[k-1] + result[k-2]));
		loop invariant \forall integer k; 0 <= k < l ==> (k == 0 ? result[k] == 2 : (k == 1 ? result[k] == 1 : result[k] == result[k - 1] + result[k - 2]));
		loop invariant \forall integer k; 0 <= k < l ==> (k == 0 ==> result[k] == 2);
		loop invariant \forall integer k; 0 <= k < l ==> (k < 2 || result[k] >= result[k-2]);
		loop invariant \forall integer k; 0 <= k < l ==> (k < 2 || result[k] >= result[k-1]);
		loop invariant \forall integer k; 0 <= k < l ==> (k < 2 || result[k] >= result[k - 2]);
		loop invariant \forall integer k; 0 <= k < l ==> (k < 2 || result[k] >= result[k - 1]);
		loop invariant \forall integer k; 0 <= k < l ==> (k < 2 || result[k] >= 1);
		loop invariant \forall integer k; 0 <= k < l ==> (k < 2 || result[k] > 0);
		loop invariant \forall integer k; 0 <= k < l ==> (k < 2 || result[k] == result[k - 1] + result[k - 2]);
		loop invariant \forall integer k; 0 <= k < l && k >= 2 ==> result[k] == result[k - 1] + result[k - 2];
		loop invariant \forall integer k; 0 <= k < l && k < result_len ==> result[k] >= result[k - 1] || k < 2;
		loop invariant \forall integer k; 0 <= k < l && k < result_len ==> result[k] >= 1;
		loop invariant \forall integer k; 0 <= k < l && k < result_len ==> result[k] > 0;
		loop invariant \forall integer k; 0 <= k < l && k < result_len ==> result[k] == (k == 0 ? 2 : (k == 1 ? 1 : result[k-1] + result[k-2]));
		loop invariant \forall integer k; 0 <= k < l && k < result_len ==> (k == 0 ? result[k] == 2 : (k == 1 ? result[k] == 1 : result[k] == result[k-1] + result[k-2]));
		loop invariant \forall integer k; 0 <= k < l && k < result_len ==> (k < 2 || result[k] == result[k - 1] + result[k - 2]);
		loop invariant \forall integer k; 0 <= k < l && k < 2 ==> result[k] == (k == 0 ? 2 : 1);
		loop invariant \forall integer k; 0 <= k < 2 ==> result[k] == (k == 0 ? 2 : 1);
		loop invariant 2 <= l;
		loop assigns result[2..seed];
		loop assigns result[0..seed];
		loop assigns l;*/
int stub_B(int seed);

/*@loop invariant result_len == seed + 1;
		loop invariant result[1] == 1;
		loop invariant result[0] == 2;
		loop invariant result[0] == 2 && result[1] == 1;
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= result[k-2];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= result[k-1];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= result[k-1] || result[k] >= result[k-2];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= result[k - 2];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= result[k - 2] && result[k] >= result[k - 1];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= result[k - 1];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= result[k - 1] || result[k] >= result[k - 2];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= result[k - 1] && result[k] >= result[k - 2];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= 2;
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= 1;
		loop invariant \forall integer k; 2 <= k < l ==> result[k] > result[k-2];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] > result[k-1];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] > 0;
		loop invariant \forall integer k; 2 <= k < l ==> result[k] == result[k-1] + result[k-2];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] == result[k - 1] + result[k - 2];
		loop invariant \forall integer k; 0 <= k < l ==> result[k] >= 1;
		loop invariant \forall integer k; 0 <= k < l ==> result[k] >= 0;
		loop invariant \forall integer k; 0 <= k < l ==> result[k] > 0;
		loop invariant \forall integer k; 0 <= k < l ==> (k >= 2 ==> result[k] >= result[k - 2]);
		loop invariant \forall integer k; 0 <= k < l ==> (k >= 2 ==> result[k] > 0);
		loop invariant \forall integer k; 0 <= k < l ==> (k >= 2 ==> result[k] == result[k - 1] + result[k - 2]);
		loop invariant \forall integer k; 0 <= k < l ==> (k == 1 ==> result[k] == 1);
		loop invariant \forall integer k; 0 <= k < l ==> (k == 0 ? result[k] == 2 : (k == 1 ? result[k] == 1 : result[k] > result[k-1]));
		loop invariant \forall integer k; 0 <= k < l ==> (k == 0 ? result[k] == 2 : (k == 1 ? result[k] == 1 : result[k] > 0));
		loop invariant \forall integer k; 0 <= k < l ==> (k == 0 ? result[k] == 2 : (k == 1 ? result[k] == 1 : result[k] == result[k-1] + result[k-2]));
		loop invariant \forall integer k; 0 <= k < l ==> (k == 0 ? result[k] == 2 : (k == 1 ? result[k] == 1 : result[k] == result[k - 1] + result[k - 2]));
		loop invariant \forall integer k; 0 <= k < l ==> (k == 0 ==> result[k] == 2);
		loop invariant \forall integer k; 0 <= k < l ==> (k < 2 || result[k] >= result[k-2]);
		loop invariant \forall integer k; 0 <= k < l ==> (k < 2 || result[k] >= result[k-1]);
		loop invariant \forall integer k; 0 <= k < l ==> (k < 2 || result[k] >= result[k - 2]);
		loop invariant \forall integer k; 0 <= k < l ==> (k < 2 || result[k] >= result[k - 1]);
		loop invariant \forall integer k; 0 <= k < l ==> (k < 2 || result[k] >= 1);
		loop invariant \forall integer k; 0 <= k < l ==> (k < 2 || result[k] > 0);
		loop invariant \forall integer k; 0 <= k < l ==> (k < 2 || result[k] == result[k - 1] + result[k - 2]);
		loop invariant \forall integer k; 0 <= k < l && k >= 2 ==> result[k] == result[k - 1] + result[k - 2];
		loop invariant \forall integer k; 0 <= k < l && k < result_len ==> result[k] >= result[k - 1] || k < 2;
		loop invariant \forall integer k; 0 <= k < l && k < result_len ==> result[k] >= 1;
		loop invariant \forall integer k; 0 <= k < l && k < result_len ==> result[k] > 0;
		loop invariant \forall integer k; 0 <= k < l && k < result_len ==> result[k] == (k == 0 ? 2 : (k == 1 ? 1 : result[k-1] + result[k-2]));
		loop invariant \forall integer k; 0 <= k < l && k < result_len ==> (k == 0 ? result[k] == 2 : (k == 1 ? result[k] == 1 : result[k] == result[k-1] + result[k-2]));
		loop invariant \forall integer k; 0 <= k < l && k < result_len ==> (k < 2 || result[k] == result[k - 1] + result[k - 2]);
		loop invariant \forall integer k; 0 <= k < l && k < 2 ==> result[k] == (k == 0 ? 2 : 1);
		loop invariant \forall integer k; 0 <= k < 2 ==> result[k] == (k == 0 ? 2 : 1);
		loop invariant 2 <= l;
		loop assigns result[2..seed];
		loop assigns result[0..seed];
		loop assigns l;*/
int check_A_implies_B(int seed) {
    return stub_A(seed);
}

/*@requires seed >= 1;*/
int check_B_implies_A(int seed) {
    return stub_B(seed);
}
