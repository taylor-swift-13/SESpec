#include <limits.h>

/*@ requires (0 <= i <= args_len) && (-1 <= r < args_len) && (i <= r + 1) && (p == -1 || (0 <= p < args_len)) && (p == -1 || args[p] == x) && (p == -1 || p < i || p > r) && (y == \at(y,Pre)) && (x == \at(x,Pre)) && (args_len == \at(args_len,Pre)) && (args == \at(args,Pre)) && (\forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *args, int args_len, int i, int k, int p, int r, int x, int y) {
    /*@ assert (\forall integer k; 0 <= k < i ==> args[k] != x || args[k] == x); */
    /*@ assert (r <= y - 1); */
    /*@ assert (r < y); */
    /*@ assert (r < i || i <= r + 1); */
    /*@ assert (p == -1 || p >= i || p <= r); */
    /*@ assert (p == -1 || p <= r + 1); */
    /*@ assert (p == -1 || p < i); */
    /*@ assert (p == -1 || p < i || p > r); */
    /*@ assert (p == -1 || args[p] == x); */
    /*@ assert (p == -1 || args[p] <= x); */
    /*@ assert (p == -1 || \exists integer k; 0 <= k < y && args[k] == x); */
    /*@ assert (p == -1 || \exists integer k; 0 <= k < i && args[k] == x); */
    /*@ assert (p == -1 || 0 <= p < y); */
    /*@ assert (p == -1 || 0 <= p < y && args[p] == x); */
    /*@ assert (p == -1 || 0 <= p < i); */
    /*@ assert (p == -1 || (\exists integer k; 0 <= k < y && args[k] == x)); */
    /*@ assert (p == -1 || (\exists integer k; 0 <= k < i && args[k] == x)); */
    /*@ assert (p == -1 || (0 <= p < y && args[p] == x)); */
    /*@ assert (p != -1 ==> p >= i || p <= r); */
    /*@ assert (p != -1 ==> p >= 0); */
    /*@ assert (p != -1 ==> p <= y - 1); */
    /*@ assert (p != -1 ==> p <= r + 1); */
    /*@ assert (p != -1 ==> p < i); */
    /*@ assert (p != -1 ==> p < i || p > r); */
    /*@ assert (p != -1 ==> args[p] == x); */
    /*@ assert (p != -1 ==> \exists integer k; 0 <= k < y && args[k] == x); */
    /*@ assert (p != -1 ==> \exists integer k; 0 <= k < i && args[k] == x); */
    /*@ assert (p != -1 ==> 0 <= p < y); */
    /*@ assert (p != -1 ==> 0 <= p < i); */
    /*@ assert (0 <= i); */
    /*@ assert (-1 <= p); */
    /*@ assert (-1 <= p < i || p == -1); */
}

/*@ requires (\forall integer k; 0 <= k < i ==> args[k] != x || args[k] == x) && (r <= y - 1) && (r < y) && (r < i || i <= r + 1) && (p == -1 || p >= i || p <= r) && (p == -1 || p <= r + 1) && (p == -1 || p < i) && (p == -1 || p < i || p > r) && (p == -1 || args[p] == x) && (p == -1 || args[p] <= x) && (p == -1 || \exists integer k; 0 <= k < y && args[k] == x) && (p == -1 || \exists integer k; 0 <= k < i && args[k] == x) && (p == -1 || 0 <= p < y) && (p == -1 || 0 <= p < y && args[p] == x) && (p == -1 || 0 <= p < i) && (p == -1 || (\exists integer k; 0 <= k < y && args[k] == x)) && (p == -1 || (\exists integer k; 0 <= k < i && args[k] == x)) && (p == -1 || (0 <= p < y && args[p] == x)) && (p != -1 ==> p >= i || p <= r) && (p != -1 ==> p >= 0) && (p != -1 ==> p <= y - 1) && (p != -1 ==> p <= r + 1) && (p != -1 ==> p < i) && (p != -1 ==> p < i || p > r) && (p != -1 ==> args[p] == x) && (p != -1 ==> \exists integer k; 0 <= k < y && args[k] == x) && (p != -1 ==> \exists integer k; 0 <= k < i && args[k] == x) && (p != -1 ==> 0 <= p < y) && (p != -1 ==> 0 <= p < i) && (0 <= i) && (-1 <= p) && (-1 <= p < i || p == -1);
    assigns \nothing;
*/
void check_B_implies_A(int *args, int args_len, int i, int k, int p, int r, int x, int y) {
    /*@ assert (0 <= i <= args_len); */
    /*@ assert (-1 <= r < args_len); */
    /*@ assert (i <= r + 1); */
    /*@ assert (p == -1 || (0 <= p < args_len)); */
    /*@ assert (p == -1 || args[p] == x); */
    /*@ assert (p == -1 || p < i || p > r); */
    /*@ assert (y == \at(y,Pre)); */
    /*@ assert (x == \at(x,Pre)); */
    /*@ assert (args_len == \at(args_len,Pre)); */
    /*@ assert (args == \at(args,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre)); */
}
