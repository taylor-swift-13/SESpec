#include <limits.h>

/*@predicate even(unsigned int x) = (x % 2) == 0;
  predicate odd(unsigned int x) = (x % 2) == 1;*/

/*@ requires ((0 < \at(n,Pre)) ==> (l <= n)) && ((0 < \at(n,Pre)) ==> (j == l / 2)) && ((0 < \at(n,Pre)) ==> (i == (l + 1) / 2)) && ((0 < \at(n,Pre)) ==> ((l % 2) == 0 ==> i == j)) && ((0 < \at(n,Pre)) ==> ((l % 2) == 1 ==> i == j + 1)) && ((!(0 < \at(n,Pre))) ==> ((l == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)))) && (n == \at(n,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int i, int j, int l, int n) {
    /*@ assert (l <= n) && (j == l / 2) && (i == (l + 1) / 2) && (i + j == l) && (0 <= l); */
}

/*@ requires (l <= n) && (j == l / 2) && (i == (l + 1) / 2) && (i + j == l) && (0 <= l);
    assigns \nothing;
*/
void check_B_implies_A(int i, int j, int l, int n) {
    /*@ assert ((0 < \at(n,Pre)) ==> (l <= n)) && ((0 < \at(n,Pre)) ==> (j == l / 2)) && ((0 < \at(n,Pre)) ==> (i == (l + 1) / 2)) && ((0 < \at(n,Pre)) ==> ((l % 2) == 0 ==> i == j)) && ((0 < \at(n,Pre)) ==> ((l % 2) == 1 ==> i == j + 1)) && ((!(0 < \at(n,Pre))) ==> ((l == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)))) && (n == \at(n,Pre)); */
}
