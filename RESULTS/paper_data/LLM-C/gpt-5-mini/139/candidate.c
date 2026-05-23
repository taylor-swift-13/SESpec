int NotCommonMultiple(int a, int b, int m);

/*@
    requires a != 0 && b != 0;
    assigns \nothing;
    ensures \result == 0 <==> (m % a == 0 && m % b == 0);
    ensures \result == 1 <==> (m % a != 0 || m % b != 0);
    ensures \result == 0 || \result == 1;
*/
int NotCommonMultiple(int a, int b, int m) {

        return m % a != 0 || m % b != 0;
}
