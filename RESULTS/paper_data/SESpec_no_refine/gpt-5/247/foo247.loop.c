
/*@
  logic integer inv_pairs(int* a, integer n, integer i) =
    i <= 0 ? 0
           : inv_pairs(a, n, i - 1)
             + (i - 1 < n ? (\sum integer k; i <= k < n ? (a[i-1] > a[k] ? 1 : 0) : 0) : 0);
*/

/*@
  requires \valid(&indices[0] + (0..indices_len-1));
  requires \forall integer i; 0 <= i < indices_len ==> 0 <= indices[i] <= 100;
  requires indices_len > 0;
  requires indices_len < 100;
*/

int foo247(int * indices, int indices_len, int num) {

		int ret = 0;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= num;
          loop invariant ret == inv_pairs(indices, num, index);
          loop invariant \forall integer k; 0 <= k < indices_len ==> indices[k] == \at(indices[k],Pre);
          loop assigns index, c, ret;
            */
            for (int index = 0; index < num; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant index + 1 <= c <= num;
              loop invariant ret == inv_pairs(indices, num, index)
                                   + (\sum integer k; index + 1 <= k < c ? (indices[index] > indices[k] ? 1 : 0) : 0);
              loop invariant \forall integer k; 0 <= k < indices_len ==> indices[k] == \at(indices[k],Pre);
              loop assigns ret, c;
            */
            for (int c = index + 1; c < num; c++) {
				if (indices[index] > indices[c]) {
					ret++;
				}
			}
            
		}
            
		return ret;
}
