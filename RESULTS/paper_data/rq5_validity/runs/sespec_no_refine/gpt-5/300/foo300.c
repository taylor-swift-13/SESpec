
/*@
  // no additional predicates or logic functions are needed
*/

/*@
  requires \valid(&array[0] + (0..array_len-1));
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  requires array_len > 0;
  requires array_len < 100;
  assigns \nothing;
  ensures (Array <= 0 ==> \result == 0) &&
          (Array > 0 ==> (0 <= \result <= Array - 1));
*/
int foo300(int * array, int array_len, int Array) {

        int found = 0, top = Array - 1;
                
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant Array == Array;
          loop invariant array_len == array_len;
          loop invariant array == array;
          loop invariant 0 <= found <= top + (top < found ? 0 : 0);
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
