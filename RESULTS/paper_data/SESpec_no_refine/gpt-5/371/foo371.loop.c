
/*@
  predicate is_match(integer c, integer p, integer z) = (c % p) == z;
*/

/*@
  predicate last_match_up_to(integer c, integer p, integer z, integer r) =
    (r == 0 &&
     (\forall integer k; 1 <= k <= c ==> !is_match(k, p, z)))
    ||
    (r >= 1 &&
     r <= c &&
     is_match(r, p, z) &&
     (\forall integer k; r < k && k <= c ==> !is_match(k, p, z)));
*/

int foo371(int value, int p, int z) {

    int result = 0;

    /*@
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
