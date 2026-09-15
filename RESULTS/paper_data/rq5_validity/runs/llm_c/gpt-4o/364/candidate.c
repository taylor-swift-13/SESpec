/*@
    requires n >= 0;
    ensures \result >= 0 && \result < 7;
    assigns \nothing;
*/
int oddDays(int n);

int oddDays(int n) {

        int hund1 = n / 100;
        int hund4 = n / 400;
        int leap = n / 4;
        int ordd = n - leap ;
        /*@
            loop invariant hund1 == n / 100;
            loop invariant hund4 == n / 400;
            loop invariant leap == n / 4;
            loop invariant ordd == n - leap;
            loop assigns ordd, leap;
        */
        if (hund1 != 0) {
            ordd += hund1 ;
            leap -= hund1 ;
        }
        if (hund4 != 0) {
            ordd -= hund4 ;
            leap += hund4 ;
        }
        int days = ordd + leap * 2;
        return days % 7;
}
