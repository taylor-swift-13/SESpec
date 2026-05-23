/*@ 
    requires x > 0 && y > 0;
    ensures \result >= 0;
    ensures \result == \sum(1 <= i <= x && 1 <= i <= y, (x % i == 0 && y % i == 0 ? 1 : 0));
    assigns \nothing;
*/
int numCommDiv(int x, int y) {

        int count = 0;
        /*@
        loop invariant 1 <= i <= x + 1 && 1 <= i <= y + 1;
        loop invariant count >= 0;
        loop invariant count == \sum(1 <= j < i, (x % j == 0 && y % j == 0 ? 1 : 0));
        loop assigns i, count;
        loop variant x + y - i;
        */
        for (int i = 1; i <= x && i <= y; i++) {
            if (x % i == 0 && y % i == 0) {
                count++;
            }
        }
        return count;
}
