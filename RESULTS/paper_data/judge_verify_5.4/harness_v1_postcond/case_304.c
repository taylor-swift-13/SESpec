#include <limits.h>
#include <stdlib.h>


/*@ logic integer pell_rec(integer k) =
      k <= 0 ? 0 :
      k == 1 ? 1 :
      (2 * pell_rec(k - 1) + pell_rec(k - 2)) % 1000000000;
*/

/*@requires n >= 1;
  
  ensures \result == pell_rec(n);*/
int stub_A(int n);

/*@loop invariant pell_len == n + 1;
        loop invariant pell[1] == 1;
        loop invariant pell[0] == 0;
        loop invariant pell[0] == 0 && pell[1] == 1;
        loop invariant i == 2 || pell[i - 1] == (2 * pell[i - 2] + pell[i - 3]) % 1000000000;
        loop invariant i == 2 || pell[i - 1] == ((2 * pell[i - 2] + pell[i - 3]) % 1000000000);
        loop invariant i == 2 ==> pell[0] == 0 && pell[1] == 1;
        loop invariant i == 2 ==> (pell[0] == 0 && pell[1] == 1);
        loop invariant i <= n + 1 || 0 <= i;
        loop invariant \forall integer k; 2 <= k < i ==> pell[k] >= 0;
        loop invariant \forall integer k; 2 <= k < i ==> pell[k] == (2 * pell[k - 1] + pell[k - 2]) % 1000000000;
        loop invariant \forall integer k; 2 <= k < i ==> pell[k] == ((2 * pell[k - 1] + pell[k - 2]) % 1000000000);
        loop invariant \forall integer k; 0 <= k < i ==> pell[k] >= 0;
        loop invariant \forall integer k; 0 <= k < i ==> pell[k] == 0 || pell[k] > 0;
        loop invariant \forall integer k; 0 <= k < i ==> pell[k] < 1000000000;
        loop invariant \forall integer k; 0 <= k < i ==> 0 <= pell[k] < 1000000000;
        loop invariant \forall integer k; 0 <= k < i ==> (k == 1 ==> pell[k] == 1);
        loop invariant \forall integer k; 0 <= k < i ==> (k == 0 ==> pell[k] == 0);
        loop invariant \forall integer k; 0 <= k < i ==> (k == 0 ==> pell[k] == 0) && (k == 1 ==> pell[k] == 1);
        loop invariant \forall integer k; 0 <= k < i ==> (k < 2 || pell[k] >= 0);
        loop invariant \forall integer k; 0 <= k < i ==> (k < 2 || pell[k] == ((2 * pell[k - 1] + pell[k - 2]) % 1000000000));
        loop invariant \forall integer k; 0 <= k < i ==> (k < 2 || pell[k] < 1000000000);
        loop invariant \forall integer k; 0 <= k < i ==> (k < 2 || 0 <= pell[k] < 1000000000);
        loop invariant \forall integer k; 0 <= k < i ==> (k < 2 || (0 <= pell[k] < 1000000000));
        loop invariant 2 <= i;
        loop invariant 1 < i;
        loop invariant 0 <= i;
        loop invariant 0 < i;
        loop invariant 0 < i;
        loop invariant 0 < i;
        loop invariant 0 < i;
        loop invariant 0 < i;
        loop invariant 0 < i;
        loop invariant 0 < i;
        loop invariant 0 < i;
        loop invariant 0 < i;
        loop invariant 0 < i;
        loop invariant 0 < i;
        loop invariant 0 < i;
        loop assigns pell[2..n];
        loop assigns pell[0..n];
        loop assigns i;*/
int stub_B(int n);

/*@loop invariant pell_len == n + 1;
        loop invariant pell[1] == 1;
        loop invariant pell[0] == 0;
        loop invariant pell[0] == 0 && pell[1] == 1;
        loop invariant i == 2 || pell[i - 1] == (2 * pell[i - 2] + pell[i - 3]) % 1000000000;
        loop invariant i == 2 || pell[i - 1] == ((2 * pell[i - 2] + pell[i - 3]) % 1000000000);
        loop invariant i == 2 ==> pell[0] == 0 && pell[1] == 1;
        loop invariant i == 2 ==> (pell[0] == 0 && pell[1] == 1);
        loop invariant i <= n + 1 || 0 <= i;
        loop invariant \forall integer k; 2 <= k < i ==> pell[k] >= 0;
        loop invariant \forall integer k; 2 <= k < i ==> pell[k] == (2 * pell[k - 1] + pell[k - 2]) % 1000000000;
        loop invariant \forall integer k; 2 <= k < i ==> pell[k] == ((2 * pell[k - 1] + pell[k - 2]) % 1000000000);
        loop invariant \forall integer k; 0 <= k < i ==> pell[k] >= 0;
        loop invariant \forall integer k; 0 <= k < i ==> pell[k] == 0 || pell[k] > 0;
        loop invariant \forall integer k; 0 <= k < i ==> pell[k] < 1000000000;
        loop invariant \forall integer k; 0 <= k < i ==> 0 <= pell[k] < 1000000000;
        loop invariant \forall integer k; 0 <= k < i ==> (k == 1 ==> pell[k] == 1);
        loop invariant \forall integer k; 0 <= k < i ==> (k == 0 ==> pell[k] == 0);
        loop invariant \forall integer k; 0 <= k < i ==> (k == 0 ==> pell[k] == 0) && (k == 1 ==> pell[k] == 1);
        loop invariant \forall integer k; 0 <= k < i ==> (k < 2 || pell[k] >= 0);
        loop invariant \forall integer k; 0 <= k < i ==> (k < 2 || pell[k] == ((2 * pell[k - 1] + pell[k - 2]) % 1000000000));
        loop invariant \forall integer k; 0 <= k < i ==> (k < 2 || pell[k] < 1000000000);
        loop invariant \forall integer k; 0 <= k < i ==> (k < 2 || 0 <= pell[k] < 1000000000);
        loop invariant \forall integer k; 0 <= k < i ==> (k < 2 || (0 <= pell[k] < 1000000000));
        loop invariant 2 <= i;
        loop invariant 1 < i;
        loop invariant 0 <= i;
        loop invariant 0 < i;
        loop invariant 0 < i;
        loop invariant 0 < i;
        loop invariant 0 < i;
        loop invariant 0 < i;
        loop invariant 0 < i;
        loop invariant 0 < i;
        loop invariant 0 < i;
        loop invariant 0 < i;
        loop invariant 0 < i;
        loop invariant 0 < i;
        loop invariant 0 < i;
        loop assigns pell[2..n];
        loop assigns pell[0..n];
        loop assigns i;*/
int check_A_implies_B(int n) {
    return stub_A(n);
}

/*@requires n >= 1;
  
  ensures \result == pell_rec(n);*/
int check_B_implies_A(int n) {
    return stub_B(n);
}
