#include <stdlib.h>

/*@ 
axiomatic Pell {
  logic integer pell(integer n);
  axiom pell_base0: pell(0) == 0;
  axiom pell_base1: pell(1) == 1;
  axiom pell_rec: \forall integer n; n >= 2 ==> pell(n) == 2 * pell(n-1) + pell(n-2);
}
*/

/*@ 
  requires seed >= 1;
  ensures \result == pell(seed) % 1000000000;
  ensures 0 <= \result < 1000000000;
  assigns \nothing;
*/
int getPell(int seed);

int getPell(int seed) {

		int *p = (int *)malloc(sizeof(int) * (seed + 1));
/*@ assert p != \null; */
/*@ assert \valid(p + (0 .. seed)); */
int p_len = seed + 1;
/*@ assert p_len == seed + 1; */
		p[0] = 0;
		p[1] = 1;
/*@ assert p[0] == pell(0) % 1000000000; */
/*@ assert p[1] == pell(1) % 1000000000; */
		for (int count = 2; count <= seed; count++) {
			/*@ 
        loop invariant 2 <= count <= seed + 1;
        loop invariant \valid(p + (0 .. seed));
        loop invariant p[0] == pell(0) % 1000000000;
        loop invariant p[1] == pell(1) % 1000000000;
        loop invariant \forall integer k; 0 <= k < count ==> p[k] == pell(k) % 1000000000;
        loop invariant \forall integer k; 0 <= k < count ==> 0 <= p[k] < 1000000000;
        loop assigns p[2 .. seed], count;
        loop variant seed - count + 1;
      */
			p[count] = (2 * p[count - 1]
					+ p[count - 2]) % 1000000000;
			/*@ assert 0 <= p[count] < 1000000000; */
			/*@ assert p[count] == (2 * pell(count - 1) + pell(count - 2)) % 1000000000; */
		}
		/*@ assert p[seed] == pell(seed) % 1000000000; */
		return p[seed];
}
