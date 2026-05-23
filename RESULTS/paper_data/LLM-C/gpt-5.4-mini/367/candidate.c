/*@
    requires n >= 2;
    ensures 2 <= \result <= n;
    ensures n % \result == 0;
    ensures \forall integer d; 2 <= d < \result ==> n % d != 0;
    assigns \nothing;
*/
int smallestDivisor(int n);

int smallestDivisor(int n) {

        int i = 2;
        /*@
            loop invariant 2 <= i;
            loop invariant i <= n + 1;
            loop invariant \forall integer d; 2 <= d < i ==> n % d != 0;
            loop assigns i;
            loop variant (n / i) - i;
        */
        while (i <= n / i) {
            if (n % i == 0) {
                return i;
            }
            i++;
        }
        return n;
}
