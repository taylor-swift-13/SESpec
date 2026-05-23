
int foo290(int c) {

	int *N = (int *)malloc(sizeof(int) * (c + 1));
	int N_len = c + 1;
	N[0] = 2;
	N[1] = 1;

	/*@
	  loop invariant 2 <= p;
	  loop invariant N[0] == 2;
	  loop invariant N[1] == 1;
	  loop assigns p, N[2..N_len-1];
	*/
	for (int p = 2; p <= c; p++) {
		N[p] = N[p - 1] + 2 * N[p - 2];
	}

	return N[c];
}
