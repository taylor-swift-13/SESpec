/*@
    requires a != 0;
    requires b != 0;
    assigns \nothing;
    ensures \result == ((m % a != 0) || (m % b != 0));
*/
int NotCommonMultiple(int a, int b, int m);

 /*@
    requires a != 0;
    requires b != 0;
    assigns \nothing;
    ensures \result == ((m % a != 0) || (m % b != 0));
*/
int NotCommonMultiple(int a, int b, int m) {

        return m % a != 0 || m % b != 0;
}
