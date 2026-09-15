/*@
    requires \valid(pairs+(0..pairs_len-1));
    requires 0 <= num <= pairs_len;
    ensures \result >= 0;
    ensures \result == \sum(0 <= i < num, \sum(i+1 <= j < num, (pairs[i] + pairs[j] == p ? 1 : 0)));
    assigns \nothing;
*/
int getPairsCount(int * pairs, int pairs_len, int num, int p);

int getPairsCount(int * pairs, int pairs_len, int num, int p) {

		int result = 0;
		/*@
        loop invariant 0 <= index <= num;
        loop invariant result >= 0;
        loop assigns index, result;
        */
		for (int index = 0; index < num; index++) {
			/*@
            loop invariant index + 1 <= j <= num;
            loop invariant result >= 0;
            loop assigns j, result;
            */
			for (int j = index + 1; j < num; j++) {
				if (pairs[index] + pairs[j] == p) {
					result++;
				}
			}
		}
		return result;
}
