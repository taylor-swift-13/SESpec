#include <limits.h>
#include <stdlib.h>

/*@logic integer lucas_seq(integer n) =
      n == 0 ? 2 :
      n == 1 ? 1 :
      lucas_seq(n - 1) + lucas_seq(n - 2);*/

/*@ requires (i >= 2) && (lucas[0] == 2) && (lucas[1] == 1) && (\forall integer k) && (\forall integer k);
    assigns \nothing;
*/
void check_A_implies_B(int *i, int k, int *lucas, int lucas_len, int n) {
    /*@ assert (\forall integer k) && (\forall integer k) && (lucas_len == n + 1) && (lucas[1] == 1) && (lucas[0] == 2) && (lucas[0] == 2 && lucas[1] == 1) && (i == 2 || lucas[i-1] == lucas[i-2] + lucas[i-3]) && (i == 2 ==> lucas[0] == 2 && lucas[1] == 1) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (2 <= i) && (0 <= i); */
}

/*@ requires (\forall integer k) && (\forall integer k) && (lucas_len == n + 1) && (lucas[1] == 1) && (lucas[0] == 2) && (lucas[0] == 2 && lucas[1] == 1) && (i == 2 || lucas[i-1] == lucas[i-2] + lucas[i-3]) && (i == 2 ==> lucas[0] == 2 && lucas[1] == 1) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (2 <= i) && (0 <= i);
    assigns \nothing;
*/
void check_B_implies_A(int *i, int k, int *lucas, int lucas_len, int n) {
    /*@ assert (i >= 2) && (lucas[0] == 2) && (lucas[1] == 1) && (\forall integer k) && (\forall integer k); */
}
