#include <stdlib.h>

/*@ 
  logic integer jacobsthal(integer n) =
    (n <= 0 ? 0 :
     (n == 1 ? 1 :
      jacobsthal(n - 1) + 2 * jacobsthal(n - 2)));
*/

/*@ 
  requires 1 <= j <= 32;
  ensures \result == jacobsthal(j);
*/
int jacobsthalNum(int j);

int jacobsthalNum(int j) {

/*@ assert 1 <= j <= 32; */
		int *ret = (int *)malloc(sizeof(int) * (j + 1));
/*@ assume ret != \null; */
/*@ assert \valid(ret + (0 .. j)); */
int ret_len = j + 1;
/*@ assert ret_len == j + 1; */
		ret[0] = 0;
/*@ assert ret[0] == jacobsthal(0); */
		ret[1] = 1;
/*@ assert ret[1] == jacobsthal(1); */
/*@ 
  loop invariant \valid(ret + (0 .. j));
  loop invariant 2 <= p <= j + 1;
  loop invariant ret[0] == jacobsthal(0);
  loop invariant j >= 1 ==> ret[1] == jacobsthal(1);
  loop invariant \forall integer k; 0 <= k < p ==> ret[k] == jacobsthal(k);
  loop assigns ret[2..j], p;
  loop variant j - p;
*/
		for (int p = 2; p <= j; p++) {
			ret[p] = ret[p - 1]
					+ 2 * ret[p - 2];
/*@ assert ret[p] == jacobsthal(p); */
		}
/*@ assert ret[j] == jacobsthal(j); */
		return ret[j];
}
