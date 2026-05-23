
/*@
  requires \valid(&pairs[0] + (0..pairs_len-1));
  requires \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
  requires pairs_len > 0;
  requires pairs_len < 100;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result == \sum(0, num - 1, \lambda integer i; \sum(i + 1, num - 1, \lambda integer j; (pairs[i] + pairs[j] == p) ? 1 : 0));
*/
int foo104(int * pairs, int pairs_len, int num, int p) {

		int ret = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (index < \at(num,Pre)) ==> (ret >= 0) ;
          loop invariant (!(index < \at(num,Pre))) ==> ((ret == 0)&&(p == \at(p,Pre))&&(num == \at(num,Pre))&&(pairs_len == \at(pairs_len,Pre))&&(pairs == \at(pairs,Pre)));
          loop invariant p == \at(p,Pre);
          loop invariant num == \at(num,Pre);
          loop invariant pairs_len == \at(pairs_len,Pre);
          loop invariant pairs == \at(pairs,Pre);
          loop invariant \forall integer k; 0 <= k < pairs_len ==> 0 <= pairs[k] <= 100 ;
          loop assigns index, j, ret;
            */
            for (int index = 0; index < num; index++) {
			
            /* >>> LOOP INVARIANT TO FILL <<< */
            /*@
              loop invariant 0 <= index <= num;
              loop invariant 0 <= ret;
              loop invariant ret >= 0;
              loop assigns index, ret, j;
            */
            for (int j = index + 1; j < num; j++) {
				if (pairs[index] + pairs[j] == p) {
					ret++;
				}
			}
            
		}
            
		return ret;
}
