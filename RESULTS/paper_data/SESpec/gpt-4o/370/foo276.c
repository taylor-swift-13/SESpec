
/*@
  logic integer modulo(integer x, integer y) = x % y;
*/

/*@
  requires value >= 0;
  requires k > 0;
  requires z >= 0 && z < k;
  assigns \nothing;
  ensures \result == 0 || (1 <= \result && \result <= value && modulo(\result, k) == z);
*/
int foo276(int value, int k, int z) {

    int result = 0;

    /*@
      loop invariant 1 <= c <= value + 1;
      loop invariant (result == 0) || (1 <= result && result < c && modulo(result, k) == z);
      loop invariant z == \at(z,Pre);
      loop invariant k == \at(k,Pre);
      loop invariant value == \at(value,Pre);
      loop assigns c, result;
    */
    for (int c = 1; c <= value; c++) {
        if ((c % k) == z) {
            result = c;
        }
    }

    return result;
}
