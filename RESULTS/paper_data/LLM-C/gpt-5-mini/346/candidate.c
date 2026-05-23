int maxPrimeFactors(int n);

/*@
    behaviour small_n:
        assumes n <= 1;
        ensures \result == 0;
        assigns \nothing;
    behaviour large_n:
        assumes n >= 2;
        assigns \nothing;
        ensures \result >= 2;
        ensures \old(n) % \result == 0;
        ensures (\forall integer d; 2 <= d < \result ==> \result % d != 0);
        ensures (\forall integer p; 2 <= p <= \old(n) && (\forall integer d; 2 <= d < p ==> p % d != 0) && \old(n) % p == 0 ==> p <= \result);
    complete behaviours small_n, large_n;
    disjoint behaviours small_n, large_n;
*/
int maxPrimeFactors(int n) {

        int max = 0;
        /*@ ghost int N0 = n; */
        /*@
            loop invariant 2 <= i <= N0;
            loop invariant 0 <= max <= i;
            loop invariant n >= 0;
            loop assigns i, n, max;
            loop variant N0 - i + 1;
        */
        for (int i = 2; i <= n; i++) {
            /*@
                loop invariant 2 <= i;
                loop invariant 0 <= max;
                loop invariant n >= 0;
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
