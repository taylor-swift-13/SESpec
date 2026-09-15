
/*@
  logic integer seqN(integer k) =
    k == 0 ? 2 :
    (k == 1 ? 1 : seqN(k - 1) + 2 * seqN(k - 2));
*/

int foo290(int c) {

		int *N = (int *)malloc(sizeof(int) * (c + 1));
int N_len = c + 1;
		N[0] = 2;
		N[1] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant N_len == c + 1;
          loop invariant p >= 2;
          loop invariant \forall integer k; (0 <= k && k < p) ==> N[k] == seqN(k);
          loop invariant \forall integer k; (2 <= k && k < p) ==> N[k] == N[k - 1] + 2 * N[k - 2];
          loop invariant (p <= c) ==> (0 <= p && p < N_len && 0 <= p - 1 && p - 1 < N_len && 0 <= p - 2 && p - 2 < N_len);
          loop assigns p, N[0..N_len-1];
            */
            for (int p = 2; p <= c; p++) {
			N[p] = N[p - 1]
					+ 2 * N[p - 2];
		}
            
		return N[c];
}
