#include <limits.h>
#include <stdlib.h>


/*@ logic integer fib295(integer n) =
      n <= 0 ? 2 :
      n == 1 ? 1 :
      fib295(n - 1) + fib295(n - 2);
*/

/*@requires num >= 1;
    ensures \result == fib295(num);*/
int stub_A(int num);

/*@loop invariant result_len == num + 1;
		loop invariant result[1] == 1;
		loop invariant result[0] == 2;
		loop invariant result[0] == 2 && result[1] == 1;
		loop invariant l == 2 ==> result[0] == 2 && result[1] == 1;
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= result[k-2];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= result[k-1];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= result[k - 2];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= result[k - 1];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= 1;
		loop invariant \forall integer k; 2 <= k < l ==> result[k] > result[k-2];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] > result[k-1];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] > result[k - 2];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] > result[k - 1];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] > 0;
		loop invariant \forall integer k; 2 <= k < l ==> result[k] == result[k-1] + result[k-2];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] == result[k - 1] + result[k - 2];
		loop invariant \forall integer k; 0 <= k < l ==> result[k] >= 1;
		loop invariant \forall integer k; 0 <= k < l ==> result[k] >= 0;
		loop invariant \forall integer k; 0 <= k < l ==> result[k] > 0;
		loop invariant \forall integer k; 0 <= k < l ==> (k == 0 ==> result[k] == 2) && (k == 1 ==> result[k] == 1);
		loop invariant \forall integer k; 0 <= k < l ==> (k < 2 ==> ((k == 0 ==> result[k] == 2) && (k == 1 ==> result[k] == 1)));
		loop invariant \forall integer k; 0 <= k < l && k >= 2 ==> result[k] > 0;
		loop invariant \forall integer k; 0 <= k < l && k >= 2 ==> result[k] == result[k-1] + result[k-2];
		loop invariant \forall integer k; 0 <= k < l && k >= 2 ==> result[k] == result[k - 1] + result[k - 2];
		loop invariant \forall integer k; 0 <= k < l && k <= num ==> result[k] >= 1;
		loop invariant \forall integer k; 0 <= k < l && k <= num ==> result[k] >= 0;
		loop invariant \forall integer k; 0 <= k < l && k <= num ==> result[k] > 0;
		loop invariant \forall integer k; 0 <= k < l && k < result_len ==> result[k] >= 1;
		loop invariant \forall integer k; 0 <= k < l && k < result_len ==> result[k] >= 0;
		loop invariant \forall integer k; 0 <= k < l && k < result_len ==> result[k] > 0;
		loop invariant \forall integer k; 0 <= k < l && k < 2 ==> (k == 0 ==> result[k] == 2) && (k == 1 ==> result[k] == 1);
		loop invariant \forall integer k; 0 <= k < l && k < 2 ==> ((k == 0 ==> result[k] == 2) && (k == 1 ==> result[k] == 1));
		loop invariant 2 <= l;
		loop assigns result[2..num];
		loop assigns result[0..num];
		loop assigns l;*/
int stub_B(int num);

/*@loop invariant result_len == num + 1;
		loop invariant result[1] == 1;
		loop invariant result[0] == 2;
		loop invariant result[0] == 2 && result[1] == 1;
		loop invariant l == 2 ==> result[0] == 2 && result[1] == 1;
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= result[k-2];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= result[k-1];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= result[k - 2];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= result[k - 1];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] >= 1;
		loop invariant \forall integer k; 2 <= k < l ==> result[k] > result[k-2];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] > result[k-1];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] > result[k - 2];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] > result[k - 1];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] > 0;
		loop invariant \forall integer k; 2 <= k < l ==> result[k] == result[k-1] + result[k-2];
		loop invariant \forall integer k; 2 <= k < l ==> result[k] == result[k - 1] + result[k - 2];
		loop invariant \forall integer k; 0 <= k < l ==> result[k] >= 1;
		loop invariant \forall integer k; 0 <= k < l ==> result[k] >= 0;
		loop invariant \forall integer k; 0 <= k < l ==> result[k] > 0;
		loop invariant \forall integer k; 0 <= k < l ==> (k == 0 ==> result[k] == 2) && (k == 1 ==> result[k] == 1);
		loop invariant \forall integer k; 0 <= k < l ==> (k < 2 ==> ((k == 0 ==> result[k] == 2) && (k == 1 ==> result[k] == 1)));
		loop invariant \forall integer k; 0 <= k < l && k >= 2 ==> result[k] > 0;
		loop invariant \forall integer k; 0 <= k < l && k >= 2 ==> result[k] == result[k-1] + result[k-2];
		loop invariant \forall integer k; 0 <= k < l && k >= 2 ==> result[k] == result[k - 1] + result[k - 2];
		loop invariant \forall integer k; 0 <= k < l && k <= num ==> result[k] >= 1;
		loop invariant \forall integer k; 0 <= k < l && k <= num ==> result[k] >= 0;
		loop invariant \forall integer k; 0 <= k < l && k <= num ==> result[k] > 0;
		loop invariant \forall integer k; 0 <= k < l && k < result_len ==> result[k] >= 1;
		loop invariant \forall integer k; 0 <= k < l && k < result_len ==> result[k] >= 0;
		loop invariant \forall integer k; 0 <= k < l && k < result_len ==> result[k] > 0;
		loop invariant \forall integer k; 0 <= k < l && k < 2 ==> (k == 0 ==> result[k] == 2) && (k == 1 ==> result[k] == 1);
		loop invariant \forall integer k; 0 <= k < l && k < 2 ==> ((k == 0 ==> result[k] == 2) && (k == 1 ==> result[k] == 1));
		loop invariant 2 <= l;
		loop assigns result[2..num];
		loop assigns result[0..num];
		loop assigns l;*/
int check_A_implies_B(int num) {
    return stub_A(num);
}

/*@requires num >= 1;
    ensures \result == fib295(num);*/
int check_B_implies_A(int num) {
    return stub_B(num);
}
