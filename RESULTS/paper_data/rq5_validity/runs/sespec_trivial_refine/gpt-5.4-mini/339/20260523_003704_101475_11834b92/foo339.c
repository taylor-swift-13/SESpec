
        /*@ logic integer count_divisors_upto(integer n, integer k) =
      k <= 0 ? 0 :
      count_divisors_upto(n, k - 1) + ((n % k == 0) ? 1 : 0); */
/*@
  assigns \nothing;
  ensures \result >= 0;
  ensures \result == count_divisors_upto(num, (z < 0 ? -z : z));
  ensures (z < 0) ==> \result == count_divisors_upto(num, -z);
  ensures (z >= 0) ==> \result == count_divisors_upto(num, z);
*/
int foo339(int num, int z) {

		if (z < 0) {
			z = -z;
		}
		int result = 0;
		
        /*@
          loop invariant 1 <= index <= z + 1;
          loop invariant 0 <= result <= index - 1;
          loop invariant result == count_divisors_upto(num, index - 1);
          loop assigns index, result;
          loop variant z - index + 1;
        */
            for (int index = 1; index <= z; index++) {
			if (num % index == 0) {
				result = result + 1;
			}
		}
            
		return result;
}
