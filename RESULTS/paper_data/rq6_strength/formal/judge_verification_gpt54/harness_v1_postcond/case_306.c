#include <limits.h>
#include <stdlib.h>


/*@ logic integer lucas_seq(integer n) =
      n == 0 ? 2 :
      n == 1 ? 1 :
      lucas_seq(n - 1) + lucas_seq(n - 2);
*/

/*@requires n >= 1;
  ensures n >= 1 ==> \result == lucas_seq(n - 1) + lucas_seq(n - 2) || n == 1;
  ensures n >= 1 ==> \true;
  ensures n >= 1 ==> \true;*/
int stub_A(int n);

/*@loop invariant \forall integer k; 2 <= k < i && k < lucas_len ==> lucas[k] == lucas[k - 1] + lucas[k - 2];
        loop invariant \forall integer k; 0 <= k < i && k < lucas_len ==> lucas[k] >= 0;
        loop invariant lucas_len == n + 1;
        loop invariant lucas[1] == 1;
        loop invariant lucas[0] == 2;
        loop invariant lucas[0] == 2 && lucas[1] == 1;
        loop invariant i == 2 || lucas[i-1] == lucas[i-2] + lucas[i-3];
        loop invariant i == 2 ==> lucas[0] == 2 && lucas[1] == 1;
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k-2];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k-1];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k-1] + lucas[k-2];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k-1] && lucas[k] >= lucas[k-2];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k - 2];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k - 2] && lucas[k] >= lucas[k - 1];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k - 1];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k - 1] + lucas[k - 2];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k - 1] && lucas[k] >= lucas[k - 2];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] >= 2;
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] > lucas[k-2];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] > lucas[k-2] && lucas[k] > lucas[k-1];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] > lucas[k-1];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] > lucas[k-1] && lucas[k] > lucas[k-2];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] > lucas[k - 2];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] > lucas[k - 2] && lucas[k] > lucas[k - 1];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] > lucas[k - 1] && lucas[k] > lucas[k - 2];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] == lucas[k-1] + lucas[k-2];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] == lucas[k - 1] + lucas[k - 2];
        loop invariant \forall integer k; 0 <= k < i ==> lucas[k] >= 1;
        loop invariant \forall integer k; 0 <= k < i ==> lucas[k] >= 0;
        loop invariant \forall integer k; 0 <= k < i ==> lucas[k] > 0;
        loop invariant \forall integer k; 0 <= k < i && k < lucas_len ==> lucas[k] >= 1;
        loop invariant \forall integer k; 0 <= k < i && k < lucas_len ==> lucas[k] > 0;
        loop invariant \forall integer k; 0 <= k < i && k < 2 ==> lucas[k] == (k == 0 ? 2 : 1);
        loop invariant \forall integer k; 0 <= k < 2 ==> lucas[k] > 0;
        loop invariant \forall integer k; 0 <= k < 2 ==> lucas[k] == (k == 0 ? 2 : 1);
        loop invariant 2 <= i;
        loop invariant 0 <= i;
        loop assigns lucas[0..n];
        loop assigns lucas[0..lucas_len-1];
        loop assigns i;*/
int stub_B(int n);

/*@loop invariant \forall integer k; 2 <= k < i && k < lucas_len ==> lucas[k] == lucas[k - 1] + lucas[k - 2];
        loop invariant \forall integer k; 0 <= k < i && k < lucas_len ==> lucas[k] >= 0;
        loop invariant lucas_len == n + 1;
        loop invariant lucas[1] == 1;
        loop invariant lucas[0] == 2;
        loop invariant lucas[0] == 2 && lucas[1] == 1;
        loop invariant i == 2 || lucas[i-1] == lucas[i-2] + lucas[i-3];
        loop invariant i == 2 ==> lucas[0] == 2 && lucas[1] == 1;
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k-2];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k-1];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k-1] + lucas[k-2];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k-1] && lucas[k] >= lucas[k-2];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k - 2];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k - 2] && lucas[k] >= lucas[k - 1];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k - 1];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k - 1] + lucas[k - 2];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k - 1] && lucas[k] >= lucas[k - 2];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] >= 2;
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] > lucas[k-2];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] > lucas[k-2] && lucas[k] > lucas[k-1];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] > lucas[k-1];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] > lucas[k-1] && lucas[k] > lucas[k-2];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] > lucas[k - 2];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] > lucas[k - 2] && lucas[k] > lucas[k - 1];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] > lucas[k - 1] && lucas[k] > lucas[k - 2];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] == lucas[k-1] + lucas[k-2];
        loop invariant \forall integer k; 2 <= k < i ==> lucas[k] == lucas[k - 1] + lucas[k - 2];
        loop invariant \forall integer k; 0 <= k < i ==> lucas[k] >= 1;
        loop invariant \forall integer k; 0 <= k < i ==> lucas[k] >= 0;
        loop invariant \forall integer k; 0 <= k < i ==> lucas[k] > 0;
        loop invariant \forall integer k; 0 <= k < i && k < lucas_len ==> lucas[k] >= 1;
        loop invariant \forall integer k; 0 <= k < i && k < lucas_len ==> lucas[k] > 0;
        loop invariant \forall integer k; 0 <= k < i && k < 2 ==> lucas[k] == (k == 0 ? 2 : 1);
        loop invariant \forall integer k; 0 <= k < 2 ==> lucas[k] > 0;
        loop invariant \forall integer k; 0 <= k < 2 ==> lucas[k] == (k == 0 ? 2 : 1);
        loop invariant 2 <= i;
        loop invariant 0 <= i;
        loop assigns lucas[0..n];
        loop assigns lucas[0..lucas_len-1];
        loop assigns i;*/
int check_A_implies_B(int n) {
    return stub_A(n);
}

/*@requires n >= 1;
  ensures n >= 1 ==> \result == lucas_seq(n - 1) + lucas_seq(n - 2) || n == 1;
  ensures n >= 1 ==> \true;
  ensures n >= 1 ==> \true;*/
int check_B_implies_A(int n) {
    return stub_B(n);
}
