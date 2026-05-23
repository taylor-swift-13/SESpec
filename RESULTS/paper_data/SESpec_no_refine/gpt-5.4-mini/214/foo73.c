
/*@
  ensures \result == 0 || \result == 1;
  ensures \old(n) <= 0 ==> \result == 0;
  assigns \nothing;
*/
int foo73(int n) {

        if(n <= 0) {
            return 0;
        }
        
            
        /*@
          loop invariant n > 0;
          loop invariant \at(n, Pre) > 0;
          loop assigns n;
        */
            while (n % 4 == 0) {
            n /= 4;
        }
            
        return n == 1;
}
