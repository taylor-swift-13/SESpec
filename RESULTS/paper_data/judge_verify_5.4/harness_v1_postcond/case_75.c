#include <limits.h>


/*@
  logic integer count_div9(integer l) =
    l <= 0 ? 0 : count_div9(l - 1) + ((l - 1) % 9 == 0 ? 1 : 0);
*/

/*@ logic integer count_div8_only(integer l) =
    l <= 0 ? 0 : count_div8_only(l - 1) + (((l - 1) % 9 != 0 && (l - 1) % 8 == 0) ? 1 : 0);

/*@ logic integer count_div7_only(integer l) =
    l <= 0 ? 0 : count_div7_only(l - 1) + (((l - 1) % 9 != 0 && (l - 1) % 8 != 0 && (l - 1) % 7 == 0) ? 1 : 0);

/*@ logic integer count_div6_only(integer l) =
    l <= 0 ? 0 : count_div6_only(l - 1) + (((l - 1) % 9 != 0 && (l - 1) % 8 != 0 && (l - 1) % 7 != 0 && (l - 1) % 6 == 0) ? 1 : 0);

/*@ logic integer count_div5_only(integer l) =
    l <= 0 ? 0 : count_div5_only(l - 1) + (((l - 1) % 9 != 0 && (l - 1) % 8 != 0 && (l - 1) % 7 != 0 && (l - 1) % 6 != 0 && (l - 1) % 5 == 0) ? 1 : 0);

/*@ logic integer count_div4_only(integer l) =
    l <= 0 ? 0 : count_div4_only(l - 1) + (((l - 1) % 9 != 0 && (l - 1) % 8 != 0 && (l - 1) % 7 != 0 && (l - 1) % 6 != 0 && (l - 1) % 5 != 0 && (l - 1) % 4 == 0) ? 1 : 0);

/*@ logic integer count_div3_only(integer l) =
    l <= 0 ? 0 : count_div3_only(l - 1) + (((l - 1) % 9 != 0 && (l - 1) % 8 != 0 && (l - 1) % 7 != 0 && (l - 1) % 6 != 0 && (l - 1) % 5 != 0 && (l - 1) % 4 != 0 && (l - 1) % 3 == 0) ? 1 : 0);

/*@ logic integer count_div2_only(integer l) =
    l <= 0 ? 0 : count_div2_only(l - 1) + (((l - 1) % 9 != 0 && (l - 1) % 8 != 0 && (l - 1) % 7 != 0 && (l - 1) % 6 != 0 && (l - 1) % 5 != 0 && (l - 1) % 4 != 0 && (l - 1) % 3 != 0 && (l - 1) % 2 == 0) ? 1 : 0);

/*@ logic integer count_other(integer l) =
    l <= 0 ? 0 : count_other(l - 1) + (((l - 1) % 9 != 0 && (l - 1) % 8 != 0 && (l - 1) % 7 != 0 && (l - 1) % 6 != 0 && (l - 1) % 5 != 0 && (l - 1) % 4 != 0 && (l - 1) % 3 != 0 && (l - 1) % 2 != 0) ? 1 : 0);

/*@loop invariant 0 <= l <= n;
      loop invariant 0 <= j <= n;
      loop invariant 0 <= i <= n;
      loop invariant 0 <= k <= n;
      loop invariant 0 <= v4 <= n;
      loop invariant 0 <= v3 <= n;
      loop invariant 0 <= v2 <= n;
      loop invariant 0 <= v1 <= n;
      loop invariant 0 <= v5 <= n;
      loop invariant 0 <= v6 <= n;
      loop invariant v6 == count_div9(l);
      loop invariant v5 == count_div8_only(l);
      loop invariant v1 == count_div7_only(l);
      loop invariant v2 == count_div6_only(l);
      loop invariant v3 == count_div5_only(l);
      loop invariant v4 == count_div4_only(l);
      loop invariant i == count_div3_only(l);
      loop invariant j == count_div2_only(l);
      loop invariant k == count_other(l);
      loop invariant l == v6 + v5 + v1 + v2 + v3 + v4 + i + j + k;
      loop invariant (l < n) ==> (l % 9 == 0 || l % 8 == 0 || l % 7 == 0 || l % 6 == 0 || l % 5 == 0 || l % 4 == 0 || l % 3 == 0 || l % 2 == 0 || l % 2 != 0);
      loop invariant (l == 0) ==> (v6 == 0 && v5 == 0 && v1 == 0 && v2 == 0 && v3 == 0 && v4 == 0 && i == 0 && j == 0 && k == 0);
      loop invariant n == \at(n,Pre);
      loop assigns v6, v5, v1, v2, v3, v4, i, j, k, l;*/
void stub_A(unsigned int n);

/*@loop invariant l <= n;
    loop invariant i >= 0 && j >= 0 && k >= 0 && v1 >= 0 && v2 >= 0 && v3 >= 0 && v4 >= 0 && v5 >= 0 && v6 >= 0;
    loop invariant i + j + k + v1 + v2 + v3 + v4 + v5 + v6 == l;
    loop invariant 0 <= v6;
    loop invariant 0 <= v5;
    loop invariant 0 <= v4;
    loop invariant 0 <= v3;
    loop invariant 0 <= v2;
    loop invariant 0 <= v1;
    loop invariant 0 <= l;
    loop invariant 0 <= k;
    loop invariant 0 <= j;
    loop invariant 0 <= i;
    loop assigns v6;
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

/*@loop invariant l <= n;
    loop invariant i >= 0 && j >= 0 && k >= 0 && v1 >= 0 && v2 >= 0 && v3 >= 0 && v4 >= 0 && v5 >= 0 && v6 >= 0;
    loop invariant i + j + k + v1 + v2 + v3 + v4 + v5 + v6 == l;
    loop invariant 0 <= v6;
    loop invariant 0 <= v5;
    loop invariant 0 <= v4;
    loop invariant 0 <= v3;
    loop invariant 0 <= v2;
    loop invariant 0 <= v1;
    loop invariant 0 <= l;
    loop invariant 0 <= k;
    loop invariant 0 <= j;
    loop invariant 0 <= i;
    loop assigns v6;
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
      loop invariant 0 <= j <= n;
      loop invariant 0 <= i <= n;
      loop invariant 0 <= k <= n;
      loop invariant 0 <= v4 <= n;
      loop invariant 0 <= v3 <= n;
      loop invariant 0 <= v2 <= n;
      loop invariant 0 <= v1 <= n;
      loop invariant 0 <= v5 <= n;
      loop invariant 0 <= v6 <= n;
      loop invariant v6 == count_div9(l);
      loop invariant v5 == count_div8_only(l);
      loop invariant v1 == count_div7_only(l);
      loop invariant v2 == count_div6_only(l);
      loop invariant v3 == count_div5_only(l);
      loop invariant v4 == count_div4_only(l);
      loop invariant i == count_div3_only(l);
      loop invariant j == count_div2_only(l);
      loop invariant k == count_other(l);
      loop invariant l == v6 + v5 + v1 + v2 + v3 + v4 + i + j + k;
      loop invariant (l < n) ==> (l % 9 == 0 || l % 8 == 0 || l % 7 == 0 || l % 6 == 0 || l % 5 == 0 || l % 4 == 0 || l % 3 == 0 || l % 2 == 0 || l % 2 != 0);
      loop invariant (l == 0) ==> (v6 == 0 && v5 == 0 && v1 == 0 && v2 == 0 && v3 == 0 && v4 == 0 && i == 0 && j == 0 && k == 0);
      loop invariant n == \at(n,Pre);
      loop assigns v6, v5, v1, v2, v3, v4, i, j, k, l;*/
void check_B_implies_A(unsigned int n) {
    stub_B(n);
}
