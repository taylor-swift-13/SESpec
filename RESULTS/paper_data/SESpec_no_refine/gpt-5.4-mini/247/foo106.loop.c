
        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
/*@
  requires \valid(&indices[0] + (0..indices_len-1));
  requires \forall integer i; 0 <= i < indices_len ==> 0 <= indices[i] <= 100;
  requires indices_len > 0;
  requires indices_len < 100;
*/

int foo106(int * indices, int indices_len, int num) {

		int ret = 0;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (index < \at(num,Pre)) ==> (ret >= 0 && ret <= index * (num - 1) - (index * (index - 1)) / 2) ;
          loop invariant (!(index < \at(num,Pre))) ==> ((ret == 0)&&(num == \at(num,Pre))&&(indices_len == \at(indices_len,Pre))&&(indices == \at(indices,Pre)));
          loop invariant num == \at(num,Pre);
          loop invariant indices_len == \at(indices_len,Pre);
          loop invariant indices == \at(indices,Pre);
          loop invariant \forall integer i; 0 <= i < indices_len ==> 0 <= indices[i] <= 100;
          loop assigns index, c, ret;
            */
            for (int index = 0; index < num; index++) {
			
            /* >>> LOOP INVARIANT TO FILL <<< */
            /*@
              loop invariant 0 <= index <= num;
              loop invariant ret >= 0;
              loop invariant ret <= index * (num - 1) - (index * (index - 1)) / 2;
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
