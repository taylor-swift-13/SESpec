
/*@
  requires n > 0;
  ensures \result >= 0;
  ensures n == 1 ==> \result == 0;
  ensures n > 1 ==> (\forall integer k; 2 <= k <= n ==> (n % k != 0 || \result == k));
*/

int foo346(int n) {

    int max = 0;

    /*@
      loop invariant max >= 0;
      loop assigns i, max, n;
    */
    for (int i = 2; i <= n; i++) {

        /*@
          loop assigns max, n;
        */
        while (n % i == 0) {
            max = i;
            n /= i;
        }
    }

    return max;
}
