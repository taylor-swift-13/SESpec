
/*@ predicate divides(integer d, integer n) = \exists integer k; n == d * k; */
/*@ predicate prime(integer n) = n >= 2 && \forall integer d; 2 <= d < n ==> !divides(d, n); */

/*@
  requires num >= 0;
  assigns \nothing;
  behavior small:
    assumes num <= 1;
    ensures \result == 0;
  behavior big:
    assumes num > 1;
    ensures \result >= 0;
    ensures \result <= \old(num);
  complete behaviors;
  disjoint behaviors;
*/
int foo336(int num) {
  int result = 0;
  int orig = num;

  if (num <= 1) {
    return 0;
  }

  /*@
    loop invariant 2 <= c;
    loop invariant c <= orig + 1;
    loop invariant num <= orig;
    loop invariant 0 <= result <= orig;
    loop assigns c, result, num;
    loop variant orig - c + 1;
  */
  for (int c = 2; c <= num; c++) {

    /*@
      loop invariant num <= orig;
      loop invariant 0 <= result <= orig;
      loop assigns result, num;
      loop variant num;
    */
    while (num % c == 0) {
      result = c;
      num /= c;
    }
  }

  return result;
}
