#include <stddef.h>

int largestPos(int * positions, int positions_len);

/*@ 
  requires positions_len >= 0;
  requires positions_len == 0 || \valid_read(positions + (0 .. positions_len-1));
  assigns \nothing;
  ensures \result >= 0;
  ensures \forall integer k; 0 <= k < positions_len ==> (positions[k] > 0 ==> \result >= positions[k]);
  ensures (\exists integer i; 0 <= i < positions_len && positions[i] > 0) ==> (\result > 0 && (\exists integer j; 0 <= j < positions_len && positions[j] == \result && positions[j] > 0));
  ensures (\forall integer i; 0 <= i < positions_len ==> positions[i] <= 0) <==> \result == 0;
*/
int largestPos(int * positions, int positions_len) {

		int largest = 0;
		/*@
		  loop invariant 0 <= count <= positions_len;
		  loop invariant largest >= 0;
		  loop invariant \forall integer k; 0 <= k < count ==> (positions[k] > 0 ==> largest >= positions[k]);
		  loop invariant (\exists integer k; 0 <= k < count && positions[k] > 0) ==> (largest > 0 && (\exists integer j; 0 <= j < count && positions[j] == largest && positions[j] > 0));
		  loop invariant (largest == 0) <==> (\forall integer k; 0 <= k < count ==> positions[k] <= 0);
		  loop assigns count, largest;
		  loop variant positions_len - count;
		*/
		for (int count = 0; count < positions_len; count++) {
			if (positions[count] > 0 && positions[count] > largest) {
				largest = positions[count];
			}
		}
		return largest;
}
