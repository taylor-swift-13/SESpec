#include <limits.h>



/*@requires a_len >= 0;
  requires \valid_read(a + (0 .. a_len - 1));
  requires \forall integer i, j; 0 <= i <= j < a_len ==> a[i] <= a[j];
  assigns \nothing;
  ensures 0 <= \result < a_len ==> a[\result] == x;
  ensures 0 <= \result < a_len ==> (\result == 0 || a[\result - 1] != x);
  ensures 0 <= \result < a_len ==> \forall integer i; 0 <= i < \result ==> a[i] <= x;
  ensures 0 <= \result < a_len ==> \forall integer i; \result < i < a_len ==> a[i] >= x;
  ensures \result == -1 ==> \forall integer i; 0 <= i < a_len ==> a[i] <= x || a[i] >= x;
  ensures \result == -1 ==> \forall integer i; 0 <= i < a_len ==> a[i] <= x || a[i] >= x;
  ensures \result == -1 || (0 <= \result < a_len);
  ensures \result == -1 || a[\result] == x;*/
int stub_A(int * a, int a_len, int x);

/*@loop invariant low == 0 || high == a_len - 1 || a[low - 1] < a[high + 1];
        loop invariant low == 0 || a[low - 1] < x;
        loop invariant low <= a_len || high + 1 <= a_len;
        loop invariant high == a_len - 1 || a[high + 1] >= x;
        loop invariant high < a_len;
        loop invariant high + 1 <= a_len;
        loop invariant high + 1 <= a_len || low <= high + 1;
        loop invariant high + 1 <= a_len || 0 <= high + 1;
        loop invariant 0 <= low;
        loop invariant 0 <= low || high < 0;
        loop invariant -1 <= high || high + 1 <= a_len;
        loop assigns low;
        loop assigns high;*/
int stub_B(int * a, int a_len, int x);

/*@loop invariant low == 0 || high == a_len - 1 || a[low - 1] < a[high + 1];
        loop invariant low == 0 || a[low - 1] < x;
        loop invariant low <= a_len || high + 1 <= a_len;
        loop invariant high == a_len - 1 || a[high + 1] >= x;
        loop invariant high < a_len;
        loop invariant high + 1 <= a_len;
        loop invariant high + 1 <= a_len || low <= high + 1;
        loop invariant high + 1 <= a_len || 0 <= high + 1;
        loop invariant 0 <= low;
        loop invariant 0 <= low || high < 0;
        loop invariant -1 <= high || high + 1 <= a_len;
        loop assigns low;
        loop assigns high;*/
int check_A_implies_B(int * a, int a_len, int x) {
    return stub_A(a, a_len, x);
}

/*@requires a_len >= 0;
  requires \valid_read(a + (0 .. a_len - 1));
  requires \forall integer i, j; 0 <= i <= j < a_len ==> a[i] <= a[j];
  assigns \nothing;
  ensures 0 <= \result < a_len ==> a[\result] == x;
  ensures 0 <= \result < a_len ==> (\result == 0 || a[\result - 1] != x);
  ensures 0 <= \result < a_len ==> \forall integer i; 0 <= i < \result ==> a[i] <= x;
  ensures 0 <= \result < a_len ==> \forall integer i; \result < i < a_len ==> a[i] >= x;
  ensures \result == -1 ==> \forall integer i; 0 <= i < a_len ==> a[i] <= x || a[i] >= x;
  ensures \result == -1 ==> \forall integer i; 0 <= i < a_len ==> a[i] <= x || a[i] >= x;
  ensures \result == -1 || (0 <= \result < a_len);
  ensures \result == -1 || a[\result] == x;*/
int check_B_implies_A(int * a, int a_len, int x) {
    return stub_B(a, a_len, x);
}
