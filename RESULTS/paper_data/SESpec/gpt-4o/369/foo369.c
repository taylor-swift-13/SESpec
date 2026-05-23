
/*@
  logic integer modulo(integer a, integer b) = (b == 0) ? 0 : a % b;
*/

/*@
  requires value >= 0; // The loop range must be valid and non-negative
  requires p > 0; // The modulo operation must be well-defined
  requires 0 <= dy < p; // dy must be within the valid range for modulo p
  assigns \nothing; // The function does not modify any caller-visible state
  ensures \result == 0 ==> \forall integer k; 1 <= k <= value ==> modulo(k, p) != dy; // If \result is 0, no k satisfies (k % p) == dy
  ensures \result != 0 ==> (1 <= \result <= value && modulo(\result, p) == dy); // If \result is non-zero, it satisfies the conditions
  ensures \result != 0 ==> \forall integer k; 1 <= k <= value ==> (modulo(k, p) == dy ==> k <= \result); // \result is the largest k satisfying the condition
*/
int foo369(int value, int p, int dy) {

    int result = 0;

    /*@
      loop invariant 1 <= c <= value + 1; // c is within the valid range
      loop invariant (result == 0) || (1 <= result <= c - 1 && modulo(result, p) == dy); // result is either 0 or satisfies the condition
      loop invariant \forall integer k; 1 <= k < c ==> ((modulo(k, p) == dy) ==> (result >= k)); // result is the largest k satisfying the condition so far
      loop invariant dy == \at(dy, Pre); // dy remains unchanged
      loop invariant p == \at(p, Pre); // p remains unchanged
      loop invariant value == \at(value, Pre); // value remains unchanged
      loop assigns c, result; // c and result are modified during the loop
    */
    for (int c = 1; c <= value; c++) {
        if ((c % p) == dy) {
            result = c;
        }
    }

    return result;
}
