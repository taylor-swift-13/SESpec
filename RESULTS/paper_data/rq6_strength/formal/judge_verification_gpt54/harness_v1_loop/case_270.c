#include <limits.h>
#include <stdlib.h>

/*@logic integer foo270_seq(integer m, integer count) =
      count == 2 ? m * m :
      count > 2 ? ((m - 1) * (foo270_seq(m, count - 1) + foo270_seq(m, count - 2))) % 1000000007 :
      1;*/

/*@ requires (d >= 3) && (div[0] == 1) && (div[1] == m) && (div[2] == m * m);
    assigns \nothing;
*/
void check_A_implies_B(int *count, int *d, int *div, int div_len, int k, int *m, int w) {
    /*@ assert (3 <= d ==> 0 <= d - 3) && (w == 1000000007) && (w == 1000000007 && div_len == count + 1) && (div_len == count + 1) && (div_len == count + 1 && w == 1000000007) && (div[2] == m * m) && (div[1] == m) && (div[0] == 1) && (div[0] == 1 && div[1] == m && div[2] == m * m) && (d >= 3 ==> div_len == count + 1) && (d >= 3 ==> div[0] == 1 && div[1] == m && div[2] == m * m) && (count >= 2 ==> div[0] == 1 && div[1] == m && div[2] == m * m) && (count + 1 == div_len) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (3 <= d) && (3 <= d ==> div[2] == m * m) && (3 <= d ==> div[1] == m) && (3 <= d ==> div[0] == 1) && (2 <= d - 1) && (2 < d) && (1 <= w) && (0 <= d) && (0 <= d ==> div_len == count + 1) && (0 <= d - 3) && (0 < w); */
}

/*@ requires (3 <= d ==> 0 <= d - 3) && (w == 1000000007) && (w == 1000000007 && div_len == count + 1) && (div_len == count + 1) && (div_len == count + 1 && w == 1000000007) && (div[2] == m * m) && (div[1] == m) && (div[0] == 1) && (div[0] == 1 && div[1] == m && div[2] == m * m) && (d >= 3 ==> div_len == count + 1) && (d >= 3 ==> div[0] == 1 && div[1] == m && div[2] == m * m) && (count >= 2 ==> div[0] == 1 && div[1] == m && div[2] == m * m) && (count + 1 == div_len) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (3 <= d) && (3 <= d ==> div[2] == m * m) && (3 <= d ==> div[1] == m) && (3 <= d ==> div[0] == 1) && (2 <= d - 1) && (2 < d) && (1 <= w) && (0 <= d) && (0 <= d ==> div_len == count + 1) && (0 <= d - 3) && (0 < w);
    assigns \nothing;
*/
void check_B_implies_A(int *count, int *d, int *div, int div_len, int k, int *m, int w) {
    /*@ assert (d >= 3) && (div[0] == 1) && (div[1] == m) && (div[2] == m * m); */
}
