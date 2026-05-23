
/*@
  // No extra predicate needed for these simple arithmetic invariants.
  // We still provide an (unused) trivial predicate to satisfy the slot possibility.
  predicate trivial_true = \true;
*/
        
void foo122_c47(int mid) {

    int lo;
    int hi;

    lo = 0;
    hi = 2 * mid;

    /*@
      loop invariant (\at(mid,Pre) > 0) ==> (lo + mid == \at(mid,Pre));
      loop invariant (\at(mid,Pre) > 0) ==> (0 <= lo && lo <= \at(mid,Pre));
      loop invariant (\at(mid,Pre) > 0) ==> (0 <= mid && mid <= \at(mid,Pre));
      loop invariant (\at(mid,Pre) > 0) ==> (hi == 2 * \at(mid,Pre) - lo);
      loop invariant (!(\at(mid,Pre) > 0)) ==> ((hi == 2 * \at(mid,Pre))&&(lo == 0)&&(mid == \at(mid,Pre)));
      loop assigns lo, hi, mid;
    */
    while(mid > 0){
       lo = lo + 1;
       hi = hi - 1;
       mid = mid - 1;
    }
}
