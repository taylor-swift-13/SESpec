/*@
    requires n > 0;
    ensures \result >= 0;
    ensures \result == (\sum integer i; 1 <= i <= n && n % i == 0; 1);
    assigns \nothing;
*/
int divisor(int n) {

        int count = 0;
        /*@
            loop invariant 1 <= i <= n + 1;
            loop invariant count == (\sum integer j; 1 <= j < i && n % j == 0; 1);
            loop assigns i, count;
            loop variant n - i;
        */
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
        return count;
}
