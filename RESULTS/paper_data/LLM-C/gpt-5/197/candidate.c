#include <stdlib.h>

int catalanNumber(int n);

/*@ 
  logic integer catalan_logic(integer n) =
    n <= 0 ? 1 : (\sum integer k; 0 <= k < n; catalan_logic(k) * catalan_logic(n - 1 - k));
*/

/*@ 
  requires n >= 0;
  assigns \nothing;
  ensures \result == (int)catalan_logic(n);
*/
int catalanNumber(int n) {

		int *arr = (int *)malloc(sizeof(int) * (n + 1));
/*@ assert arr != \null; */
/*@ assert \valid(arr + (0..n)); */
int arr_len = n + 1;
/*@ assert arr_len == n + 1; */
		arr[0] = 1;
		/*@ 
		  loop invariant 1 <= c <= n + 1;
		  loop invariant \valid(arr + (0..n));
		  loop invariant arr_len == n + 1;
		  loop invariant arr[0] == 1;
		  loop invariant \forall integer j; 0 <= j < c ==> arr[j] == (int)catalan_logic(j);
		  loop assigns arr[0..n], c;
		  loop variant n - c + 1;
		*/
		for (int c = 1; c <= n; c++) {
			arr[c] = 0;
			/*@
			  loop invariant 0 <= k <= c;
			  loop invariant \valid(arr + (0..n));
			  loop invariant arr_len == n + 1;
			  loop invariant \forall integer j; 0 <= j < c ==> arr[j] == (int)catalan_logic(j);
			  loop invariant \integer(arr[c]) == (\sum integer i; 0 <= i < k; \integer(arr[i]) * \integer(arr[c - 1 - i]));
			  loop assigns arr[c], k;
			  loop variant c - k;
			*/
			for (int k = 0; k < c; k++) {
				arr[c] += arr[k]
						* arr[c - k - 1];
			}
		}
		/*@ assert \valid(arr + (0..n)); */
		/*@ assert \result == (int)catalan_logic(n); */
		return arr[n];
}
