/*@
    requires factor > 0;
    ensures \result == 1 <==> (a % factor == 0 && b % factor == 0);
    ensures \result == 0 <==> (a % factor != 0 || b % factor != 0);
    assigns \nothing;
*/
int isCommonFactor(int a, int b, int factor);

int isCommonFactor(int a, int b, int factor) {

        if (a % factor != 0) {
            return 0;
        }
        if (b % factor != 0) {
            return 0;
        }
        return 1;
}
