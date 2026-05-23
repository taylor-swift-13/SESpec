
/*@
  requires 0 <= value;
  requires p > 0;
  assigns \nothing;
  ensures 0 <= \result;
  ensures \result <= value;
  ensures \result == 0 <==> (\forall integer c; 1 <= c <= value ==> (c % p) != dy);
  ensures \result != 0 ==> (\result % p == dy && \forall integer c; \result < c <= value ==> (c % p) != dy);
*/
int foo369(int value, int p, int dy) {
  int result = 0;

  /*@
    loop invariant 1 <= c <= value + 1;
    loop invariant 0 <= result <= value;
    loop invariant result == 0 || (1 <= result < c && (result % p) == dy);
    loop invariant \forall integer k; 1 <= k < c && result < k ==> (k % p) != dy;
    loop assigns c, result;
  */
  for (int c = 1; c <= value; c++) {
    if ((c % p) == dy) {
      result = c;
    }
  }

  return result;
}
