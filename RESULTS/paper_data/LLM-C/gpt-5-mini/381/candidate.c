int numCommDiv(int x, int y);

/*@
    requires x >= 0 && y >= 0;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == (\sum integer k; 1 <= k <= (x < y ? x : y); ((x % k == 0 && y % k == 0) ? 1 : 0));
*/
int numCommDiv(int x, int y) {

        int count = 0;
        /*@
            loop invariant 1 <= i <= (x < y ? x : y) + 1;
            loop invariant count >= 0;
            loop invariant count == (\sum integer k; 1 <= k < i; ((x % k == 0 && y % k == 0) ? 1 : 0));
            loop assigns i, count;
            loop variant (x < y ? x : y) - i + 1;
        */
        for (int i = 1; i <= x && i <= y; i++) {
            if (x % i == 0 && y % i == 0) {
                count++;
            }
        }
        return count;
}
