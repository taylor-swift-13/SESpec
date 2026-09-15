#include <limits.h>
#include <stdlib.h>

/*@ logic integer lucas_seq(integer n) =
      n == 0 ? 2 :
      n == 1 ? 1 :
      lucas_seq(n - 1) + lucas_seq(n - 2); */

/*@ requires (i >= 2) && (lucas[0] == 2) && (lucas[1] == 1) && (\forall integer k; 2 <= k < i ==> lucas[k] == lucas[k - 1] + lucas[k - 2]) && (\forall integer k; 0 <= k < i ==> lucas[k] == lucas_seq(k));
    assigns \nothing;
*/
void check_A_implies_B(int i, int k, int *lucas, int lucas_len, int n) {
    /*@ assert (\forall integer k; 2 <= k < i && k < lucas_len ==> lucas[k] == lucas[k - 1] + lucas[k - 2]); */
    /*@ assert (\forall integer k; 0 <= k < i && k < lucas_len ==> lucas[k] >= 0); */
    /*@ assert (lucas_len == n + 1); */
    /*@ assert (lucas[1] == 1); */
    /*@ assert (lucas[0] == 2); */
    /*@ assert (lucas[0] == 2 && lucas[1] == 1); */
    /*@ assert (i == 2 || lucas[i-1] == lucas[i-2] + lucas[i-3]); */
    /*@ assert (i == 2 ==> lucas[0] == 2 && lucas[1] == 1); */
    /*@ assert (\forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k-2]); */
    /*@ assert (\forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k-1]); */
    /*@ assert (\forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k-1] + lucas[k-2]); */
    /*@ assert (\forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k-1] && lucas[k] >= lucas[k-2]); */
    /*@ assert (\forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k - 2]); */
    /*@ assert (\forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k - 2] && lucas[k] >= lucas[k - 1]); */
    /*@ assert (\forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k - 1]); */
    /*@ assert (\forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k - 1] + lucas[k - 2]); */
    /*@ assert (\forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k - 1] && lucas[k] >= lucas[k - 2]); */
    /*@ assert (\forall integer k; 2 <= k < i ==> lucas[k] >= 2); */
    /*@ assert (\forall integer k; 2 <= k < i ==> lucas[k] > lucas[k-2]); */
    /*@ assert (\forall integer k; 2 <= k < i ==> lucas[k] > lucas[k-2] && lucas[k] > lucas[k-1]); */
    /*@ assert (\forall integer k; 2 <= k < i ==> lucas[k] > lucas[k-1]); */
    /*@ assert (\forall integer k; 2 <= k < i ==> lucas[k] > lucas[k-1] && lucas[k] > lucas[k-2]); */
    /*@ assert (\forall integer k; 2 <= k < i ==> lucas[k] > lucas[k - 2]); */
    /*@ assert (\forall integer k; 2 <= k < i ==> lucas[k] > lucas[k - 2] && lucas[k] > lucas[k - 1]); */
    /*@ assert (\forall integer k; 2 <= k < i ==> lucas[k] > lucas[k - 1] && lucas[k] > lucas[k - 2]); */
    /*@ assert (\forall integer k; 2 <= k < i ==> lucas[k] == lucas[k-1] + lucas[k-2]); */
    /*@ assert (\forall integer k; 2 <= k < i ==> lucas[k] == lucas[k - 1] + lucas[k - 2]); */
    /*@ assert (\forall integer k; 0 <= k < i ==> lucas[k] >= 1); */
    /*@ assert (\forall integer k; 0 <= k < i ==> lucas[k] >= 0); */
    /*@ assert (\forall integer k; 0 <= k < i ==> lucas[k] > 0); */
    /*@ assert (\forall integer k; 0 <= k < i && k < lucas_len ==> lucas[k] >= 1); */
    /*@ assert (\forall integer k; 0 <= k < i && k < lucas_len ==> lucas[k] > 0); */
    /*@ assert (\forall integer k; 0 <= k < i && k < 2 ==> lucas[k] == (k == 0 ? 2 : 1)); */
    /*@ assert (\forall integer k; 0 <= k < 2 ==> lucas[k] > 0); */
    /*@ assert (\forall integer k; 0 <= k < 2 ==> lucas[k] == (k == 0 ? 2 : 1)); */
    /*@ assert (2 <= i); */
    /*@ assert (0 <= i); */
}

/*@ requires (\forall integer k; 2 <= k < i && k < lucas_len ==> lucas[k] == lucas[k - 1] + lucas[k - 2]) && (\forall integer k; 0 <= k < i && k < lucas_len ==> lucas[k] >= 0) && (lucas_len == n + 1) && (lucas[1] == 1) && (lucas[0] == 2) && (lucas[0] == 2 && lucas[1] == 1) && (i == 2 || lucas[i-1] == lucas[i-2] + lucas[i-3]) && (i == 2 ==> lucas[0] == 2 && lucas[1] == 1) && (\forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k-2]) && (\forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k-1]) && (\forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k-1] + lucas[k-2]) && (\forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k-1] && lucas[k] >= lucas[k-2]) && (\forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k - 2]) && (\forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k - 2] && lucas[k] >= lucas[k - 1]) && (\forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k - 1]) && (\forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k - 1] + lucas[k - 2]) && (\forall integer k; 2 <= k < i ==> lucas[k] >= lucas[k - 1] && lucas[k] >= lucas[k - 2]) && (\forall integer k; 2 <= k < i ==> lucas[k] >= 2) && (\forall integer k; 2 <= k < i ==> lucas[k] > lucas[k-2]) && (\forall integer k; 2 <= k < i ==> lucas[k] > lucas[k-2] && lucas[k] > lucas[k-1]) && (\forall integer k; 2 <= k < i ==> lucas[k] > lucas[k-1]) && (\forall integer k; 2 <= k < i ==> lucas[k] > lucas[k-1] && lucas[k] > lucas[k-2]) && (\forall integer k; 2 <= k < i ==> lucas[k] > lucas[k - 2]) && (\forall integer k; 2 <= k < i ==> lucas[k] > lucas[k - 2] && lucas[k] > lucas[k - 1]) && (\forall integer k; 2 <= k < i ==> lucas[k] > lucas[k - 1] && lucas[k] > lucas[k - 2]) && (\forall integer k; 2 <= k < i ==> lucas[k] == lucas[k-1] + lucas[k-2]) && (\forall integer k; 2 <= k < i ==> lucas[k] == lucas[k - 1] + lucas[k - 2]) && (\forall integer k; 0 <= k < i ==> lucas[k] >= 1) && (\forall integer k; 0 <= k < i ==> lucas[k] >= 0) && (\forall integer k; 0 <= k < i ==> lucas[k] > 0) && (\forall integer k; 0 <= k < i && k < lucas_len ==> lucas[k] >= 1) && (\forall integer k; 0 <= k < i && k < lucas_len ==> lucas[k] > 0) && (\forall integer k; 0 <= k < i && k < 2 ==> lucas[k] == (k == 0 ? 2 : 1)) && (\forall integer k; 0 <= k < 2 ==> lucas[k] > 0) && (\forall integer k; 0 <= k < 2 ==> lucas[k] == (k == 0 ? 2 : 1)) && (2 <= i) && (0 <= i);
    assigns \nothing;
*/
void check_B_implies_A(int i, int k, int *lucas, int lucas_len, int n) {
    /*@ assert (i >= 2); */
    /*@ assert (lucas[0] == 2); */
    /*@ assert (lucas[1] == 1); */
    /*@ assert (\forall integer k; 2 <= k < i ==> lucas[k] == lucas[k - 1] + lucas[k - 2]); */
    /*@ assert (\forall integer k; 0 <= k < i ==> lucas[k] == lucas_seq(k)); */
}
