
/*@ axiomatic Factorial {
    logic integer fact(integer n);

    axiom fact_0: fact(0) == 1;
    axiom fact_1: fact(1) == 1;
    axiom fact_succ:
      \forall integer n; n > 1 ==> fact(n) == n * fact(n - 1);
  }
*/

/*@
  requires number >= 0;
  assigns \nothing;
  ensures 0 <= \result <= 9;
*/
int foo324(int number) {
  int first = 1;
  int c;

  /*@
    loop invariant 2 <= c <= number + 2;
    loop invariant first == fact(c - 1);
    loop invariant first > 0;
    loop assigns c, first;
    loop variant number - c + 2;
  */
  for (c = 2; c <= number; c++) {
    first *= c;
  }

  int result = 0;

  /*@
    loop invariant first >= 0;
    loop invariant 0 <= result <= 9;
    loop assigns first, result;
    loop variant first;
  */
  while (first > 0) {
    result = first % 10;
    first /= 10;
  }

  return result;
}
