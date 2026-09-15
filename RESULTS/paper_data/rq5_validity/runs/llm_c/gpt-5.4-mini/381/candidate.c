/*@
    requires x >= 0;
    requires y >= 0;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == (\numof integer i; 1 <= i <= x && 1 <= i <= y && x % i == 0 && y % i == 0);
*/
int numCommDiv(int x, int y);

 /*@
    requires x >= 0;
    requires y >= 0;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == (\numof integer i; 1 <= i <= x && 1 <= i <= y && x % i == 0 && y % i == 0);
*/
int numCommDiv(int x, int y) {

        int count = 0;
        /*@
            loop invariant 1 <= i <= (x < y ? x : y) + 1;
            loop invariant count == (\numof integer j; 1 <= j < i && j <= x && j <= y && x % j == 0 && y % j == 0);
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
