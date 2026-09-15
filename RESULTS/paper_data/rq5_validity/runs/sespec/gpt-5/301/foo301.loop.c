
/*@
  predicate unchanged_array_int{L1,L2}(int *a, integer n) =
    \forall integer k; 0 <= k < n ==> \at(a[k],L1) == \at(a[k],L2);
*/

int foo301(int * data, int data_len, int array) {

	int found = 0, top = array - 1;

	/* >>> LOOP INVARIANT TO FILL <<< */

	/*@
	  loop invariant 0 <= found;
	  loop invariant (0 < \at(array,Pre) - 1) ==> (found <= top);
	  loop invariant (0 < \at(array,Pre) - 1) ==> (top <= \at(array,Pre) - 1);

	  loop invariant top <= \at(array,Pre) - 1;
	  loop invariant (0 < \at(array,Pre) - 1) ==> (0 <= top);
	  loop invariant (found < top) ==> (found <= top);

	  loop invariant (0 < \at(array,Pre) - 1) ==> (0 <= found && found <= top);
	  loop invariant (0 < \at(array,Pre) - 1) ==> (top < \at(array,Pre));
	  loop invariant (0 < \at(array,Pre) - 1) ==> (0 <= found && found < \at(array,Pre));
	  loop invariant (0 < \at(array,Pre) - 1) ==> (0 <= top && top < \at(array,Pre));

	  loop invariant (0 < \at(array,Pre) - 1) ==> (top - found >= 0);

	  loop invariant (0 < \at(array,Pre) - 1) ==>
	    (\forall integer j; found <= j && j <= top ==> found <= j && j <= top);

	  loop invariant (0 < \at(array,Pre) - 1) ==> ((found >= top) ==> (found == top));

	  loop invariant (0 < \at(array,Pre) - 1) ==> (0 <= found && found <= top && top < \at(array,Pre));

	  loop invariant (0 < \at(array,Pre) - 1) ==> (0 <= found && found <= top && top < \at(array,Pre));
	  loop invariant (0 < \at(array,Pre) - 1) ==> (((top == \at(array,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre))) || ((0 <= found) && (found <= top) && (top <= \at(array,Pre) - 1)));
	  loop invariant (0 < \at(array,Pre) - 1) ==> (((top == \at(array,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre))) || ((0 <= top) && (found <= top) && (top <= \at(array,Pre) - 1)));
	  loop invariant (!(0 < \at(array,Pre) - 1)) ==> ((top == \at(array,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre)));
	  loop invariant array == \at(array,Pre);
	  loop invariant data_len == \at(data_len,Pre);
	  loop invariant data == \at(data,Pre);
	  loop invariant (\valid_read(data + (0 .. \at(data_len,Pre)-1)) ==> unchanged_array_int{Pre,Here}(data, \at(data_len,Pre)));
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
