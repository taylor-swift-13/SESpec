/*@
    requires array >= 0;
    requires \valid(args + (0 .. array-1)) || array == 0;
    requires \forall integer i, j; 0 <= i < j < array ==> (args[i] - i) <= (args[j] - j);
    assigns \nothing;
    ensures -1 <= \result < array;
    behavior found:
        assumes \result >= 0;
        ensures 0 <= \result < array;
        ensures args[\result] == \result;
    behavior not_found:
        assumes \result == -1;
        ensures \forall integer k; 0 <= k < array ==> args[k] != k;
    complete behaviors found, not_found;
    disjoint behaviors found, not_found;
*/
int findFixedPoint(int * args, int args_len, int array);

int findFixedPoint(int * args, int args_len, int array) {

		int i = 0;
		int stop = array - 1;
		/*@
		    loop invariant 0 <= i <= array;
		    loop invariant -1 <= stop <= array-1;
		    loop invariant i <= stop + 1;
		    loop invariant \forall integer j; 0 <= j < i ==> args[j] - j < 0;
		    loop invariant \forall integer j; stop < j < array ==> args[j] - j > 0;
		    loop assigns i, stop;
		    loop variant stop - i + 1;
		*/
		while (i <= stop) {
			int cur = i + (stop - i) / 2;
			if (args[cur] == cur) {
				return cur;
			} else if (args[cur] < cur) {
				i = cur + 1;
			} else {
				stop = cur - 1;
			}
		}
		return -1;
}
