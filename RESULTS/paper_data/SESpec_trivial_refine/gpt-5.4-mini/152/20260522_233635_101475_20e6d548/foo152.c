


/*@
  requires number >= 0;
  ensures 0 <= \result <= number;
*/

int foo152(int number, int p) {

  int result[(number > 0) ? number : 1];
  int b[(number > 0) ? number : 1];
  int c, j = 0;

  /*@
    loop invariant 0 <= c <= number;
    loop invariant \forall integer i; 0 <= i < c ==> result[i] == i + 1;
    loop assigns c, result[0 .. number-1];
    loop variant number - c;
  */
  for (c = 0; c < number; c++) {
    result[c] = c + 1;
  }

  /*@ assert \forall integer i; 0 <= i < number ==> result[i] == i + 1; */

  /*@
    loop invariant 0 <= c <= number;
    loop invariant 0 <= j <= c;
    loop assigns c, j, b[0 .. number-1];
    loop variant number - c;
  */
  for (c = 0; c < number; c++) {
    b[c] = result[c];
    if (result[c] % 2 != 0) {
      j++;
      if (j == p) {
        return c + 1;
      }
    }
  }

  /*@
    loop invariant 0 <= c <= number;
    loop invariant 0 <= j <= number + c;
    loop assigns c, j, b[0 .. number-1];
    loop variant number - c;
  */
  for (c = 0; c < number; c++) {
    b[c] = result[c];
    if (result[c] % 2 == 0) {
      j++;
      if (j == p) {
        return c + 1;
      }
    }
  }

  return 0;
}
