#include <limits.h>



/*@loop invariant 0 <= l <= n;
      loop invariant 0 <= j <= l;
      loop invariant 0 <= i <= l;
      loop invariant 0 <= k <= l;
      loop invariant 0 <= v4 <= l;
      loop invariant 0 <= v3 <= l;
      loop invariant 0 <= v2 <= l;
      loop invariant 0 <= v1 <= l;
      loop invariant 0 <= v5 <= l;
      loop invariant i + j + k + v1 + v2 + v3 + v4 + v5 == l;
      loop invariant v5 <= l;
      loop invariant v1 <= l;
      loop invariant v2 <= l;
      loop invariant v3 <= l;
      loop invariant v4 <= l;
      loop invariant i <= l;
      loop invariant j <= l;
      loop invariant k <= l;
      loop invariant n == \at(n,Pre);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= j <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= i <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= k <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= v4 <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= v3 <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= v2 <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= v1 <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= v5 <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= l <= n);
      loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(v5 == 0)&&(v1 == 0)&&(v2 == 0)&&(v3 == 0)&&(v4 == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
      loop assigns v5, v1, v2, v3, v4, i, j, k, l;*/
void stub_A(unsigned int n);

/*@loop invariant v5 <= l;
    loop invariant v4 <= l;
    loop invariant v3 <= l;
    loop invariant v2 <= l;
    loop invariant v1 >= 0 && v2 >= 0 && v3 >= 0 && v4 >= 0 && v5 >= 0;
    loop invariant v1 <= l;
    loop invariant l <= n;
    loop invariant i >= 0 && j >= 0 && k >= 0;
    loop invariant i >= 0 && j >= 0 && k >= 0 && v1 >= 0 && v2 >= 0 && v3 >= 0 && v4 >= 0 && v5 >= 0;
    loop invariant i + j + k + v1 + v2 + v3 + v4 + v5 == l;
    loop invariant 0 <= l;
    loop assigns v5;
    loop assigns v4;
    loop assigns v3;
    loop assigns v2;
    loop assigns v1;
    loop assigns l;
    loop assigns k;
    loop assigns j;
    loop assigns i;*/
void stub_B(unsigned int n);

/*@loop invariant v5 <= l;
    loop invariant v4 <= l;
    loop invariant v3 <= l;
    loop invariant v2 <= l;
    loop invariant v1 >= 0 && v2 >= 0 && v3 >= 0 && v4 >= 0 && v5 >= 0;
    loop invariant v1 <= l;
    loop invariant l <= n;
    loop invariant i >= 0 && j >= 0 && k >= 0;
    loop invariant i >= 0 && j >= 0 && k >= 0 && v1 >= 0 && v2 >= 0 && v3 >= 0 && v4 >= 0 && v5 >= 0;
    loop invariant i + j + k + v1 + v2 + v3 + v4 + v5 == l;
    loop invariant 0 <= l;
    loop assigns v5;
    loop assigns v4;
    loop assigns v3;
    loop assigns v2;
    loop assigns v1;
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
      loop invariant 0 <= v3 <= l;
      loop invariant 0 <= v2 <= l;
      loop invariant 0 <= v1 <= l;
      loop invariant 0 <= v5 <= l;
      loop invariant i + j + k + v1 + v2 + v3 + v4 + v5 == l;
      loop invariant v5 <= l;
      loop invariant v1 <= l;
      loop invariant v2 <= l;
      loop invariant v3 <= l;
      loop invariant v4 <= l;
      loop invariant i <= l;
      loop invariant j <= l;
      loop invariant k <= l;
      loop invariant n == \at(n,Pre);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= j <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= i <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= k <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= v4 <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= v3 <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= v2 <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= v1 <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= v5 <= l);
      loop invariant (0 < \at(n,Pre)) ==> (0 <= l <= n);
      loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(v5 == 0)&&(v1 == 0)&&(v2 == 0)&&(v3 == 0)&&(v4 == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
      loop assigns v5, v1, v2, v3, v4, i, j, k, l;*/
void check_B_implies_A(unsigned int n) {
    stub_B(n);
}
