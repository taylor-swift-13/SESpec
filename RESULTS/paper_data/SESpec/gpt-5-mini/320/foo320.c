
/*@
  requires n >= 1 && y >= 1;
  assigns \nothing; // function only modifies locals and returns result
*/
int foo320(int n, int y) {

		int ret = 1;
		int g = 1;
		if (n > y) {
			int r = n;
			n = y;
			y = r;
		}
		
		/*@
		  loop invariant 1 <= l <= n + 1;
		  loop invariant 1 <= ret <= \at(y,Pre);
		  loop invariant 0 <= n && 0 <= y;
		  loop invariant \forall integer d; 1 <= d && d <= l-1 ==> ((n % d == 0 && y % d == 0) ==> d <= ret);
		  loop invariant (\exists integer d; 1 <= d && d <= l-1 && n % d == 0 && y % d == 0 && d == ret) || ret == 1;
		  loop invariant (l <= \at(y,Pre)) ==> (ret > 0);
		  loop invariant g == 1;
		  loop assigns l, ret;
		*/
        for (int l = 1; l <= n; l++) {
			if (n % l == 0 && y % l == 0) {
				ret = l;
			}
		}
            
		g = (n * y) / ret;
		return g;
}
