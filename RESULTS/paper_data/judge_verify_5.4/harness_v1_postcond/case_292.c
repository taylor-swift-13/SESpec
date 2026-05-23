#include <limits.h>
#include <stdlib.h>


/*@ logic integer rec(integer n) =
      n == 0 ? 0 :
      n == 1 ? 1 :
      (2 * rec(n - 1) + rec(n - 2)) % 1000000000;
*/

/*@requires seed == 1;
  
  ensures seed >= 1 ==> \result >= 0;
  ensures seed == 1 ==> \result == 1;
  ensures seed >= 2 ==> \result == (2 * rec(seed - 1) + rec(seed - 2)) % 1000000000;*/
int stub_A(int seed);

/*@loop invariant p_len == seed + 1;
		loop invariant p[1] == 1;
		loop invariant p[0] == 0;
		loop invariant p[0] == 0 && p[1] == 1;
		loop invariant \forall integer k; 2 <= k < count ==> p[k] == (2 * p[k - 1] + p[k - 2]) % 1000000000;
		loop invariant \forall integer k; 2 <= k < count ==> p[k] == ((2 * p[k - 1] + p[k - 2]) % 1000000000);
		loop invariant \forall integer k; 2 <= k < count ==> 0 <= p[k] < 1000000000;
		loop invariant \forall integer k; 0 <= k < count ==> p[k] >= 0;
		loop invariant \forall integer k; 0 <= k < count ==> p[k] == p[k];
		loop invariant \forall integer k; 0 <= k < count ==> p[k] < 1000000000;
		loop invariant \forall integer k; 0 <= k < count ==> 0 <= p[k] < 1000000000;
		loop invariant \forall integer k; 0 <= k < count && k >= 2 ==> p[k] == (2 * p[k - 1] + p[k - 2]) % 1000000000;
		loop invariant \forall integer k; 0 <= k < count && k < 2 ==> (k == 0 ==> p[k] == 0) && (k == 1 ==> p[k] == 1);
		loop invariant \forall integer k; 0 <= k < 2 ==> (k == 0 ==> p[k] == 0) && (k == 1 ==> p[k] == 1);
		loop invariant \forall integer i; 2 <= i < count ==> p[i] == (2 * p[i - 1] + p[i - 2]) % 1000000000;
		loop invariant \forall integer i; 2 <= i < count ==> p[i] == ((2 * p[i-1] + p[i-2]) % 1000000000);
		loop invariant \forall integer i; 2 <= i < count ==> p[i] == ((2 * p[i - 1] + p[i - 2]) % 1000000000);
		loop invariant \forall integer i; 2 <= i < count ==> 0 <= p[i] < 1000000000;
		loop invariant \forall integer i; 0 <= i < count ==> p[i] >= 0;
		loop invariant \forall integer i; 0 <= i < count ==> p[i] == p[i];
		loop invariant \forall integer i; 0 <= i < count ==> p[i] < 1000000000;
		loop invariant \forall integer i; 0 <= i < count ==> 0 <= p[i] < 1000000000;
		loop invariant \forall integer i; 0 <= i < count && i < 2 ==> (i == 0 ==> p[i] == 0) && (i == 1 ==> p[i] == 1);
		loop invariant \forall integer i; 0 <= i < 2 ==> (i == 0 ==> p[i] == 0) && (i == 1 ==> p[i] == 1);
		loop invariant 2 <= count;
		loop assigns p[2..seed];
		loop assigns p[0..seed];
		loop assigns count;*/
int stub_B(int seed);

/*@loop invariant p_len == seed + 1;
		loop invariant p[1] == 1;
		loop invariant p[0] == 0;
		loop invariant p[0] == 0 && p[1] == 1;
		loop invariant \forall integer k; 2 <= k < count ==> p[k] == (2 * p[k - 1] + p[k - 2]) % 1000000000;
		loop invariant \forall integer k; 2 <= k < count ==> p[k] == ((2 * p[k - 1] + p[k - 2]) % 1000000000);
		loop invariant \forall integer k; 2 <= k < count ==> 0 <= p[k] < 1000000000;
		loop invariant \forall integer k; 0 <= k < count ==> p[k] >= 0;
		loop invariant \forall integer k; 0 <= k < count ==> p[k] == p[k];
		loop invariant \forall integer k; 0 <= k < count ==> p[k] < 1000000000;
		loop invariant \forall integer k; 0 <= k < count ==> 0 <= p[k] < 1000000000;
		loop invariant \forall integer k; 0 <= k < count && k >= 2 ==> p[k] == (2 * p[k - 1] + p[k - 2]) % 1000000000;
		loop invariant \forall integer k; 0 <= k < count && k < 2 ==> (k == 0 ==> p[k] == 0) && (k == 1 ==> p[k] == 1);
		loop invariant \forall integer k; 0 <= k < 2 ==> (k == 0 ==> p[k] == 0) && (k == 1 ==> p[k] == 1);
		loop invariant \forall integer i; 2 <= i < count ==> p[i] == (2 * p[i - 1] + p[i - 2]) % 1000000000;
		loop invariant \forall integer i; 2 <= i < count ==> p[i] == ((2 * p[i-1] + p[i-2]) % 1000000000);
		loop invariant \forall integer i; 2 <= i < count ==> p[i] == ((2 * p[i - 1] + p[i - 2]) % 1000000000);
		loop invariant \forall integer i; 2 <= i < count ==> 0 <= p[i] < 1000000000;
		loop invariant \forall integer i; 0 <= i < count ==> p[i] >= 0;
		loop invariant \forall integer i; 0 <= i < count ==> p[i] == p[i];
		loop invariant \forall integer i; 0 <= i < count ==> p[i] < 1000000000;
		loop invariant \forall integer i; 0 <= i < count ==> 0 <= p[i] < 1000000000;
		loop invariant \forall integer i; 0 <= i < count && i < 2 ==> (i == 0 ==> p[i] == 0) && (i == 1 ==> p[i] == 1);
		loop invariant \forall integer i; 0 <= i < 2 ==> (i == 0 ==> p[i] == 0) && (i == 1 ==> p[i] == 1);
		loop invariant 2 <= count;
		loop assigns p[2..seed];
		loop assigns p[0..seed];
		loop assigns count;*/
int check_A_implies_B(int seed) {
    return stub_A(seed);
}

/*@requires seed == 1;
  
  ensures seed >= 1 ==> \result >= 0;
  ensures seed == 1 ==> \result == 1;
  ensures seed >= 2 ==> \result == (2 * rec(seed - 1) + rec(seed - 2)) % 1000000000;*/
int check_B_implies_A(int seed) {
    return stub_B(seed);
}
