#include <stdlib.h>

/*@
    requires c >= 0;
    requires c <= INT_MAX - 1; // prevent overflow in allocation size computation
    assigns \nothing; // does not modify caller-visible memory
    ensures \result >= 1;
    ensures c == 0 ==> \result == 1;
*/
int catalanNumber(int c) {

		int *arr = (int *)malloc(sizeof(int) * (c + 1));
		int arr_len = c + 1;
		/*@ 
		    // assume allocation succeeded for the rest of the proof
		    assert arr != \null;
		    assert \valid(arr + (0 .. arr_len - 1));
		*/
		arr[0] = 1;
		/*@
		    loop invariant 1 <= cat <= c + 1;
		    loop invariant \valid(arr + (0 .. arr_len - 1));
		    loop invariant arr[0] == 1;
		    loop assigns cat, n, arr[0 .. arr_len - 1];
		    loop variant c - cat + 1;
		*/
		for (int cat = 1; cat <= c; cat++) {
			arr[cat] = 0;
			/*@
			    loop invariant 0 <= n <= cat;
			    loop invariant \valid(arr + (0 .. arr_len - 1));
			    loop invariant arr[cat] == \sum integer j; 0 <= j < n; arr[j] * arr[cat - j - 1];
			    loop assigns n, arr[0 .. arr_len - 1];
			    loop variant cat - n;
			*/
			for (int n = 0; n < cat; n++) {
				arr[cat] += arr[n]
						* arr[cat - n - 1];
			}
		}
		return arr[c];
}
