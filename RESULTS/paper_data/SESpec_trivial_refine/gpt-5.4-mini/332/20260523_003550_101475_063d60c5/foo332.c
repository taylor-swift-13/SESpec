
        /*@ logic integer foo332_prod10(integer a, integer b) =
      a > b ? 1 : ((foo332_prod10(a, b - 1) * (b % 10)) % 10); */
/*@
  requires 0 <= num <= c;
  assigns \nothing;
  ensures num == c ==> \result == 1;
  ensures num != c && (c - num) >= 5 ==> \result == 0;
  ensures num != c && (c - num) < 5 ==> \result == foo332_prod10(num + 1, c);
  ensures 0 <= \result <= 9;
*/
int foo332(int num, int c) {
  int result = 1;

  if (num == c) {
    return 1;
  } else if ((c - num) >= 5) {
    return 0;
  } else {
    /*@
      loop invariant num < c;
      loop invariant num + 1 <= var <= c + 1;
      loop invariant result == foo332_prod10(num + 1, var - 1);
      loop invariant 0 <= result <= 9;
      loop assigns result, var;
      loop variant c - var + 1;
    */
    for (int var = num + 1; var < c + 1; var++) {
      result = (result * (var % 10)) % 10;
    }

    return result;
  }
}
