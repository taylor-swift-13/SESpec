

/*@
  requires \valid(&array[0] + (0..array_len-1));
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  requires array_len > 0;
  requires array_len < 100;
  requires count >= 0;
  assigns \nothing;
  ensures array == \old(array) && array_len == \old(array_len) && count == \old(count);
  ensures \forall integer k; 0 <= k < array_len ==> array[k] == \old(array[k]);
  ensures (count == 0 ==> \result == 0);
  ensures (count != 0 ==> 1 <= \result <= count);
  ensures \result == ((count == 0) ? 0 : \result);
*/
int foo36_c181(int * array, int array_len, int count) {

		if (count == 0) {
			return 0;
		}
		int r = 0, top = count - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 < \at(count,Pre) - 1) ==> (0 <= r <= top < \at(count,Pre));
          loop invariant (0 < \at(count,Pre) - 1) ==> (((top == \at(count,Pre) - 1)&&(r == 0)&&(count == \at(count,Pre))&&(array_len == \at(array_len,Pre))&&(array == \at(array,Pre))) || (0 <= r < \at(count,Pre)));
          loop invariant (0 < \at(count,Pre) - 1) ==> (((top == \at(count,Pre) - 1)&&(r == 0)&&(count == \at(count,Pre))&&(array_len == \at(array_len,Pre))&&(array == \at(array,Pre))) || (0 <= top < \at(count,Pre)));
          loop invariant (!(0 < \at(count,Pre) - 1)) ==> ((top == \at(count,Pre) - 1)&&(r == 0)&&(count == \at(count,Pre))&&(array_len == \at(array_len,Pre))&&(array == \at(array,Pre)));
          loop invariant count == \at(count,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant \forall integer k; 0 <= k < \at(array_len,Pre) ==> array[k] == \at(array[k], Pre) ;
          loop assigns r, top;
            */
            while (r < top) {
			if (array[r] < array[top]) {
				return r + 1;
			}
			int i = (r + top) / 2;
			if (array[i] > array[r]) {
				r = i;
			} else {
				top = i;
			}
		}
            
		return r + 1;
}
