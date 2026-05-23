
/*@ 
  requires array_len >= 0;
  requires \valid_read(array + (0 .. array_len-1));
  requires \forall integer p, q; 0 <= p <= q < array_len ==> array[p] <= array[q];
  ensures -1 <= \result < array_len;
  ensures \result == -1 ==> \forall integer t; 0 <= t < array_len ==> array[t] != x;
  ensures \result != -1 ==> array[\result] == x;
  assigns \nothing;  // functionally, the array is read-only; local scalars are assigned in code
*/


        
int foo216(int * array, int array_len, int x, int y) {

		int i = 0;
		int r = y - 1;
		int k = -1;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \forall integer p, q; 0 <= p <= q < array_len ==> array[p] <= array[q];
          loop invariant \forall integer t; 0 <= t < array_len ==> array[t] == \at(array[t], Pre);
          loop assigns k, i, r;
            */
            while (i <= r) {
			int tmp = (i + r) / 2;
			if (array[tmp] == x) {
				k = tmp;
				i = tmp + 1;
			} else if (array[tmp] < x) {
				i = tmp + 1;
			} else {
				r = tmp - 1;
			}
		}
            

		return k;
}
