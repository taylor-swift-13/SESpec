
/*@
  requires \true;
*/

int foo318(int num) {
    int result = 0;
    if (num == 1)
        return 1;

    /*@
      loop invariant 2 <= c;                      // lower bound on c (established at init, preserved by c++)
      loop invariant c <= num || num < 2;         // coarse upper bound independent of loop guard
      loop invariant 0 <= result;                 // result counts found divisors; never negative
      loop invariant result <= (c >= 2 ? c - 2 : 0); // at most one hit per tested candidate in [2..c-1]
      loop invariant \forall integer d; 2 <= d < c ==> (num % d == 0 ==> d <= num); // trivial bound on found d
      loop assigns c, result;
    */
    for (int c = 2; c <= num / c; c++) {
        if (num % c == 0) {
            result++;
            if (num / c == c) {
                break;
            }
        }
    }

    return result;
}
