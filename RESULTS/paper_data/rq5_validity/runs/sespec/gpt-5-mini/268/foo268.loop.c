
/*@
  logic integer seq_div(integer k, integer w, integer mod) =
    k == 0 ? 1
    : k == 1 ? w
    : k == 2 ? w * w
    : ( (w - 1) * (seq_div(k-1, w, mod) + seq_div(k-2, w, mod)) ) % mod;
*/

/*@
  requires count >= 0;
*/
int foo268(int count, int w) {

		int result = 1000000007;
		int *div = (int *)malloc(sizeof(int) * (count + 1));
int div_len = count + 1;
		div[0] = 1;
		div[1] = w;
		div[2] = w * w;
		
            
        /*@
          loop invariant 3 <= d;
          loop invariant d <= count + 1 || d == 3;
          loop invariant 0 <= count;
          loop invariant 0 <= div_len && div_len == count + 1;
          loop assigns d, div[0 .. div_len - 1];
        */
            for (int d = 3; d <= count; d++) {
			div[d] = ((w - 1)
					* (div[d - 1] + div[d - 2])) % result;
		}
            
		return div[count];
}
