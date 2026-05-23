#include <stdlib.h>

/*@
    logic integer catalan_spec(integer m) =
        m == 0 ? 1
        : \sum( integer k; 0 <= k < m; catalan_spec(k) * catalan_spec(m - k - 1));
*/

/*@
    requires n >= 0;
    ensures \result == catalan_spec(n);
    assigns \nothing;
*/
int catalanNumber(int n) {

		int *arr = (int *)malloc(sizeof(int) * (n + 1));
int arr_len = n + 1;
		arr[0] = 1;
		/*@
		    loop invariant 1 <= c <= n+1;
		    loop invariant \valid(arr + (0..n));
		    loop invariant (\forall integer j; 0 <= j < c ==> arr[j] == catalan_spec(j));
		    loop assigns c, arr[0..n];
		    loop variant n - c + 1;
		*/
		for (int c = 1; c <= n; c++) {
			arr[c] = 0;
			/*@
			    loop invariant 0 <= k <= c;
			    loop invariant arr[c] == \sum(integer j; 0 <= j < k; arr[j] * arr[c - j - 1]);
			    loop assigns k, arr[c];
			    loop variant c - k;
			*/
			for (int k = 0; k < c; k++) {
				arr[c] += arr[k]
						* arr[c - k - 1];
			}
		}
		return arr[n];
}
