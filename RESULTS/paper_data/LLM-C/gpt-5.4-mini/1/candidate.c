/*@
    requires n >= 0 || n <= 0;
    ensures \result == m + n;
    assigns \nothing;
    decreases n >= 0 ? n : -n;
*/
int addition(int m, int n);

 /*@
    requires n >= 0 || n <= 0;
    ensures \result == m + n;
    assigns \nothing;
    decreases n >= 0 ? n : -n;
*/
int addition(int m, int n) {

        if (n == 0) {
            return m;
        }
        if (n > 0) {
            return addition(m + 1, n - 1);
        } else {
            return addition(m - 1, n + 1);
        }
}
