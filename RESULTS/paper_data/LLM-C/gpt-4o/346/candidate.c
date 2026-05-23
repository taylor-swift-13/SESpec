/*@
    requires n > 0;
    ensures \result > 0;
    ensures \forall integer i; 2 <= i <= n ==> (n % i == 0 ==> i <= \result);
    ensures \exists integer i; 2 <= i <= n && n % i == 0 && i == \result;
    assigns \nothing;
*/
int maxPrimeFactors(int n) {

        int max = 0;
        /*@
        loop invariant 2 <= i <= n + 1;
        loop invariant max > 0 ==> \exists integer j; 2 <= j <= i - 1 && n % j == 0 && j == max;
        loop assigns i, n, max;
        loop variant n;
        */
        for (int i = 2; i <= n; i++) {
            /*@
            loop invariant n >= 0;
            loop invariant max == i;
            loop assigns n;
            loop variant n;
            */
            while (n % i == 0) {
                max = i;
                n /= i;
            }
        }
        return max;
}
