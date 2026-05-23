
/*@
  requires \valid(&p[0] + (0..p_len-1));
  requires \forall integer i; 0 <= i < p_len ==> 0 <= p[i] <= 100;
  requires p_len > 0;
  requires p_len < 100;
           assigns *p, count, total, array, index, c;
  ensures \result == count;
  ensures \result >= 0;
*/
int foo90(int * p, int p_len, int array) {

		int count = 0;
		int total = p_len;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= \at(p_len,Pre) - 1;
          loop invariant 0 <= count;
          loop invariant total == \at(p_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant p_len == \at(p_len,Pre);
          loop invariant p == \at(p,Pre);
          loop invariant \forall integer i; 0 <= i < \at(p_len,Pre) ==> 0 <= p[i] <= 100;
          loop assigns index, c, count;
            */
            for (int index = 0; index < total - 1; index++) {
			
            /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= index <= total - 1;
              loop invariant 0 <= count;
              loop assigns count;
            */
            for (int c = index + 1; c < total; c++) {
				if (p[index] != p[c]) {
					count++;
				}
			}
            
		}
            
		return count;
}
