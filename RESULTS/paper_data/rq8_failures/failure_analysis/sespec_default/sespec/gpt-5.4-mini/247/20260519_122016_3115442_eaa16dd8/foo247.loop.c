
/*@
  logic integer pair_count(int *indices, integer num, integer index) =
    index <= 0 ? 0 :
    pair_count(indices, num, index - 1) +
    (indices[index - 1] > indices[index] ? 1 : 0);
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
          loop invariant 0 <= ret;
          loop invariant ret == pair_count(indices, num, index);
          loop invariant num == \at(num,Pre);
          loop invariant indices_len == \at(indices_len,Pre);
          loop invariant indices == \at(indices,Pre);
          loop invariant \forall integer i; 0 <= i < indices_len ==> indices[i] == \at(indices[i], Pre);
          loop assigns index, c, ret;
            */
            for (int index = 0; index < num; index++) {
			
            /* >>> LOOP INVARIANT TO FILL <<< */
            /*@
              loop invariant 0 <= index <= num;
              loop invariant 0 <= ret;
              loop assigns index, ret;
            */
            for (int c = index + 1; c < num; c++) {
				if (indices[index] > indices[c]) {
					ret++;
				}
			}
            
		}
            
		return ret;
}
