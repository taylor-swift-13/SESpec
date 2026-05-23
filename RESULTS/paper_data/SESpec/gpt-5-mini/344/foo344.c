
/*@ 
  logic integer count_not_divisible(integer start, integer end, integer code) =
    start > end ? 0 :
    ( (start % code != 0) ? 1 : 0 ) + count_not_divisible(start+1, end, code);
*/

/*@
  requires \true;
  assigns \nothing;
*/
int foo344(int code, int b, int l, int m) {

	int ret = 0;
	
    /*@
      loop invariant m == \at(m,Pre);
      loop invariant l == \at(l,Pre);
      loop invariant b == \at(b,Pre);
      loop invariant code == \at(code,Pre);
      loop assigns c, ret;
      loop variant m - c + 1;
    */
    for (int c = l; c <= m; c++) {
		if (c % code != 0) {
			ret++;
		}
		if (ret == b) {
			return c;
		}
	}
		
	return -1;
}
