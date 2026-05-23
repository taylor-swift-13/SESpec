#include <limits.h>
#include <stdlib.h>


/*@
  logic integer dpval(integer k) =
    k == 0 ? 2 :
    k == 1 ? 1 :
    dpval(k - 1) + 2 * dpval(k - 2);
*/

/*@requires n >= 1;*/
int stub_A(int n);

/*@loop invariant dp_len == n + 1;
        loop invariant dp_len == n + 1 && dp[0] == 2 && dp[1] == 1;
        loop invariant dp[1] == 1;
        loop invariant dp[0] == 2;
        loop invariant dp[0] == 2 && dp[1] == 1;
        loop invariant \forall integer k; i <= k < dp_len ==> dp[k] == dp[k];
        loop invariant \forall integer k; i <= k < dp_len ==> dp[k] == 0 || dp[k] == dp[k];
        loop invariant \forall integer k; 2 <= k < i ==> dp[k] >= dp[k - 1];
        loop invariant \forall integer k; 2 <= k < i ==> dp[k] == dp[k - 1] + 2 * dp[k - 2];
        loop invariant \forall integer k; 0 <= k < i ==> dp[k] >= 0;
        loop invariant \forall integer k; 0 <= k < i ==> dp[k] == dp[k];
        loop invariant \forall integer k; 0 <= k < i ==> dp[k] != 0 || k < 2;
        loop invariant \forall integer k; 0 <= k < i ==> (k == 0 ? dp[k] == 2 : (k == 1 ? dp[k] == 1 : dp[k] >= dp[k - 1]));
        loop invariant \forall integer k; 0 <= k < i ==> (k == 0 ? dp[k] == 2 : (k == 1 ? dp[k] == 1 : dp[k] >= 0));
        loop invariant \forall integer k; 0 <= k < i ==> (k == 0 ? dp[k] == 2 : (k == 1 ? dp[k] == 1 : dp[k] > 0));
        loop invariant \forall integer k; 0 <= k < i ==> (k == 0 ? dp[k] == 2 : (k == 1 ? dp[k] == 1 : dp[k] == dp[k - 1] + 2 * dp[k - 2]));
        loop invariant \forall integer k; 0 <= k < i ==> (k < 2 || dp[k] > 0);
        loop invariant \forall integer k; 0 <= k < i ==> (k < 2 ==> (k == 0 ? dp[k] == 2 : dp[k] == 1));
        loop invariant \forall integer k; 0 <= k < i && k < dp_len ==> dp[k] >= 0;
        loop invariant \forall integer k; 0 <= k < i && k < dp_len ==> dp[k] == dp[k];
        loop invariant \forall integer k; 0 <= k < 2 ==> dp[k] == (k == 0 ? 2 : 1);
        loop invariant \forall integer k; 0 <= k < 2 ==> (k == 0 ? dp[k] == 2 : dp[k] == 1);
        loop invariant \forall integer k; 0 <= k < 2 ==> (k == 0 ==> dp[k] == 2) && (k == 1 ==> dp[k] == 1);
        loop invariant 2 <= i;
        loop invariant 0 <= i;
        loop assigns i;
        loop assigns dp[2..n];
        loop assigns dp[0..n];
        loop assigns dp[0..dp_len-1];*/
int stub_B(int n);

/*@loop invariant dp_len == n + 1;
        loop invariant dp_len == n + 1 && dp[0] == 2 && dp[1] == 1;
        loop invariant dp[1] == 1;
        loop invariant dp[0] == 2;
        loop invariant dp[0] == 2 && dp[1] == 1;
        loop invariant \forall integer k; i <= k < dp_len ==> dp[k] == dp[k];
        loop invariant \forall integer k; i <= k < dp_len ==> dp[k] == 0 || dp[k] == dp[k];
        loop invariant \forall integer k; 2 <= k < i ==> dp[k] >= dp[k - 1];
        loop invariant \forall integer k; 2 <= k < i ==> dp[k] == dp[k - 1] + 2 * dp[k - 2];
        loop invariant \forall integer k; 0 <= k < i ==> dp[k] >= 0;
        loop invariant \forall integer k; 0 <= k < i ==> dp[k] == dp[k];
        loop invariant \forall integer k; 0 <= k < i ==> dp[k] != 0 || k < 2;
        loop invariant \forall integer k; 0 <= k < i ==> (k == 0 ? dp[k] == 2 : (k == 1 ? dp[k] == 1 : dp[k] >= dp[k - 1]));
        loop invariant \forall integer k; 0 <= k < i ==> (k == 0 ? dp[k] == 2 : (k == 1 ? dp[k] == 1 : dp[k] >= 0));
        loop invariant \forall integer k; 0 <= k < i ==> (k == 0 ? dp[k] == 2 : (k == 1 ? dp[k] == 1 : dp[k] > 0));
        loop invariant \forall integer k; 0 <= k < i ==> (k == 0 ? dp[k] == 2 : (k == 1 ? dp[k] == 1 : dp[k] == dp[k - 1] + 2 * dp[k - 2]));
        loop invariant \forall integer k; 0 <= k < i ==> (k < 2 || dp[k] > 0);
        loop invariant \forall integer k; 0 <= k < i ==> (k < 2 ==> (k == 0 ? dp[k] == 2 : dp[k] == 1));
        loop invariant \forall integer k; 0 <= k < i && k < dp_len ==> dp[k] >= 0;
        loop invariant \forall integer k; 0 <= k < i && k < dp_len ==> dp[k] == dp[k];
        loop invariant \forall integer k; 0 <= k < 2 ==> dp[k] == (k == 0 ? 2 : 1);
        loop invariant \forall integer k; 0 <= k < 2 ==> (k == 0 ? dp[k] == 2 : dp[k] == 1);
        loop invariant \forall integer k; 0 <= k < 2 ==> (k == 0 ==> dp[k] == 2) && (k == 1 ==> dp[k] == 1);
        loop invariant 2 <= i;
        loop invariant 0 <= i;
        loop assigns i;
        loop assigns dp[2..n];
        loop assigns dp[0..n];
        loop assigns dp[0..dp_len-1];*/
int check_A_implies_B(int n) {
    return stub_A(n);
}

/*@requires n >= 1;*/
int check_B_implies_A(int n) {
    return stub_B(n);
}
