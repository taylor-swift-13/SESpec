
/*@
  predicate unchanged_array(int *a, integer len) =
    \forall integer k; 0 <= k < len ==> a[k] == \at(a[k], Pre);
*/
        
int foo201(int * data, int data_len, int array) {

		int i = 0, top = array - 1;
		
            
        /*@
          loop invariant 0 <= i <= top + 1;
          loop invariant (\at(array,Pre) - 1) >= 0 ==> 0 <= top <= \at(array,Pre) - 1;
          loop invariant (\at(array,Pre) - 1) >= 0 ==> 0 <= i <= \at(array,Pre) - 1;
          loop invariant (0 < \at(array,Pre) - 1) ==> (((top == \at(array,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre))) || (0 <= i && i < \at(array,Pre) && 0 <= top && top < \at(array,Pre) && i <= top));
          loop invariant (0 < \at(array,Pre) - 1) ==> (((top == \at(array,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre))) || (0 <= top && top < \at(array,Pre) && 0 <= i && i < \at(array,Pre) && i <= top));
          loop invariant (!(0 < \at(array,Pre) - 1)) ==> ((top == \at(array,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant data_len == \at(data_len,Pre);
          loop invariant data == \at(data,Pre);
          loop invariant unchanged_array(data, \at(data_len,Pre)) ;
          loop assigns p, i, top;
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
