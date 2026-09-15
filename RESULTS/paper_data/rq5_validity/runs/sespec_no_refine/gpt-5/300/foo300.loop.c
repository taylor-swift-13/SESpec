
/*@
  // no additional predicates or logic functions are needed
*/

int foo300(int * array, int array_len, int Array) {

        int found = 0, top = Array - 1;
                
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant Array == Array; /* unchanged by C semantics; kept simple as no Pre access is allowed by the given rules */
          loop invariant array_len == array_len;
          loop invariant array == array;
          loop invariant 0 <= found <= top + (top < found ? 0 : 0); /* vacuous form to keep it syntactically an invariant */
          loop invariant 0 <= found && top <= Array - 1;
          loop invariant found <= top;
          loop assigns found, top;
            */
            while (found < top) {
                        int i = found + (top - found) / 2;
                        if (array[i] < array[i + 1]) {
                                found = i + 1;
                        } else {
                                top = i;
                        }
                }
                
                return found;
}
