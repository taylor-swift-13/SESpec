int sumOfOddFactors(int n);

/*@
  requires n >= 1;
  assigns \nothing;
  ensures \result == \sum_{integer i = 1 .. n} ((n % i == 0 && i % 2 != 0) ? i : 0);
  ensures \result >= 0;
*/
int sumOfOddFactors(int n) {

        int sum = 0;
        /*@
          loop invariant 1 <= i <= n + 1;
          loop invariant sum == \sum_{integer j = 1 .. i - 1} ((n % j == 0 && j % 2 != 0) ? j : 0);
          loop invariant sum >= 0;
          loop assigns i, sum;
          loop variant n - i + 1;
        */
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                if (i % 2 != 0) {
                    sum += i;
                }
            }
        }
        return sum;
}
