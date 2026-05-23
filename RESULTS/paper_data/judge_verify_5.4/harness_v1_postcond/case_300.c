#include <limits.h>



/*@requires \valid(&array[0] + (0..array_len-1));
  requires 0 < Array <= array_len;
  requires \forall integer i; 0 <= i < Array - 1 ==> array[i] < array[i + 1];
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  assigns \nothing;
  ensures 0 <= \result < Array;*/
int stub_A(int * array, int array_len, int Array);

/*@loop invariant top == Array - 1 || array[top] >= array[top + 1];
		loop invariant found == 0 || array[found - 1] <= array[found];
		loop invariant top == Array - 1 || array[top] >= array[top+1];
		loop invariant top <= Array - 1;
		loop invariant top < Array;
		loop invariant found == 0 || array[found-1] <= array[found];
		loop invariant found == 0 || array[found-1] < array[found];
		loop invariant found == 0 || array[found-1] < array[found] || array[found-1] >= array[found];
		loop invariant array_len == array_len;
		loop invariant \forall integer k; found <= k < top ==> array[k] <= array[k+1] || array[k] >= array[k+1];
		loop invariant \forall integer k; found <= k < top ==> array[k] < array[k+1] || array[k] >= array[k+1];
		loop invariant \forall integer k; found <= k < top ==> (array[k] < array[k+1] || array[k] >= array[k+1]);
		loop invariant \forall integer k; 0 <= k < top ==> array[k] <= array[k+1] || array[k] >= array[k+1];
		loop invariant \exists integer k; found <= k;
		loop invariant \exists integer k; 0 <= k;
		loop invariant 0 <= found;
		loop assigns top;
		loop assigns found;*/
int stub_B(int * array, int array_len, int Array);

/*@loop invariant top == Array - 1 || array[top] >= array[top + 1];
		loop invariant found == 0 || array[found - 1] <= array[found];
		loop invariant top == Array - 1 || array[top] >= array[top+1];
		loop invariant top <= Array - 1;
		loop invariant top < Array;
		loop invariant found == 0 || array[found-1] <= array[found];
		loop invariant found == 0 || array[found-1] < array[found];
		loop invariant found == 0 || array[found-1] < array[found] || array[found-1] >= array[found];
		loop invariant array_len == array_len;
		loop invariant \forall integer k; found <= k < top ==> array[k] <= array[k+1] || array[k] >= array[k+1];
		loop invariant \forall integer k; found <= k < top ==> array[k] < array[k+1] || array[k] >= array[k+1];
		loop invariant \forall integer k; found <= k < top ==> (array[k] < array[k+1] || array[k] >= array[k+1]);
		loop invariant \forall integer k; 0 <= k < top ==> array[k] <= array[k+1] || array[k] >= array[k+1];
		loop invariant \exists integer k; found <= k;
		loop invariant \exists integer k; 0 <= k;
		loop invariant 0 <= found;
		loop assigns top;
		loop assigns found;*/
int check_A_implies_B(int * array, int array_len, int Array) {
    return stub_A(array, array_len, Array);
}

/*@requires \valid(&array[0] + (0..array_len-1));
  requires 0 < Array <= array_len;
  requires \forall integer i; 0 <= i < Array - 1 ==> array[i] < array[i + 1];
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  assigns \nothing;
  ensures 0 <= \result < Array;*/
int check_B_implies_A(int * array, int array_len, int Array) {
    return stub_B(array, array_len, Array);
}
