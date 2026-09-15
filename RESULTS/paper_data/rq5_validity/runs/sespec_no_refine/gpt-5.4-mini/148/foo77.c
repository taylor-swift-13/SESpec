
/*@
  assigns \nothing;
  ensures n <= 0 ==> \result == 0;
*/
int foo77(int n) {

        if(n <= 0) {
            return 0;
        }
        
            
        /*@
          loop invariant n >= 1;
          loop invariant n > 0;
          loop invariant n == n;
          loop assigns n;
        */
            while (n % 2 == 0) {
            n /= 2;
        }
            
        return n == 1;
}
