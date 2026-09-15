
/*@
  logic integer mod(integer x, integer y) = x % y;
*/

/*@
  logic integer last_mod_match(integer value, integer p, integer z) =
    \exists integer c; 1 <= c <= value && mod(c, p) == z && 
    (\forall integer d; c < d <= value ==> mod(d, p) != z);
*/

/*@
  logic integer no_mod_match(integer value, integer p, integer z) =
    \forall integer c; 1 <= c <= value ==> mod(c, p) != z;
*/

int foo277(int value, int p, int z) {

    int result = 0;

    /*@
      loop invariant (c <= \at(value,Pre)) ==> 
        (((result == 0) && (z == \at(z,Pre)) && (p == \at(p,Pre)) && (value == \at(value,Pre))) || 
         (result > 0 && mod(result, p) == z && 
          (\forall integer d; result < d < c ==> mod(d, p) != z)));
      loop invariant (!(c <= \at(value,Pre))) ==> 
        ((result == 0 && no_mod_match(\at(value,Pre), \at(p,Pre), \at(z,Pre))) || 
         (result > 0 && mod(result, p) == z && 
          (\forall integer d; result < d <= \at(value,Pre) ==> mod(d, p) != z)));
      loop invariant z == \at(z,Pre);
      loop invariant p == \at(p,Pre);
      loop invariant value == \at(value,Pre);
      loop assigns c, result;
    */
    for (int c = 1; c <= value; c++) {
        if ((c % p) == z) {
            result = c;
        }
    }

    return result;
}
