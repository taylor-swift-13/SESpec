
/*@ logic integer count_divisors(integer n, integer z) =
      z <= 0 ? 0 :
      count_divisors(n, z - 1) + ((n % z) == 0 ? 1 : 0);
*/

/*@ 
  requires z >= 0;
  assigns \nothing;
  ensures z >= 0;
  ensures n == \old(n);
  
  ensures \result == count_divisors(n, (\old(z) >= 0 ? \old(z) : -\old(z)));
  ensures \result >= 0;
  ensures \result <= (\old(z) >= 0 ? \old(z) : -\old(z));
*/
int foo340(int n, int z) {
		if (z < 0) {
			z = -z;
		}
		int result = 0;
		
            /*@
          loop invariant 1 <= loop <= z + 1;
          loop invariant 0 <= result <= loop - 1;
          loop invariant result == count_divisors(n, loop - 1);
          loop invariant \forall integer k; 1 <= k < loop ==> (n % k == 0 || n % k != 0);
          loop invariant \forall integer k; 1 <= k < loop ==> (n % k == 0 ==> result >= 1);
          loop invariant (loop > z) ==> (result == count_divisors(n, z));
          loop invariant (loop > z) ==> (0 <= result <= z);
          loop invariant (loop > z) ==> (z == (\at(z,Pre) >= 0 ? \at(z,Pre) : -\at(z,Pre)));
          loop invariant (loop > z) ==> (n == \at(n,Pre));
          loop assigns loop, result;
            */
            for (int loop = 1; loop <= z; loop++) {
			if (n % loop == 0) {
				result = result + 1;
			}
		}
            
		return result;
}
