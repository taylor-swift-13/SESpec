
/*@ 
  logic integer count_div_prefix(integer num, integer k) =
    k <= 0 ? 0 :
    ((num % k == 0) ? 1 : 0) + count_div_prefix(num, k - 1);
*/

/*@
  requires \true;
  assigns \nothing;
  
  ensures \result >= 0;
  ensures (\at(z,Pre) >= 0) ==> \result == count_div_prefix(num, \at(z,Pre));
  ensures (\at(z,Pre) < 0) ==> \result == count_div_prefix(num, -\at(z,Pre));
  ensures num == \at(num,Pre);
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
