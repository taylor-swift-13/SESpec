

/*@ logic integer foo293_seq(integer n) =
      n == 0 ? 0 :
      n == 1 ? 1 :
      (2 * foo293_seq(n - 1) + foo293_seq(n - 2)) % 1000000000; */
/*@
  requires 1 <= seed;
  assigns \result \from seed;
  ensures \result == foo293_seq(seed);
  ensures 0 <= \result < 1000000000;
*/
int foo293(int seed) {
    int i = 2;
    int prev2 = 0;
    int prev1 = 1;
    int curr = 0;

    /*@
      loop invariant 2 <= i <= seed + 1;
      loop invariant prev2 == foo293_seq(i - 2);
      loop invariant prev1 == foo293_seq(i - 1);
      loop invariant 0 <= prev2 < 1000000000;
      loop invariant 0 <= prev1 < 1000000000;
      loop assigns i, prev2, prev1, curr;
      loop variant seed + 1 - i;
    */
    for (; i <= seed; i++) {
        curr = (int)(((long long)2 * prev1 + prev2) % 1000000000LL);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
