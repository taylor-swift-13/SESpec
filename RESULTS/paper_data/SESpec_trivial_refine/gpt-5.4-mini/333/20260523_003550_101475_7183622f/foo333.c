
/*@
  logic integer mod10(integer x) = ((x % 10) + 10) % 10;

  logic integer fold10(integer n, integer c, integer acc) =
    (n > c) ? (acc % 10)
            : fold10(n + 1, c, (acc * mod10(n)) % 10);
*/

/*@ 
  assigns \nothing;
  ensures n == c ==> \result == 1;
  ensures n > c ==> \result == 1;
  ensures c - n >= 5 ==> \result == 0;
  ensures 0 <= \result <= 9;
*/
int foo333(int n, int c) {
  int result = 1;

  if (n == c) {
    return 1;
  } else if (n > c) {
    return 1;
  } else if ((c - n) >= 5) {
    return 0;
  } else {
    /*@
      loop invariant n + 1 <= var <= c + 1;
      loop invariant 0 <= result <= 9;
      loop assigns var, result;
      loop variant c - var + 1;
    */
    for (int var = n + 1; var < c + 1; var++) {
      int digit = ((var % 10) + 10) % 10;
      result = (result * digit) % 10;
    }

    return result;
  }
}
