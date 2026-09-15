
/*@ logic integer foo269_seq(integer dim, integer w) =
      dim <= 0 ? 1 :
      dim == 1 ? w :
      dim == 2 ? w * w :
      ((w - 1) * (foo269_seq(dim - 1, w) + foo269_seq(dim - 2, w))) % 1000000007;
*/
/*@
  assigns \nothing;
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
          loop assigns d, div[0..div_len-1];
            */
            for (int d = 3; d <= dim; d++) {
			div[d] = ((w - 1)
					* (div[d - 1] + div[d - 2])) % count;
		}
            
		return div[dim];
}
