/*@
    requires pairs_len >= 0;
    requires num >= 0;
    requires \valid_read(pairs + (0 .. pairs_len - 1));
    requires num <= pairs_len;
    assigns \nothing;
    ensures \result >= 0;
*/
int getPairsCount(int * pairs, int pairs_len, int num, int p);

 /*@
    requires pairs_len >= 0;
    requires num >= 0;
    requires \valid_read(pairs + (0 .. pairs_len - 1));
    requires num <= pairs_len;
    assigns \nothing;
    ensures \result >= 0;
*/
int getPairsCount(int * pairs, int pairs_len, int num, int p) {

		int ret = 0;
		/*@
		    loop invariant 0 <= index <= num;
		    loop invariant ret >= 0;
		    loop assigns index, ret, j;
		    loop variant num - index;
		*/
		for (int index = 0; index < num; index++) {
			/*@
			    loop invariant index + 1 <= j <= num;
			    loop invariant ret >= 0;
			    loop assigns j, ret;
			    loop variant num - j;
			*/
			for (int j = index + 1; j < num; j++) {
				if (pairs[index] + pairs[j] == p) {
					ret++;
				}
			}
		}
		return ret;
}
