#include <limits.h>



/*@loop invariant (\at(mid,Pre) > 0) ==> (lo + mid == \at(mid,Pre));
      loop invariant (\at(mid,Pre) > 0) ==> (hi + lo == 2 * \at(mid,Pre));
      loop invariant (\at(mid,Pre) > 0) ==> (lo >= 0);
      loop invariant (\at(mid,Pre) > 0) ==> (hi >= 0);
      loop invariant (!(\at(mid,Pre) > 0)) ==> ((hi == 2 * \at(mid,Pre))&&(lo == 0)&&(mid == \at(mid,Pre)));
      loop assigns lo, hi, mid;*/
void stub_A(int mid);

/*@loop invariant lo == 0 + (2 * (hi - 2 * mid)) / 2;
    loop invariant lo + mid == hi - mid;
    loop invariant lo + mid == 0 + \at(mid,Pre);
    loop invariant lo + hi == 2 * (lo + mid);
    loop invariant hi == 2*mid + lo;
    loop invariant hi == 2 * mid + lo;
    loop invariant 0 <= lo;
    loop assigns mid;
    loop assigns lo;
    loop assigns hi;*/
void stub_B(int mid);

/*@loop invariant lo == 0 + (2 * (hi - 2 * mid)) / 2;
    loop invariant lo + mid == hi - mid;
    loop invariant lo + mid == 0 + \at(mid,Pre);
    loop invariant lo + hi == 2 * (lo + mid);
    loop invariant hi == 2*mid + lo;
    loop invariant hi == 2 * mid + lo;
    loop invariant 0 <= lo;
    loop assigns mid;
    loop assigns lo;
    loop assigns hi;*/
void check_A_implies_B(int mid) {
    stub_A(mid);
}

/*@loop invariant (\at(mid,Pre) > 0) ==> (lo + mid == \at(mid,Pre));
      loop invariant (\at(mid,Pre) > 0) ==> (hi + lo == 2 * \at(mid,Pre));
      loop invariant (\at(mid,Pre) > 0) ==> (lo >= 0);
      loop invariant (\at(mid,Pre) > 0) ==> (hi >= 0);
      loop invariant (!(\at(mid,Pre) > 0)) ==> ((hi == 2 * \at(mid,Pre))&&(lo == 0)&&(mid == \at(mid,Pre)));
      loop assigns lo, hi, mid;*/
void check_B_implies_A(int mid) {
    stub_B(mid);
}
