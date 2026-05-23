#include <limits.h>

/*@ logic integer fact(integer n) =
      n <= 1 ? 1 : n * fact(n - 1); */

/*@ requires (0 <= first) && (0 <= result <= 9) && (num == \at(num,Pre)) && (result >= 0) && (first == 0 || first > 0);
    assigns \nothing;
*/
void check_A_implies_B(int first, int num) {
    /*@ assert (first <= num || first >= 0); */
    /*@ assert (first < 10 || result < 10); */
    /*@ assert (first % 10 >= 0 && first % 10 < 10); */
    /*@ assert (result >= 0 || first == 0); */
    /*@ assert (result == first % 10 || result >= 0); */
    /*@ assert (result == first % 10 || result < 10); */
    /*@ assert (result == 0 || result >= 0); */
    /*@ assert (result == 0 || result > 0); */
    /*@ assert (result == 0 || result < 10); */
    /*@ assert (result <= 9); */
    /*@ assert (result < 10); */
    /*@ assert (result < 10 || first == 0); */
    /*@ assert (result < 10 && result >= 0); */
    /*@ assert (result < 10 && first >= 0); */
    /*@ assert (first >= 0 ==> result < 10); */
    /*@ assert (first > 0 ==> result >= 0); */
    /*@ assert (first > 0 ==> result == first % 10 || result < 10); */
    /*@ assert (first > 0 ==> result < 10); */
    /*@ assert (first > 0 ==> first % 10 >= 0); */
    /*@ assert (first > 0 ==> 0 <= result); */
    /*@ assert (first > 0 ==> 0 <= result <= 9); */
    /*@ assert (first > 0 ==> 0 <= result < 10); */
    /*@ assert (first == 0 || result < 10); */
    /*@ assert (first == 0 || first > 0); */
    /*@ assert (first == 0 ==> result == 0 || result >= 0); */
    /*@ assert (first == 0 ==> result <= 9); */
    /*@ assert (first == 0 ==> result < 10); */
    /*@ assert (first == 0 ==> 0 <= result <= 9); */
    /*@ assert (first % 10 == 0 || first % 10 > 0); */
    /*@ assert (first % 10 <= 9); */
    /*@ assert (first % 10 <= 9 || first % 10 < 10); */
    /*@ assert (first % 10 <= 10); */
    /*@ assert (first % 10 < 10); */
    /*@ assert (0 <= result); */
    /*@ assert (0 <= first); */
    /*@ assert (0 <= first % 10); */
}

/*@ requires (first <= num || first >= 0) && (first < 10 || result < 10) && (first % 10 >= 0 && first % 10 < 10) && (result >= 0 || first == 0) && (result == first % 10 || result >= 0) && (result == first % 10 || result < 10) && (result == 0 || result >= 0) && (result == 0 || result > 0) && (result == 0 || result < 10) && (result <= 9) && (result < 10) && (result < 10 || first == 0) && (result < 10 && result >= 0) && (result < 10 && first >= 0) && (first >= 0 ==> result < 10) && (first > 0 ==> result >= 0) && (first > 0 ==> result == first % 10 || result < 10) && (first > 0 ==> result < 10) && (first > 0 ==> first % 10 >= 0) && (first > 0 ==> 0 <= result) && (first > 0 ==> 0 <= result <= 9) && (first > 0 ==> 0 <= result < 10) && (first == 0 || result < 10) && (first == 0 || first > 0) && (first == 0 ==> result == 0 || result >= 0) && (first == 0 ==> result <= 9) && (first == 0 ==> result < 10) && (first == 0 ==> 0 <= result <= 9) && (first % 10 == 0 || first % 10 > 0) && (first % 10 <= 9) && (first % 10 <= 9 || first % 10 < 10) && (first % 10 <= 10) && (first % 10 < 10) && (0 <= result) && (0 <= first) && (0 <= first % 10);
    assigns \nothing;
*/
void check_B_implies_A(int first, int num) {
    /*@ assert (0 <= first); */
    /*@ assert (0 <= result <= 9); */
    /*@ assert (num == \at(num,Pre)); */
    /*@ assert (result >= 0); */
    /*@ assert (first == 0 || first > 0); */
}
