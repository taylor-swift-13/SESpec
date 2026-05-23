
/*@ 
  requires 1 <= x && 1 <= y;
  assigns \nothing;
  ensures \exists integer g;
            1 <= g && g <= \at(x,Pre)
            && \at(x,Pre) % g == 0 && \at(y,Pre) % g == 0
            && \result == (\at(x,Pre) * \at(y,Pre)) / g;
*/
int foo140(int x, int y) {

        int gcd = 1;
        int foo140 = 1;
        if (x > y) {
            int temp = x;
            x = y;
            y = temp;
        }
        
        /*@
          loop invariant 1 <= i;
          loop invariant 1 <= gcd;
          loop invariant x % gcd == 0 && y % gcd == 0;
          loop invariant gcd <= i;
          loop invariant foo140 == 1;
          loop assigns i, gcd;
        */
        for (int i = 1; i <= x; i++) {
            if (x % i == 0 && y % i == 0) {
                gcd = i;
            }
        }
            
        foo140 = (x * y) / gcd;
        return foo140;
}
