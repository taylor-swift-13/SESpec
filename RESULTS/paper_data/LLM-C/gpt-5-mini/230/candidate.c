int countPairs(int * pairs, int pairs_len, int array);

/*@
    requires pairs_len >= 0;
    requires pairs_len == 0 || \valid(pairs + (0 .. pairs_len-1));
    assigns \nothing;
    ensures 0 <= \result <= pairs_len*(pairs_len-1)/2;
    ensures \result == 
        (\sum integer i; 0 <= i <= pairs_len-2;
            (\sum integer j; i+1 <= j <= pairs_len-1; (pairs[i] != pairs[j] ? 1 : 0)));
*/
int countPairs(int * pairs, int pairs_len, int array) {

		int count = 0;
		int total = pairs_len;
		/*@ 
		    loop invariant 0 <= index <= total;
		    loop invariant 0 <= count <= total*(total-1)/2;
		    loop invariant count == 
		        (\sum integer ii; 0 <= ii <= index-1;
		            (\sum integer jj; ii+1 <= jj <= total-1; (pairs[ii] != pairs[jj] ? 1 : 0)));
		    loop assigns index, count;
		    loop variant total - index;
		*/
		for (int index = 0; index < total - 1; index++) {
			/*@
			    loop invariant index+1 <= k <= total;
			    loop invariant 0 <= count <= total*(total-1)/2;
			    loop invariant count ==
			        (\sum integer ii; 0 <= ii <= index-1;
			            (\sum integer jj; ii+1 <= jj <= total-1; (pairs[ii] != pairs[jj] ? 1 : 0)))
			        + (\sum integer jj; index+1 <= jj <= k-1; (pairs[index] != pairs[jj] ? 1 : 0));
			    loop assigns k, count;
			    loop variant total - k;
			*/
			for (int k = index + 1; k < total; k++) {
				if (pairs[index] != pairs[k]) {
					count++;
				}
			}
		}
		return count;
}
