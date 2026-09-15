
/*@
  requires array >= 0;
*/
int foo301(int * data, int data_len, int array) {

		int found = 0, top = array - 1;
		
            
        /*@
          loop invariant 0 <= found <= top + 1;
          loop invariant top < array;
          loop invariant array == \at(array,Pre);
          loop invariant data_len == \at(data_len,Pre);
          loop invariant data == \at(data,Pre);
          loop invariant \forall integer k; 0 <= k < data_len ==> data[k] == \at(data[k],Pre);
          loop invariant (0 < \at(array,Pre) - 1) ==> (0 <= found <= top + 1);
          loop invariant (0 < \at(array,Pre) - 1) ==> (((top == \at(array,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre))) || (0 <= found <= top + 1));
          loop invariant (0 < \at(array,Pre) - 1) ==> (((top == \at(array,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre))) || (0 <= top < array));
          loop invariant (!(0 < \at(array,Pre) - 1)) ==> ((top == \at(array,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant data_len == \at(data_len,Pre);
          loop invariant data == \at(data,Pre);
          loop invariant \forall integer k; 0 <= k < data_len ==> data[k] == \at(data[k],Pre);
          loop assigns found, top;
            */
            while (found < top) {
			int i = found + (top - found) / 2;
			if (data[i] < data[i + 1]) {
				found = i + 1;
			} else {
				top = i;
			}
		}
            
		return found;
}
