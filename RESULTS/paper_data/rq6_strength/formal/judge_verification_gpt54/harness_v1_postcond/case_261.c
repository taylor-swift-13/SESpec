#include <limits.h>



/*@requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  assigns \nothing;
  ensures a_len <= 0 ==> \result == 0;
  ensures a_len > 0 ==> 0 <= \result <= a_len;
  ensures a == \at(a,Pre);
  ensures x == \at(x,Pre);
  ensures a_len == \at(a_len,Pre);
  ensures \result == (a_len <= 0 ? 0 : \result);*/
int stub_A(int * a, int a_len, int x);

/*@loop invariant j == a_len - 1 || a[j+1] >= x;
        loop invariant j == a_len - 1 || a[j+1] > x;
        loop invariant j < a_len;
        loop invariant i == 0 || a[i-1] <= x;
        loop invariant i == 0 || a[i-1] < x;
        loop invariant 0 <= i;
        loop assigns j;
        loop assigns i;*/
int stub_B(int * a, int a_len, int x);

/*@loop invariant j == a_len - 1 || a[j+1] >= x;
        loop invariant j == a_len - 1 || a[j+1] > x;
        loop invariant j < a_len;
        loop invariant i == 0 || a[i-1] <= x;
        loop invariant i == 0 || a[i-1] < x;
        loop invariant 0 <= i;
        loop assigns j;
        loop assigns i;*/
int check_A_implies_B(int * a, int a_len, int x) {
    return stub_A(a, a_len, x);
}

/*@requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  assigns \nothing;
  ensures a_len <= 0 ==> \result == 0;
  ensures a_len > 0 ==> 0 <= \result <= a_len;
  ensures a == \at(a,Pre);
  ensures x == \at(x,Pre);
  ensures a_len == \at(a_len,Pre);
  ensures \result == (a_len <= 0 ? 0 : \result);*/
int check_B_implies_A(int * a, int a_len, int x) {
    return stub_B(a, a_len, x);
}
