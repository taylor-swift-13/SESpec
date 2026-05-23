#include <stdlib.h>

/*@ 
  requires count >= 1;
  ensures \true;
*/
int countWays(int count);

int countWays(int count) {

		int *w = (int *)malloc(sizeof(int) * (count + 1));
/*@ 
  assert count + 1 >= 2;
  // assume successful allocation and usable block
  assume w != \null;
  assume \valid(w + (0 .. count));
*/
int w_len = count + 1;
		int *C = (int *)malloc(sizeof(int) * (count + 1));
/*@ 
  // assume successful allocation and usable block
  assume C != \null;
  assume \valid(C + (0 .. count));
*/
int C_len = count + 1;
		w[0] = 1;
		w[1] = 0;
		C[0] = 0;
		C[1] = 1;
/*@ 
  // Establish base cases before entering the loop
  assert w_len >= 2 && C_len >= 2;
  assert \valid(w + (0 .. count)) && \valid(C + (0 .. count));
  assert w[0] == 1 && w[1] == 0;
  assert C[0] == 0 && C[1] == 1;
*/
/*@ 
  loop invariant 2 <= index <= count + 1;
  loop invariant \valid(w + (0 .. count)) && \valid(C + (0 .. count));
  loop invariant w[0] == 1 && C[0] == 0;
  loop invariant w[1] == 0 && C[1] == 1;
  loop invariant \forall integer k; 2 <= k < index ==> 
                      (w[k] == w[k - 2] + 2 * C[k - 1] && 
                       C[k] == w[k - 1] + C[k - 2]);
  loop assigns w[2 .. count], C[2 .. count], index;
  loop variant count - index;
*/
		for (int index = 2; index <= count; index++) {
			w[index] = w[index - 2]
					+ 2 * C[index - 1];
			C[index] = w[index - 1] + C[index - 2];
		}
/*@ 
  assert 0 <= count < w_len;
  assert \valid_read(w + count);
*/
		return w[count];
}
