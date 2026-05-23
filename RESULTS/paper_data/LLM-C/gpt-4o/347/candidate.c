/*@
    requires y != 0;
    ensures \result >= 0;
    ensures \result == (\sum integer i; 1 <= i <= \abs(y) && x % i == 0; 1);
*/
int findDivisor(int x, int y);

int findDivisor(int x, int y) {

        if (y < 0) {
            y = -y;
        }
        int count = 0;
        /*@
            loop invariant 1 <= i <= y + 1;
            loop invariant count == (\sum integer j; 1 <= j < i && x % j == 0; 1);
            loop assigns i, count;
            loop variant y - i;
        */
        for (int i = 1; i <= y; i++) {
            if (x % i == 0) {
                count = count + 1;
            }
        }
        return count;
}
