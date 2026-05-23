
/*@
  requires number >= 0;
  assigns \nothing;
  ensures \result == count_divisors(number, number);
*/
int foo283(int number) {

    int div = 0;

    /*@
      loop invariant 1 <= c <= number + 1;
      loop invariant div == count_divisors(number, c - 1);
      loop invariant number == \at(number, Pre);
      loop assigns c, div;
      loop variant number - c;
    */
    for (int c = 1; c <= number; c++) {
        if (number % c == 0) {
            div++;
        }
    }

    return div;
}
