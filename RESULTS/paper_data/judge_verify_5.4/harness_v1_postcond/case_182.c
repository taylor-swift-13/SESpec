#include <limits.h>



/*@requires a_len >= 0;
  requires \valid_read(a + (0 .. a_len - 1));
              
  ensures \result == -1 || (0 <= \result < a_len);
  ensures \result != -1 ==> a[\result] == x;
  ensures \result != -1 ==> (\result == a_len - 1 || a[\result + 1] != x);
  ensures \result == -1 || (0 <= \result < a_len);*/
int stub_A(int * a, int a_len, int x);

/*@loop invariant a_len > 0 ==> low <= a_len && -1 <= high < a_len;
        loop invariant a_len == 0 || (high == a_len - 1 || a[high + 1] != x);
        loop invariant mid >= 0 || mid == 0;
        loop invariant mid == 0 || 0 <= mid < a_len;
        loop invariant mid == 0 || (0 <= mid < a_len);
        loop invariant low >= 0 && high < a_len;
        loop invariant low == 0 || a[low - 1] <= x;
        loop invariant high == a_len - 1 || high + 1 >= 0;
        loop invariant high == a_len - 1 || a[high + 1] >= x;
        loop invariant high == a_len - 1 || a[high + 1] != x;
        loop invariant high < a_len;
        loop invariant high < a_len || high == -1;
        loop invariant a_len > 0 ==> low >= 0 && high < a_len;
        loop invariant a_len > 0 ==> low == 0 || a[low - 1] <= x;
        loop invariant a_len > 0 ==> low <= high + 1;
        loop invariant a_len > 0 ==> low <= a_len;
        loop invariant a_len > 0 ==> low <= a_len && high >= -1;
        loop invariant a_len > 0 ==> low <= a_len && high < a_len;
        loop invariant a_len > 0 ==> low <= a_len && -1 <= high;
        loop invariant a_len > 0 ==> high >= -1;
        loop invariant a_len > 0 ==> high == a_len - 1 || a[high + 1] >= x;
        loop invariant a_len > 0 ==> high == a_len - 1 || a[high + 1] > x;
        loop invariant a_len > 0 ==> high == a_len - 1 || a[high + 1] != x;
        loop invariant a_len > 0 ==> high < a_len;
        loop invariant a_len > 0 ==> 0 <= mid < a_len;
        loop invariant a_len > 0 ==> 0 <= low;
        loop invariant a_len > 0 ==> 0 <= low <= a_len;
        loop invariant a_len > 0 ==> 0 <= low <= a_len && -1 <= high < a_len;
        loop invariant a_len > 0 ==> 0 <= low && high < a_len;
        loop invariant a_len > 0 ==> 0 <= low && -1 <= high < a_len;
        loop invariant a_len > 0 ==> -1 <= high < a_len;
        loop invariant a_len > 0 ==> (low == 0 || a[low - 1] <= x);
        loop invariant a_len > 0 ==> (low == 0 || a[low - 1] <= x) && (high == a_len - 1 || a[high + 1] >= x);
        loop invariant a_len > 0 ==> (low <= high + 1);
        loop invariant a_len > 0 ==> (low <= a_len && high >= -1);
        loop invariant a_len > 0 ==> (low <= a_len && -1 <= high);
        loop invariant a_len > 0 ==> (low <= a_len && -1 <= high < a_len);
        loop invariant a_len > 0 ==> (high == a_len - 1 || a[high + 1] >= x);
        loop invariant a_len > 0 ==> (high == a_len - 1 || a[high + 1] > x);
        loop invariant a_len > 0 ==> (high == a_len - 1 || a[high + 1] != x);
        loop invariant a_len > 0 ==> (0 <= mid < a_len);
        loop invariant a_len > 0 ==> (0 <= low <= a_len);
        loop invariant a_len > 0 ==> (0 <= low && low <= a_len);
        loop invariant a_len > 0 ==> (0 <= low && high < a_len);
        loop invariant a_len > 0 ==> (0 <= low && -1 <= high < a_len);
        loop invariant a_len > 0 ==> (-1 <= high < a_len);
        loop invariant a_len > 0 ==> (-1 <= high && high < a_len);
        loop invariant a_len == 0 || (low == 0 || a[low - 1] <= x);
        loop invariant a_len == 0 || (high == a_len - 1 || a[high + 1] >= x);
        loop invariant a_len == 0 || (0 <= low && high < a_len);
        loop invariant a_len == 0 ==> low == 0 && high == -1;
        loop invariant a_len == 0 ==> high == -1;
        loop invariant 0 <= mid;
        loop invariant 0 <= mid || mid == 0;
        loop invariant 0 <= mid <= a_len - 1 || mid == 0;
        loop invariant 0 <= mid < a_len || mid == 0;
        loop invariant 0 <= low;
        loop invariant 0 <= low || low == 0;
        loop invariant 0 <= low && high < a_len;
        loop assigns mid;
        loop assigns low;
        loop assigns high;*/
int stub_B(int * a, int a_len, int x);

/*@loop invariant a_len > 0 ==> low <= a_len && -1 <= high < a_len;
        loop invariant a_len == 0 || (high == a_len - 1 || a[high + 1] != x);
        loop invariant mid >= 0 || mid == 0;
        loop invariant mid == 0 || 0 <= mid < a_len;
        loop invariant mid == 0 || (0 <= mid < a_len);
        loop invariant low >= 0 && high < a_len;
        loop invariant low == 0 || a[low - 1] <= x;
        loop invariant high == a_len - 1 || high + 1 >= 0;
        loop invariant high == a_len - 1 || a[high + 1] >= x;
        loop invariant high == a_len - 1 || a[high + 1] != x;
        loop invariant high < a_len;
        loop invariant high < a_len || high == -1;
        loop invariant a_len > 0 ==> low >= 0 && high < a_len;
        loop invariant a_len > 0 ==> low == 0 || a[low - 1] <= x;
        loop invariant a_len > 0 ==> low <= high + 1;
        loop invariant a_len > 0 ==> low <= a_len;
        loop invariant a_len > 0 ==> low <= a_len && high >= -1;
        loop invariant a_len > 0 ==> low <= a_len && high < a_len;
        loop invariant a_len > 0 ==> low <= a_len && -1 <= high;
        loop invariant a_len > 0 ==> high >= -1;
        loop invariant a_len > 0 ==> high == a_len - 1 || a[high + 1] >= x;
        loop invariant a_len > 0 ==> high == a_len - 1 || a[high + 1] > x;
        loop invariant a_len > 0 ==> high == a_len - 1 || a[high + 1] != x;
        loop invariant a_len > 0 ==> high < a_len;
        loop invariant a_len > 0 ==> 0 <= mid < a_len;
        loop invariant a_len > 0 ==> 0 <= low;
        loop invariant a_len > 0 ==> 0 <= low <= a_len;
        loop invariant a_len > 0 ==> 0 <= low <= a_len && -1 <= high < a_len;
        loop invariant a_len > 0 ==> 0 <= low && high < a_len;
        loop invariant a_len > 0 ==> 0 <= low && -1 <= high < a_len;
        loop invariant a_len > 0 ==> -1 <= high < a_len;
        loop invariant a_len > 0 ==> (low == 0 || a[low - 1] <= x);
        loop invariant a_len > 0 ==> (low == 0 || a[low - 1] <= x) && (high == a_len - 1 || a[high + 1] >= x);
        loop invariant a_len > 0 ==> (low <= high + 1);
        loop invariant a_len > 0 ==> (low <= a_len && high >= -1);
        loop invariant a_len > 0 ==> (low <= a_len && -1 <= high);
        loop invariant a_len > 0 ==> (low <= a_len && -1 <= high < a_len);
        loop invariant a_len > 0 ==> (high == a_len - 1 || a[high + 1] >= x);
        loop invariant a_len > 0 ==> (high == a_len - 1 || a[high + 1] > x);
        loop invariant a_len > 0 ==> (high == a_len - 1 || a[high + 1] != x);
        loop invariant a_len > 0 ==> (0 <= mid < a_len);
        loop invariant a_len > 0 ==> (0 <= low <= a_len);
        loop invariant a_len > 0 ==> (0 <= low && low <= a_len);
        loop invariant a_len > 0 ==> (0 <= low && high < a_len);
        loop invariant a_len > 0 ==> (0 <= low && -1 <= high < a_len);
        loop invariant a_len > 0 ==> (-1 <= high < a_len);
        loop invariant a_len > 0 ==> (-1 <= high && high < a_len);
        loop invariant a_len == 0 || (low == 0 || a[low - 1] <= x);
        loop invariant a_len == 0 || (high == a_len - 1 || a[high + 1] >= x);
        loop invariant a_len == 0 || (0 <= low && high < a_len);
        loop invariant a_len == 0 ==> low == 0 && high == -1;
        loop invariant a_len == 0 ==> high == -1;
        loop invariant 0 <= mid;
        loop invariant 0 <= mid || mid == 0;
        loop invariant 0 <= mid <= a_len - 1 || mid == 0;
        loop invariant 0 <= mid < a_len || mid == 0;
        loop invariant 0 <= low;
        loop invariant 0 <= low || low == 0;
        loop invariant 0 <= low && high < a_len;
        loop assigns mid;
        loop assigns low;
        loop assigns high;*/
int check_A_implies_B(int * a, int a_len, int x) {
    return stub_A(a, a_len, x);
}

/*@requires a_len >= 0;
  requires \valid_read(a + (0 .. a_len - 1));
              
  ensures \result == -1 || (0 <= \result < a_len);
  ensures \result != -1 ==> a[\result] == x;
  ensures \result != -1 ==> (\result == a_len - 1 || a[\result + 1] != x);
  ensures \result == -1 || (0 <= \result < a_len);*/
int check_B_implies_A(int * a, int a_len, int x) {
    return stub_B(a, a_len, x);
}
