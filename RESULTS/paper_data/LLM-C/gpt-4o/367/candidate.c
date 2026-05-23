/*@
    requires n > 1;
    ensures \result > 1;
    ensures n % \result == 0;
    ensures \forall integer k; 1 < k < \result ==> n % k != 0;
    assigns \nothing;
*/
int smallestDivisor(int n) {

        int i = 2;
        /*@
        loop invariant 2 <= i <= n / i + 1;
        loop invariant \forall integer k; 2 <= k < i ==> n % k != 0;
        loop assigns i;
        loop variant n / i;
        */
        while (i <= n / i) {
            if (n % i == 0) {
                return i;
            }
            i++;
        }
        return n;
}
