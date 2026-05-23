int canWinNim(int n);

/*@
    requires n >= 0;
    assigns \nothing;
    ensures \result == (n % 4 != 0);
    ensures \result == 0 || \result == 1;
*/
int canWinNim(int n) {

        return n % 4 != 0;
}
