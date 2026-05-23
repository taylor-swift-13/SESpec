int lcm(int x, int y);

/*@
    requires x > 0 && y > 0;
    assigns \nothing;
    ensures \exists integer g;
        1 <= g &&
        g <= \old(x) &&
        \old(x) % g == 0 &&
        \old(y) % g == 0 &&
        (\forall integer k; 1 <= k <= \old(x) && \old(x) % k == 0 && \old(y) % k == 0 ==> k <= g) &&
        \result == (\old(x) * \old(y)) / g;
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
            loop invariant 1 <= i && i <= x + 1;
            loop invariant 1 <= gcd && gcd <= x;
            loop invariant x % gcd == 0 && y % gcd == 0;
            loop invariant \forall integer j; 1 <= j < i ==> ((x % j == 0 && y % j == 0) ==> j <= gcd);
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
