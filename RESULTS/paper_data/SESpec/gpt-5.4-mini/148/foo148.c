

        
/*@
  assigns \nothing;
  ensures \at(n, Pre) <= 0 ==> \result == 0;
  ensures \at(n, Pre) > 0 ==> (0 <= \result <= 1);
  ensures 0 <= \result <= 1;
*/
int foo148(int n) {

        if(n <= 0) {
            return 0;
        }
        
            
        /*@
          loop invariant n >= 1;
          loop invariant n == 1 || n >= 2;
          loop invariant (n % 2 == 0) ==> n >= 2;
          loop invariant (n % 2 == 0) ==> (n > 0);
          loop invariant (!(n % 2 == 0)) ==> (\true);
          loop invariant (n % 2 == 0) ==> (n % 2 == 0);
          loop invariant (n % 2 != 0) ==> (n % 2 == 1);
          loop assigns n;
            */
            while (n % 2 == 0) {
            n /= 2;
        }
            
        return n == 1;
}
