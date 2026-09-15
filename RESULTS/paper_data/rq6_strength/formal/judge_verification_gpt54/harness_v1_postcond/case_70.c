#include <limits.h>



/*@loop invariant 0 <= l <= n;
      loop invariant 0 <= j <= l;
      loop invariant 0 <= i <= l;
      loop invariant 0 <= k <= l;
      loop invariant 0 <= v4 <= l;
      loop invariant v4 + i + j + k == l;
      loop invariant j + i + k + v4 <= n;
      loop invariant l >= v4;
      loop invariant l >= i;
      loop invariant l >= j;
      loop invariant l >= k;
      loop invariant (0 < \at(n,Pre)) ==> (v4 + i + j + k == l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= j <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= i <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= k <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= v4 <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= l <= n);
      loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(v4 == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
      loop invariant n == \at(n,Pre);
      loop assigns v4, i, j, k, l;*/
void stub_A(unsigned int n);

/*@loop invariant l <= n;
    loop invariant k <= l;
    loop invariant i >= 0 && j >= 0 && k >= 0 && v4 >= 0;
    loop invariant i + j + k + v4 == l;
    loop invariant i + j + k + v4 <= l;
    loop invariant 0 <= v4;
    loop invariant 0 <= l;
    loop invariant 0 <= k;
    loop invariant 0 <= j;
    loop invariant 0 <= i;
    loop assigns v4;
    loop assigns l;
    loop assigns k;
    loop assigns j;
    loop assigns i;*/
void stub_B(unsigned int n);

/*@loop invariant l <= n;
    loop invariant k <= l;
    loop invariant i >= 0 && j >= 0 && k >= 0 && v4 >= 0;
    loop invariant i + j + k + v4 == l;
    loop invariant i + j + k + v4 <= l;
    loop invariant 0 <= v4;
    loop invariant 0 <= l;
    loop invariant 0 <= k;
    loop invariant 0 <= j;
    loop invariant 0 <= i;
    loop assigns v4;
    loop assigns l;
    loop assigns k;
    loop assigns j;
    loop assigns i;*/
void check_A_implies_B(unsigned int n) {
    stub_A(n);
}

/*@loop invariant 0 <= l <= n;
      loop invariant 0 <= j <= l;
      loop invariant 0 <= i <= l;
      loop invariant 0 <= k <= l;
      loop invariant 0 <= v4 <= l;
      loop invariant v4 + i + j + k == l;
      loop invariant j + i + k + v4 <= n;
      loop invariant l >= v4;
      loop invariant l >= i;
      loop invariant l >= j;
      loop invariant l >= k;
      loop invariant (0 < \at(n,Pre)) ==> (v4 + i + j + k == l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= j <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= i <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= k <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= v4 <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= l <= n);
      loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(v4 == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
      loop invariant n == \at(n,Pre);
      loop assigns v4, i, j, k, l;*/
void check_B_implies_A(unsigned int n) {
    stub_B(n);
}
