#include <limits.h>

/*@ logic integer factorial(integer x) =
    x <= 1 ? 1 : x * factorial(x - 1); */

/*@ requires (fact >= 0) && (0 <= foo327 <= 9) && ((fact > 0) ==> 0 <= foo327 <= 9) && ((fact == 0) ==> 0 <= foo327 <= 9);
    assigns \nothing;
*/
void check_A_implies_B(int fact, int firstDigit, int foo327) {
    /*@ assert (firstDigit >= 0 && firstDigit <= 9); */
    /*@ assert (firstDigit == 0 || firstDigit >= 0); */
    /*@ assert (firstDigit == 0 || firstDigit > 0); */
    /*@ assert (firstDigit == 0 || firstDigit <= 9); */
    /*@ assert (firstDigit == 0 || (0 <= firstDigit && firstDigit <= 9)); */
    /*@ assert (firstDigit <= fact || fact % 10 <= 9); */
    /*@ assert (firstDigit <= fact + 9); */
    /*@ assert (firstDigit <= 9); */
    /*@ assert (fact >= 0 ==> firstDigit >= 0); */
    /*@ assert (fact >= 0 ==> firstDigit <= fact + 9); */
    /*@ assert (fact >= 0 ==> firstDigit <= fact % 10 + 9); */
    /*@ assert (fact >= 0 ==> firstDigit <= 9); */
    /*@ assert (fact >= 0 ==> 0 <= firstDigit); */
    /*@ assert (fact >= 0 ==> 0 <= firstDigit <= 9); */
    /*@ assert (fact >= 0 ==> (fact == 0 || fact > 0)); */
    /*@ assert (fact > 0 ==> firstDigit >= 0); */
    /*@ assert (fact > 0 ==> firstDigit <= fact % 10 + 9); */
    /*@ assert (fact > 0 ==> firstDigit <= 9); */
    /*@ assert (fact > 0 ==> 0 <= firstDigit <= 9); */
    /*@ assert (fact == 0 || fact > 0); */
    /*@ assert (fact == 0 ==> firstDigit >= 0); */
    /*@ assert (fact == 0 ==> firstDigit <= 9); */
    /*@ assert (fact == 0 ==> 0 <= firstDigit <= 9); */
    /*@ assert (fact / 10 <= fact); */
    /*@ assert (fact % 10 == fact - 10 * (fact / 10)); */
    /*@ assert (fact % 10 <= 9); */
    /*@ assert (0 <= firstDigit); */
    /*@ assert (0 <= fact); */
    /*@ assert (0 <= fact ==> firstDigit <= 9); */
    /*@ assert (0 <= fact % 10); */
}

/*@ requires (firstDigit >= 0 && firstDigit <= 9) && (firstDigit == 0 || firstDigit >= 0) && (firstDigit == 0 || firstDigit > 0) && (firstDigit == 0 || firstDigit <= 9) && (firstDigit == 0 || (0 <= firstDigit && firstDigit <= 9)) && (firstDigit <= fact || fact % 10 <= 9) && (firstDigit <= fact + 9) && (firstDigit <= 9) && (fact >= 0 ==> firstDigit >= 0) && (fact >= 0 ==> firstDigit <= fact + 9) && (fact >= 0 ==> firstDigit <= fact % 10 + 9) && (fact >= 0 ==> firstDigit <= 9) && (fact >= 0 ==> 0 <= firstDigit) && (fact >= 0 ==> 0 <= firstDigit <= 9) && (fact >= 0 ==> (fact == 0 || fact > 0)) && (fact > 0 ==> firstDigit >= 0) && (fact > 0 ==> firstDigit <= fact % 10 + 9) && (fact > 0 ==> firstDigit <= 9) && (fact > 0 ==> 0 <= firstDigit <= 9) && (fact == 0 || fact > 0) && (fact == 0 ==> firstDigit >= 0) && (fact == 0 ==> firstDigit <= 9) && (fact == 0 ==> 0 <= firstDigit <= 9) && (fact / 10 <= fact) && (fact % 10 == fact - 10 * (fact / 10)) && (fact % 10 <= 9) && (0 <= firstDigit) && (0 <= fact) && (0 <= fact ==> firstDigit <= 9) && (0 <= fact % 10);
    assigns \nothing;
*/
void check_B_implies_A(int fact, int firstDigit, int foo327) {
    /*@ assert (fact >= 0); */
    /*@ assert (0 <= foo327 <= 9); */
    /*@ assert ((fact > 0) ==> 0 <= foo327 <= 9); */
    /*@ assert ((fact == 0) ==> 0 <= foo327 <= 9); */
}
