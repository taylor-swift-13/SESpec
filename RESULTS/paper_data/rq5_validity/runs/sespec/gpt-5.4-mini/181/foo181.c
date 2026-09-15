

/*@ 
  requires \valid(&array[0] + (0..array_len-1));
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  assigns \nothing;
  ensures count == 0 ==> \result == 0;
  ensures count < 0 ==> \result == 1;
  ensures count > 0 ==> 1 <= \result <= count;
  ensures \result >= 0;
  ensures \result <= count || count <= 0;
  ensures \result == 0 <==> count == 0;
*/
int foo181(int * array, int array_len, int count) {

		if (count == 0) {
			return 0;
		}
		int r = 0, top = count - 1;
		
            /*@
          loop invariant count == \at(count,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant 0 <= r;
          loop invariant (0 < count) ==> (0 <= r <= count - 1);
          loop invariant (0 < count) ==> (top < count);
          loop invariant (count <= 0) ==> (r == 0 && top == count - 1);
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
