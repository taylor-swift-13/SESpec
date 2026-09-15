
/*@ logic integer gcd(integer a, integer b) = 1; */

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
