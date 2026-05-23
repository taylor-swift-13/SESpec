/*@
    requires n >= 0;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == 0 <==> n <= 1;
*/
int maxPrimeFactors(int n);

 /*@
    requires n >= 0;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == 0 <==> n <= 1;
*/
int maxPrimeFactors(int n) {

        int max = 0;
        /*@
            loop invariant 2 <= i <= n + 1;
            loop invariant max >= 0;
            loop invariant n >= 0;
            loop assigns i, n, max;
            loop variant n - i + 1;
        */
        for (int i = 2; i <= n; i++) {
            /*@
                loop invariant n >= 0;
                loop invariant i >= 2;
                loop invariant n % i == 0;
                loop assigns n, max;
                loop variant n;
            */
            while (n % i == 0) {
                max = i;
                n /= i;
            }
        }
        return max;
}
