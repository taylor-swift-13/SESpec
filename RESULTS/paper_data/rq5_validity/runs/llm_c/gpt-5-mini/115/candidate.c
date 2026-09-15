int isCommonFactor(int a, int b, int factor);

/*@
    requires factor != 0;
    assigns \nothing;
    ensures \result == ((a % factor == 0) && (b % factor == 0));
*/
int isCommonFactor(int a, int b, int factor) {

        return a % factor == 0 && b % factor == 0;
}
