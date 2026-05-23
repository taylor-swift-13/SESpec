#include <stdlib.h>

/*@
    requires n >= 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int catalanNumber(int n);

int catalanNumber(int n) {

		int *arr = (int *)malloc(sizeof(int) * (n + 1));
int arr_len = n + 1;
		arr[0] = 1;
		/*@
		    loop invariant 1 <= c <= n + 1;
		    loop invariant \valid(arr + (0 .. arr_len - 1));
		    loop invariant arr[0] == 1;
		    loop invariant \forall integer i; 1 <= i < c ==> arr[i] >= 0;
		    loop assigns c, arr[0 .. arr_len - 1];
		    loop variant n - c + 1;
		*/
		for (int c = 1; c <= n; c++) {
			arr[c] = 0;
			/*@
			    loop invariant 0 <= k <= c;
			    loop invariant \valid(arr + (0 .. arr_len - 1));
			    loop invariant arr[0] == 1;
			    loop invariant arr[c] >= 0;
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
