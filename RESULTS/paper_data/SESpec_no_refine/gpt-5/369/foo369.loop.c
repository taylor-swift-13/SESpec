
/*@ predicate exists_match_in_range(integer start, integer end, integer p, integer dy) =
      \exists integer k; start <= k <= end && (k % p) == dy;
*/

/*@
  requires \true;
*/
int foo369(int value, int p, int dy) {

    int result = 0;

    /*@
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
