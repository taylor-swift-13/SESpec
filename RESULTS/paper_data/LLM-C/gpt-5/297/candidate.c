#include <stdlib.h>

/*@ axiomatic Lucas {
  logic integer lucas(integer n);
  axiom lucas0: lucas(0) == 2;
  axiom lucas1: lucas(1) == 1;
  axiom lucas_rec:
    \forall integer n; n >= 2 ==> lucas(n) == lucas(n - 1) + lucas(n - 2);
} */

/*@ requires seed >= 1;
    ensures \result == lucas(seed);
*/
int findLucas(int seed);

int findLucas(int seed) {

		int *result = (int *)malloc(sizeof(int) * (seed + 1));
/*@ assert seed >= 1; */
int result_len = seed + 1;
/*@ assert result_len == seed + 1; */
/*@ assert result != \null; */
/*@ assert \valid(result + (0 .. seed)); */
		result[0] = 2;
/*@ assert result[0] == lucas(0); */
		result[1] = 1;
/*@ assert result[1] == lucas(1); */
		/*@ 
		  loop invariant 2 <= l <= seed + 1;
		  loop invariant \valid(result + (0 .. seed));
		  loop invariant \forall integer i; 0 <= i < l ==> result[i] == lucas(i);
		  loop assigns result[2 .. seed];
		  loop variant seed - l + 1;
		*/
		for (int l = 2; l <= seed; l++) {
			result[l] = result[l - 1]
					+ result[l - 2];
			/*@ assert result[l] == result[l-1] + result[l-2]; */
			/*@ assert result[l] == lucas(l); */
		}
		/*@ assert result[seed] == lucas(seed); */
		return result[seed];
}
