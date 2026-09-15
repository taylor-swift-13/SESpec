int maxPrimeFactors(int num);

/*@ predicate is_prime(integer p) =
      p >= 2 &&
      (\forall integer k; 2 <= k <= p - 1 ==> p % k != 0);

    predicate divides(integer a, integer b) =
      a != 0 && b % a == 0;
*/

/*@ 
  requires num >= 0;
  assigns \nothing;

  behavior trivial:
    assumes num < 2;
    ensures \result == 0;

  behavior nontrivial:
    assumes num >= 2;
    ensures is_prime(\result);
    ensures divides(\result, \old(num));
    ensures \forall integer p; is_prime(p) && divides(p, \old(num)) ==> p <= \result;
    ensures is_prime(\old(num)) ==> \result == \old(num);

  complete behaviors;
  disjoint behaviors;
*/
int maxPrimeFactors(int num) {

		int result = 0;
		/*@
		  loop assigns result, num;
		  loop invariant 1 <= num <= \old(num);
		  loop invariant result == 0 || (is_prime(result) && divides(result, \old(num)) && result < j);
		  loop invariant \forall integer p; is_prime(p) && p < j && divides(p, \old(num)) ==> p <= result;
		  loop invariant \forall integer p; is_prime(p) && p < j ==> !divides(p, num);
		  loop variant \old(num) - j;
		*/
		for (int j = 2; j <= num; j++) {
			/*@
			  loop assigns num, result;
			  loop invariant j >= 2;
			  loop invariant 1 <= num;
			  loop invariant \forall integer p; is_prime(p) && p < j ==> !divides(p, num);
			  loop invariant result == 0 || (is_prime(result) && divides(result, \old(num)) && result <= j);
			  loop variant num;
			*/
			while (num % j == 0) {
				result = j;
				num /= j;
			}
		}
		return result;
}
