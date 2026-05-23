
/*@
  logic integer max_positive_prefix(int* positions, integer n, integer i) =
    i <= 0 ? 0 :
    max_positive_prefix(positions, n, i - 1) >
    (positions[i - 1] > 0 ? positions[i - 1] : 0)
      ? max_positive_prefix(positions, n, i - 1)
      : (positions[i - 1] > 0 ? positions[i - 1] : 0);
*/

/*@
  requires \valid(&positions[0] + (0..positions_len-1));
  requires \forall integer i; 0 <= i < positions_len ==> 0 <= positions[i] <= 100;
  requires positions_len > 0;
  requires positions_len < 100;
  assigns \nothing;
*/
int foo210(int * positions, int positions_len) {

		int largest = 0;
		
            
            /*@
          loop invariant positions_len == \at(positions_len,Pre);
          loop invariant positions == \at(positions,Pre);
          loop invariant \forall integer k; 0 <= k < \at(positions_len,Pre) ==> positions[k] == \at(positions[k],Pre);
          loop invariant (count < \at(positions_len,Pre)) ==> (((largest == 0)&&(positions_len == \at(positions_len,Pre))&&(positions == \at(positions,Pre))) || (largest >= 0));
          loop assigns count, largest;
            */
            for (int count = 0; count < positions_len; count++) {
			if (positions[count] > 0 && positions[count] > largest) {
				largest = positions[count];
			}
		}
            
		return largest;
}
