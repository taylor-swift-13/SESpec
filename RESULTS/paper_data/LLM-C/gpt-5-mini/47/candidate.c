/*@
    requires \true;
    assigns \nothing;
    behavior positive:
        assumes \old(mid) > 0;
        ensures lo == \old(mid);
        ensures hi == \old(mid);
    behavior non_positive:
        assumes \old(mid) <= 0;
        ensures lo == 0;
        ensures hi == 2 * \old(mid);
    complete behaviors positive, non_positive;
    disjoint behaviors positive, non_positive;
*/
void foo145(int mid) {

    int lo;
    int hi;

    lo = 0;
    hi = 2 * mid;

    /*@
        loop invariant lo >= 0;
        loop invariant hi + lo == 2 * \old(mid);
        loop invariant mid == \old(mid) - lo;
        loop assigns lo, hi, mid;
        loop variant mid;
    */
    while(mid > 0){
       lo = lo + 1;
       hi = hi - 1;
       mid = mid - 1;
      }

  }
