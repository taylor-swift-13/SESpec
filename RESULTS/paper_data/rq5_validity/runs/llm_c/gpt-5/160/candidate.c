int firstMissingPositive(int * positions, int positions_len, int array);

/*@
  requires array >= 0;
  requires positions_len >= array;
  requires \valid(positions + (0..positions_len-1));
  // No duplicates among values in 1..array within the first 'array' elements
  requires \forall integer i,j; 0 <= i < j < array ==> 
            !(1 <= positions[i] && positions[i] <= array && positions[i] == positions[j]);

  assigns positions[0..array-1];

  ensures 1 <= \result <= array + 1;

  // If all numbers 1..array are present in the initial segment, result is array+1
  ensures (\result == array + 1) <==> 
          (\forall integer k; 1 <= k <= array ==> 
              (\exists integer i; 0 <= i < array && \old(positions[i]) == k));

  // Otherwise, result is the smallest missing positive
  ensures 1 <= \result <= array ==>
          ((\forall integer k; 1 <= k < \result ==> 
               (\exists integer i; 0 <= i < array && \old(positions[i]) == k)))
          && (\forall integer i; 0 <= i < array ==> \old(positions[i]) != \result);
*/
int firstMissingPositive(int * positions, int positions_len, int array) {

		int ret = 0;
		/*@
		  loop invariant 0 <= ret <= array;
		  loop invariant \valid(positions + (0..array-1));
		  loop assigns positions[0..array-1], ret;
		*/
		while (ret < array) {
			if (positions[ret] <= 0 || positions[ret] > array
					|| positions[ret] == ret + 1) {
				ret++;
			} else {
				int index = positions[ret];
				/*@ assert 1 <= index <= array && index != ret + 1; */
				positions[ret] = positions[index - 1];
				positions[index - 1] = index;
			}
		}
		/*@
		  loop invariant 0 <= ret <= array;
		  loop invariant \forall integer i; 0 <= i < ret ==> positions[i] == i + 1;
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
