
/*@ logic integer fact(integer n) =
      n <= 1 ? 1 : n * fact(n - 1);
*/

/*@ logic integer first_digit(integer n) =
      (n < 10 ? n : first_digit(n / 10));
*/

/*@ axiomatic FirstDigitLemmas {
      lemma first_digit_small:
        \forall integer n; 0 <= n < 10 ==> first_digit(n) == n;

      lemma first_digit_step:
        \forall integer n; n >= 10 ==> first_digit(n) == first_digit(n / 10);
  }
*/

/*@
  requires num >= 0;
  assigns \nothing;
  ensures \result == first_digit(fact(num));
  ensures \result >= 0;
  ensures \result <= 9;
*/
int foo325(int num) {
    int first = 1;

    /*@
      loop invariant 1 <= j <= num + 1;
      loop invariant first == fact(j - 1);
      loop invariant first >= 1;
      loop assigns first, j;
      loop variant num - j + 1;
    */
    for (int j = 1; j <= num; j++) {
        first *= j;
    }

    /*@
      loop invariant first >= 1;
      loop invariant first_digit(first) == first_digit(fact(num));
      loop assigns first;
      loop variant first;
    */
    while (first >= 10) {
        first /= 10;
    }

    /*@ assert 0 <= first < 10; */
    /*@ assert first_digit(first) == first; */
    /*@ assert first == first_digit(fact(num)); */

    return first;
}
