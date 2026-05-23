
/*@ 
  logic integer count_nd(integer a, integer b, integer code) =
    a > b ? 0 : ((a % code) != 0 ? 1 : 0) + count_nd(a + 1, b, code);
*/

/*@
  requires m == \at(m,Pre);
  requires l == \at(l,Pre);
  requires b == \at(b,Pre);
  requires code == \at(code,Pre);
  requires l <= m;
  requires b >= 0;
*/
int foo342(int code, int b, int l, int m) {

	int result = 0;
	
    /*@
      loop invariant l <= c <= m + 1;
      loop invariant (c <= m && b > 0) ==> result < b;
      loop invariant m == \at(m,Pre);
      loop invariant l == \at(l,Pre);
      loop invariant b == \at(b,Pre);
      loop invariant code == \at(code,Pre);
      loop assigns c, result;
    */
    for (int c = l; c <= m; c++) {
		if (c % code != 0) {
			result++;
		}
		if (result == b) {
			return c;
		}
	}
		
	return -1;
}
