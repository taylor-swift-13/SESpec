/*@
    requires x >= 0;
    requires y >= 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int lcm(int x, int y);

 /*@
    requires x >= 0;
    requires y >= 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int lcm(int x, int y) {

        int gcd = 1;
        int lcm = 1;
        if (x > y) {
            int temp = x;
            x = y;
            y = temp;
        }
        /*@
            loop invariant 1 <= i <= x + 1;
            loop invariant gcd >= 1;
            loop invariant \forall integer k; 1 <= k < i && x % k == 0 && y % k == 0 ==> k <= gcd;
            loop assigns i, gcd;
            loop variant x - i + 1;
        */
        for (int i = 1; i <= x; i++) {
            if (x % i == 0 && y % i == 0) {
                gcd = i;
            }
        }
        lcm = (x * y) / gcd;
        return lcm;
}
