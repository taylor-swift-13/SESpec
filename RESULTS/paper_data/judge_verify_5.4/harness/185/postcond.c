#include <limits.h>

/*@ requires a_len >= 0;
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
  ensures \result == -1 || a[\result] == x; */
int stub_A(int * a, int a_len, int x);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * a, int a_len, int x);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * a, int a_len, int x) {
    return stub_A(a, a_len, x);
}

/*@ requires a_len >= 0;
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
  ensures \result == -1 || a[\result] == x; */
int check_B_implies_A(int * a, int a_len, int x) {
    return stub_B(a, a_len, x);
}
