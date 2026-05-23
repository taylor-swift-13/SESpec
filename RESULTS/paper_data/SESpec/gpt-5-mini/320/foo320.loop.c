
/*@
  // No extra predicate/logic definition is required.
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
		  loop invariant \forall integer d; 1 <= d && d < l ==> ((n % d == 0 && y % d == 0) ==> (ret % d == 0));
		  loop invariant \forall integer d; 1 <= d && d < l ==> ((n % d == 0 && y % d == 0) ==> d <= ret);
		  loop invariant (\exists integer d; 1 <= d && d < l && n % d == 0 && y % d == 0 && d == ret) || ret == 1;
		  loop invariant (l <= \at(y,Pre)) ==> (ret > 0);
		  loop invariant (l <= \at(y,Pre)) ==> (((g == 1) && (ret == 1) && (y == \at(n,Pre)) && (n == \at(y,Pre))) || (ret > 0));
		  loop invariant (!(l <= \at(y,Pre))) ==> ((g == 1) && (ret == 1) && (y == \at(n,Pre)) && (n == \at(y,Pre)));
		  loop invariant g == 1;
		  loop invariant y == \at(n,Pre);
		  loop invariant n == \at(y,Pre);
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
