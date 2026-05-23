
/*@ 
  logic integer sum_cubes(integer n) =
    n <= 0 ? 0 : sum_cubes(n-1) + n*n*n;
*/

/*@ requires diff >= 0; */

int foo329(int diff) {

	int ret = 0;
	int max = 0;
	
    /*@ 
      loop invariant 0 <= j-1;
      loop invariant 0 <= ret;
      loop invariant ret == sum_cubes(j-1);
      loop invariant max == 0;
      loop invariant diff == \at(diff,Pre);
      loop assigns j, ret;
    */
    for (int j = 1; j <= diff; j++) {
		ret += j * j * j;
	}
		
    /*@
      loop invariant 0 <= j-1;
      loop invariant 0 <= max;
      loop invariant max == ((j-1) * j) / 2;
      loop invariant \forall integer k; 1 <= k && k < j ==> 1 <= k;
      loop invariant (j <= diff) ==> (max + j == (j * (j + 1)) / 2);
      loop invariant (!(j <= diff)) ==> (max == (diff * (diff + 1)) / 2);
      loop assigns j, max;
    */
    for (int j = 1; j <= diff; j++) {
		max += j;
	}
            
	return ret - max;
}
