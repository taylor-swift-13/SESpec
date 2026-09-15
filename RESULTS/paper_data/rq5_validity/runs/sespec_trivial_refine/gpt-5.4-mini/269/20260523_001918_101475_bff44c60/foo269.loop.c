
int foo269(int dim, int w) {

		int count = 1000000007;
		int *div = (int *)malloc(sizeof(int) * (dim + 1));
        int div_len = dim + 1;
		div[0] = 1;
		div[1] = w;
		div[2] = w * w;
		
        /*@
          loop invariant d >= 3;
          loop assigns d, div[3..dim];
          loop variant dim - d + 1;
        */
        for (int d = 3; d <= dim; d++) {
			div[d] = ((w - 1)
					* (div[d - 1] + div[d - 2])) % count;
		}
            
		return div[dim];
}
