int maxPrimeFactors(int n);

/*@ predicate is_prime(integer x) =
      x >= 2 && (\forall integer d; 2 <= d <= x-1 ==> x % d != 0);

    predicate divides(integer a, integer b) =
      a != 0 && b % a == 0;
*/

/*@
  assigns \nothing;

  behavior nonpos:
    assumes n <= 1;
    ensures \result == 0;

  behavior pos:
    assumes n >= 2;
    ensures is_prime(\result);
    ensures divides(\result, \old(n));
    ensures \forall integer p; is_prime(p) && divides(p, \old(n)) ==> p <= \result;

  complete behaviors;
  disjoint behaviors;
*/
int maxPrimeFactors(int n) {

        int max = 0;
        /*@
          loop invariant i >= 2;
          loop invariant n >= 1;
          loop invariant divides(n, \at(n, Pre));
          loop invariant max == 0 || (is_prime(max) && divides(max, \at(n, Pre)) && max < i);
          loop invariant \forall integer p; is_prime(p) && divides(p, \at(n, Pre)) && p < i ==> p <= max;
          loop invariant \forall integer p; is_prime(p) && divides(p, n) ==> p >= i;
          loop variant \at(n, Pre) - i + 1;
        */
        for (int i = 2; i <= n; i++) {
            /*@
              loop invariant i >= 2;
              loop invariant n >= 1;
              loop invariant divides(n, \at(n, Pre));
              loop invariant max <= i;
              loop invariant max == 0 || (is_prime(max) && divides(max, \at(n, Pre)));
              loop assigns max, n;
              loop variant n;
            */
            while (n % i == 0) {
                max = i;
                n /= i;
            }
        }
        return max;
}
