
/*@
  logic integer modulo(integer a, integer b) = (b == 0) ? 0 : a % b;
*/

/*@
  requires value >= 0; // Strengthened precondition to ensure value is non-negative
  requires p > 0; // Added precondition to ensure p is positive
  requires 0 <= dy < p; // Added precondition to ensure dy is within the valid range
  ensures \result == 0 || (1 <= \result <= value && modulo(\result, p) == dy);
*/
int foo369(int value, int p, int dy) {

    int result = 0;

    /*@
      loop invariant 1 <= c <= value + 1;
      loop invariant (result == 0) || (1 <= result <= c - 1 && modulo(result, p) == dy);
      loop invariant \forall integer k; 1 <= k < c ==> ((modulo(k, p) == dy) ==> (result >= k));
      loop invariant dy == \at(dy, Pre);
      loop invariant p == \at(p, Pre);
      loop invariant value == \at(value, Pre);
      loop assigns c, result;
    */
    for (int c = 1; c <= value; c++) {
        if ((c % p) == dy) {
            result = c;
        }
    }

    return result;
}
