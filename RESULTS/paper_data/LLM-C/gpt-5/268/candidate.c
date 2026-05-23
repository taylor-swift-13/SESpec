#include <stdlib.h>

/*@ 
  logic integer ways(integer n, integer w, integer M) =
    n == 0 ? 1 :
    n == 1 ? w :
    n == 2 ? w*w :
    ((w - 1) * (ways(n - 1, w, M) + ways(n - 2, w, M))) % M;
*/

/*@ 
  requires count >= 2;
  requires 1 <= w <= 2;
  assigns \nothing;
  ensures \result == ways(count, w, 1000000007);
  ensures 0 <= \result < 1000000007;
*/
int countNoOfWays(int count, int w);

int countNoOfWays(int count, int w) {

		int result = 1000000007;
		int *div = (int *)malloc(sizeof(int) * (count + 1));
/*@ assert div != \null; */
/*@ assert \valid(div + (0 .. count)); */
int div_len = count + 1;
		div[0] = 1;
		div[1] = w;
		div[2] = w * w;
		/*@ 
		  loop invariant 3 <= d ==> \valid(div + (0 .. count));
		  loop invariant 3 <= d <= count + 1;
		  loop invariant div[0] == 1;
		  loop invariant div[1] == w;
		  loop invariant div[2] == w * w;
		  loop invariant \forall integer k; 3 <= k < d ==> 
		        div[k] == ((w - 1) * (div[k - 1] + div[k - 2])) % 1000000007;
		  loop invariant \forall integer k; 3 <= k < d ==> 
		        0 <= div[k] < 1000000007;
		  loop invariant \forall integer k; 0 <= k < d ==> 
		        div[k] == ways(k, w, 1000000007);
		  loop assigns div[3 .. count], d;
		  loop variant count - d;
		*/
		for (int d = 3; d <= count; d++) {
			div[d] = ((w - 1)
					* (div[d - 1] + div[d - 2])) % result;
		}
		/*@ assert div[count] == ways(count, w, 1000000007); */
		return div[count];
}
