
/*@
  logic integer modulo(integer x, integer y) = x % y;
*/

/*@
  logic integer max_value(integer value, integer p, integer dy) =
    \exists integer c; 1 <= c <= value && modulo(c, p) == dy ? c : 0;
*/

/*@
  logic integer compute_result(integer value, integer p, integer dy) =
    \exists integer c; 1 <= c <= value && modulo(c, p) == dy ? c : 0;
*/

int foo275(int value, int p, int dy) {

    int result = 0;

    /*@
      loop invariant 1 <= c <= \at(value, Pre) + 1;
      loop invariant (c <= \at(value, Pre)) ==> (((result == 0)&&(dy == \at(dy,Pre))&&(p == \at(p,Pre))&&(value == \at(value,Pre))) || (PLACE_HOLDER_result));
      loop invariant (!(c <= \at(value,Pre))) ==> ((result == 0)&&(dy == \at(dy,Pre))&&(p == \at(p,Pre))&&(value == \at(value,Pre)));
      loop invariant dy == \at(dy,Pre);
      loop invariant p == \at(p,Pre);
      loop invariant value == \at(value,Pre);
      loop assigns c, result;
    */
    for (int c = 1; c <= value; c++) {
        if ((c % p) == dy) {
            result = c;
        }
    }

    return result;
}
