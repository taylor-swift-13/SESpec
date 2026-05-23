#include <stdlib.h>

/*@ 
  logic integer pell(integer n) = 
    n <= 0 ? 0 : (n == 1 ? 1 : 2 * pell(n - 1) + pell(n - 2));
*/

/*@
  requires seed >= 1;
  ensures 0 <= \result < 1000000000;
  ensures \result == (pell(seed) % 1000000000);
*/
int getPell(int seed);

int getPell(int seed) {

		int *arr = (int *)malloc(sizeof(int) * (seed + 1));
/*@ assert arr != \null; */
/*@ assert \valid(arr + (0 .. seed)); */
int arr_len = seed + 1;
/*@ assert arr_len == seed + 1; */
		arr[0] = 0;
		arr[1] = 1;
/*@ assert arr[0] == 0 && arr[1] == 1; */
/*@ assert 0 <= arr[0] < 1000000000; */
/*@ assert 0 <= arr[1] < 1000000000; */
		for (int p = 2; p <= seed; p++) {
			/*@
			 loop invariant \valid(arr + (0 .. seed));
			 loop invariant 2 <= p <= seed + 1;
			 loop invariant \forall integer k; 0 <= k < p ==> 0 <= arr[k] < 1000000000;
			 loop invariant \forall integer k; 0 <= k < p ==> arr[k] == (pell(k) % 1000000000);
			 loop variant seed - p + 1;
			*/
			arr[p] = (2 * arr[p - 1]
					+ arr[p - 2]) % 1000000000;
			/*@ assert 0 <= arr[p] < 1000000000; */
		}
/*@ assert arr[seed] == (pell(seed) % 1000000000); */
		return arr[seed];
}
