
/*@
  ensures \result == 0 || \result == 1;
  ensures \result == 0 <==> \old(n) <= 0;
  ensures \result == 1 <==> \old(n) > 0 && (\old(n) % 4 != 0 || \old(n) == 1 || (\old(n) % 4 == 0 && (\old(n) / 4 == 1 || (\old(n) / 4) % 4 != 0)));
  assigns \nothing;
*/
int foo73(int n) {

        if(n <= 0) {
            return 0;
        }
        
            
        /*@
          loop invariant n > 0;
          loop invariant n % 4 == 0;
        */
        
            /*@
          loop invariant (!(n % 4 == 0)) ==> ();
          loop assigns n;
            */
            while (n % 4 == 0) {
            n /= 4;
        }
            
        return n == 1;
}
