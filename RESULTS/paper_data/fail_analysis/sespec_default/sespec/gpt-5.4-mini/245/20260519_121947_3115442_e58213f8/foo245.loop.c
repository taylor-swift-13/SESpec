
        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
/*@
  requires \valid(&pairs[0] + (0..pairs_len-1));
  requires \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
  requires pairs_len > 0;
  requires pairs_len < 100;
*/

int foo245(int * pairs, int pairs_len, int num, int p) {

		int ret = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= num;
          loop invariant (index < \at(num,Pre)) ==> (0 <= ret);
          loop invariant (!(index < \at(num,Pre))) ==> ((ret == 0)&&(p == \at(p,Pre))&&(num == \at(num,Pre))&&(pairs_len == \at(pairs_len,Pre))&&(pairs == \at(pairs,Pre)));
          loop invariant p == \at(p,Pre);
          loop invariant num == \at(num,Pre);
          loop invariant pairs_len == \at(pairs_len,Pre);
          loop invariant pairs == \at(pairs,Pre);
          loop invariant \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
          loop assigns index, ret;
            */
            for (int index = 0; index < num; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= index <= num;
              loop invariant 0 <= ret;
              loop assigns index, ret;
              loop variant num - index;
            */
            for (int j = index + 1; j < num; j++) {
				if (pairs[index] + pairs[j] == p) {
					ret++;
				}
			}
            
		}
            
		return ret;
}
