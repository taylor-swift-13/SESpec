/*@
    requires \true;
    ensures \result == m + n;
    assigns \nothing;
*/
int addition(int m, int n);

int addition(int m, int n) {

        if (n == 0) {
            return m;
        }
        if (n > 0) {
            /*@
                ensures \result == m + n;
            */
            return addition(m + 1, n - 1);
        } else {
            /*@
                ensures \result == m + n;
            */
            return addition(m - 1, n + 1);
        }
}
