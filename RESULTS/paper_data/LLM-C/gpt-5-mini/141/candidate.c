int numberOfCuts(int n);

/*@
    requires \true;
    assigns \nothing;
    ensures (n == 1 && \result == 0)
         || (n != 1 && n % 2 == 0 && \result == n/2)
         || (n != 1 && n % 2 != 0 && \result == n);
*/
int numberOfCuts(int n) {

        return ((n == 1) ? 0 : ((n % 2 == 0) ? (n / 2) : n));
}
