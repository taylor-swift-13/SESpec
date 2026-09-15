
/*@ logic integer rec_div(int w, integer d) =
      d == 0 ? 1 :
      d == 1 ? w :
      d == 2 ? w * w :
      ((w - 1) * (rec_div(w, d - 1) + rec_div(w, d - 2))) % 1000000007;
*/

int foo269(int dim, int w) {

		int count = 1000000007;
		int *div = (int *)malloc(sizeof(int) * (dim + 1));
int div_len = dim + 1;
		div[0] = 1;
		div[1] = w;
		div[2] = w * w;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant div_len == dim + 1;
          loop assigns d, div[0..dim];
            */
            for (int d = 3; d <= dim; d++) {
			div[d] = ((w - 1)
					* (div[d - 1] + div[d - 2])) % count;
		}
            
		return div[dim];
}
