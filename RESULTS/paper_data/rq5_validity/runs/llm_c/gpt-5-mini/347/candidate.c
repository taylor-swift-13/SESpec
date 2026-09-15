int findDivisor(int x, int y);

/*@
    requires \true;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == \numof integer k; 1 <= k <= (y < 0 ? -y : y) && x % k == 0;
*/
int findDivisor(int x, int y) {

        if (y < 0) {
            y = -y;
        }
        int count = 0;
        /*@
            loop invariant 1 <= i <= y + 1;
            loop invariant 0 <= count <= i-1;
            loop invariant count == \numof integer k; 1 <= k < i && x % k == 0;
            loop assigns i, count;
            loop variant y - i + 1;
        */
        for (int i = 1; i <= y; i++) {
            if (x % i == 0) {
                count = count + 1;
            }
        }
        return count;
}
