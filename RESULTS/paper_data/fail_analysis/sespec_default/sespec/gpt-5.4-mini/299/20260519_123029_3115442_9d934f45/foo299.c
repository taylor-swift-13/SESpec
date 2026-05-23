
/*@
  predicate valid_data(int *data, integer n) =
    n > 0 ==> \valid_read(data + (0 .. n-1));
*/

/*@
  requires data_len > 0 && data_len < 100;
  requires \valid_read(data + (0 .. data_len - 1));
  assigns \nothing;
  ensures 0 <= \result;
*/
int foo299(int * data, int data_len, int array) {

		int i = 0, top = array - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i;
          loop invariant top <= array - 1;
          loop invariant array == \at(array, Pre);
          loop invariant data_len == \at(data_len, Pre);
          loop invariant data == \at(data, Pre);
          loop invariant \valid_read(data + (0 .. data_len - 1));
          loop assigns i, top;
            */
            while (i < top) {
			int p = i + (top - i) / 2;
			if (data[p] < data[p + 1]) {
				i = p + 1;
			} else {
				top = p;
			}
		}
            
		return i;
}
