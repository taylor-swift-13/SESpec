
        /*@ logic integer divcount(integer n, integer k) =
      k <= 0 ? 0 : divcount(n, k - 1) + ((n % k) == 0 ? 1 : 0); */
/*@
  assigns \nothing;
  ensures \result == divcount(num, \old(z) < 0 ? -\old(z) : \old(z));
  ensures \old(z) < 0 ==> \result == divcount(num, -\old(z));
  ensures \old(z) >= 0 ==> \result == divcount(num, \old(z));
*/
int foo341(int num, int z) {
  if (z < 0) {
    z = -z;
  }

  int result = 0;

  /*@
    loop invariant 1 <= loop <= z + 1;
    loop invariant result == divcount(num, loop - 1);
    loop assigns loop, result;
  */
  for (int loop = 1; loop <= z; loop++) {
    if (num % loop == 0) {
      result = result + 1;
    }
  }

  return result;
}
