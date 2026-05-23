int notCommonFactor(int a, int b, int factor);

/*@
    requires factor != 0;
    assigns \nothing;
    ensures \result == (a % factor != 0 || b % factor != 0);
    ensures \result == 0 || \result == 1;
*/
int notCommonFactor(int a, int b, int factor) {

        return a % factor != 0 || b % factor != 0;
}
