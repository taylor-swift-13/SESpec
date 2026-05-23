#include <stdlib.h>

/*@ axiomatic Pow2 {
  logic integer pow2(integer n);
  axiom pow2_base: pow2(0) == 1;
  axiom pow2_step: \forall integer n; n >= 0 ==> pow2(n+1) == 2 * pow2(n);
} */

int evenBinomialCoeffSum(int b);

/*@ 
  requires 0 <= b <= 31;
  assigns \nothing;
  ensures (b == 0) ==> (\result == 1);
  ensures (b >= 1) ==> (\result == pow2(b-1));
*/
int evenBinomialCoeffSum(int b) {

		int result = 0;
		int *arr = (int *)malloc(sizeof(int) * (b + 1));
/*@ assert arr != \null; */
/*@ assert \valid(arr + (0..b)); */
int arr_len = b + 1;
/*@ assert arr_len == b + 1; */
		arr[0] = 1;
		for (int d = 1; d <= b; d++) {
			/*@ 
			  loop invariant 1 <= d <= b + 1;
			  loop invariant \valid(arr + (0..b));
			  loop assigns arr[0..b];
			  loop variant b - d + 1;
			*/
			for (int c = 0; c < d; c++) {
				/*@
				  loop invariant 0 <= c <= d;
				  loop assigns arr[d];
				  loop variant d - c;
				*/
				arr[d] = arr[d] + arr[c];
			}
		}
		return arr[b];
}
