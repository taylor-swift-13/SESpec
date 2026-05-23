
/*@
  logic integer seq(integer k) =
    k == 0 ? 2
    : k == 1 ? 1
    : seq(k-1) + 2*seq(k-2);
*/

/*@
  requires c >= 1;
  assigns \nothing;
*/
int foo290(int c) {

		int *N = (int *)malloc(sizeof(int) * (c + 1));
int N_len = c + 1;
		N[0] = 2;
		N[1] = 1;
		
            
        /*@
          loop invariant 2 <= p <= c + 1;
          loop invariant p >= 2 ==> N[p-1] == seq(p-1);
          loop invariant p >= 2 ==> N[p-2] == seq(p-2);
          loop invariant 0 <= p-1 < N_len;
          loop assigns p, N[0..c];
        */
            for (int p = 2; p <= c; p++) {
			N[p] = N[p - 1]
					+ 2 * N[p - 2];
		}
            
		return N[c];
}
