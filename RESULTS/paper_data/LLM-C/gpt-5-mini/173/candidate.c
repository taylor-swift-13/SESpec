int findKth(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int p);

/*@
    requires 0 <= Array <= arr1_len;
    requires 0 <= n <= arr_len;
    requires \valid(arr1 + (0 .. Array-1));
    requires \valid(arr  + (0 .. n-1));
    requires 0 <= p <= Array + n;
    assigns \nothing;
    behavior zero:
        assumes p == 0;
        ensures \result == -1;
    behavior positive:
        assumes p >= 1;
        ensures \result != -1;
        ensures (\exists integer i; 0 <= i < Array && \result == arr1[i]) ||
                (\exists integer j; 0 <= j < n     && \result == arr[j]);
    complete behaviors zero, positive;
    disjoint behaviors zero, positive;
*/
int findKth(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int p) {

		int result = 0;
		int tmp = 0;

		/*@
		    loop invariant 0 <= result <= Array;
		    loop invariant 0 <= tmp <= n;
		    loop invariant 0 <= count <= p;
		    loop invariant result + tmp == count;
		    loop assigns count, result, tmp;
		    loop variant p - count;
		*/
		for (int count = 0; count < p; count++) {
			if (result < Array
					&& (tmp >= n || arr1[result] <= arr[tmp])) {
				if (count == p - 1) {
					return arr1[result];
				}
				result++;
			} else {
				if (count == p - 1) {
					return arr[tmp];
				}
				tmp++;
			}
		}
		return -1;
}
