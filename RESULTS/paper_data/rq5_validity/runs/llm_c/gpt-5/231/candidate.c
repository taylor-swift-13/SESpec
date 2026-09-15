int countPairs(int * p, int p_len, int array);

/*@ 
  requires p_len >= 0;
  requires p_len == 0 || \valid_read(p + (0 .. p_len-1));
  assigns \nothing;
  ensures 0 <= \result <= (p_len <= 1 ? 0 : (p_len * (p_len - 1)) / 2);
  ensures p_len <= 1 ==> \result == 0;
  ensures \result == \sum(0, p_len-1, \lambda integer i; 
                          \sum(i+1, p_len-1, \lambda integer j; (p[i] != p[j]) ? 1 : 0));
*/
int countPairs(int * p, int p_len, int array) {

		int count = 0;
		int total = p_len;
		/*@ 
		  loop invariant 0 <= index <= total;
		  loop invariant count ==
		    \sum(0, index-1, \lambda integer i;
		                \sum(i+1, total-1, \lambda integer j; (p[i] != p[j]) ? 1 : 0));
		  loop assigns index, c, count;
		  loop variant (total - 1) - index;
		*/
		for (int index = 0; index < total - 1; index++) {
			/*@
			  loop invariant index + 1 <= c <= total;
			  loop invariant count ==
			    \sum(0, index-1, \lambda integer i;
			                \sum(i+1, total-1, \lambda integer j; (p[i] != p[j]) ? 1 : 0))
			    + \sum(index+1, c-1, \lambda integer k; (p[index] != p[k]) ? 1 : 0);
			  loop assigns c, count;
			  loop variant total - c;
			*/
			for (int c = index + 1; c < total; c++) {
				if (p[index] != p[c]) {
					count++;
				}
			}
		}
		return count;
}
