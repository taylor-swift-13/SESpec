
/*@
  requires 0 <= positions_len;
  requires 0 <= array <= positions_len;
  requires \valid(positions + (0 .. positions_len - 1));
  assigns positions[0 .. array - 1];
  ensures 1 <= \result <= array + 1;
  ensures \result <= array ==> positions[\result - 1] != \result;
  ensures \result == array + 1 ==> \forall integer k; 0 <= k < array ==> positions[k] == k + 1;
*/
int foo161(int * positions, int positions_len, int array) {

	int ret = 0;
	
	/*@
	  loop invariant 0 <= ret <= array;
	  loop invariant \forall integer k; 0 <= k < ret ==> 
	                   (positions[k] == k + 1 || positions[k] <= 0 || positions[k] > array);
	  loop assigns ret, positions[0 .. array - 1];
	  loop variant array - ret;
	*/
	while (ret < array) {
		if (positions[ret] <= 0 || positions[ret] > array
				|| positions[ret] == ret + 1) {
			ret++;
		} else {
			int j = positions[ret];
			positions[ret] = positions[j - 1];
			positions[j - 1] = j;
		}
	}
	
	/*@
	  loop invariant 0 <= ret <= array;
	  loop invariant \forall integer k; 0 <= k < ret ==> positions[k] == k + 1;
	  loop assigns ret;
	  loop variant array - ret;
	*/
	for (ret = 0; ret < array; ret++) {
		if (positions[ret] != ret + 1) {
			return ret + 1;
		}
	}
	
	return array + 1;
}
