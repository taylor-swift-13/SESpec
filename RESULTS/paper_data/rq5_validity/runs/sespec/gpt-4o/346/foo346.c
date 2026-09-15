
/*@
  requires n > 1; // Strengthened precondition to exclude n == 1
  assigns \nothing;
*/
int foo346(int n) {

    int max = 0;

    /*@
      loop invariant \exists integer k; 2 <= k < i && n % k == 0 ==> max == k; // Strengthened invariant
      loop assigns i, max, n;
      loop variant n - i;
    */
    for (int i = 2; i <= n; i++) {

        /*@
          loop assigns max, n;
          loop variant n;
        */
        while (n % i == 0) {
            max = i;
            n /= i;
        }
    }

    return max;
}
