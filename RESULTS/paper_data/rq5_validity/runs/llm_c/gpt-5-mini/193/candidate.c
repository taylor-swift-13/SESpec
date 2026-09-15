#include <stdlib.h>

/*@
    requires count >= 1;
    assigns \nothing;
    logic integer arr_seq(integer k) =
        k == 0 ? 1
        : k == 1 ? 0
        : arr_seq(k-2) + 2 * c_seq(k-1);
    logic integer c_seq(integer k) =
        k == 0 ? 0
        : k == 1 ? 1
        : arr_seq(k-1) + c_seq(k-2);
    ensures \result == arr_seq(count);
*/
int countWays(int count);

int countWays(int count) {

		int *arr = (int *)malloc(sizeof(int) * (count + 1));
int arr_len = count + 1;
		int *C = (int *)malloc(sizeof(int) * (count + 1));
int C_len = count + 1;
		/*@ 
		    assume arr != \null && C != \null;
		    assume \valid(arr + (0 .. arr_len-1));
		    assume \valid(C + (0 .. C_len-1));
		*/
		arr[0] = 1;
		arr[1] = 0;
		C[0] = 0;
		C[1] = 1;
		/*@
		    loop invariant 2 <= w <= count + 1;
		    loop invariant \forall integer k; 0 <= k < w ==> arr[k] == arr_seq(k) && C[k] == c_seq(k);
		    loop assigns w, arr[0 .. arr_len-1], C[0 .. C_len-1];
		    loop variant count - w + 1;
		*/
		for (int w = 2; w <= count; w++) {
			arr[w] = arr[w - 2]
					+ 2 * C[w - 1];
			C[w] = arr[w - 1] + C[w - 2];
		}
		return arr[count];
}
