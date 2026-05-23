#include <limits.h>
#include <stdlib.h>


/*@
  logic integer recN(int* N, integer i) =
      i <= 0 ? 2 :
      i == 1 ? 1 :
      recN(N, i - 1) + 2 * recN(N, i - 2);
*/

/*@loop invariant 2 <= p;
          loop invariant N[0] == 2;
          loop invariant N[1] == 1;
          loop invariant \forall integer k; 2 <= k < p ==> N[k] == N[k - 1] + 2 * N[k - 2];
          loop assigns p, N[0 .. c];*/
int stub_A(int c);

/*@loop invariant \forall integer k; 2 <= k < p ==> N[k] >= N[k - 2];
		loop invariant \forall integer k; 2 <= k < p ==> N[k] >= N[k - 1];
		loop invariant \forall integer k; 2 <= k < p ==> N[k] >= 2 * N[k - 2];
		loop invariant \forall integer k; 2 <= k < p ==> N[k] > N[k - 1];
		loop invariant \forall integer k; 2 <= k < p ==> N[k] == N[k - 1] + 2 * N[k - 2];
		loop invariant \forall integer k; 0 <= k < p ==> N[k] >= 1;
		loop invariant \forall integer k; 0 <= k < p ==> N[k] >= 0;
		loop invariant \forall integer k; 0 <= k < p ==> N[k] > 0;
		loop invariant \forall integer k; 0 <= k < p ==> N[k] == (k == 0 ? 2 : (k == 1 ? 1 : N[k]));
		loop invariant \forall integer k; 0 <= k < p ==> N[k] != 0;
		loop invariant \forall integer k; 0 <= k < p ==> (k >= 2 ==> N[k] == N[k - 1] + 2 * N[k - 2]);
		loop invariant \forall integer k; 0 <= k < p ==> (k == 1 ==> N[k] == 1);
		loop invariant \forall integer k; 0 <= k < p ==> (k == 0 ==> N[k] == 2);
		loop invariant \forall integer k; 0 <= k < 2 ==> N[k] == (k == 0 ? 2 : 1);
		loop invariant \forall integer i; 2 <= i < p ==> N[i] >= N[i - 2];
		loop invariant \forall integer i; 2 <= i < p ==> N[i] >= N[i - 1];
		loop invariant \forall integer i; 2 <= i < p ==> N[i] == N[i - 1] + 2 * N[i - 2];
		loop invariant \forall integer i; 0 <= i < p ==> N[i] >= 1;
		loop invariant \forall integer i; 0 <= i < p ==> N[i] >= 0;
		loop invariant \forall integer i; 0 <= i < p ==> N[i] > 0;
		loop invariant \forall integer i; 0 <= i < p ==> N[i] != 0;
		loop invariant \forall integer i; 0 <= i < 2 ==> N[i] == (i == 0 ? 2 : 1);
		loop invariant N_len == c + 1;
		loop invariant N[1] == 1;
		loop invariant N[0] == 2;
		loop invariant N[0] == 2 && N[1] == 1;
		loop invariant 2 <= p;
		loop invariant 0 <= p;
		loop invariant 0 <= p - 2;
		loop invariant 0 < N[p - 2];
		loop invariant 0 < N[p - 1];
		loop assigns p;
		loop assigns N[2..c];
		loop assigns N[0..c];*/
int stub_B(int c);

/*@loop invariant \forall integer k; 2 <= k < p ==> N[k] >= N[k - 2];
		loop invariant \forall integer k; 2 <= k < p ==> N[k] >= N[k - 1];
		loop invariant \forall integer k; 2 <= k < p ==> N[k] >= 2 * N[k - 2];
		loop invariant \forall integer k; 2 <= k < p ==> N[k] > N[k - 1];
		loop invariant \forall integer k; 2 <= k < p ==> N[k] == N[k - 1] + 2 * N[k - 2];
		loop invariant \forall integer k; 0 <= k < p ==> N[k] >= 1;
		loop invariant \forall integer k; 0 <= k < p ==> N[k] >= 0;
		loop invariant \forall integer k; 0 <= k < p ==> N[k] > 0;
		loop invariant \forall integer k; 0 <= k < p ==> N[k] == (k == 0 ? 2 : (k == 1 ? 1 : N[k]));
		loop invariant \forall integer k; 0 <= k < p ==> N[k] != 0;
		loop invariant \forall integer k; 0 <= k < p ==> (k >= 2 ==> N[k] == N[k - 1] + 2 * N[k - 2]);
		loop invariant \forall integer k; 0 <= k < p ==> (k == 1 ==> N[k] == 1);
		loop invariant \forall integer k; 0 <= k < p ==> (k == 0 ==> N[k] == 2);
		loop invariant \forall integer k; 0 <= k < 2 ==> N[k] == (k == 0 ? 2 : 1);
		loop invariant \forall integer i; 2 <= i < p ==> N[i] >= N[i - 2];
		loop invariant \forall integer i; 2 <= i < p ==> N[i] >= N[i - 1];
		loop invariant \forall integer i; 2 <= i < p ==> N[i] == N[i - 1] + 2 * N[i - 2];
		loop invariant \forall integer i; 0 <= i < p ==> N[i] >= 1;
		loop invariant \forall integer i; 0 <= i < p ==> N[i] >= 0;
		loop invariant \forall integer i; 0 <= i < p ==> N[i] > 0;
		loop invariant \forall integer i; 0 <= i < p ==> N[i] != 0;
		loop invariant \forall integer i; 0 <= i < 2 ==> N[i] == (i == 0 ? 2 : 1);
		loop invariant N_len == c + 1;
		loop invariant N[1] == 1;
		loop invariant N[0] == 2;
		loop invariant N[0] == 2 && N[1] == 1;
		loop invariant 2 <= p;
		loop invariant 0 <= p;
		loop invariant 0 <= p - 2;
		loop invariant 0 < N[p - 2];
		loop invariant 0 < N[p - 1];
		loop assigns p;
		loop assigns N[2..c];
		loop assigns N[0..c];*/
int check_A_implies_B(int c) {
    return stub_A(c);
}

/*@loop invariant 2 <= p;
          loop invariant N[0] == 2;
          loop invariant N[1] == 1;
          loop invariant \forall integer k; 2 <= k < p ==> N[k] == N[k - 1] + 2 * N[k - 2];
          loop assigns p, N[0 .. c];*/
int check_B_implies_A(int c) {
    return stub_B(c);
}
