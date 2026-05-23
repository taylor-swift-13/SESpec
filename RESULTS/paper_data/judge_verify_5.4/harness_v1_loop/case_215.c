#include <limits.h>

/*@ requires (0 <= i <= args_len) && (-1 <= r < args_len) && (i <= r + 1) && (p == -1 || (0 <= p < args_len)) && (p == -1 || args[p] == x) && (p == -1 || p < i || p > r) && (y == \at(y,Pre)) && (x == \at(x,Pre)) && (args_len == \at(args_len,Pre)) && (args == \at(args,Pre)) && (\forall integer k);
    assigns \nothing;
*/
void check_A_implies_B(int *args, int args_len, int i, int k, int *p, int r, int *x, int *y) {
    /*@ assert (\forall integer k) && (r <= y - 1) && (r < y) && (r < i || i <= r + 1) && (p == -1 || p >= i || p <= r) && (p == -1 || p <= r + 1) && (p == -1 || p < i) && (p == -1 || p < i || p > r) && (p == -1 || args[p] == x) && (p == -1 || args[p] <= x) && (p == -1 || \exists integer k) && (p == -1 || \exists integer k) && (p == -1 || 0 <= p < y) && (p == -1 || 0 <= p < y && args[p] == x) && (p == -1 || 0 <= p < i) && (p == -1 || (\exists integer k) && (p == -1 || (\exists integer k) && (p == -1 || (0 <= p < y && args[p] == x)) && (p != -1 ==> p >= i || p <= r) && (p != -1 ==> p >= 0) && (p != -1 ==> p <= y - 1) && (p != -1 ==> p <= r + 1) && (p != -1 ==> p < i) && (p != -1 ==> p < i || p > r) && (p != -1 ==> args[p] == x) && (p != -1 ==> \exists integer k) && (p != -1 ==> \exists integer k) && (p != -1 ==> 0 <= p < y) && (p != -1 ==> 0 <= p < i) && (0 <= i) && (-1 <= p) && (-1 <= p < i || p == -1); */
}

/*@ requires (\forall integer k) && (r <= y - 1) && (r < y) && (r < i || i <= r + 1) && (p == -1 || p >= i || p <= r) && (p == -1 || p <= r + 1) && (p == -1 || p < i) && (p == -1 || p < i || p > r) && (p == -1 || args[p] == x) && (p == -1 || args[p] <= x) && (p == -1 || \exists integer k) && (p == -1 || \exists integer k) && (p == -1 || 0 <= p < y) && (p == -1 || 0 <= p < y && args[p] == x) && (p == -1 || 0 <= p < i) && (p == -1 || (\exists integer k) && (p == -1 || (\exists integer k) && (p == -1 || (0 <= p < y && args[p] == x)) && (p != -1 ==> p >= i || p <= r) && (p != -1 ==> p >= 0) && (p != -1 ==> p <= y - 1) && (p != -1 ==> p <= r + 1) && (p != -1 ==> p < i) && (p != -1 ==> p < i || p > r) && (p != -1 ==> args[p] == x) && (p != -1 ==> \exists integer k) && (p != -1 ==> \exists integer k) && (p != -1 ==> 0 <= p < y) && (p != -1 ==> 0 <= p < i) && (0 <= i) && (-1 <= p) && (-1 <= p < i || p == -1);
    assigns \nothing;
*/
void check_B_implies_A(int *args, int args_len, int i, int k, int *p, int r, int *x, int *y) {
    /*@ assert (0 <= i <= args_len) && (-1 <= r < args_len) && (i <= r + 1) && (p == -1 || (0 <= p < args_len)) && (p == -1 || args[p] == x) && (p == -1 || p < i || p > r) && (y == \at(y,Pre)) && (x == \at(x,Pre)) && (args_len == \at(args_len,Pre)) && (args == \at(args,Pre)) && (\forall integer k); */
}
