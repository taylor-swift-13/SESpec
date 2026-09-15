/*@
    requires num >= 0;
    ensures \result >= 0 && \result < 10;
    ensures \result == num || (\exists integer k; k >= 1 && \result == (num - 9 * k) % 9);
*/
int digitRoot(int num);

int digitRoot(int num) {
    /*@
        loop invariant num >= 0;
        loop invariant num >= 10 ==> \exists integer k; k >= 1 && num == (num - 9 * k) % 9;
        loop assigns num;
        loop variant num;
    */
    while (num >= 10) {
        int sum = 0;
        /*@
            loop invariant sum >= 0;
            loop invariant num >= 0;
            loop assigns sum, num;
            loop variant num;
        */
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }
    return num;
}
