
/*@ requires \valid(&pairs[0] + (0..pairs_len-1));
  requires \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
  requires pairs_len > 0;
  requires pairs_len < 100;
*/

int foo91(int * pairs, int pairs_len, int array) {

		int count = 0;
		int total = pairs_len;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= \at(pairs_len,Pre) - 1;
          loop invariant 0 <= count;
          loop invariant total == \at(pairs_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant pairs_len == \at(pairs_len,Pre);
          loop invariant pairs == \at(pairs,Pre);
          loop invariant \forall integer i; 0 <= i < \at(pairs_len,Pre) ==> pairs[i] == \at(pairs[i],Pre);
          loop assigns index, count;
            */
            for (int index = 0; index < total - 1; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant index + 1 <= c <= total;
              loop invariant 0 <= index <= total - 1;
              loop invariant count >= 0;
              loop invariant total == \at(pairs_len,Pre);
              loop invariant array == \at(array,Pre);
              loop invariant pairs_len == \at(pairs_len,Pre);
              loop invariant pairs == \at(pairs,Pre);
              loop invariant \forall integer i; 0 <= i < \at(pairs_len,Pre) ==> pairs[i] == \at(pairs[i],Pre);
              loop assigns c, count;
            */
            for (int c = index + 1; c < total; c++) {
				if (pairs[index] != pairs[c]) {
					count++;
				}
			}
            
		}
            
		return count;
}
