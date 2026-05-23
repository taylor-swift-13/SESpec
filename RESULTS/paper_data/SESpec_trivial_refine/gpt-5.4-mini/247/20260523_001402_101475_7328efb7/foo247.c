
/*@
*/

/*@
  requires 0 <= num <= indices_len;
  requires \valid_read(indices + (0 .. num-1));
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= num * (num - 1) / 2;
  ensures num <= 1 ==> \result == 0;
  ensures \result == 0 <==> (\forall integer i, j; 0 <= i < j < num ==> indices[i] <= indices[j]);
  ensures \result == inv_count(indices, num);
*/

int foo247(int * indices, int indices_len, int num) {

		int ret = 0;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= num;
          loop invariant ret >= 0;
          loop assigns index, ret, c;
            */
            for (int index = 0; index < num; index++) {
			
            /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant index + 1 <= c && c <= num;
          loop invariant 0 <= index && index < num;
          loop invariant ret >= 0;
          loop assigns c, ret;
            */
            for (int c = index + 1; c < num; c++) {
				if (indices[index] > indices[c]) {
					ret++;
				}
			}
            
		}
            
		return ret;
}
