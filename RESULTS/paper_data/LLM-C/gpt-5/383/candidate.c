int divisor(int n);

/*@ 
  assigns \nothing;
  ensures \result == \numof integer d; 1 <= d <= n && n % d == 0;
  ensures n <= 0 ==> \result == 0;
  ensures n >= 1 ==> 1 <= \result <= n;
*/
int divisor(int n) {

        int count = 0;
        /*@
          loop invariant 1 <= i <= n + 1;
          loop invariant 0 <= count <= i - 1;
          loop invariant count == \numof integer d; 1 <= d < i && n % d == 0;
          loop assigns i, count;
          loop variant n - i + 1;
        */
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
        return count;
}
