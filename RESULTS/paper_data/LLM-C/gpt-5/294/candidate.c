#include <stdlib.h>

/*@ 
  logic integer MOD = 1000000000;

  logic integer pell_mod(integer n) =
    n <= 0 ? 0 :
    n == 1 ? 1 :
    (2 * pell_mod(n - 1) + pell_mod(n - 2)) % MOD;
*/

/*@ 
  requires p >= 1;
  requires \forall integer i; 2 <= i <= p ==> 2 * pell_mod(i-1) + pell_mod(i-2) <= 2147483647;
  assigns \nothing;
  ensures 0 <= \result < MOD;
  ensures \result == pell_mod(p);
*/
int getPell(int p);

int getPell(int p) {

		int *arr = (int *)malloc(sizeof(int) * (p + 1));
int arr_len = p + 1;
		/*@ assert arr_len == p + 1; */
		arr[0] = 0;
		arr[1] = 1;
		/*@
		  loop invariant 2 <= count <= p + 1;
		  loop invariant \forall integer i; 0 <= i < \min(count, p+1) ==> 0 <= arr[i] < MOD;
		  loop invariant \valid(arr + (0..p));
		  loop invariant arr[0] == 0 && arr[1] == 1;
		  loop invariant \forall integer i; 2 <= i < count ==> arr[i] == (2 * arr[i-1] + arr[i-2]) % MOD;
		  loop assigns count, arr[0..p];
		  loop variant p - count;
		*/
		for (int count = 2; count <= p; count++) {
			arr[count] = (2 * arr[count - 1]
					+ arr[count - 2]) % 1000000000;
		}
		return arr[p];
}
