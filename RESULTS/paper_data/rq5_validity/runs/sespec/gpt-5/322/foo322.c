
/*@
  assigns \nothing;
  ensures x == 0 || y == 0 ==> \result == 0;
  ensures x != 0 && y != 0 ==> \exists integer g; 1 <= g && x % g == 0 && y % g == 0 && \result == (x * y) / g;
  ensures x == 0 && y != 0 ==> \result == 0;
  ensures y == 0 && x != 0 ==> \result == 0;
*/
int foo322(int x, int y) {

        int gcd = 1;
        int foo322 = 1;
        if (x > y) {
            int temp = x;
            x = y;
            y = temp;
        }
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i;
          loop invariant gcd >= 1;
          loop invariant x <= y;
          loop invariant (x % gcd == 0) && (y % gcd == 0);
          loop invariant \forall integer d; 1 <= d < i ==> ((x % d == 0 && y % d == 0) ==> d <= gcd);
          loop invariant (\exists integer d; 2 <= d < i && x % d == 0 && y % d == 0) ==> (gcd >= 2);
          loop invariant \forall integer d; i <= d <= x ==> ((x % d == 0 && y % d == 0) ==> gcd <= d || gcd == 1);
          loop invariant (i <= \at(y,Pre)) ==> (gcd >= 1);
          loop invariant (i <= \at(y,Pre)) ==> ((foo322 == 1) && (gcd >= 1));
          loop invariant (!(i <= \at(y,Pre))) ==> (foo322 == 1);
          loop invariant foo322 == 1;
          loop assigns i, gcd;
            */
            for (int i = 1; i <= x; i++) {
            if (x % i == 0 && y % i == 0) {
                gcd = i;
            }
        }
            
        foo322 = (x * y) / gcd;
        return foo322;
}
