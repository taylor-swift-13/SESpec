
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@ 
  requires \at(positions_len,Pre) > 0 && \at(positions_len,Pre) < 100;
  assigns positions[0 .. array - 1];
  ensures \result == (\exists integer i; 0 <= i < array && positions[i] != i + 1 ? 
                      (\min_integer { integer j; 0 <= j < array && positions[j] != j + 1; } (j + 1)) :
                      array + 1);
  ensures \result == array + 1 || (1 <= \result <= array);
*/
int foo11(int * positions, int positions_len, int array) {

		int ret = 0;
		
        /*@
          loop invariant 0 <= ret <= array;
          loop invariant array == \at(array,Pre);
          loop invariant positions_len == \at(positions_len,Pre);
          loop invariant positions == \at(positions,Pre);
          loop invariant \forall integer i; 0 <= i < ret ==> positions[i] == i + 1;
          loop invariant \forall integer i; ret <= i < array ==> positions[i] > 0 && positions[i] <= array;
          loop invariant \forall integer v; 1 <= v <= array ==> count_eq(positions, 0, array, v) == \at(count_eq(positions, 0, array, v), Pre);
          loop assigns index, positions[..], ret;
        */
            while (ret < array) {
			if (positions[ret] <= 0 || positions[ret] > array
					|| positions[ret] == ret + 1) {
				ret++;
			} else {
				int index = positions[ret];
				positions[ret] = positions[index - 1];
				positions[index - 1] = index;
			}
		}
            
		
            
        /*@
          loop invariant 0 <= ret <= array;
          loop invariant positions == \at(positions,Pre);
          loop invariant positions_len == \at(positions_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant \forall integer i; 0 <= i < ret ==> positions[i] == i + 1;
          loop invariant \forall integer i; ret <= i < array ==> positions[i] > 0 && positions[i] <= array;
          loop invariant \forall integer v; 1 <= v <= array ==> count_eq(positions, 0, array, v) == \at(count_eq(positions, 0, array, v), Pre);
          loop assigns ret;
        */
            for (ret = 0; ret < array; ret++) {
			if (positions[ret] != ret + 1) {
				return ret + 1;
			}
		}
            
		return array + 1;
}
