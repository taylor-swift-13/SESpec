
/*@
  // No additional predicates or logic functions are required.
*/

int foo391(int n) {

        int i = 1;
        int square = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant n == \at(n,Pre);
          loop invariant i >= 1;
          loop invariant square >= 1;
          loop invariant square == (i-1)*(i-1);
          loop assigns square, i;
            */
            while (square <= n) {
            square = i*i;
            i++;
        }
            
        return square;
}
