
/*@
  loop invariant n > 0;
  loop invariant n % 4 == 0;
  loop invariant n == n;
*/

int foo73(int n) {

        if(n <= 0) {
            return 0;
        }
        
            
        /*@
          loop invariant n > 0;
          loop invariant n % 4 == 0;
          loop invariant n == \at(n, Pre);
          loop invariant \at(n, Pre) > 0;
          loop assigns n;
        */
            while (n % 4 == 0) {
            n /= 4;
        }
            
        return n == 1;
}
