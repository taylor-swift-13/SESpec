
#include <stdlib.h>

/*@
  requires b >= 0;
*/
int foo227(int b) {
		int result = 0;
		int *arr = (int *)malloc(sizeof(int) * (b + 1));
		int arr_len = b + 1;
		arr[0] = 1;

		/*@
		  loop invariant 0 <= d;
		  loop invariant arr[0] == 1;
		*/
		for (int d = 1; d <= b; d++) {

			/*@
			  loop invariant 0 <= c <= d;
			  loop invariant arr[0] == 1;
			  loop assigns c, arr[d];
			*/
			for (int c = 0; c < d; c++) {
				arr[d] = arr[d] + arr[c];
			}

		}

		return arr[b];
}
