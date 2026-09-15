#include <stdlib.h>

/*@ 
  logic integer fib_val(integer k) =
    k <= 0 ? 0 : (k == 1 ? 1 : fib_val(k - 1) + fib_val(k - 2));
*/

/*@ 
  requires n <= 0 || fib_val(n) <= 2147483647;
  ensures n < 0 ==> \result == -1;
  ensures n >= 0 ==> \result == fib_val(n);
*/
int fibCompute(int n);

int fibCompute(int n) {

		if(n < 0) return -1;
		else if(n == 0) return 0;

		int *fib = (int *)malloc(sizeof(int) * (n + 1));
/*@ assert n >= 1; */
/*@ assert fib_len == n + 1; */
/*@ assert \true; */
int fib_len = n + 1;
/*@ assert fib_len >= 2; */
		fib[0] = 0;
		fib[1] = 1;
		int index = 2;

/*@ 
  loop invariant fib_len == n + 1;
  loop invariant fib_len >= 2;
  loop invariant 2 <= index <= fib_len;
  loop invariant \valid(fib + (0 .. fib_len - 1));
  loop invariant fib[0] == 0;
  loop invariant fib[1] == 1;
  loop invariant \forall integer k; 2 <= k < index ==> fib[k] == fib[k - 1] + fib[k - 2];
  loop assigns index, fib[2 .. fib_len - 1];
  loop variant fib_len - index;
*/
		while (index < fib_len) {
			fib[index] = fib[index - 2] + fib[index - 1];
			index++;
		}
/*@ assert index == fib_len; */
/*@ assert \valid(fib + (0 .. fib_len - 1)); */
/*@ assert \forall integer k; 0 <= k < fib_len ==> (k == 0 ? fib[k] == 0 : (k == 1 ? fib[k] == 1 : fib[k] == fib[k-1] + fib[k-2])); */
/*@ assert fib[n] == fib_val(n); */

		return fib[n];
}
