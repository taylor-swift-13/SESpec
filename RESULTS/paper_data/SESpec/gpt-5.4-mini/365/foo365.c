
/*@
  assigns \nothing;
  ensures n > 0 ==> \result >= 1;
  
*/
int foo365(int n) {

        int sum = 0;
        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant i >= 1;
          loop invariant 0 <= count;
          loop invariant 0 <= sum;
          loop invariant count == i / 2;
          loop invariant sum == count * count;
          loop invariant n == \at(n,Pre);
          loop assigns i, sum, count;
            */
            for (int i = 1; i <= n; i++) {
            if (i % 2 != 0) {
                sum += i;
                count++;
            }
        }
            
        return sum / count;
}
