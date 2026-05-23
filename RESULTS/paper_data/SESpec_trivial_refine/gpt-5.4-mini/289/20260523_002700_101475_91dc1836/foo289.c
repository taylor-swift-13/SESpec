
/*@
predicate_or_logic_function PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/

/*@ logic integer foo289_value(integer n) =
      n == 0 ? 2 :
      n == 1 ? 1 :
      foo289_value(n - 1) + 2 * foo289_value(n - 2); */
/*@
  requires c >= 1;
  assigns \nothing;
  ensures \result == foo289_value(c);
  ensures c == 1 ==> \result == 1;
  ensures c == 2 ==> \result == 5;
  ensures c >= 1 ==> \result > 0;
  ensures c >= 2 ==> \result == foo289_value(c - 1) + 2 * foo289_value(c - 2);
  ensures \result == \null ==> \false;
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
