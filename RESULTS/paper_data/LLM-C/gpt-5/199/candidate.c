#include <stdlib.h>

/*@ 
  logic integer cat(integer n) = 
    n == 0 ? 1 : \sum_{integer k; 0 <= k < n} cat(k) * cat(n-1-k);
*/

/*@ 
  requires number >= 0;
  ensures \result == cat(number);
*/
int catalanNumber(int number);

int catalanNumber(int number) {

		int *arr = (int *)malloc(sizeof(int) * (number + 1));
/*@ assume arr != \null; */
/*@ assume \valid(arr + (0..number)); */
int arr_len = number + 1;
		arr[0] = 1;
		/*@ 
		  loop invariant 1 <= c <= number + 1;
		  loop invariant \valid(arr + (0..number));
		  loop invariant \forall integer i; 0 <= i < c ==> arr[i] == cat(i);
		  loop assigns c, arr[1..number];
		  loop variant number - c;
		*/
		for (int c = 1; c <= number; c++) {
			arr[c] = 0;
			/*@ 
			  loop invariant 0 <= n <= c;
			  loop invariant \valid(arr + (0..number));
			  loop invariant \forall integer i; 0 <= i < c ==> arr[i] == cat(i);
			  loop invariant arr[c] == \sum_{integer k; 0 <= k < n} arr[k] * arr[c - 1 - k];
			  loop assigns n, arr[c];
			  loop variant c - n;
			*/
			for (int n = 0; n < c; n++) {
				arr[c] += arr[n]
						* arr[c - n - 1];
			}
			/*@ assert arr[c] == cat(c); */
		}
		/*@ assert arr[number] == cat(number); */
		return arr[number];
}
