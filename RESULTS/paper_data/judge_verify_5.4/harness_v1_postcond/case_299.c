#include <limits.h>


/*@ logic integer max_int(integer a, integer b) = a > b ? a : b; */

/*@assigns \nothing;
  ensures 0 < \at(array,Pre) - 1 ==> \result <= (\at(array,Pre) - 1);
  ensures !(0 < \at(array,Pre) - 1) ==> \result == 0;*/
int stub_A(int * data, int data_len, int array);

/*@loop invariant top <= array - 1;
		loop invariant top < array;
		loop invariant top < array ==> data[top] == data[top];
		loop invariant top + 1 <= array;
		loop invariant i < array ==> data[i] == data[i];
		loop invariant \forall integer k; top < k < array ==> k < array;
		loop invariant \forall integer k; top < k < array ==> 0 <= k < array;
		loop invariant \forall integer k; i <= k <= top ==> k < array;
		loop invariant \forall integer k; i <= k <= top ==> 0 <= k < array;
		loop invariant \forall integer k; i <= k < top+1 ==> k < array;
		loop invariant \forall integer k; i <= k < array ==> k < array;
		loop invariant \forall integer k; 0 <= k <= top ==> k < array;
		loop invariant \forall integer k; 0 <= k <= top ==> 0 <= k < array;
		loop invariant \forall integer k; 0 <= k < top+1 ==> k < array;
		loop invariant \forall integer k; 0 <= k < i ==> k < array;
		loop invariant \forall integer k; 0 <= k < i ==> data[k] == data[k];
		loop invariant \forall integer k; 0 <= k < i ==> 0 <= k < array;
		loop invariant \forall integer k; 0 <= k < array ==> data[k] == data[k];
		loop invariant \forall integer k; 0 <= k < array ==> 0 <= data[k] || 1;
		loop invariant 0 <= i;
		loop assigns top;
		loop assigns i;*/
int stub_B(int * data, int data_len, int array);

/*@loop invariant top <= array - 1;
		loop invariant top < array;
		loop invariant top < array ==> data[top] == data[top];
		loop invariant top + 1 <= array;
		loop invariant i < array ==> data[i] == data[i];
		loop invariant \forall integer k; top < k < array ==> k < array;
		loop invariant \forall integer k; top < k < array ==> 0 <= k < array;
		loop invariant \forall integer k; i <= k <= top ==> k < array;
		loop invariant \forall integer k; i <= k <= top ==> 0 <= k < array;
		loop invariant \forall integer k; i <= k < top+1 ==> k < array;
		loop invariant \forall integer k; i <= k < array ==> k < array;
		loop invariant \forall integer k; 0 <= k <= top ==> k < array;
		loop invariant \forall integer k; 0 <= k <= top ==> 0 <= k < array;
		loop invariant \forall integer k; 0 <= k < top+1 ==> k < array;
		loop invariant \forall integer k; 0 <= k < i ==> k < array;
		loop invariant \forall integer k; 0 <= k < i ==> data[k] == data[k];
		loop invariant \forall integer k; 0 <= k < i ==> 0 <= k < array;
		loop invariant \forall integer k; 0 <= k < array ==> data[k] == data[k];
		loop invariant \forall integer k; 0 <= k < array ==> 0 <= data[k] || 1;
		loop invariant 0 <= i;
		loop assigns top;
		loop assigns i;*/
int check_A_implies_B(int * data, int data_len, int array) {
    return stub_A(data, data_len, array);
}

/*@assigns \nothing;
  ensures 0 < \at(array,Pre) - 1 ==> \result <= (\at(array,Pre) - 1);
  ensures !(0 < \at(array,Pre) - 1) ==> \result == 0;*/
int check_B_implies_A(int * data, int data_len, int array) {
    return stub_B(data, data_len, array);
}
