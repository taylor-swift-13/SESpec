
/*@
  logic integer cnt_neq_from(int* a, integer i, integer lo, integer hi) =
    lo >= hi ? 0
             : cnt_neq_from(a, i, lo, hi - 1) + (a[hi - 1] != a[i] ? 1 : 0);
*/

        
/*@
  requires \valid(&pairs[0] + (0..pairs_len-1));
  requires \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
  requires pairs_len > 0;
  requires pairs_len < 100;
  assigns \nothing;
  ensures \forall integer t; 0 <= t < pairs_len ==> pairs[t] == \at(pairs[t], Pre);
  ensures \result == (\sum(integer i = 0; i < pairs_len - 1; i++) cnt_neq_from(pairs, i, i + 1, pairs_len));
*/
int foo230(int * pairs, int pairs_len, int array) {

		int count = 0;
		int total = pairs_len;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant total == pairs_len;
              loop invariant array == \at(array,Pre);
              loop invariant pairs_len == \at(pairs_len,Pre);
              loop invariant pairs == \at(pairs,Pre);
              loop invariant \forall integer t; 0 <= t < total ==> pairs[t] == \at(pairs[t],Pre);
              loop invariant 0 <= index <= total - 1;
              loop invariant count == \sum(integer i = 0; i < index; i++) cnt_neq_from(pairs, i, i+1, total);
              loop assigns index, k, count;
            */
            for (int index = 0; index < total - 1; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop assigns count, k;
              loop invariant index >= 0 && index < total;
              loop invariant 0 <= k <= total;
              loop invariant count >= 0;
              loop invariant \forall integer j; index+1 <= j < k ==> (pairs[index] != pairs[j]) ==> \true;
              loop invariant \forall integer j; index+1 <= j < k ==> 0 <= j < total;
              loop invariant \forall integer j; index+1 <= j < k ==> \valid(pairs + j) && \valid(pairs + index);
            */
            for (int k = index + 1; k < total; k++) {
				if (pairs[index] != pairs[k]) {
					count++;
				}
			}
            
		}
            
		return count;
}
