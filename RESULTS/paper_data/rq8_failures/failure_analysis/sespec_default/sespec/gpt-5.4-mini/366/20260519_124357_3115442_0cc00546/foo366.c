
/*@ requires n >= 1;
    requires n >= 2;
    assigns \nothing;
*/
int foo366(int n) {

        int sum = 0;
        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant n == \at(n,Pre);
          loop invariant sum >= 0;
          loop invariant count >= 0;
          loop invariant count <= i - 1;
          loop assigns i, sum, count;
            */
            for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                sum += i;
                count++;
            }
        }
            
        return sum / count;
}
