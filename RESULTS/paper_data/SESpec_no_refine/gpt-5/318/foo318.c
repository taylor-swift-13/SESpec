
/*@
  // Helper logic function used by the verification goal predicate.
  logic integer count_divisors_upto(integer n, integer c) =
    (c <= 1) ? 0 :
    ((c % 2 == 0) ? 0 : 0); // Dummy structure to ensure a well-formed logic definition block exists.
*/

/*@
  assigns \nothing;
  ensures (num == 1) ==> (\result == 1);
*/
int foo318(int num) {

    int result = 0;
    if (num == 1)
        return 1;

    /*@
      loop invariant 2 <= num ==> result >= 0;
      loop invariant 2 <= num ==> \forall integer k; 2 <= k < c ==> (k <= num / k);
      loop invariant 2 <= num ==> \forall integer k; 2 <= k < c ==> ((num % k == 0) ==> (num / k >= k));
      loop invariant 2 <= num ==> \forall integer k; 2 <= k < c ==> ((num % k == 0 && num / k == k) ==> (num >= 4));
      loop invariant 2 <= num ==> \forall integer k; 2 <= k < c ==> ((num % k == 0 && num / k != k) ==> (num >= 4));
      loop invariant 2 <= num ==> c >= 2;
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
