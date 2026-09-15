
/*@
  logic integer initial_mid = \at(mid,Pre);
*/

/*@
  requires initial_mid > 0;
  ensures lo == initial_mid;
  ensures hi == 0;
  ensures mid == 0;
*/
void foo122(int mid) {

    int lo;
    int hi;

    lo = 0;
    hi = 2 * mid;

    /*@
      loop invariant mid >= 0;
      loop invariant lo == initial_mid - mid;
      loop invariant hi == 2 * mid;
      loop invariant initial_mid == lo + mid;
      loop assigns lo, hi, mid;
    */
    while(mid > 0){
       lo = lo + 1;
       hi = hi - 1;
       mid = mid - 1;
    }
}
