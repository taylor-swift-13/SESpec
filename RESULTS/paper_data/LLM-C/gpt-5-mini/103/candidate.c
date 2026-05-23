int divisorGame(int n);

/*@
    requires \true;
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures (n % 2 == 0) ==> \result == 1;
    ensures (n % 2 != 0) ==> \result == 0;
*/
int divisorGame(int n) {

        return n % 2 == 0;
}
