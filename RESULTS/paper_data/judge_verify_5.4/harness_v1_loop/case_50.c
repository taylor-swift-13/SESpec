#include <limits.h>

/*@logic integer parity(integer x) = x % 2;*/

/*@ requires (0 <= n) && (b == n % 2) && (i + j == \at(i,Pre) + \at(j,Pre) + n) && (i >= \at(i,Pre)) && (j >= \at(j,Pre)) && (0 <= b <= 1) && (\at(i,Pre) <= i <= \at(i,Pre) + n) && (\at(j,Pre) <= j <= \at(j,Pre) + n) && (n == i + j - \at(i,Pre) - \at(j,Pre)) && ((n % 2 == 0) ==> (b == 0)) && ((n % 2 == 1) ==> (b == 1)) && ((0 < (2 * \at(k,Pre))) ==> (b == n % 2)) && ((0 < (2 * \at(k,Pre))) ==> (0 <= n)) && ((0 < (2 * \at(k,Pre))) ==> (\at(i,Pre) <= i <= \at(i,Pre) + n)) && ((0 < (2 * \at(k,Pre))) ==> (\at(j,Pre) <= j <= \at(j,Pre) + n)) && ((0 < (2 * \at(k,Pre))) ==> (0 <= b <= 1)) && ((!(0 < (2 * \at(k,Pre)))) ==> ((b == 0)&&(n == 0)&&(k == \at(k,Pre))&&(j == \at(j,Pre))&&(i == \at(i,Pre)))) && (k == \at(k,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int b, int i, int j, int k, int n) {
    /*@ assert (n == i + j - (i + j - n)) && (n % 2 == b) && (b == n % 2) && (b == 0 || b == 1) && (0 <= n) && ((n % 2 == 1) ==> b == 1) && ((n % 2 == 0) ==> b == 0); */
}

/*@ requires (n == i + j - (i + j - n)) && (n % 2 == b) && (b == n % 2) && (b == 0 || b == 1) && (0 <= n) && ((n % 2 == 1) ==> b == 1) && ((n % 2 == 0) ==> b == 0);
    assigns \nothing;
*/
void check_B_implies_A(int b, int i, int j, int k, int n) {
    /*@ assert (0 <= n) && (b == n % 2) && (i + j == \at(i,Pre) + \at(j,Pre) + n) && (i >= \at(i,Pre)) && (j >= \at(j,Pre)) && (0 <= b <= 1) && (\at(i,Pre) <= i <= \at(i,Pre) + n) && (\at(j,Pre) <= j <= \at(j,Pre) + n) && (n == i + j - \at(i,Pre) - \at(j,Pre)) && ((n % 2 == 0) ==> (b == 0)) && ((n % 2 == 1) ==> (b == 1)) && ((0 < (2 * \at(k,Pre))) ==> (b == n % 2)) && ((0 < (2 * \at(k,Pre))) ==> (0 <= n)) && ((0 < (2 * \at(k,Pre))) ==> (\at(i,Pre) <= i <= \at(i,Pre) + n)) && ((0 < (2 * \at(k,Pre))) ==> (\at(j,Pre) <= j <= \at(j,Pre) + n)) && ((0 < (2 * \at(k,Pre))) ==> (0 <= b <= 1)) && ((!(0 < (2 * \at(k,Pre)))) ==> ((b == 0)&&(n == 0)&&(k == \at(k,Pre))&&(j == \at(j,Pre))&&(i == \at(i,Pre)))) && (k == \at(k,Pre)); */
}
