#include <limits.h>


/*@
  logic integer count_eq;(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  assigns \nothing;
  ensures \result >= leftElement;*/
int stub_A(int * a, int a_len, int leftElement, int rightElement);

/*@loop invariant leftElement <= i;
        loop invariant j <= rightElement;
        loop assigns j;
        loop assigns i;*/
int stub_B(int * a, int a_len, int leftElement, int rightElement);

/*@loop invariant leftElement <= i;
        loop invariant j <= rightElement;
        loop assigns j;
        loop assigns i;*/
int check_A_implies_B(int * a, int a_len, int leftElement, int rightElement) {
    return stub_A(a, a_len, leftElement, rightElement);
}

/*@requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  assigns \nothing;
  ensures \result >= leftElement;*/
int check_B_implies_A(int * a, int a_len, int leftElement, int rightElement) {
    return stub_B(a, a_len, leftElement, rightElement);
}
