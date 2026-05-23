/*@
    requires n > 0;
    ensures \result == 1 <==> n % 2 == 0;
    ensures \result == 0 <==> n % 2 != 0;
    assigns \nothing;
*/
int divisorGame(int n) {
    return n % 2 == 0;
}
