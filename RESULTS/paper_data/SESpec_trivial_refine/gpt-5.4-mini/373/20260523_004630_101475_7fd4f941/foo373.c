
        /*@
  assigns \nothing;
  ensures \result >= 0;
  ensures number < 1 ==> \result == 0;
  ensures number >= 1 ==> \result >= 1;
  ensures number >= 1 ==> \result <= number;
*/
int foo373(int number) {

  int div = 0;

  /*@
    loop invariant 0 <= div;
    loop invariant 1 <= index;
    loop invariant number < 1 ==> (index == 1 && div == 0);
    loop invariant number >= 1 ==> index <= number + 1;
    loop invariant number >= 1 && index > 1 ==> div >= 1;
    loop invariant div <= index - 1;
    loop assigns div, index;
    loop variant number >= 1 ? number - index + 1 : 0;
  */
  for (int index = 1; index <= number; index++) {
    if (number % index == 0) {
      div++;
    }
  }

  return div;
}
