#include <limits.h>



/*@requires array >= 0;
  requires array > 0 ==> \valid_read(data + (0 .. array - 1));
  assigns \nothing;
  ensures array <= 0 ==> \result == 0;
  ensures array > 0 ==> 0 <= \result <= array;
  
  ensures \result >= 0;*/
int stub_A(int * data, int data_len, int array);

/*@loop invariant top == array - 1 || data[top] >= data[top + 1];
		loop invariant top <= array - 1;
		loop invariant top < array;
		loop invariant found == 0 || data[found - 1] <= data[found];
		loop invariant found == 0 || data[found - 1] < data[found];
		loop invariant \forall integer k; found <= k < top ==> data[k] <= data[k + 1] || data[k] >= data[k + 1];
		loop invariant \forall integer k; found <= k < top ==> data[k] < data[k + 1] || data[k] >= data[k + 1];
		loop invariant \exists integer k; found <= k <= top ==> data[k] >= data[k + 1];
		loop invariant 0 <= found;
		loop assigns top;
		loop assigns found;*/
int stub_B(int * data, int data_len, int array);

/*@loop invariant top == array - 1 || data[top] >= data[top + 1];
		loop invariant top <= array - 1;
		loop invariant top < array;
		loop invariant found == 0 || data[found - 1] <= data[found];
		loop invariant found == 0 || data[found - 1] < data[found];
		loop invariant \forall integer k; found <= k < top ==> data[k] <= data[k + 1] || data[k] >= data[k + 1];
		loop invariant \forall integer k; found <= k < top ==> data[k] < data[k + 1] || data[k] >= data[k + 1];
		loop invariant \exists integer k; found <= k <= top ==> data[k] >= data[k + 1];
		loop invariant 0 <= found;
		loop assigns top;
		loop assigns found;*/
int check_A_implies_B(int * data, int data_len, int array) {
    return stub_A(data, data_len, array);
}

/*@requires array >= 0;
  requires array > 0 ==> \valid_read(data + (0 .. array - 1));
  assigns \nothing;
  ensures array <= 0 ==> \result == 0;
  ensures array > 0 ==> 0 <= \result <= array;
  
  ensures \result >= 0;*/
int check_B_implies_A(int * data, int data_len, int array) {
    return stub_B(data, data_len, array);
}
