int countFac(int n);

/*@
    requires n >= 1;
    assigns \nothing;
    ensures n == 1 ==> \result == 1;
    ensures n >= 2 ==> \result == \numof integer k; 2 <= k <= n / k && n % k == 0; 1;
    ensures \result >= 0;
*/
int countFac(int n) {

        int count = 0;
        if (n == 1) return 1;
        /*@
            loop invariant 2 <= i <= n+1;
            loop invariant count >= 0;
            loop invariant count == \numof integer k; 2 <= k < i && n % k == 0; 1;
            loop assigns i, count;
            loop variant n - i + 1;
        */
        for (int i = 2; i <= n / i; i++) {
            if (n % i == 0) {
                count++;
                if (n / i == i) {
                    break;
                }
            }
        }
        return count;
}
