
/*@
  requires \valid(&array[0] + (0..array_len-1));
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  requires array_len > 0;
  requires array_len < 100;
*/

int foo103(int * array, int array_len, int num, int p) {

		int ret = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (index < \at(num,Pre)) ==> (ret >= 0);
          loop invariant (!(index < \at(num,Pre))) ==> ((ret == 0)&&(p == \at(p,Pre))&&(num == \at(num,Pre))&&(array_len == \at(array_len,Pre))&&(array == \at(array,Pre)));
          loop invariant p == \at(p,Pre);
          loop invariant num == \at(num,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant \valid(&array[0] + (0..array_len-1));
          loop assigns index, j, ret;
            */
            for (int index = 0; index < num; index++) {
			
            /* >>> LOOP INVARIANT TO FILL <<< */
            /*@
              loop invariant 0 <= index <= num;
              loop invariant ret >= 0;
              loop invariant \true;
              loop assigns index, ret;
            */
            for (int j = index + 1; j < num; j++) {
				if (array[index] + array[j] == p) {
					ret++;
				}
			}
            
		}
            
		return ret;
}
