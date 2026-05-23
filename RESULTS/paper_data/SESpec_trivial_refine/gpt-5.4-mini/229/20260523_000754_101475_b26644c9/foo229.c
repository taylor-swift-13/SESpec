
/*@ 
logic integer dummy(integer x) = x;
*/

/*@ logic integer pow2(integer n) = n <= 0 ? 1 : 2 * pow2(n - 1); */
/*@
  requires 0 <= seed;
  assigns \result \from seed;
  ensures \result == pow2(seed);
  ensures \result >= 1;
  ensures seed > 0 ==> \result == 2 * pow2(seed - 1);
*/
int foo229(int seed) {
  int result = 1;

  /*@
    loop invariant 0 <= d <= seed;
    loop invariant result == pow2(d);
    loop invariant result >= 1;
    loop assigns d, result;
    loop variant seed - d;
  */
  for (int d = 0; d < seed; d++) {
    result = 2 * result;
  }

  return result;
}
