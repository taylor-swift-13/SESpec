
/*@
  // Helper logic: count_div_prefix(n, m) returns the number of integers
  // k with 1 <= k <= m that divide n.
  logic integer count_div_prefix(integer n, integer m) =
    m <= 0 ? 0 :
    ( (n % m == 0) ? 1 + count_div_prefix(n, m - 1) : count_div_prefix(n, m - 1) );
*/

int foo341(int num, int z) {

	if (z < 0) {
		z = -z;
	}
	int result = 0;
	
	/*@ 
	  loop invariant 1 <= loop <= z + 1;
	  loop invariant 0 <= result;
	  loop invariant result == count_div_prefix(num, loop - 1);
	  loop invariant ( \at(z,Pre) >= 0 && z == \at(z,Pre) ) || ( \at(z,Pre) < 0 && z == -\at(z,Pre) );
	  loop invariant num == \at(num,Pre);
	  loop assigns loop, result;
	*/
	for (int loop = 1; loop <= z; loop++) {
		if (num % loop == 0) {
			result = result + 1;
		}
	}
	    
	return result;
}
