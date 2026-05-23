/*@ 
  requires x > 0 && y > 0;
  requires x <= 46340 && y <= 46340;

  assigns \nothing;

  ensures \result > 0;
  ensures x % \result == 0 && y % \result == 0;
  ensures \forall integer m; m > 0 && x % m == 0 && y % m == 0 ==> \result <= m * (x / m) * (y / m);
*/
int lcm(int x, int y);

int lcm(int x, int y) {

        int gcd = 1;
        int lcm = 1;

        /*@ 
          assigns x, y;
          ensures x <= y;
          ensures x > 0 && y > 0;
        */
        if (x > y) {
            int temp = x;
            x = y;
            y = temp;
        }

        /*@ 
          loop invariant 1 <= i <= x + 1;
          loop invariant 1 <= gcd <= x;
          loop invariant x % gcd == 0;
          loop invariant y % gcd == 0;
          loop invariant \forall integer d; 1 <= d < i && x % d == 0 && y % d == 0 ==> d <= gcd;
          loop assigns i, gcd;
          loop variant x - i;
        */
        for (int i = 1; i <= x; i++) {
            if (x % i == 0 && y % i == 0) {
                gcd = i;
            }
        }

        /*@ assert gcd > 0; */
        /*@ assert x % gcd == 0 && y % gcd == 0; */

        lcm = (x * y) / gcd;

        /*@ assert lcm > 0; */
        /*@ assert lcm % x == 0 || x % lcm == 0; */
        return lcm;
}
