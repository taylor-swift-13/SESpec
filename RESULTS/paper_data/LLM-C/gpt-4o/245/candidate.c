/*@ 
    requires \valid(pairs + (0..pairs_len-1));
    requires 0 <= num <= pairs_len;
    ensures \result >= 0;
    ensures \result == 
        \sum(0 <= i < num, 
            \sum(i+1 <= j < num, (pairs[i] + pairs[j] == p ? 1 : 0)));
    assigns \nothing;
*/
int getPairsCount(int * pairs, int pairs_len, int num, int p);

int getPairsCount(int * pairs, int pairs_len, int num, int p) {

		int ret = 0;
		/*@
		loop invariant 0 <= index <= num;
		loop invariant ret >= 0;
		loop assigns index, ret;
		loop invariant ret == 
		    \sum(0 <= i < index, 
		        \sum(i+1 <= j < num, (pairs[i] + pairs[j] == p ? 1 : 0)));
		*/
		for (int index = 0; index < num; index++) {
			/*@
			loop invariant index + 1 <= j <= num;
			loop invariant ret >= 0;
			loop assigns j, ret;
			loop invariant ret == 
			    \sum(0 <= i < index, 
			        \sum(i+1 <= j < num, (pairs[i] + pairs[j] == p ? 1 : 0)))
			    + \sum(index+1 <= k < j, (pairs[index] + pairs[k] == p ? 1 : 0));
			*/
			for (int j = index + 1; j < num; j++) {
				if (pairs[index] + pairs[j] == p) {
					ret++;
				}
			}
		}
		return ret;
}
