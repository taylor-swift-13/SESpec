#include <limits.h>
#include <stdlib.h>

/*@ logic integer fibo(integer n) =
      n <= 1 ? n : fibo(n - 1) + fibo(n - 2); */

/*@ requires (2 <= index <= fib_len) && (fib_len == n + 1) && (fib[0] == 0) && (fib[1] == 1) && (fib[index - 1] == fibo(index - 1)) && (fib[index - 2] == fibo(index - 2)) && (\exists integer k; 0 <= k < index && fib[k] == fib[index - 1]) && ((index < fib_len) ==> (fib[index - 1] == fibo(index - 1))) && ((!(index < fib_len)) ==> (index == fib_len));
    assigns \nothing;
*/
void check_A_implies_B(int *fib, int fib_len, int index, int k, int n) {
    /*@ assert (index == 2 || fib[index - 1] >= fib[index - 2]); */
    /*@ assert (index == 2 || fib[index - 1] == fib[index - 2] + fib[index - 3]); */
    /*@ assert (index == 2 ==> fib[0] == 0 && fib[1] == 1); */
    /*@ assert (index <= n + 1); */
    /*@ assert (index <= fib_len); */
    /*@ assert (index - 2 <= n - 1); */
    /*@ assert (fib_len == n + 1); */
    /*@ assert (fib[index-2] <= fib[index-1]); */
    /*@ assert (fib[index - 2] <= fib[index - 1]); */
    /*@ assert (fib[1] == 1); */
    /*@ assert (fib[0] == 0); */
    /*@ assert (fib[0] == 0 && fib[1] == 1); */
    /*@ assert (fib[0] == 0 && fib[1] == 1 && index >= 2); */
    /*@ assert (fib[0] == 0 && fib[1] == 1 && fib_len == n + 1); */
    /*@ assert (\forall integer k; 2 <= k < index ==> fib[k] >= fib[k-2]); */
    /*@ assert (\forall integer k; 2 <= k < index ==> fib[k] >= fib[k-1]); */
    /*@ assert (\forall integer k; 2 <= k < index ==> fib[k] >= fib[k - 2]); */
    /*@ assert (\forall integer k; 2 <= k < index ==> fib[k] >= fib[k - 1]); */
    /*@ assert (\forall integer k; 2 <= k < index ==> fib[k] == fib[k-2] + fib[k-1]); */
    /*@ assert (\forall integer k; 2 <= k < index ==> fib[k] == fib[k-1] + fib[k-2]); */
    /*@ assert (\forall integer k; 2 <= k < index ==> fib[k] == fib[k - 2] + fib[k - 1]); */
    /*@ assert (\forall integer k; 2 <= k < index ==> fib[k] == fib[k - 1] + fib[k - 2]); */
    /*@ assert (\forall integer k; 1 <= k < index ==> fib[k] >= fib[k-1]); */
    /*@ assert (\forall integer k; 1 <= k < index ==> fib[k] >= fib[k - 1]); */
    /*@ assert (\forall integer k; 1 <= k < index ==> fib[k] >= 1); */
    /*@ assert (\forall integer k; 0 <= k < index ==> fib[k] >= 0); */
    /*@ assert (\forall integer k; 0 <= k < 2 ==> fib[k] >= 0); */
    /*@ assert (2 <= index); */
    /*@ assert (2 <= index || index == 2); */
    /*@ assert (2 <= index || fib_len <= 2); */
    /*@ assert (2 <= index ==> fib[index-1] >= fib[index-2]); */
    /*@ assert (2 <= index ==> fib[index - 1] >= fib[index - 2]); */
    /*@ assert (2 <= index ==> fib[0] == 0 && fib[1] == 1); */
    /*@ assert (0 <= n); */
    /*@ assert (0 <= index); */
    /*@ assert (0 <= index - 2); */
}

/*@ requires (index == 2 || fib[index - 1] >= fib[index - 2]) && (index == 2 || fib[index - 1] == fib[index - 2] + fib[index - 3]) && (index == 2 ==> fib[0] == 0 && fib[1] == 1) && (index <= n + 1) && (index <= fib_len) && (index - 2 <= n - 1) && (fib_len == n + 1) && (fib[index-2] <= fib[index-1]) && (fib[index - 2] <= fib[index - 1]) && (fib[1] == 1) && (fib[0] == 0) && (fib[0] == 0 && fib[1] == 1) && (fib[0] == 0 && fib[1] == 1 && index >= 2) && (fib[0] == 0 && fib[1] == 1 && fib_len == n + 1) && (\forall integer k; 2 <= k < index ==> fib[k] >= fib[k-2]) && (\forall integer k; 2 <= k < index ==> fib[k] >= fib[k-1]) && (\forall integer k; 2 <= k < index ==> fib[k] >= fib[k - 2]) && (\forall integer k; 2 <= k < index ==> fib[k] >= fib[k - 1]) && (\forall integer k; 2 <= k < index ==> fib[k] == fib[k-2] + fib[k-1]) && (\forall integer k; 2 <= k < index ==> fib[k] == fib[k-1] + fib[k-2]) && (\forall integer k; 2 <= k < index ==> fib[k] == fib[k - 2] + fib[k - 1]) && (\forall integer k; 2 <= k < index ==> fib[k] == fib[k - 1] + fib[k - 2]) && (\forall integer k; 1 <= k < index ==> fib[k] >= fib[k-1]) && (\forall integer k; 1 <= k < index ==> fib[k] >= fib[k - 1]) && (\forall integer k; 1 <= k < index ==> fib[k] >= 1) && (\forall integer k; 0 <= k < index ==> fib[k] >= 0) && (\forall integer k; 0 <= k < 2 ==> fib[k] >= 0) && (2 <= index) && (2 <= index || index == 2) && (2 <= index || fib_len <= 2) && (2 <= index ==> fib[index-1] >= fib[index-2]) && (2 <= index ==> fib[index - 1] >= fib[index - 2]) && (2 <= index ==> fib[0] == 0 && fib[1] == 1) && (0 <= n) && (0 <= index) && (0 <= index - 2);
    assigns \nothing;
*/
void check_B_implies_A(int *fib, int fib_len, int index, int k, int n) {
    /*@ assert (2 <= index <= fib_len); */
    /*@ assert (fib_len == n + 1); */
    /*@ assert (fib[0] == 0); */
    /*@ assert (fib[1] == 1); */
    /*@ assert (fib[index - 1] == fibo(index - 1)); */
    /*@ assert (fib[index - 2] == fibo(index - 2)); */
    /*@ assert (\exists integer k; 0 <= k < index && fib[k] == fib[index - 1]); */
    /*@ assert ((index < fib_len) ==> (fib[index - 1] == fibo(index - 1))); */
    /*@ assert ((!(index < fib_len)) ==> (index == fib_len)); */
}
