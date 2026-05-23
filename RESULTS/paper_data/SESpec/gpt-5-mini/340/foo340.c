
/*@
  requires \at(z,Pre) >= 0 || \at(z,Pre) < 0;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= (\at(z,Pre) >= 0 ? \at(z,Pre) : -\at(z,Pre));
  ensures (\at(z,Pre) == 0) ==> \result == 0;
*/
int foo340(int n, int z) {

		if (z < 0) {
			z = -z;
		}
		int result = 0;
		
            
        /*@
          loop invariant 1 <= loop && loop <= z + 1;
          loop invariant 0 <= result && result <= z;
          loop invariant result <= loop - 1;
          loop invariant \forall int k; 1 <= k && k < loop ==> (0 <= k && k <= z);
          loop invariant \forall int k; 1 <= k && k < loop ==> (n % k == 0 ==> 1 <= result);
          loop invariant z == (\at(z,Pre) >= 0 ? \at(z,Pre) : -\at(z,Pre));
          loop invariant n == \at(n,Pre);
          loop assigns loop, result;
        */
            for (int loop = 1; loop <= z; loop++) {
			if (n % loop == 0) {
				result = result + 1;
			}
		}
            
		return result;
}
