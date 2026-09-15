
/*@
predicate_or_logic_function PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/

int foo289(int c) {

		int *j = (int *)malloc(sizeof(int) * (c + 1));
int j_len = c + 1;
		j[0] = 2;
		j[1] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant j_len == c + 1;
          loop invariant 2 <= d <= c + 1;
          loop invariant \valid(j + (0 .. c));
          loop invariant j[0] == 2;
          loop invariant j[1] == 1;
          loop invariant \forall int i; 2 <= i < d ==> j[i] == j[i - 1] + 2 * j[i - 2];
          loop assigns d, j[2 .. c];
            */
            for (int d = 2; d <= c; d++) {
			j[d] = j[d - 1]
					+ 2 * j[d - 2];
		}
            
		return j[c];
}
