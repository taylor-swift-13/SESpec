
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
          loop invariant result == \numof(int i, int j; 0 <= i < index && i < j < num && pairs[i] + pairs[j] == p);
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
              loop invariant 0 <= index <= num;
              loop invariant 0 <= result;
              loop invariant result == \numof(int i, int j; 0 <= i < index && i < j < num && pairs[i] + pairs[j] == p);
              loop assigns index, result;
              loop variant num - index;
            */
            for (int j = index + 1; j < num; j++) {
				if (pairs[index] + pairs[j] == p) {
					result++;
				}
			}
            
		}
            
		return result;
}
