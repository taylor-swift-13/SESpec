#include <limits.h>
#include <stdlib.h>

/*@ logic integer foo270_seq(integer m, integer count) =
      count == 2 ? m * m :
      count > 2 ? ((m - 1) * (foo270_seq(m, count - 1) + foo270_seq(m, count - 2))) % 1000000007 :
      1; */

/*@ requires (d >= 3) && (div[0] == 1) && (div[1] == m) && (div[2] == m * m);
    assigns \nothing;
*/
void check_A_implies_B(int count, int d, int *div, int div_len, int k, int *m, int w) {
    /*@ assert (3 <= d ==> 0 <= d - 3); */
    /*@ assert (w == 1000000007); */
    /*@ assert (w == 1000000007 && div_len == count + 1); */
    /*@ assert (div_len == count + 1); */
    /*@ assert (div_len == count + 1 && w == 1000000007); */
    /*@ assert (div[2] == m * m); */
    /*@ assert (div[1] == m); */
    /*@ assert (div[0] == 1); */
    /*@ assert (div[0] == 1 && div[1] == m && div[2] == m * m); */
    /*@ assert (d >= 3 ==> div_len == count + 1); */
    /*@ assert (d >= 3 ==> div[0] == 1 && div[1] == m && div[2] == m * m); */
    /*@ assert (count >= 2 ==> div[0] == 1 && div[1] == m && div[2] == m * m); */
    /*@ assert (count + 1 == div_len); */
    /*@ assert (\forall integer k; 0 <= k < d ==> div[k] == div[k]); */
    /*@ assert (\forall integer k; 0 <= k < d ==> div[k] == (k == 0 ? 1 : (k == 1 ? m : (k == 2 ? m * m : div[k])))); */
    /*@ assert (\forall integer k; 0 <= k < d ==> (k == 2 ==> div[k] == m * m)); */
    /*@ assert (\forall integer k; 0 <= k < d ==> (k == 1 ==> div[k] == m)); */
    /*@ assert (\forall integer k; 0 <= k < d ==> (k == 0 ? div[k] == 1 : (k == 1 ? div[k] == m : (k == 2 ? div[k] == m * m : 1)))); */
    /*@ assert (\forall integer k; 0 <= k < d ==> (k == 0 ==> div[k] == 1)); */
    /*@ assert (\forall integer k; 0 <= k < d ==> (k < 3 ==> div[k] == (k == 0 ? 1 : (k == 1 ? m : m * m)))); */
    /*@ assert (\forall integer k; 0 <= k < d ==> (k < 3 ==> (k == 0 ? div[k] == 1 : (k == 1 ? div[k] == m : div[k] == m * m)))); */
    /*@ assert (\forall integer k; 0 <= k < d && k <= count ==> (k == 0 ? div[k] == 1 : (k == 1 ? div[k] == m : (k == 2 ? div[k] == m * m : 1)))); */
    /*@ assert (\forall integer k; 0 <= k < d && k <= 2 ==> div[k] == (k == 0 ? 1 : (k == 1 ? m : m * m))); */
    /*@ assert (\forall integer k; 0 <= k < d && k < count + 1 ==> div[k] == (k == 0 ? 1 : (k == 1 ? m : (k == 2 ? m * m : div[k])))); */
    /*@ assert (\forall integer k; 0 <= k < d && k < 3 ==> div[k] == (k == 0 ? 1 : (k == 1 ? m : m * m))); */
    /*@ assert (\forall integer k; 0 <= k < d && k < 3 ==> (k == 2 ==> div[k] == m * m)); */
    /*@ assert (\forall integer k; 0 <= k < d && k < 3 ==> (k == 1 ==> div[k] == m)); */
    /*@ assert (\forall integer k; 0 <= k < d && k < 3 ==> (k == 0 ==> div[k] == 1)); */
    /*@ assert (\forall integer k; 0 <= k < 3 ==> div[k] == (k == 0 ? 1 : (k == 1 ? m : m * m))); */
    /*@ assert (3 <= d); */
    /*@ assert (3 <= d ==> div[2] == m * m); */
    /*@ assert (3 <= d ==> div[1] == m); */
    /*@ assert (3 <= d ==> div[0] == 1); */
    /*@ assert (2 <= d - 1); */
    /*@ assert (2 < d); */
    /*@ assert (1 <= w); */
    /*@ assert (0 <= d); */
    /*@ assert (0 <= d ==> div_len == count + 1); */
    /*@ assert (0 <= d - 3); */
    /*@ assert (0 < w); */
}

/*@ requires (3 <= d ==> 0 <= d - 3) && (w == 1000000007) && (w == 1000000007 && div_len == count + 1) && (div_len == count + 1) && (div_len == count + 1 && w == 1000000007) && (div[2] == m * m) && (div[1] == m) && (div[0] == 1) && (div[0] == 1 && div[1] == m && div[2] == m * m) && (d >= 3 ==> div_len == count + 1) && (d >= 3 ==> div[0] == 1 && div[1] == m && div[2] == m * m) && (count >= 2 ==> div[0] == 1 && div[1] == m && div[2] == m * m) && (count + 1 == div_len) && (\forall integer k; 0 <= k < d ==> div[k] == div[k]) && (\forall integer k; 0 <= k < d ==> div[k] == (k == 0 ? 1 : (k == 1 ? m : (k == 2 ? m * m : div[k])))) && (\forall integer k; 0 <= k < d ==> (k == 2 ==> div[k] == m * m)) && (\forall integer k; 0 <= k < d ==> (k == 1 ==> div[k] == m)) && (\forall integer k; 0 <= k < d ==> (k == 0 ? div[k] == 1 : (k == 1 ? div[k] == m : (k == 2 ? div[k] == m * m : 1)))) && (\forall integer k; 0 <= k < d ==> (k == 0 ==> div[k] == 1)) && (\forall integer k; 0 <= k < d ==> (k < 3 ==> div[k] == (k == 0 ? 1 : (k == 1 ? m : m * m)))) && (\forall integer k; 0 <= k < d ==> (k < 3 ==> (k == 0 ? div[k] == 1 : (k == 1 ? div[k] == m : div[k] == m * m)))) && (\forall integer k; 0 <= k < d && k <= count ==> (k == 0 ? div[k] == 1 : (k == 1 ? div[k] == m : (k == 2 ? div[k] == m * m : 1)))) && (\forall integer k; 0 <= k < d && k <= 2 ==> div[k] == (k == 0 ? 1 : (k == 1 ? m : m * m))) && (\forall integer k; 0 <= k < d && k < count + 1 ==> div[k] == (k == 0 ? 1 : (k == 1 ? m : (k == 2 ? m * m : div[k])))) && (\forall integer k; 0 <= k < d && k < 3 ==> div[k] == (k == 0 ? 1 : (k == 1 ? m : m * m))) && (\forall integer k; 0 <= k < d && k < 3 ==> (k == 2 ==> div[k] == m * m)) && (\forall integer k; 0 <= k < d && k < 3 ==> (k == 1 ==> div[k] == m)) && (\forall integer k; 0 <= k < d && k < 3 ==> (k == 0 ==> div[k] == 1)) && (\forall integer k; 0 <= k < 3 ==> div[k] == (k == 0 ? 1 : (k == 1 ? m : m * m))) && (3 <= d) && (3 <= d ==> div[2] == m * m) && (3 <= d ==> div[1] == m) && (3 <= d ==> div[0] == 1) && (2 <= d - 1) && (2 < d) && (1 <= w) && (0 <= d) && (0 <= d ==> div_len == count + 1) && (0 <= d - 3) && (0 < w);
    assigns \nothing;
*/
void check_B_implies_A(int count, int d, int *div, int div_len, int k, int *m, int w) {
    /*@ assert (d >= 3); */
    /*@ assert (div[0] == 1); */
    /*@ assert (div[1] == m); */
    /*@ assert (div[2] == m * m); */
}
