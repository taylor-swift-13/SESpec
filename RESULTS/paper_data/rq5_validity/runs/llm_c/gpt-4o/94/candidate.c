/*@
    requires n >= 0;
    ensures \result == 1 <==> n % 4 != 0;
    ensures \result == 0 <==> n % 4 == 0;
    assigns \nothing;
*/
int canWinNim(int n) {

        return n % 4 != 0;
}
