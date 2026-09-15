
int foo321(int n, int y) {

	int ret = 1;
	int r = 1;
	if (n > y) {
		int g = n;
		n = y;
		y = g;
	}
	
	/*@
	  loop invariant 1 <= l; 
	  loop invariant ret >= 1;
	  loop invariant n % ret == 0 && y % ret == 0;
	  loop invariant \forall integer k; 1 <= k < l ==> ((n % k == 0 && y % k == 0) ==> k <= ret);
	  loop assigns l, ret;
	*/
	for (int l = 1; l <= n; l++) {
		if (n % l == 0 && y % l == 0) {
			ret = l;
		}
	}
		
	r = (n * y) / ret;
	return r;
}
