
/*@
        */

int foo268(int n) {

        int i = 2;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (2 <= \at(n,Pre) / 2) ==> (i <= n);
          loop invariant (!(2 <= \at(n,Pre) / 2)) ==> ((i == 2)&&(n == \at(n,Pre)));
          loop invariant n == \at(n,Pre);
          loop assigns i;
            */
            while (i <= n / i) {
            if (n % i == 0) {
                return i;
            }
            i++;
        }
            
        return n;
}
