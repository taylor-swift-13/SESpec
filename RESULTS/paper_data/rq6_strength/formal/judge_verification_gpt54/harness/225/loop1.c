#include <limits.h>

/*@ requires (1 <= remaining) && (1 <= find) && (find == remaining || find == remaining - 1) && (\forall integer k; 1 <= k < remaining ==> args[k - 1] == k) && (\forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *args, int args_len, int array, int find, int k, int remaining) {
    /*@ assert (remaining == find || remaining == find + 1 || find == 1); */
    /*@ assert (remaining == 1 ==> find == 1); */
    /*@ assert (remaining <= array || remaining - find <= 1); */
    /*@ assert (remaining <= array + 1 || remaining - find <= 1); */
    /*@ assert (remaining - find <= 1); */
    /*@ assert (find == remaining - 1 || find == remaining); */
    /*@ assert (find == remaining - 1 || find == 1); */
    /*@ assert (find == 1 || find == remaining || find == remaining - 1); */
    /*@ assert (find == 1 || find == remaining - 1); */
    /*@ assert (find == 1 || find == remaining - 1 || find == remaining); */
    /*@ assert (find == 1 || find < remaining); */
    /*@ assert (find == 1 || (1 <= find <= remaining)); */
    /*@ assert (find <= remaining); */
    /*@ assert (find <= remaining + 1); */
    /*@ assert (find <= array || remaining - find <= 1); */
    /*@ assert (\forall integer k; 1 <= k < remaining ==> args[k - 1] == k); */
    /*@ assert (\forall integer k; 1 <= k < remaining ==> args[k - 1] == k || args[k - 1] != k); */
    /*@ assert (\forall integer k; 1 <= k < remaining ==> args[k - 1] == k ==> find >= k); */
    /*@ assert (\forall integer k; 1 <= k < remaining ==> args[k - 1] == k ==> find >= k - 1); */
    /*@ assert (\forall integer k; 1 <= k < remaining ==> args[k - 1] == k ==> find <= remaining); */
    /*@ assert (\forall integer k; 1 <= k < remaining ==> args[k - 1] == k ==> find != k - 1); */
    /*@ assert (\forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find == k - 1); */
    /*@ assert (\forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find == k - 1 || find == 1); */
    /*@ assert (\forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find == 1 || find == k - 1); */
    /*@ assert (\forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find <= remaining); */
    /*@ assert (\forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find <= k); */
    /*@ assert (\forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find <= k - 1); */
    /*@ assert (\forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find != k); */
    /*@ assert (\forall integer k; 1 <= k < remaining ==> (args[k - 1] == k || args[k - 1] != k)); */
    /*@ assert (\forall integer k; 1 <= k < remaining ==> (args[k - 1] == k ==> find >= k)); */
    /*@ assert (\forall integer k; 1 <= k < remaining ==> (args[k - 1] == k ==> find >= k - 1)); */
    /*@ assert (\forall integer k; 1 <= k < remaining ==> (args[k - 1] == k ==> find != k - 1)); */
    /*@ assert (\forall integer k; 1 <= k < remaining ==> (args[k - 1] != k ==> find == k - 1 || find == 1)); */
    /*@ assert (\forall integer k; 1 <= k < remaining ==> (args[k - 1] != k ==> find == 1 || find == k - 1)); */
    /*@ assert (\forall integer k; 1 <= k < remaining ==> (args[k - 1] != k ==> find <= remaining)); */
    /*@ assert (\forall integer k; 1 <= k < remaining ==> (args[k - 1] != k ==> find <= k)); */
    /*@ assert (\forall integer k; 1 <= k < remaining ==> (args[k - 1] != k ==> find <= k - 1)); */
    /*@ assert (\forall integer k; 1 <= k < remaining ==> (args[k - 1] != k ==> find != k)); */
    /*@ assert (1 <= remaining); */
    /*@ assert (1 <= find); */
}

/*@ requires (remaining == find || remaining == find + 1 || find == 1) && (remaining == 1 ==> find == 1) && (remaining <= array || remaining - find <= 1) && (remaining <= array + 1 || remaining - find <= 1) && (remaining - find <= 1) && (find == remaining - 1 || find == remaining) && (find == remaining - 1 || find == 1) && (find == 1 || find == remaining || find == remaining - 1) && (find == 1 || find == remaining - 1) && (find == 1 || find == remaining - 1 || find == remaining) && (find == 1 || find < remaining) && (find == 1 || (1 <= find <= remaining)) && (find <= remaining) && (find <= remaining + 1) && (find <= array || remaining - find <= 1) && (\forall integer k; 1 <= k < remaining ==> args[k - 1] == k) && (\forall integer k; 1 <= k < remaining ==> args[k - 1] == k || args[k - 1] != k) && (\forall integer k; 1 <= k < remaining ==> args[k - 1] == k ==> find >= k) && (\forall integer k; 1 <= k < remaining ==> args[k - 1] == k ==> find >= k - 1) && (\forall integer k; 1 <= k < remaining ==> args[k - 1] == k ==> find <= remaining) && (\forall integer k; 1 <= k < remaining ==> args[k - 1] == k ==> find != k - 1) && (\forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find == k - 1) && (\forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find == k - 1 || find == 1) && (\forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find == 1 || find == k - 1) && (\forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find <= remaining) && (\forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find <= k) && (\forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find <= k - 1) && (\forall integer k; 1 <= k < remaining ==> args[k - 1] != k ==> find != k) && (\forall integer k; 1 <= k < remaining ==> (args[k - 1] == k || args[k - 1] != k)) && (\forall integer k; 1 <= k < remaining ==> (args[k - 1] == k ==> find >= k)) && (\forall integer k; 1 <= k < remaining ==> (args[k - 1] == k ==> find >= k - 1)) && (\forall integer k; 1 <= k < remaining ==> (args[k - 1] == k ==> find != k - 1)) && (\forall integer k; 1 <= k < remaining ==> (args[k - 1] != k ==> find == k - 1 || find == 1)) && (\forall integer k; 1 <= k < remaining ==> (args[k - 1] != k ==> find == 1 || find == k - 1)) && (\forall integer k; 1 <= k < remaining ==> (args[k - 1] != k ==> find <= remaining)) && (\forall integer k; 1 <= k < remaining ==> (args[k - 1] != k ==> find <= k)) && (\forall integer k; 1 <= k < remaining ==> (args[k - 1] != k ==> find <= k - 1)) && (\forall integer k; 1 <= k < remaining ==> (args[k - 1] != k ==> find != k)) && (1 <= remaining) && (1 <= find);
    assigns \nothing;
*/
void check_B_implies_A(int *args, int args_len, int array, int find, int k, int remaining) {
    /*@ assert (1 <= remaining); */
    /*@ assert (1 <= find); */
    /*@ assert (find == remaining || find == remaining - 1); */
    /*@ assert (\forall integer k; 1 <= k < remaining ==> args[k - 1] == k); */
    /*@ assert (\forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre)); */
}
