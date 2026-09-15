
/*@
  requires mid >= 0;
*/
void foo47(int mid) {

    int lo;
    int hi;

    lo = 0;
    hi = 2 * mid;

    /*@
      loop invariant 0 <= lo;
      loop invariant 0 <= mid;
      loop invariant 0 <= hi;
      loop invariant lo == \at(mid,Pre) - mid;
      loop invariant hi == \at(mid,Pre) + mid;
      loop invariant (\at(mid,Pre) == 0) || (mid > 0 ==> lo < \at(mid,Pre));
      loop invariant (\at(mid,Pre) > 0) ==> (lo >= 1 || mid + lo == \at(mid,Pre));
      loop invariant (\at(mid,Pre) > 0) ==> (mid >= 0 && lo >= 0 && hi >= 0);
      loop invariant (\at(mid,Pre) > 0) ==> (mid <= \at(mid,Pre));
      loop invariant (!(\at(mid,Pre) > 0)) ==> ((hi == 2 * \at(mid,Pre))&&(lo == 0)&&(mid == \at(mid,Pre)));
      loop assigns lo, hi, mid;
    */
    while(mid > 0){
       lo = lo + 1;
       hi = hi - 1;
       mid = mid - 1;
    }

}
