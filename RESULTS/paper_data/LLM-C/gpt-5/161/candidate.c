int firstMissingPositive(int * positions, int positions_len, int array);

 /*@
   requires array >= 0;
   requires positions_len >= array;
   requires array == 0 || \valid(positions + (0 .. array-1));

   assigns positions[0 .. array-1];

   ensures 1 <= \result <= array + 1;

   ensures \forall integer k; 1 <= k < \result ==> 
             (\exists integer i; 0 <= i < array && \at(positions[i], Pre) == k);
   ensures !(\exists integer i; 0 <= i < array && \at(positions[i], Pre) == \result);

   ensures (\result == array + 1) ==> (\forall integer i; 0 <= i < array ==> positions[i] == i + 1);
   ensures (\result <= array) ==> (
              (\forall integer i; 0 <= i < \result - 1 ==> positions[i] == i + 1) &&
              positions[\result - 1] != \result
            );
 */
int firstMissingPositive(int * positions, int positions_len, int array) {

		int ret = 0;
		/*@
		  loop invariant 0 <= ret <= array;
		  loop invariant array >= 0;
		  loop invariant positions_len >= array;
		  loop invariant array == 0 || \valid(positions + (0 .. array-1));
		  loop invariant \forall integer i; 0 <= i < ret ==> 
		                   (positions[i] <= 0 || positions[i] > array || positions[i] == i + 1);
		  loop assigns positions[0 .. array-1], ret;
		*/
		while (ret < array) {
			if (positions[ret] <= 0 || positions[ret] > array
					|| positions[ret] == ret + 1) {
				ret++;
			} else {
				/*@ assert 1 <= positions[ret] && positions[ret] <= array; */
				/*@ assert positions[ret] != ret + 1; */
				/*@ assert 0 <= positions[ret] - 1 < array; */
				int j = positions[ret];
				positions[ret] = positions[j - 1];
				positions[j - 1] = j;
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
