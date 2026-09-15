
        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
/*@
  requires \valid(&pairs[0] + (0..pairs_len-1));
  requires \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
  requires pairs_len > 0;
  requires pairs_len < 100;
  assigns \nothing;
  ensures \result == (num <= 0 ? 0 : num * (num - 1) / 2);
*/
int foo102(int * pairs, int pairs_len, int num, int p) {

		int result = 0;
		
            /*@
          loop invariant 0 <= index <= num;
          loop invariant p == \at(p,Pre);
          loop invariant num == \at(num,Pre);
          loop invariant pairs_len == \at(pairs_len,Pre);
          loop invariant pairs == \at(pairs,Pre);
          loop invariant \forall integer k; 0 <= k < pairs_len ==> pairs[k] == \at(pairs[k],Pre);
          loop invariant (index < \at(num,Pre)) ==> (result >= 0);
          loop invariant (!(index < \at(num,Pre))) ==> ((result == 0)&&(p == \at(p,Pre))&&(num == \at(num,Pre))&&(pairs_len == \at(pairs_len,Pre))&&(pairs == \at(pairs,Pre)));
          loop assigns index, j, result;
            */
            for (int index = 0; index < num; index++) {
			
            /*@
            loop invariant 0 <= index <= num;
            loop invariant 0 <= result;
            loop assigns index, result;
            */
            for (int j = index + 1; j < num; j++) {
				if (pairs[index] + pairs[j] == p) {
					result++;
				}
			}
            
		}
            
		return result;
}
