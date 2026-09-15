int countNo(int code, int b, int l, int c);

/*@ 
  requires code != 0;
  requires b > 0;
  requires l <= c ==> c < INT_MAX;
  assigns \nothing;
  ensures l > c ==> \result == -1;
  ensures \result == -1 
          || (l <= \result <= c 
              && \result % code != 0 
              && \sum integer i; l <= i <= \result; (i % code != 0 ? 1 : 0) == b);
  ensures \result != -1 ==> 
            (\forall integer t; l <= t < \result ==> 
                \sum integer i; l <= i <= t; (i % code != 0 ? 1 : 0) < b);
*/
int countNo(int code, int b, int l, int c) {

		int ret = 0;
		/*@
		  loop invariant l <= loop <= c + 1;
		  loop invariant ret >= 0;
		  loop invariant ret <= loop - l;
		  loop invariant \sum integer i; l <= i < loop; (i % code != 0 ? 1 : 0) == ret;
		  loop assigns ret, loop;
		  loop variant c - loop + 1;
		*/
		for (int loop = l; loop <= c; loop++) {
			if (loop % code != 0) {
				ret++;
			}
			if (ret == b) {
				//@ assert loop % code != 0;
				return loop;
			}
		}
		return -1;
}
