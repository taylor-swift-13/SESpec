/*@
    assigns \nothing;
    ensures \result == (n % 4 != 0);
*/
int canWinNim(int n);

int canWinNim(int n) {

        return n % 4 != 0;
}
