
/*@ logic integer foo296_seq(integer n) =
      n == 0 ? 2 :
      n == 1 ? 1 :
      foo296_seq(n - 1) + foo296_seq(n - 2); */
/*@
  requires seed >= 0;
  assigns \result \from seed;
  ensures seed == 0 ==> \result == 2;
  ensures seed == 1 ==> \result == 1;
  ensures seed >= 2 ==> \result == foo296_seq(seed);
  ensures \result == foo296_seq(seed);
*/
int foo296(int seed) {
  if (seed == 0) return 2;
  if (seed == 1) return 1;

  int a = 2;
  int b = 1;

  /*@
    loop invariant 2 <= c <= seed + 1;
    loop invariant a == foo296_seq(c - 2);
    loop invariant b == foo296_seq(c - 1);
    loop assigns c, a, b;
    loop variant seed + 1 - c;
  */
  for (int c = 2; c <= seed; c++) {
    int t = a + b;
    a = b;
    b = t;
  }

  return b;
}
