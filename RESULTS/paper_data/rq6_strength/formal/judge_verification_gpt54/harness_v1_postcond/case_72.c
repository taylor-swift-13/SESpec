#include <limits.h>



/*@loop invariant 0 <= l <= n;
      loop invariant v2 + v3 + v4 + i + j + k == l;
      loop invariant (\forall integer t; 0 <= t < l ==>
                        (t % 6 == 0) || (t % 5 == 0) || (t % 4 == 0) ||
                        (t % 3 == 0) || (t % 2 == 0) ||
                        (!(t % 6 == 0) && !(t % 5 == 0) && !(t % 4 == 0) &&
                         !(t % 3 == 0) && !(t % 2 == 0)));
      loop invariant v2 <= l;
      loop invariant v3 <= l;
      loop invariant v4 <= l;
      loop invariant i <= l;
      loop invariant j <= l;
      loop invariant k <= l;
      loop invariant (0 < \at(n,Pre)) ==> (j <= \at(n,Pre));
      loop invariant (0 < \at(n,Pre)) ==> (i <= \at(n,Pre));
      loop invariant (0 < \at(n,Pre)) ==> (k <= \at(n,Pre));
      loop invariant (0 < \at(n,Pre)) ==> (v4 <= \at(n,Pre));
      loop invariant (0 < \at(n,Pre)) ==> (v3 <= \at(n,Pre));
      loop invariant (0 < \at(n,Pre)) ==> (v2 <= \at(n,Pre));
      loop invariant (0 < \at(n,Pre)) ==> (l <= \at(n,Pre));
      loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(v2 == 0)&&(v3 == 0)&&(v4 == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
      loop invariant n == \at(n,Pre);
      loop assigns v2, v3, v4, i, j, k, l;*/
void stub_A(unsigned int n);

/*@loop invariant v4 <= l;
    loop invariant v3 <= l;
    loop invariant v2 >= 0 && v3 >= 0 && v4 >= 0 && i >= 0 && j >= 0 && k >= 0;
    loop invariant v2 == (l + 5) / 6;
    loop invariant v2 <= l;
    loop invariant v2 <= l / 6 + 1;
    loop invariant l <= n;
    loop invariant k <= l;
    loop invariant j <= l;
    loop invariant i <= l;
    loop invariant i + j + k + v2 + v3 + v4 == l;
    loop invariant 0 <= l;
    loop assigns v4;
    loop assigns v3;
    loop assigns v2;
    loop assigns l;
    loop assigns k;
    loop assigns j;
    loop assigns i;*/
void stub_B(unsigned int n);

/*@loop invariant v4 <= l;
    loop invariant v3 <= l;
    loop invariant v2 >= 0 && v3 >= 0 && v4 >= 0 && i >= 0 && j >= 0 && k >= 0;
    loop invariant v2 == (l + 5) / 6;
    loop invariant v2 <= l;
    loop invariant v2 <= l / 6 + 1;
    loop invariant l <= n;
    loop invariant k <= l;
    loop invariant j <= l;
    loop invariant i <= l;
    loop invariant i + j + k + v2 + v3 + v4 == l;
    loop invariant 0 <= l;
    loop assigns v4;
    loop assigns v3;
    loop assigns v2;
    loop assigns l;
    loop assigns k;
    loop assigns j;
    loop assigns i;*/
void check_A_implies_B(unsigned int n) {
    stub_A(n);
}

/*@loop invariant 0 <= l <= n;
      loop invariant v2 + v3 + v4 + i + j + k == l;
      loop invariant (\forall integer t; 0 <= t < l ==>
                        (t % 6 == 0) || (t % 5 == 0) || (t % 4 == 0) ||
                        (t % 3 == 0) || (t % 2 == 0) ||
                        (!(t % 6 == 0) && !(t % 5 == 0) && !(t % 4 == 0) &&
                         !(t % 3 == 0) && !(t % 2 == 0)));
      loop invariant v2 <= l;
      loop invariant v3 <= l;
      loop invariant v4 <= l;
      loop invariant i <= l;
      loop invariant j <= l;
      loop invariant k <= l;
      loop invariant (0 < \at(n,Pre)) ==> (j <= \at(n,Pre));
      loop invariant (0 < \at(n,Pre)) ==> (i <= \at(n,Pre));
      loop invariant (0 < \at(n,Pre)) ==> (k <= \at(n,Pre));
      loop invariant (0 < \at(n,Pre)) ==> (v4 <= \at(n,Pre));
      loop invariant (0 < \at(n,Pre)) ==> (v3 <= \at(n,Pre));
      loop invariant (0 < \at(n,Pre)) ==> (v2 <= \at(n,Pre));
      loop invariant (0 < \at(n,Pre)) ==> (l <= \at(n,Pre));
      loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(v2 == 0)&&(v3 == 0)&&(v4 == 0)&&(k == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
      loop invariant n == \at(n,Pre);
      loop assigns v2, v3, v4, i, j, k, l;*/
void check_B_implies_A(unsigned int n) {
    stub_B(n);
}
