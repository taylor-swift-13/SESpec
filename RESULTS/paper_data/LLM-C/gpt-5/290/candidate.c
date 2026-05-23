#include <stdlib.h>

/*@ logic integer jl(integer n) = (n == 0 ? 2 : (n == 1 ? 1 : jl(n-1) + 2*jl(n-2))); */

/*@ 
  requires 1 <= c <= 31;
  ensures \result == jl(c);
*/
int jacobsthalLucas(int c);

int jacobsthalLucas(int c) {

		int *N = (int *)malloc(sizeof(int) * (c + 1));
int N_len = c + 1;
		N[0] = 2;
		N[1] = 1;
		/*@
		  loop invariant 2 <= p <= c+1;
		  loop invariant \forall integer i; 0 <= i < p ==> N[i] == jl(i);
		  loop invariant \forall integer i; 2 <= i < p ==> N[i] == N[i - 1] + 2 * N[i - 2];
		  loop assigns N[2..c], p;
		  loop variant c - p + 1;
		*/
		for (int p = 2; p <= c; p++) {
			N[p] = N[p - 1]
					+ 2 * N[p - 2];
		}
		return N[c];
}
