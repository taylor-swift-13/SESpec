#include <stdlib.h>

/*@
  logic integer fib_rec(integer k) =
    k < 0 ? -1 :
    k == 0 ? 0 :
    k == 1 ? 1 :
    fib_rec(k-1) + fib_rec(k-2);

  requires \true;
  behavior negative:
    assumes n < 0;
    assigns \nothing;
    ensures \result == -1;
  behavior zero:
    assumes n == 0;
    assigns \nothing;
    ensures \result == 0;
  behavior positive:
    assumes n >= 1;
    assigns \nothing;
    ensures \result == fib_rec(n);
  complete behaviors negative, zero, positive;
  disjoint behaviors negative, zero, positive;
*/
int fibCompute(int n);

int fibCompute(int n) {

		if(n < 0) return -1;
		else if(n == 0) return 0;

		int *fib = (int *)malloc(sizeof(int) * (n + 1));
		int fib_len = n + 1;
		/*@ assert fib != \null; */
		/*@ assert \valid(fib + (0 .. fib_len-1)); */

		fib[0] = 0;
		fib[1] = 1;
		int index = 2;

		/*@
		  loop invariant 2 <= index <= fib_len;
		  loop invariant \forall integer j; 0 <= j < index ==> fib[j] == fib_rec(j);
		  loop assigns index, fib[0 .. index-1];
		  loop variant fib_len - index;
		*/
		while (index < fib_len) {
			fib[index] = fib[index - 2] + fib[index - 1];
			index++;
		}

		return fib[n];
}
