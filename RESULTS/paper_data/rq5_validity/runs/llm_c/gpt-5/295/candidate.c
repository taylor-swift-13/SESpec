#include <stdlib.h>

/*@ 
  logic integer lucas(integer n);

  axiom lucas_base0: lucas(0) == 2;
  axiom lucas_base1: lucas(1) == 1;
  axiom lucas_rec: \forall integer n; n >= 2 ==> lucas(n) == lucas(n-1) + lucas(n-2);
*/

/*@ 
  requires 1 <= num <= 44;
  ensures \result == lucas(num);
*/
int findLucas(int num);

int findLucas(int num) {

/*@ assert num >= 1; */
		int *result = (int *)malloc(sizeof(int) * (num + 1));
/*@ 
  assert result != \null;
  assert \fresh(result, (num + 1) * sizeof(int));
  assert \valid(result + (0 .. num));
*/
int result_len = num + 1;
/*@ assert result_len == num + 1; */
		result[0] = 2;
		result[1] = 1;
/*@ 
  assert result[0] == lucas(0);
  assert result[1] == lucas(1);
*/
/*@ 
  loop invariant 2 <= l <= num + 1;
  loop invariant \valid(result + (0 .. num));
  loop invariant \forall integer i; 0 <= i < l ==> result[i] == lucas(i);
  loop invariant \forall integer i; 0 <= i < l ==> result[i] >= 0;
  loop assigns result[2 .. num];
  loop variant num - l;
*/
		for (int l = 2; l <= num; l++) {
			result[l] = result[l - 1]
					+ result[l - 2];
/*@ assert result[l] == lucas(l); */
		}
/*@ assert result[num] == lucas(num); */
		return result[num];
}
