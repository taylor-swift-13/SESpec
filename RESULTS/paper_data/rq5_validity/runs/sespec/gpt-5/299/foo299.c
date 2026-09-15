

/*@
  requires \valid(&data[0] + (0..data_len-1));
  requires \forall integer i; 0 <= i < data_len ==> 0 <= data[i] <= 100;
  assigns \nothing;
  ensures \forall integer k; 0 <= k < data_len ==> data[k] == \old(data[k]);
  ensures array <= 1 ==> \result == 0;
  ensures array > 1 ==> (0 <= \result && \result < array);
  ensures array > 1 ==> (\result <= array - 1);
  ensures \result >= 0;
  ensures \result == \result;
*/
int foo299(int * data, int data_len, int array) {

		int i = 0, top = array - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 < \at(array,Pre) - 1) ==> (0 <= i && i <= top + 1);
          loop invariant (0 < \at(array,Pre) - 1) ==> (-1 <= top && top < \at(array,Pre));
          loop invariant (0 < \at(array,Pre) - 1) ==> (i <= top || i == top + 1);

          loop invariant (0 < \at(array,Pre) - 1) ==> (0 <= i);
          loop invariant (0 < \at(array,Pre) - 1) ==> (top < \at(array,Pre));
          loop invariant (0 < \at(array,Pre) - 1) ==> (i <= top + 1);
          loop invariant (0 < \at(array,Pre) - 1) ==> ((i < top) ==> (i + 1 <= top));
          loop invariant (0 < \at(array,Pre) - 1) ==> ((i >= top) ==> (i == top));
          
          loop invariant (0 < \at(array,Pre) - 1) ==> (top <= \at(array,Pre) - 1);
          loop invariant (0 < \at(array,Pre) - 1) ==> (i <= top);

          loop invariant (0 < \at(array,Pre) - 1) ==> (((top == \at(array,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre))) || (0 <= i && i <= top && top < \at(array,Pre)));
          loop invariant (0 < \at(array,Pre) - 1) ==> (((top == \at(array,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre))) || (i <= top && top < \at(array,Pre) && 0 <= top));
          loop invariant (!(0 < \at(array,Pre) - 1)) ==> ((top == \at(array,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant data_len == \at(data_len,Pre);
          loop invariant data == \at(data,Pre);
          loop invariant \forall integer k; 0 <= k < data_len ==> data[k] == \at(data[k],Pre) ;
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
