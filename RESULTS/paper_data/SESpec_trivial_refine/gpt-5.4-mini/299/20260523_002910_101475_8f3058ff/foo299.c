
/*@
  requires array > 0;
  requires \valid(data + (0 .. array - 1));
  assigns \nothing;
  ensures 0 <= \result < array;
*/
int foo299(int * data, int data_len, int array) {

		int i = 0, top = array - 1;
		
        /*@
          loop invariant 0 <= i <= top;
          loop invariant top < array;
          loop assigns i, top;
          loop variant top - i;
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
