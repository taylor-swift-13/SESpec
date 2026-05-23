
/*@ logic integer max_int(integer a, integer b) = a > b ? a : b; */

/*@ 
  assigns \nothing;
  ensures 0 < \at(array,Pre) - 1 ==> \result <= (\at(array,Pre) - 1);
  ensures !(0 < \at(array,Pre) - 1) ==> \result == 0;
*/
int foo201(int * data, int data_len, int array) {

		int i = 0, top = array - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 < \at(array,Pre) - 1) ==> (((top == \at(array,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre))) || (0 <= i <= top));
          loop invariant (0 < \at(array,Pre) - 1) ==> (((top == \at(array,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre))) || (top <= \at(array,Pre) - 1));
          loop invariant (!(0 < \at(array,Pre) - 1)) ==> ((top == \at(array,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant data_len == \at(data_len,Pre);
          loop invariant data == \at(data,Pre);
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
