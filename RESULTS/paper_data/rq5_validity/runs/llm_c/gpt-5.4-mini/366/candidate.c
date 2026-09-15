/*@
    requires n >= 2;
    assigns \nothing;
    ensures \result >= 2;
*/
int averageEven(int n);

int averageEven(int n) {

        int sum = 0;
        int count = 0;
        /*@
            loop invariant 1 <= i <= n + 1;
            loop invariant sum >= 0;
            loop invariant count >= 0;
            loop invariant count <= i / 2;
            loop assigns i, sum, count;
            loop variant n - i + 1;
        */
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                sum += i;
                count++;
            }
        }
        return sum / count;
}
