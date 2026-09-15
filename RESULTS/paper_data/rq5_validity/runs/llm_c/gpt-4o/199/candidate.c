#include <stdlib.h>

/*@
    requires number >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int catalanNumber(int number);

/*@
    requires number >= 0;
    ensures \result >= 0;
    ensures \result == \sum(0 <= n < number, catalanNumber(n) * catalanNumber(number - n - 1));
    assigns \nothing;
*/
int catalanNumber(int number) {

		int *arr = (int *)malloc(sizeof(int) * (number + 1));
		int arr_len = number + 1;
		/*@
		    loop invariant 0 <= c <= number + 1;
		    loop invariant \forall integer i; 0 <= i < c ==> arr[i] >= 0;
		    loop assigns c, arr[0..number];
		    loop variant number - c;
		*/
		arr[0] = 1;
		for (int c = 1; c <= number; c++) {
			arr[c] = 0;
			/*@
			    loop invariant 0 <= n <= c;
			    loop invariant arr[c] == \sum(0 <= i < n, arr[i] * arr[c - i - 1]);
			    loop assigns n, arr[c];
			    loop variant c - n;
			*/
			for (int n = 0; n < c; n++) {
				arr[c] += arr[n]
						* arr[c - n - 1];
			}
		}
		int result = arr[number];
		free(arr);
		return result;
}
