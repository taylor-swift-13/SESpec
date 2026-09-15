/*@
    requires x > 0 && y > 0;
    ensures \result == (x * y) / (\lambda integer gcd; gcd > 0 && x % gcd == 0 && y % gcd == 0 && 
                        (\forall integer k; k > 0 && k < gcd ==> x % k != 0 || y % k != 0));
    assigns \nothing;
*/
int lcm(int x, int y);

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
            loop invariant gcd > 0 && gcd <= x;
            loop invariant \forall integer k; 1 <= k < i ==> (x % k == 0 && y % k == 0) ==> k <= gcd;
            loop assigns i, gcd;
            loop variant x - i;
        */
        for (int i = 1; i <= x; i++) {
            if (x % i == 0 && y % i == 0) {
                gcd = i;
            }
        }
        lcm = (x * y) / gcd;
        return lcm;
}
