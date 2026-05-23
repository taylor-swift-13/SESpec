/*@
    requires n >= 1;
    ensures \result == ((n == 1) ? 0 : ((n % 2 == 0) ? (n / 2) : n));
    assigns \nothing;
*/
int numberOfCuts(int n);

int numberOfCuts(int n) {

        return ((n == 1) ? 0 : ((n % 2 == 0) ? (n / 2) : n));
}
