
/*@
  requires \true;
*/
void foo47(int mid) {

    int lo;
    int hi;

    lo = 0;
    hi = 2 * mid;

    /*@
      loop invariant (\at(mid,Pre) > 0) ==> (0 <= lo);
      loop invariant (\at(mid,Pre) > 0) ==> (lo <= \at(mid,Pre));
      loop invariant (\at(mid,Pre) > 0) ==> (hi == 2 * \at(mid,Pre) - lo);
      loop invariant (\at(mid,Pre) > 0) ==> (mid == \at(mid,Pre) - lo);
      loop invariant (\at(mid,Pre) > 0) ==> (lo + mid == \at(mid,Pre));
      loop invariant (\at(mid,Pre) > 0) ==> (mid >= 0);
      loop invariant (\at(mid,Pre) > 0) ==> (hi >= 0);
      loop invariant (\at(mid,Pre) > 0) ==> ((mid == 0) ==> (lo == \at(mid,Pre) && hi == \at(mid,Pre)));
      loop invariant (\at(mid,Pre) > 0) ==> ((lo == 0) ==> (hi == 2 * \at(mid,Pre) && mid == \at(mid,Pre)));
      loop invariant (\at(mid,Pre) > 0) ==> ((hi == \at(mid,Pre)) <==> (mid == 0));
      loop invariant (\at(mid,Pre) > 0) ==> ((lo == \at(mid,Pre)) <==> (mid == 0));

      loop invariant (\at(mid,Pre) > 0) ==> (mid == \at(mid,Pre) - lo);
      loop invariant (\at(mid,Pre) > 0) ==> (0 <= lo);
      loop invariant (\at(mid,Pre) > 0) ==> (lo <= \at(mid,Pre));
      loop invariant (\at(mid,Pre) > 0) ==> (hi == 2 * \at(mid,Pre) - lo);
      loop invariant (\at(mid,Pre) > 0) ==> (hi >= 0);

      loop assigns lo, hi, mid;
    */
    while(mid > 0){
       lo = lo + 1;
       hi = hi - 1;
       mid = mid - 1;
    }

}
