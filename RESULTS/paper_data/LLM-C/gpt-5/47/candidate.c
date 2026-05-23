/*@ 
  requires \true;
  assigns \nothing;

  behavior pos:
    assumes \old(mid) > 0;
    ensures mid == 0;

  behavior nonpos:
    assumes \old(mid) <= 0;
    ensures mid == \old(mid);

  complete behaviors;
  disjoint behaviors;
*/
void foo145(int mid) {

    int lo;
    int hi;

    lo = 0;
    hi = 2 * mid;

    /*@
      loop invariant lo == \at(mid,Pre) - mid;
      loop invariant hi + lo == 2 * \at(mid,Pre);
      loop assigns lo, hi, mid;
      loop variant mid > 0 ? mid : 0;
    */
    while(mid > 0){
       lo = lo + 1;
       hi = hi - 1;
       mid = mid - 1;
      }

    /*@ assert hi + lo == 2 * \at(mid,Pre); */
    /*@ assert (\at(mid,Pre) > 0 ==> mid == 0) && (\at(mid,Pre) <= 0 ==> mid == \at(mid,Pre)); */

  }
