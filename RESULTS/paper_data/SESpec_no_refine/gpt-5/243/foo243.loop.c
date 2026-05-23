
/*@
  predicate PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION == \true;
*/

/*@
  logic integer count_pairs_prefix(int* a, integer n, integer upto_i, integer target) =
    (upto_i <= 0) ? 0
    : count_pairs_prefix(a, n, upto_i - 1, target)
      + \sum(0, upto_i, \lambda integer b;
               ((upto_i - 1) >= 0 && (upto_i - 1) < n && b >= 0 && b < n && (upto_i - 1) < b
                && a[upto_i - 1] + a[b] == target) ? 1 : 0);
*/
        
/*@
  requires \valid(&pairs[0] + (0..pairs_len-1));
  requires \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
  requires pairs_len > 0;
  requires pairs_len < 100;
*/

int foo243(int * pairs, int pairs_len, int num, int p) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= num;
          loop invariant 0 <= result;
          loop invariant result == count_pairs_prefix(pairs, pairs_len, index, p);
          loop invariant \forall integer k; 0 <= k < pairs_len ==> pairs[k] == \at(pairs[k], Pre);
          loop assigns index, j, result;
            */
            for (int index = 0; index < num; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant index >= 0 && index < num;
              loop invariant index + 1 <= j <= num;
              loop invariant result >= 0;
              loop invariant result
                == count_pairs_prefix(pairs, pairs_len, index, p)
                   + \sum(index+1, j,
                          \lambda integer b;
                            (index >= 0 && index < pairs_len && b >= 0 && b < pairs_len && index < b
                             && pairs[index] + pairs[b] == p) ? 1 : 0);
              loop assigns result, j;
            */
            for (int j = index + 1; j < num; j++) {
				if (pairs[index] + pairs[j] == p) {
					result++;
				}
			}
            
		}
            
		return result;
}
