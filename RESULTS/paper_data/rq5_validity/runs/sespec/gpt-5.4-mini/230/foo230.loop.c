
/*@ logic integer mismatch_suffix(int* pairs, integer i, integer lo, integer hi) =
      lo >= hi ? 0 :
      mismatch_suffix(pairs, i, lo, hi - 1) + ((pairs[i] != pairs[hi - 1]) ? 1 : 0);
*/

/*@ logic integer prefix_mismatch(int* pairs, integer n, integer idx) =
      idx <= 0 ? 0 :
      prefix_mismatch(pairs, n, idx - 1) + mismatch_suffix(pairs, idx - 1, idx, n);
*/
        
/*@
  requires pairs_len >= 0;
  requires \valid(&pairs[0] + (0..pairs_len-1));
  requires \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
*/

int foo230(int * pairs, int pairs_len, int array) {

		int count = 0;
		int total = pairs_len;
		
            /*@
          loop invariant 0 <= index <= total;
          loop invariant total == \at(pairs_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant pairs_len == \at(pairs_len,Pre);
          loop invariant pairs == \at(pairs,Pre);
          loop invariant count >= 0;
          loop invariant \forall integer p; 0 <= p < index ==> 0 <= pairs[p] <= 100;
          loop invariant \forall integer p; 0 <= p < index ==> \forall integer q; p + 1 <= q < total ==> ((pairs[p] == pairs[q]) || (pairs[p] != pairs[q]));
          loop invariant count == prefix_mismatch(pairs, total, index);
          loop invariant \valid_read(pairs + (0 .. total - 1));
          loop assigns index, count;
            */
            for (int index = 0; index < total - 1; index++) {
			
            /*@
          loop invariant 0 <= index < total - 1;
          loop invariant index + 1 <= k <= total;
          loop invariant count >= 0;
          loop invariant count == prefix_mismatch(pairs, total, index) + mismatch_suffix(pairs, index, index + 1, k);
          loop invariant \forall integer t; index + 1 <= t < k ==> (pairs[index] == pairs[t] || pairs[index] != pairs[t]);
          loop invariant \valid_read(pairs + (0 .. total - 1));
          loop assigns count, k;
            */
            for (int k = index + 1; k < total; k++) {
				if (pairs[index] != pairs[k]) {
					count++;
				}
			}
            
		}
            
		return count;
}
