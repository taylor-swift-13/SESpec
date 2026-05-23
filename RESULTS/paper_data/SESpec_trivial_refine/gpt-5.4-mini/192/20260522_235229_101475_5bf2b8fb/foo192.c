
        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */

/*@ logic integer wval(integer n, integer i) =
      i == 0 ? 1 :
      i == 1 ? 0 :
      wval(n, i - 2) + 2 * cval(n, i - 1);
*/
/*@ logic integer cval(integer n, integer i) =
      i == 0 ? 0 :
      i == 1 ? 1 :
      wval(n, i - 1) + cval(n, i - 2);
*/
/*@
  requires count >= 1;
  assigns \nothing;
  ensures \result == wval(count, count);
  ensures count == 1 ==> \result == 0;
  ensures count >= 2 ==> \result == wval(count, count);
*/
int foo192(int count) {

		int *w = (int *)malloc(sizeof(int) * (count + 1));
int w_len = count + 1;
		int *C = (int *)malloc(sizeof(int) * (count + 1));
int C_len = count + 1;
		w[0] = 1;
		w[1] = 0;
		C[0] = 0;
		C[1] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant index >= 2;
          loop invariant count < 1 || index <= count + 1;
          loop assigns index, w[2 .. count], C[2 .. count];
            */
            for (int index = 2; index <= count; index++) {
			w[index] = w[index - 2]
					+ 2 * C[index - 1];
			C[index] = w[index - 1] + C[index - 2];
		}
            
		return w[count];
}
