#include <limits.h>
#include <stdlib.h>

/*@logic integer fibo(integer n) =
      n <= 1 ? n : fibo(n - 1) + fibo(n - 2);*/

/*@ requires (2 <= index <= fib_len) && (fib_len == n + 1) && (fib[0] == 0) && (fib[1] == 1) && (fib[index - 1] == fibo(index - 1)) && (fib[index - 2] == fibo(index - 2)) && (\exists integer k) && ((index < fib_len) ==> (fib[index - 1] == fibo(index - 1))) && ((!(index < fib_len)) ==> (index == fib_len));
    assigns \nothing;
*/
void check_A_implies_B(int *fib, int *fib_len, int *index, int k, int *n) {
    /*@ assert (index == 2 || fib[index - 1] >= fib[index - 2]) && (index == 2 || fib[index - 1] == fib[index - 2] + fib[index - 3]) && (index == 2 ==> fib[0] == 0 && fib[1] == 1) && (index <= n + 1) && (index <= fib_len) && (index - 2 <= n - 1) && (fib_len == n + 1) && (fib[index-2] <= fib[index-1]) && (fib[index - 2] <= fib[index - 1]) && (fib[1] == 1) && (fib[0] == 0) && (fib[0] == 0 && fib[1] == 1) && (fib[0] == 0 && fib[1] == 1 && index >= 2) && (fib[0] == 0 && fib[1] == 1 && fib_len == n + 1) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (2 <= index) && (2 <= index || index == 2) && (2 <= index || fib_len <= 2) && (2 <= index ==> fib[index-1] >= fib[index-2]) && (2 <= index ==> fib[index - 1] >= fib[index - 2]) && (2 <= index ==> fib[0] == 0 && fib[1] == 1) && (0 <= n) && (0 <= index) && (0 <= index - 2); */
}

/*@ requires (index == 2 || fib[index - 1] >= fib[index - 2]) && (index == 2 || fib[index - 1] == fib[index - 2] + fib[index - 3]) && (index == 2 ==> fib[0] == 0 && fib[1] == 1) && (index <= n + 1) && (index <= fib_len) && (index - 2 <= n - 1) && (fib_len == n + 1) && (fib[index-2] <= fib[index-1]) && (fib[index - 2] <= fib[index - 1]) && (fib[1] == 1) && (fib[0] == 0) && (fib[0] == 0 && fib[1] == 1) && (fib[0] == 0 && fib[1] == 1 && index >= 2) && (fib[0] == 0 && fib[1] == 1 && fib_len == n + 1) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (2 <= index) && (2 <= index || index == 2) && (2 <= index || fib_len <= 2) && (2 <= index ==> fib[index-1] >= fib[index-2]) && (2 <= index ==> fib[index - 1] >= fib[index - 2]) && (2 <= index ==> fib[0] == 0 && fib[1] == 1) && (0 <= n) && (0 <= index) && (0 <= index - 2);
    assigns \nothing;
*/
void check_B_implies_A(int *fib, int *fib_len, int *index, int k, int *n) {
    /*@ assert (2 <= index <= fib_len) && (fib_len == n + 1) && (fib[0] == 0) && (fib[1] == 1) && (fib[index - 1] == fibo(index - 1)) && (fib[index - 2] == fibo(index - 2)) && (\exists integer k) && ((index < fib_len) ==> (fib[index - 1] == fibo(index - 1))) && ((!(index < fib_len)) ==> (index == fib_len)); */
}
