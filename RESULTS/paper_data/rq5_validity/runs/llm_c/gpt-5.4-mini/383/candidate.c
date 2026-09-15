/*@
    requires n >= 0;
    assigns \nothing;
    ensures \result >= 1;
*/
int divisor(int n);

 /*@
    requires n >= 0;
    assigns \nothing;
    ensures \result >= 1;
*/
int divisor(int n) {

        int count = 0;
        /*@
            loop invariant 1 <= i <= n + 1;
            loop invariant 0 <= count <= i - 1;
            loop assigns i, count;
            loop variant n - i + 1;
        */
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
        return count;
}
