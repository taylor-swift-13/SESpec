
/*@
  requires \valid(&p[0] + (0..p_len-1));
  requires \forall integer i; 0 <= i < p_len ==> 0 <= p[i] <= 100;
  assigns \nothing;
  ensures p == \at(p,Pre);
  ensures p_len == \at(p_len,Pre);
  ensures array == \at(array,Pre);
  ensures \forall integer k; 0 <= k < p_len ==> p[k] == \at(p[k],Pre);
  ensures \result >= 0;
  
  
*/
int foo231(int * p, int p_len, int array) {

		int count = 0;
		int total = p_len;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= count;
          loop invariant total == \at(p_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant p_len == \at(p_len,Pre);
          loop invariant p == \at(p,Pre);
          loop invariant \forall integer k; 0 <= k < total ==> p[k] == \at(p[k],Pre);
          loop invariant \forall integer k; 0 <= k < total ==> 0 <= p[k] <= 100;
          loop assigns index, count;
            */
            for (int index = 0; index < total - 1; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant index + 1 <= c <= total;
          loop invariant 0 <= count;
          loop invariant \forall integer k; 0 <= k < total ==> p[k] == \at(p[k], Pre);
          loop invariant \forall integer k; 0 <= k < total ==> 0 <= p[k] <= 100;
          loop assigns count, c;
            */
            for (int c = index + 1; c < total; c++) {
				if (p[index] != p[c]) {
					count++;
				}
			}
            
		}
            
		return count;
}
