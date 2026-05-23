/*@ 
    requires i_len > 0;
    requires \valid_read(i + (0..i_len-1));
    requires 0 <= array <= i_len;
    requires \forall integer k; 0 <= k < i_len-1 ==> i[k] <= i[k+1];
    assigns \nothing;
    ensures \result == -1 || (0 <= \result < array && i[\result] == \result);
    ensures \result != -1 ==> \exists integer k; 0 <= k < array && i[k] == k;
*/
int findFixedPoint(int * i, int i_len, int array);

int findFixedPoint(int * i, int i_len, int array) {

		int ret = 0;
		int stop = array - 1;
		/*@
		    loop invariant 0 <= ret <= stop + 1;
		    loop invariant -1 <= stop < array;
		    loop invariant 0 <= array <= i_len;
		    loop invariant \forall integer k; 0 <= k < ret ==> i[k] < k;
		    loop invariant \forall integer k; stop < k < array ==> i[k] > k;
		    loop assigns ret, stop;
		    loop variant stop - ret + 1;
		*/
		while (ret <= stop) {
			int cur = ret + (stop - ret) / 2;
			if (i[cur] == cur) {
				return cur;
			} else if (i[cur] < cur) {
				ret = cur + 1;
			} else {
				stop = cur - 1;
			}
		}
		return -1;
}
