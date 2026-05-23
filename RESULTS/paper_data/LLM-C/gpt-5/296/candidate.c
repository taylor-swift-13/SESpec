#include <stdlib.h>

/*@ 
  logic integer lucas(integer n) =
    (n == 0) ? 2 :
    (n == 1) ? 1 :
    (lucas(n - 1) + lucas(n - 2));
*/

/*@ 
  requires seed >= 1;
  assigns \nothing;
  ensures \result == lucas(seed);
  terminates;
*/
int findLucas(int seed);

int findLucas(int seed) {

		int *result = (int *)malloc(sizeof(int) * (seed + 1));
/*@ assert \valid(result + (0 .. seed)); */
int result_len = seed + 1;
/*@ assert result_len == seed + 1; */
		result[0] = 2;
		result[1] = 1;
		/*@ 
		  loop invariant 2 <= c <= seed + 1;
		  loop invariant \valid(result + (0 .. seed));
		  loop invariant \forall integer i; 0 <= i < c ==> result[i] == lucas(i);
		  loop assigns c, result[0 .. seed];
		  loop variant seed - c;
		*/
		for (int c = 2; c <= seed; c++) {
			result[c] = result[c - 1]
					+ result[c - 2];
		}
		/*@ assert result[seed] == lucas(seed); */
		return result[seed];
}
