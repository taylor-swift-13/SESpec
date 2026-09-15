
/*@ logic integer int_abs(integer v) =
      v < 0 ? -v : v; */
/*@
  assigns \nothing;
                                   t % int_abs(\old(x) <= \old(y) ? \old(y) : \old(x)) == 0 ==> int_abs(\result) <= t));
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
          loop invariant foo322 == 1;
          loop invariant \forall integer d; 1 <= d < i ==> (d <= x && d <= y && x % d == 0 && y % d == 0) ==> gcd >= d;
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
