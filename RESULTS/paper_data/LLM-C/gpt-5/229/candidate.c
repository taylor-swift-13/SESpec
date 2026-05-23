#include <stdlib.h>

/*@
  requires seed >= 0;
  ensures seed == 0 ==> \result == 1;
  terminates \true;
*/
int evenBinomialCoeffSum(int seed);

int evenBinomialCoeffSum(int seed) {

		int result = 0;
		int *arr = (int *)malloc(sizeof(int) * (seed + 1));
/*@ assert arr != \null; */
int arr_len = seed + 1;
/*@ assert arr_len == seed + 1; */
/*@ assert arr_len >= 1; */
/*@ assert \valid(arr + (0 .. arr_len-1)); */
		arr[0] = 1;
		/*@
		  loop invariant 1 <= d <= seed + 1;
		  loop invariant arr_len == seed + 1;
		  loop invariant \valid(arr + (0 .. arr_len-1));
		  loop assigns d, arr[0 .. seed];
		  loop variant seed - d + 1;
		*/
		for (int d = 1; d <= seed; d++) {
			/*@ assert 0 <= d < arr_len; */
			/*@ assert \valid(&arr[d]); */
			/*@
			  loop invariant 0 <= c <= d;
			  loop invariant arr_len == seed + 1;
			  loop invariant \valid(arr + (0 .. arr_len-1));
			  loop assigns c, arr[d];
			  loop variant d - c;
			*/
			for (int c = 0; c < d; c++) {
				/*@ assert 0 <= c < arr_len; */
				/*@ assert \valid(&arr[c]); */
				/*@ assert \valid(&arr[d]); */
				arr[d] = arr[d] + arr[c];
			}
		}
		return arr[seed];
}
