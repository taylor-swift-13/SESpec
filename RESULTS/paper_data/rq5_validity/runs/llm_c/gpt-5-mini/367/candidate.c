int smallestDivisor(int n);

 /*@
    requires n >= 2;
    assigns \nothing;
    ensures 2 <= \result <= n;
    ensures n % \result == 0;
    ensures \forall integer k; 2 <= k < \result ==> n % k != 0;
 */
int smallestDivisor(int n) {

        int i = 2;
        /*@
            loop invariant 2 <= i;
            loop invariant \forall integer j; 2 <= j < i ==> n % j != 0;
            loop assigns i;
            loop variant n - i;
        */
        while (i <= n / i) {
            if (n % i == 0) {
                return i;
            }
            i++;
        }
        return n;
}
