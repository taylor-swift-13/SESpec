
/*@
  logic integer mod(integer x, integer y) = (y == 0) ? 0 : x % y;
*/

/*@
  logic integer last_mod_match(integer value, integer k, integer z) =
    \exists integer c; 1 <= c <= value && mod(c, k) == z && 
    (\forall integer d; 1 <= d < c ==> mod(d, k) != z);
*/

/*@
  predicate result_matches_last_mod_match(integer result, integer value, integer k, integer z) =
    (result == 0 && (\forall integer c; 1 <= c <= value ==> mod(c, k) != z)) ||
    (result != 0 && mod(result, k) == z && last_mod_match(value, k, z) == result);
*/

int foo276(int value, int k, int z) {

    int result = 0;

    /*@
      loop invariant 1 <= c <= value + 1;
      loop invariant z == \at(z,Pre);
      loop invariant k == \at(k,Pre);
      loop invariant value == \at(value,Pre);
      loop invariant (c <= \at(value,Pre)) ==> 
        (((result == 0) && (\forall integer d; 1 <= d < c ==> mod(d, k) != z)) || 
         (result != 0 && mod(result, k) == z && 
          (\forall integer d; 1 <= d < c ==> mod(d, k) != z)));
      loop invariant (!(c <= \at(value,Pre))) ==> 
        result_matches_last_mod_match(result, \at(value,Pre), \at(k,Pre), \at(z,Pre));
      loop assigns c, result;
    */
    for (int c = 1; c <= value; c++) {
        if ((c % k) == z) {
            result = c;
        }
    }

    return result;
}
