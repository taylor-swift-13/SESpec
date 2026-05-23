
/*@
  assigns \nothing;
  ensures number == 1 ==> \result == 1;
  ensures number <= 0 ==> \result == 0;
  ensures number > 1 && (\forall integer i; 2 <= i <= number / i ==> number % i != 0) ==> \result == 0;
  ensures number > 1 && (\exists integer i; 2 <= i <= number / i && number % i == 0) ==> \result >= 1;
  ensures \result >= 0;
*/
int foo316(int number) {
  if (number == 1) {
    return 1;
  }

  if (number <= 0) {
    return 0;
  }

  /*@
    loop invariant 2 <= c;
    loop invariant \forall integer i; 2 <= i < c ==> number % i != 0;
    loop assigns c;
    loop variant number - c;
  */
  for (int c = 2; c <= number / c; c++) {
    if (number % c == 0) {
      return 1;
    }
  }

  return 0;
}
