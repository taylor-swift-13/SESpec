
/*@
  logic integer count_pairs(int *pairs, integer lo, integer hi, integer p) =
    lo >= hi ? 0 :
    count_pairs(pairs, lo, hi - 1, p) + ((pairs[lo] + pairs[hi - 1] == p) ? 1 : 0);
*/

/*@ 
  requires \valid(&pairs[0] + (0..pairs_len-1));
  requires \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
  requires pairs_len > 0;
  requires pairs_len < 100;
  requires 0 <= num <= pairs_len;
  assigns \nothing;
  ensures \result >= 0;
*/
int foo102(int * pairs, int pairs_len, int num, int p) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index;
          loop invariant 0 <= result;
          loop invariant p == \at(p,Pre);
          loop invariant num == \at(num,Pre);
          loop invariant pairs_len == \at(pairs_len,Pre);
          loop invariant pairs == \at(pairs,Pre);
          loop invariant \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
          loop assigns index, result;
            */
            for (int index = 0; index < num; index++) {
			
            /* >>> LOOP INVARIANT TO FILL <<< */
            /*@
              loop invariant index >= 0;
              loop invariant result >= 0;
              loop assigns j, result;
            */
            for (int j = index + 1; j < num; j++) {
				if (pairs[index] + pairs[j] == p) {
					result++;
				}
			}
            
		}
            
		return result;
}
