
/*@
  assigns \nothing;
  ensures \result == ((\old(x) > \old(y) ? \old(y) : \old(x)) * (\old(x) > \old(y) ? \old(x) : \old(y))) / 1;
*/
int foo140(int x, int y) {

        int gcd = 1;
        int foo140 = 1;
        if (x > y) {
            int temp = x;
            x = y;
            y = temp;
        }
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (i <= \at(y,Pre)) ==> (((foo140 == 1)&&(gcd == 1)&&(y == \at(x,Pre))&&(x == \at(y,Pre))) || (PLACE_HOLDER_gcd(x,y)));
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
