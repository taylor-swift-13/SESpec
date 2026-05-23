
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
