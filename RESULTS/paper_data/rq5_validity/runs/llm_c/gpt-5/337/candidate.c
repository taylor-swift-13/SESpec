/*@ predicate divides(integer a, integer b) = \exists integer k; b == k * a; */
/*@ predicate is_prime(integer p) =
      p >= 2 &&
      (\forall integer d; 2 <= d <= p - 1 ==> p % d != 0);
*/

/*@ requires \true;
    assigns \nothing;

    behavior trivial:
      assumes num < 2;
      ensures \result == 0;

    behavior normal:
      assumes num >= 2;
      ensures is_prime(\result);
      ensures divides(\result, \old(num));
      ensures \forall integer p; is_prime(p) && divides(p, \old(num)) ==> p <= \result;

    complete behaviors;
    disjoint behaviors;
*/
int maxPrimeFactors(int num);

int maxPrimeFactors(int num) {

		int ret = 0;

		/*@ 
		  loop invariant ret >= 0;
		  loop invariant (\at(num,Pre) >= 2 ==> num >= 1);
		  loop invariant ret == 0 || is_prime(ret);
		  loop invariant ret == 0 || divides(ret, \at(num,Pre));
		  loop assigns num, ret, j;
		  loop variant (\at(num,Pre) >= 2 ? \at(num,Pre) - j : 0);
		*/
		for (int j = 2; j <= num; j++) {
			/*@
			  loop invariant j >= 2;
			  loop invariant ret >= 0;
			  loop invariant (\at(num,Pre) >= 2 ==> num >= 1);
			  loop assigns num, ret;
			  loop variant num;
			*/
			while (num % j == 0) {
				ret = j;
				num /= j;
			}
		}
		return ret;
}
