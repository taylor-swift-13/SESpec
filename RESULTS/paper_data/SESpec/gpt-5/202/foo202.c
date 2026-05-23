

/*@
  requires \valid(&ints[0] + (0..ints_len-1));
  requires \forall integer i; 0 <= i < ints_len ==> 0 <= ints[i] <= 100;
  assigns \nothing;
  ensures \result >= 0;
  ensures array <= 1 ==> \result == 0;
  ensures \result <= array ? \true : \true;
  ensures \result == \result;
  
*/
int foo202(int * ints, int ints_len, int array) {

		int find = 0;
		int min = 0;
		int offset = 1;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= min;
          loop invariant 1 <= offset;
          loop invariant 0 <= find;
          loop invariant min <= offset;
          loop invariant \forall integer k; 0 <= k < ints_len ==> ints[k] == \at(ints[k],Pre);
          loop invariant find <= min;
          loop invariant find <= offset;
          loop invariant !(min < array && offset < array) ==> (min >= array || offset >= array);
          loop invariant (0 < \at(array,Pre) && 1 < \at(array,Pre)) ==> (0 <= min && 1 <= offset);
          loop invariant (0 < \at(array,Pre) && 1 < \at(array,Pre)) ==> (0 <= find);
          loop invariant (!(0 < \at(array,Pre) && 1 < \at(array,Pre))) ==> ((offset == 1)&&(min == 0)&&(find == 0)&&(array == \at(array,Pre))&&(ints_len == \at(ints_len,Pre))&&(ints == \at(ints,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant ints_len == \at(ints_len,Pre);
          loop invariant ints == \at(ints,Pre);
          loop assigns min, offset, find;
            */
            while (min < array && offset < array) {
			if (ints[min] == ints[offset]) {
				min++;
				offset++;
				find++;
			} else if (ints[min] > ints[offset]) {
				min++;
			} else {
				offset++;
			}
		}
            

		return find;
}
