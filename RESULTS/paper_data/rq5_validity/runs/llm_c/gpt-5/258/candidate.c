int findFixedPoint(int * i, int i_len, int array);

/*@ 
  requires array >= 0;
  requires array == 0 || \valid_read(i + (0 .. array-1));
  requires i_len >= array;
  requires \forall integer k; 0 <= k < array - 1 ==> i[k+1] >= i[k] + 1;

  assigns \nothing;

  ensures \result == -1 ==> \forall integer k; 0 <= k < array ==> i[k] != k;
  ensures \result >= 0 ==> \result < array && i[\result] == \result;
  ensures (\exists integer k; 0 <= k < array && i[k] == k) ==> \result >= 0;
*/
int findFixedPoint(int * i, int i_len, int array) {

		int ret = 0;
		int stop = array - 1;
		/*@ 
		  loop invariant 0 <= ret <= array;
		  loop invariant -1 <= stop < array;
		  loop invariant ret <= stop + 1;
		  loop invariant \forall integer k; 0 <= k < ret ==> i[k] < k;
		  loop invariant \forall integer k; stop + 1 <= k < array ==> i[k] > k;
		  loop assigns ret, stop;
		  loop variant stop - ret + 1;
		*/
		while (ret <= stop) {
			int cur = ret + (stop - ret) / 2;
			/*@ assert 0 <= cur < array; */
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
