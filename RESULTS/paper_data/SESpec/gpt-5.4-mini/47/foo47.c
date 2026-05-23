
void foo47(int mid) {

    int lo;
    int hi;

    lo = 0;
    hi = 2 * mid;

    /*@
      loop invariant (\at(mid,Pre) > 0) ==> (lo + mid == \at(mid,Pre));
      loop invariant (\at(mid,Pre) > 0) ==> (hi + lo == 2 * \at(mid,Pre));
      loop invariant (\at(mid,Pre) > 0) ==> (lo >= 0);
      loop invariant (\at(mid,Pre) > 0) ==> (hi >= 0);
      loop invariant (!(\at(mid,Pre) > 0)) ==> ((hi == 2 * \at(mid,Pre))&&(lo == 0)&&(mid == \at(mid,Pre)));
      loop assigns lo, hi, mid;
    */
    while(mid > 0){
       lo = lo + 1;
       hi = hi - 1;
       mid = mid - 1;
    }
}
