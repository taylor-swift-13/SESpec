int difference(int n);

/*@ 
  requires n <= 303;
  assigns \nothing;
  ensures \result == (\sum(integer k=1, n, k*k*k) - \sum(integer k=1, n, k));
  ensures n <= 0 ==> \result == 0;
  ensures n > 0 ==> \result == ((n*(n+1))/2) * ((n*(n+1))/2) - (n*(n+1))/2;
*/
int difference(int n) {

        int sum = 0;
        int sum1 = 0;
        /*@ 
            loop invariant 1 <= i;
            loop invariant (n < 1) ? i == 1 : i <= n + 1;
            loop invariant sum == \sum(integer k=1, i-1, k*k*k);
            loop invariant sum >= 0;
            loop assigns i, sum;
            loop variant n < 1 ? 0 : n - i + 1;
        */
        for (int i = 1; i <= n; i++) {
            sum += i * i * i;
        }
        /*@
            loop invariant 1 <= i;
            loop invariant (n < 1) ? i == 1 : i <= n + 1;
            loop invariant sum1 == \sum(integer k=1, i-1, k);
            loop invariant sum1 >= 0;
            loop assigns i, sum1;
            loop variant n < 1 ? 0 : n - i + 1;
        */
        for (int i = 1; i <= n; i++) {
            sum1 += i;
        }
        return sum - sum1;
}
