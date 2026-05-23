/*@
    requires pairs != \null;
    requires pairs_len >= 0;
    requires 0 <= num <= pairs_len;
    requires \valid_read(pairs + (0 .. pairs_len-1));
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == \num_of integer i,j; 0 <= i < j < num && pairs[i] + pairs[j] == p;
*/
int getPairsCount(int * pairs, int pairs_len, int num, int p) {

		int result = 0;
		/*@
		    loop invariant 0 <= index <= num;
		    loop invariant result ==
		        (\num_of integer i,j; 0 <= i < j < num && i < index && pairs[i] + pairs[j] == p);
		    loop assigns index, result;
		    loop variant num - index;
		*/
		for (int index = 0; index < num; index++) {
			/*@
			    loop invariant index + 1 <= j <= num;
			    loop invariant result ==
			        (\num_of integer i,k; 0 <= i < k < num && i < index && pairs[i] + pairs[k] == p)
			        + (\num_of integer k; index < k < j && pairs[index] + pairs[k] == p);
			    loop assigns j, result;
			    loop variant num - j;
			*/
			for (int j = index + 1; j < num; j++) {
				if (pairs[index] + pairs[j] == p) {
					result++;
				}
			}
		}
		return result;
}
