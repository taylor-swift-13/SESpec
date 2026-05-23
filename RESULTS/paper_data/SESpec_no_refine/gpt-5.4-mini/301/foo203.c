
/*@
  logic integer max2(integer a, integer b) = a >= b ? a : b;
*/

/*@
  logic integer abs_int(integer x) = x >= 0 ? x : -x;
*/

/*@
  requires \valid(&data[0] + (0..data_len-1));
  requires \forall integer i; 0 <= i < data_len ==> 0 <= data[i] <= 100;
  requires data_len > 0;
  requires data_len < 100;
  assigns \nothing;
  ensures 0 <= \result < array;
  ensures \result == found;
  ensures \result == top;
*/
int foo203(int * data, int data_len, int array) {

		int found = 0, top = array - 1;
		
            
        /*@
          loop invariant (0 < \at(array,Pre) - 1) ==> (((top == \at(array,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre))) || ((0 <= found <= top) && (top < \at(array,Pre)) && (array == \at(array,Pre)) && (data_len == \at(data_len,Pre)) && (data == \at(data,Pre))));
          loop invariant (0 < \at(array,Pre) - 1) ==> (((top == \at(array,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre))) || ((0 <= found <= top) && (top <= \at(array,Pre) - 1) && (array == \at(array,Pre)) && (data_len == \at(data_len,Pre)) && (data == \at(data,Pre))));
          loop invariant (!(0 < \at(array,Pre) - 1)) ==> ((top == \at(array,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant data_len == \at(data_len,Pre);
          loop invariant data == \at(data,Pre);
          loop assigns i, found, top;
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
