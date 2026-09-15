#include <limits.h>

/*@ logic integer fact(integer n) =
      n <= 1 ? 1 : n * fact(n - 1); */

/*@ requires (2 <= c) && (first == fact(c - 1)) && (first >= 1) && (num == \at(num,Pre)) && ((c <= num) ==> (first > 0)) && ((c <= num) ==> (first == fact(c - 1) && first >= 1));
    assigns \nothing;
*/
void check_A_implies_B(int c, int first, int num) {
    /*@ assert (first >= 0 && c >= 2); */
    /*@ assert (first > 0 ==> c >= 2); */
    /*@ assert (first == 1 || first >= 1); */
    /*@ assert (first == 1 || first > 1); */
    /*@ assert (first == 0 || first >= 1); */
    /*@ assert (first == 0 || first > 0); */
    /*@ assert (first <= num || first > 0); */
    /*@ assert (first <= num || first % 10 <= 9); */
    /*@ assert (first <= num || first % 10 < 10); */
    /*@ assert (first <= c || c <= num + 1); */
    /*@ assert (first % c == 0 || first % c >= 0); */
    /*@ assert (first % 10 >= 0 && first % 10 < 10); */
    /*@ assert (first % 10 == first || first >= 10); */
    /*@ assert (first % 10 <= 9); */
    /*@ assert (first % 10 <= 10); */
    /*@ assert (first % 10 < 10); */
    /*@ assert (first % 10 < 10 || first % 10 <= 9); */
    /*@ assert (first % 1 == 0); */
    /*@ assert (c <= num + 1 || c - 1 <= first); */
    /*@ assert (c <= num + 1 || 0 <= first % c); */
    /*@ assert (c <= first || 0 <= first % c); */
    /*@ assert (c - 1 <= first); */
    /*@ assert (c - 1 <= first || c <= first); */
    /*@ assert (c - 1 <= first || 0 <= first % c); */
    /*@ assert (2 <= c); */
    /*@ assert (1 <= first); */
    /*@ assert (1 <= first || first == 0); */
    /*@ assert (1 <= c); */
    /*@ assert (0 <= first); */
    /*@ assert (0 <= first || c <= num + 1); */
    /*@ assert (0 <= first || c <= first); */
    /*@ assert (0 <= first || c - 1 <= first); */
    /*@ assert (0 <= first || 0 <= first % c); */
    /*@ assert (0 <= first || 0 <= first % 10); */
    /*@ assert (0 <= first % c); */
    /*@ assert (0 <= first % 10); */
    /*@ assert (0 <= first % 10 || c <= num + 1); */
    /*@ assert (0 <= first % 10 || c <= first); */
    /*@ assert (0 <= first % 10 || c - 1 <= first); */
    /*@ assert (0 <= first % 10 || 0 <= first % c); */
    /*@ assert (0 < first); */
}

/*@ requires (first >= 0 && c >= 2) && (first > 0 ==> c >= 2) && (first == 1 || first >= 1) && (first == 1 || first > 1) && (first == 0 || first >= 1) && (first == 0 || first > 0) && (first <= num || first > 0) && (first <= num || first % 10 <= 9) && (first <= num || first % 10 < 10) && (first <= c || c <= num + 1) && (first % c == 0 || first % c >= 0) && (first % 10 >= 0 && first % 10 < 10) && (first % 10 == first || first >= 10) && (first % 10 <= 9) && (first % 10 <= 10) && (first % 10 < 10) && (first % 10 < 10 || first % 10 <= 9) && (first % 1 == 0) && (c <= num + 1 || c - 1 <= first) && (c <= num + 1 || 0 <= first % c) && (c <= first || 0 <= first % c) && (c - 1 <= first) && (c - 1 <= first || c <= first) && (c - 1 <= first || 0 <= first % c) && (2 <= c) && (1 <= first) && (1 <= first || first == 0) && (1 <= c) && (0 <= first) && (0 <= first || c <= num + 1) && (0 <= first || c <= first) && (0 <= first || c - 1 <= first) && (0 <= first || 0 <= first % c) && (0 <= first || 0 <= first % 10) && (0 <= first % c) && (0 <= first % 10) && (0 <= first % 10 || c <= num + 1) && (0 <= first % 10 || c <= first) && (0 <= first % 10 || c - 1 <= first) && (0 <= first % 10 || 0 <= first % c) && (0 < first);
    assigns \nothing;
*/
void check_B_implies_A(int c, int first, int num) {
    /*@ assert (2 <= c); */
    /*@ assert (first == fact(c - 1)); */
    /*@ assert (first >= 1); */
    /*@ assert (num == \at(num,Pre)); */
    /*@ assert ((c <= num) ==> (first > 0)); */
    /*@ assert ((c <= num) ==> (first == fact(c - 1) && first >= 1)); */
}
