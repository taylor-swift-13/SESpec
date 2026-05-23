#include <stdlib.h>

/*@
    requires number >= 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int catalanNumber(int number);

 /*@
    requires number >= 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int catalanNumber(int number) {

		int *arr = (int *)malloc(sizeof(int) * (number + 1));
int arr_len = number + 1;
		arr[0] = 1;
		/*@
		    loop invariant 1 <= c <= number + 1;
		    loop invariant arr[0] == 1;
		    loop invariant \forall integer k; 1 <= k < c ==> arr[k] >= 0;
		    loop assigns c, arr[0..number];
		    loop variant number - c + 1;
		*/
		for (int c = 1; c <= number; c++) {
			arr[c] = 0;
			/*@
			    loop invariant 0 <= n <= c;
			    loop invariant arr[c] >= 0;
			    loop invariant \forall integer k; 0 <= k < c ==> arr[k] >= 0;
			    loop assigns n, arr[c];
			    loop variant c - n;
			*/
			for (int n = 0; n < c; n++) {
				arr[c] += arr[n]
						* arr[c - n - 1];
			}
		}
		return arr[number];
}
