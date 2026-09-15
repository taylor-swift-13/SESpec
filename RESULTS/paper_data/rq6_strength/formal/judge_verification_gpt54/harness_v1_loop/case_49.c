#include <limits.h>

/*@ requires (0 <= n) && (n <= 2 * k || k < 0) && (i == \at(i,Pre) + (n + 1) / 2) && (j == \at(j,Pre) + n / 2) && (k == \at(k,Pre)) && (b == 1 <==> n % 2 == 0) && (i + j == \at(i,Pre) + \at(j,Pre) + n) && (n % 2 == 0 ==> b == 1) && (n % 2 != 0 ==> b == 0) && (\at(i,Pre) <= i) && (\at(j,Pre) <= j) && (0 < (2 * \at(k,Pre)) ==> (i + j == \at(i,Pre) + \at(j,Pre) + n)) && (0 < (2 * \at(k,Pre)) ==> (i == \at(i,Pre) + (n + 1) / 2)) && (0 < (2 * \at(k,Pre)) ==> (j == \at(j,Pre) + n / 2)) && (0 < (2 * \at(k,Pre)) ==> (0 <= n <= 2 * k || k < 0)) && (0 < (2 * \at(k,Pre)) ==> ((n % 2 == 0 && b == 1) || (n % 2 != 0 && b == 0))) && ((!(0 < (2 * \at(k,Pre)))) ==> ((b == 1)&&(n == 0)&&(k == \at(k,Pre))&&(j == \at(j,Pre))&&(i == \at(i,Pre))));
    assigns \nothing;
*/
void check_A_implies_B(int b, int i, int j, int k, int n) {
    /*@ assert (n == i + j - (i + j - n)) && (i + j == n + i + j - n) && (i + j == i + j) && (b == 1 ==> n % 2 == 0) && (b == 0 || b == 1) && (b == 0 ==> n % 2 == 1) && (0 <= n) && ((b == 1) ==> (n % 2 == 0)) && ((b == 1 ==> n % 2 == 0) && (b == 0 ==> n % 2 == 1)) && ((b == 0) ==> (n % 2 == 1)) && ((b == 0 || b == 1)); */
}

/*@ requires (n == i + j - (i + j - n)) && (i + j == n + i + j - n) && (i + j == i + j) && (b == 1 ==> n % 2 == 0) && (b == 0 || b == 1) && (b == 0 ==> n % 2 == 1) && (0 <= n) && ((b == 1) ==> (n % 2 == 0)) && ((b == 1 ==> n % 2 == 0) && (b == 0 ==> n % 2 == 1)) && ((b == 0) ==> (n % 2 == 1)) && ((b == 0 || b == 1));
    assigns \nothing;
*/
void check_B_implies_A(int b, int i, int j, int k, int n) {
    /*@ assert (0 <= n) && (n <= 2 * k || k < 0) && (i == \at(i,Pre) + (n + 1) / 2) && (j == \at(j,Pre) + n / 2) && (k == \at(k,Pre)) && (b == 1 <==> n % 2 == 0) && (i + j == \at(i,Pre) + \at(j,Pre) + n) && (n % 2 == 0 ==> b == 1) && (n % 2 != 0 ==> b == 0) && (\at(i,Pre) <= i) && (\at(j,Pre) <= j) && (0 < (2 * \at(k,Pre)) ==> (i + j == \at(i,Pre) + \at(j,Pre) + n)) && (0 < (2 * \at(k,Pre)) ==> (i == \at(i,Pre) + (n + 1) / 2)) && (0 < (2 * \at(k,Pre)) ==> (j == \at(j,Pre) + n / 2)) && (0 < (2 * \at(k,Pre)) ==> (0 <= n <= 2 * k || k < 0)) && (0 < (2 * \at(k,Pre)) ==> ((n % 2 == 0 && b == 1) || (n % 2 != 0 && b == 0))) && ((!(0 < (2 * \at(k,Pre)))) ==> ((b == 1)&&(n == 0)&&(k == \at(k,Pre))&&(j == \at(j,Pre))&&(i == \at(i,Pre)))); */
}
