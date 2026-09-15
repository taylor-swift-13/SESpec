#include <stdlib.h>

/*@
    logic integer pell(integer n) =
        n == 0 ? 0 :
        n == 1 ? 1 :
        (2 * pell(n-1) + pell(n-2)) % 1000000000;
*/

/*@
    requires seed >= 1;
    assigns \nothing;
    ensures \result == pell(seed);
*/
int getPell(int seed) {

		int *arr = (int *)malloc(sizeof(int) * (seed + 1));
    int arr_len = seed + 1;
    /*@ assert arr_len == seed + 1; */
    /*@ assert seed >= 1; */
    /*@ assert \valid(arr + (0 .. arr_len-1)); */
		arr[0] = 0;
		arr[1] = 1;
		/*@ 
		    loop invariant 2 <= p <= arr_len;
		    loop invariant \forall integer k; 0 <= k < p ==> arr[k] == pell(k);
		    loop assigns p, arr+(2 .. arr_len-1);
		    loop variant arr_len - p;
		*/
		for (int p = 2; p <= seed; p++) {
			arr[p] = (2 * arr[p - 1]
					+ arr[p - 2]) % 1000000000;
		}
		return arr[seed];
}
