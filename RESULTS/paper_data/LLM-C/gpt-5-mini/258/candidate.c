int findFixedPoint(int * i, int i_len, int array);

 /*@
    requires array >= 0;
    requires \valid(i + (0 .. array-1));
    /* The array is strictly increasing (distinct, sorted) */
    requires \forall integer a, b; 0 <= a < b < array ==> i[a] < i[b];
    assigns \nothing;
    ensures \result == -1
            <==> (\forall integer k; 0 <= k < array ==> i[k] != k);
    ensures \result >= 0 ==> (0 <= \result < array && i[\result] == \result);
 */
int findFixedPoint(int * i, int i_len, int array) {

		int ret = 0;
		int stop = array - 1;
		/*@
		    loop invariant 0 <= ret <= array;
		    loop invariant -1 <= stop < array;
		    loop invariant \forall integer j; 0 <= j < ret ==> i[j] < j;
		    loop invariant \forall integer j; stop < j < array ==> i[j] > j;
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
