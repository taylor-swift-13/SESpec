#include <limits.h>


/*@
  logic integer factorial(integer x) =
    x <= 1 ? 1 : x * factorial(x - 1);
*/

/*@requires n >= 1;
  requires n <= 4;
  assigns \nothing;
  ensures \result >= 0;
  ensures 0 <= \result && \result <= 9;
  ensures n == 1 ==> \result >= 0;
  ensures n == 2 ==> \result >= 0;
  ensures n == 3 ==> \result >= 0;
  ensures n == 4 ==> \result >= 0;
  ensures n >= 5 ==> \result >= 0;*/
int stub_A(int n);

/*@loop invariant firstDigit >= 0 && firstDigit <= 9;
        loop invariant firstDigit == 0 || firstDigit >= 0;
        loop invariant firstDigit == 0 || firstDigit > 0;
        loop invariant firstDigit == 0 || firstDigit <= 9;
        loop invariant firstDigit == 0 || (0 <= firstDigit && firstDigit <= 9);
        loop invariant firstDigit <= fact || fact % 10 <= 9;
        loop invariant firstDigit <= fact + 9;
        loop invariant firstDigit <= 9;
        loop invariant fact >= 0 ==> firstDigit >= 0;
        loop invariant fact >= 0 ==> firstDigit <= fact + 9;
        loop invariant fact >= 0 ==> firstDigit <= fact % 10 + 9;
        loop invariant fact >= 0 ==> firstDigit <= 9;
        loop invariant fact >= 0 ==> 0 <= firstDigit;
        loop invariant fact >= 0 ==> 0 <= firstDigit <= 9;
        loop invariant fact >= 0 ==> (fact == 0 || fact > 0);
        loop invariant fact > 0 ==> firstDigit >= 0;
        loop invariant fact > 0 ==> firstDigit <= fact % 10 + 9;
        loop invariant fact > 0 ==> firstDigit <= 9;
        loop invariant fact > 0 ==> 0 <= firstDigit <= 9;
        loop invariant fact == 0 || fact > 0;
        loop invariant fact == 0 ==> firstDigit >= 0;
        loop invariant fact == 0 ==> firstDigit <= 9;
        loop invariant fact == 0 ==> 0 <= firstDigit <= 9;
        loop invariant fact / 10 <= fact;
        loop invariant fact % 10 == fact - 10 * (fact / 10);
        loop invariant fact % 10 <= 9;
        loop invariant 0 <= firstDigit;
        loop invariant 0 <= fact;
        loop invariant 0 <= fact ==> firstDigit <= 9;
        loop invariant 0 <= fact % 10;
        loop assigns firstDigit;
        loop assigns fact;*/
int stub_B(int n);

/*@loop invariant firstDigit >= 0 && firstDigit <= 9;
        loop invariant firstDigit == 0 || firstDigit >= 0;
        loop invariant firstDigit == 0 || firstDigit > 0;
        loop invariant firstDigit == 0 || firstDigit <= 9;
        loop invariant firstDigit == 0 || (0 <= firstDigit && firstDigit <= 9);
        loop invariant firstDigit <= fact || fact % 10 <= 9;
        loop invariant firstDigit <= fact + 9;
        loop invariant firstDigit <= 9;
        loop invariant fact >= 0 ==> firstDigit >= 0;
        loop invariant fact >= 0 ==> firstDigit <= fact + 9;
        loop invariant fact >= 0 ==> firstDigit <= fact % 10 + 9;
        loop invariant fact >= 0 ==> firstDigit <= 9;
        loop invariant fact >= 0 ==> 0 <= firstDigit;
        loop invariant fact >= 0 ==> 0 <= firstDigit <= 9;
        loop invariant fact >= 0 ==> (fact == 0 || fact > 0);
        loop invariant fact > 0 ==> firstDigit >= 0;
        loop invariant fact > 0 ==> firstDigit <= fact % 10 + 9;
        loop invariant fact > 0 ==> firstDigit <= 9;
        loop invariant fact > 0 ==> 0 <= firstDigit <= 9;
        loop invariant fact == 0 || fact > 0;
        loop invariant fact == 0 ==> firstDigit >= 0;
        loop invariant fact == 0 ==> firstDigit <= 9;
        loop invariant fact == 0 ==> 0 <= firstDigit <= 9;
        loop invariant fact / 10 <= fact;
        loop invariant fact % 10 == fact - 10 * (fact / 10);
        loop invariant fact % 10 <= 9;
        loop invariant 0 <= firstDigit;
        loop invariant 0 <= fact;
        loop invariant 0 <= fact ==> firstDigit <= 9;
        loop invariant 0 <= fact % 10;
        loop assigns firstDigit;
        loop assigns fact;*/
int check_A_implies_B(int n) {
    return stub_A(n);
}

/*@requires n >= 1;
  requires n <= 4;
  assigns \nothing;
  ensures \result >= 0;
  ensures 0 <= \result && \result <= 9;
  ensures n == 1 ==> \result >= 0;
  ensures n == 2 ==> \result >= 0;
  ensures n == 3 ==> \result >= 0;
  ensures n == 4 ==> \result >= 0;
  ensures n >= 5 ==> \result >= 0;*/
int check_B_implies_A(int n) {
    return stub_B(n);
}
