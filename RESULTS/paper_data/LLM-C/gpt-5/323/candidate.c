int countFac(int n);

/*@
  requires n >= 1;
  assigns \nothing;
  ensures (n == 1 ==> \result == 1);
  ensures (n > 1 ==> \result == (\sum integer i; 2 <= i <= n; ((i <= n / i && n % i == 0) ? 1 : 0)));
  ensures (\forall integer k; 2 <= k < n ==> n % k != 0) ==> \result == 0;
  ensures \result >= 0;
*/
int countFac(int n) {

        int count = 0;
        if (n == 1) return 1;
        /*@
          loop invariant i >= 2;
          loop invariant i <= n;
          loop invariant 0 <= count;
          loop invariant count == (\sum integer j; 2 <= j < i; ((n % j == 0) ? 1 : 0));
          loop assigns i, count;
          loop variant n - i;
        */
        for (int i = 2; i <= n / i; i++) {
            if (n % i == 0) {
                count++;
                /*@ assert n / i == i ==> i * i == n; */
                if (n / i == i) {
                    break;
                }
            }
        }
        return count;
}
