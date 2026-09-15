
        /*@
        logic integer seq(int n) =
          n == 0 ? 0 :
          n == 1 ? 1 :
          seq(n - 1) + 2 * seq(n - 2);
        */

/*@
  requires 1 <= j < INT_MAX;
  assigns \nothing;
  ensures \result == seq(j);
  ensures j == 1 ==> \result == 1;
  ensures j >= 2 ==> \result == seq(j - 1) + 2 * seq(j - 2);
  ensures \result >= 0;
*/
int foo288(int j) {

		int *ret = (int *)malloc(sizeof(int) * (j + 1));
int ret_len = j + 1;
		ret[0] = 0;
		ret[1] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= p <= j + 1;
          loop invariant \forall integer i; 0 <= i < p ==> ret[i] == seq(i);
          loop assigns p, ret[2 .. j];
            */
            for (int p = 2; p <= j; p++) {
			ret[p] = ret[p - 1]
					+ 2 * ret[p - 2];
		}
            
		return ret[j];
}
