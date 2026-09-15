
/*@
  logic integer count_divisors_up_to(integer n, integer up) =
    up <= 0 ? 0 : count_divisors_up_to(n, up-1) + ((n % up == 0) ? 1 : 0);
*/

/*@
  requires \true;
  assigns \nothing;
  ensures \result == count_divisors_up_to(num, (z < 0 ? -z : z));
  ensures \result >= 0;
  ensures \result <= (z < 0 ? -z : z);
*/
int foo339(int num, int z) {

		if (z < 0) {
			z = -z;
		}
		int result = 0;
		
            /*@
          loop invariant 1 <= index && index <= z + 1;
          loop invariant 0 <= result && result <= index - 1;
          loop invariant result == count_divisors_up_to(num, index - 1);
          loop invariant z >= 0;
          loop invariant num == \at(num,Pre);
          loop assigns index, result;
            */
            for (int index = 1; index <= z; index++) {
			if (num % index == 0) {
				result = result + 1;
			}
		}
            
		return result;
}
