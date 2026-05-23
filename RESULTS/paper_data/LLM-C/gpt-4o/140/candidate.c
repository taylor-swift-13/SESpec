/*@
    requires n > 0;
    ensures \result == 0 <==> n == 1;
    ensures n > 1 && n % 2 == 0 ==> \result == n / 2;
    ensures n > 1 && n % 2 != 0 ==> \result == n;
    assigns \nothing;
*/
int numberOfCuts(int n) {

        if (n == 1) {
            return 0;
        }
        if (n % 2 == 0) {
            return n / 2;
        }
        return n;
}
