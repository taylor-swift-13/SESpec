
/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/

/*@
  assigns \nothing;
  ensures \result == 0 || \result >= 2;
*/
int foo198(int n) {

        int max = 0;
        
            
        /*@
          loop invariant max == 0 || max >= 2;
          loop invariant n >= 0;
          loop assigns i, max, n;
        */
            for (int i = 2; i <= n; i++) {
            
            
        /*@
              loop invariant max == 0 || max >= 2;
              loop invariant n >= 0;
              loop invariant n % i == 0 || n % i != 0;
              loop assigns max, n;
            */
            while (n % i == 0) {
                max = i;
                n /= i;
            }
            
        }
            
        return max;
}
