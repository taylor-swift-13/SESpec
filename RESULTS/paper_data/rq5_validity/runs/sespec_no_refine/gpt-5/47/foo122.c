
/*@
  predicate pre_state_inited(integer mid_pre, integer lo, integer hi, integer mid) =
    (hi == 2 * mid_pre) && (lo == 0) && (mid == mid_pre);
*/

void foo122(int mid) {

    int lo;
    int hi;

    lo = 0;
    hi = 2 * mid;

    /*@
      loop invariant (\at(mid,Pre) > 0) ==> (mid >= 0);
      loop invariant (\at(mid,Pre) > 0) ==> (lo == \at(mid,Pre) - mid);
      loop invariant (!(\at(mid,Pre) > 0)) ==> ((hi == 2 * \at(mid,Pre))&&(lo == 0)&&(mid == \at(mid,Pre)));
      loop assigns lo, hi, mid;
    */
    while(mid > 0){
       lo = lo + 1;
       hi = hi - 1;
       mid = mid - 1;
    }

}
