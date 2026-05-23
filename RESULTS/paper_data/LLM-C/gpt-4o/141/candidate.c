/*@
    requires n > 0;
    ensures \result == 0 <==> n == 1;
    ensures n > 1 && n % 2 == 0 ==> \result == n / 2;
    ensures n > 1 && n % 2 != 0 ==> \result == n;
    assigns \nothing;
*/
int numberOfCuts(int n);

int numberOfCuts(int n) {

        return ((n == 1) ? 0 : ((n % 2 == 0) ? (n / 2) : n));
}
