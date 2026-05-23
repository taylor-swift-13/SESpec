#include <stdlib.h>

int catalanNumber(int number);

/*@
    logic integer Cat(integer n) =
        (n == 0 ? 1 : \sum integer i; 0 <= i < n; Cat(i) * Cat(n - 1 - i));

    requires number >= 0;
    requires \mallocable(sizeof(int) * (number + 1));
    assigns \nothing;
    ensures \result == Cat(number);
*/
int catalanNumber(int number) {

		int *arr = (int *)malloc(sizeof(int) * (number + 1));
int arr_len = number + 1;
		arr[0] = 1;
		/*@
		  loop invariant 1 <= c && c <= number + 1;
		  loop invariant \forall integer k; 0 <= k < c ==> arr[k] == Cat(k);
		  loop assigns c, arr[1..number];
		  loop variant number - c + 1;
		*/
		for (int c = 1; c <= number; c++) {
			arr[c] = 0;
			/*@
			  loop invariant 0 <= n && n <= c;
			  loop invariant arr[c] == \sum integer j; 0 <= j < n; arr[j] * arr[c - j - 1];
			  loop invariant \forall integer k; 0 <= k < c ==> arr[k] == Cat(k);
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
