#include <limits.h>

/*@ requires (0 <= found <= top + 1) && (top < array) && (array == \at(array,Pre)) && (data_len == \at(data_len,Pre)) && (data == \at(data,Pre)) && (\forall integer k; 0 <= k < data_len ==> data[k] == \at(data[k],Pre)) && ((0 < \at(array,Pre) - 1) ==> (0 <= found <= top + 1)) && ((0 < \at(array,Pre) - 1) ==> (((top == \at(array,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre))) || (0 <= found <= top + 1))) && ((0 < \at(array,Pre) - 1) ==> (((top == \at(array,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre))) || (0 <= top < array))) && ((!(0 < \at(array,Pre) - 1)) ==> ((top == \at(array,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre)))) && (array == \at(array,Pre)) && (data_len == \at(data_len,Pre)) && (data == \at(data,Pre)) && (\forall integer k; 0 <= k < data_len ==> data[k] == \at(data[k],Pre));
    assigns \nothing;
*/
void check_A_implies_B(int array, int *data, int data_len, int found, int k, int top) {
    /*@ assert (top == array - 1 || data[top] >= data[top + 1]); */
    /*@ assert (top <= array - 1); */
    /*@ assert (top < array); */
    /*@ assert (found == 0 || data[found - 1] <= data[found]); */
    /*@ assert (found == 0 || data[found - 1] < data[found]); */
    /*@ assert (\forall integer k; found <= k < top ==> data[k] <= data[k + 1] || data[k] >= data[k + 1]); */
    /*@ assert (\forall integer k; found <= k < top ==> data[k] < data[k + 1] || data[k] >= data[k + 1]); */
    /*@ assert (\exists integer k; found <= k <= top ==> data[k] >= data[k + 1]); */
    /*@ assert (0 <= found); */
}

/*@ requires (top == array - 1 || data[top] >= data[top + 1]) && (top <= array - 1) && (top < array) && (found == 0 || data[found - 1] <= data[found]) && (found == 0 || data[found - 1] < data[found]) && (\forall integer k; found <= k < top ==> data[k] <= data[k + 1] || data[k] >= data[k + 1]) && (\forall integer k; found <= k < top ==> data[k] < data[k + 1] || data[k] >= data[k + 1]) && (\exists integer k; found <= k <= top ==> data[k] >= data[k + 1]) && (0 <= found);
    assigns \nothing;
*/
void check_B_implies_A(int array, int *data, int data_len, int found, int k, int top) {
    /*@ assert (0 <= found <= top + 1); */
    /*@ assert (top < array); */
    /*@ assert (array == \at(array,Pre)); */
    /*@ assert (data_len == \at(data_len,Pre)); */
    /*@ assert (data == \at(data,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < data_len ==> data[k] == \at(data[k],Pre)); */
    /*@ assert ((0 < \at(array,Pre) - 1) ==> (0 <= found <= top + 1)); */
    /*@ assert ((0 < \at(array,Pre) - 1) ==> (((top == \at(array,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre))) || (0 <= found <= top + 1))); */
    /*@ assert ((0 < \at(array,Pre) - 1) ==> (((top == \at(array,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre))) || (0 <= top < array))); */
    /*@ assert ((!(0 < \at(array,Pre) - 1)) ==> ((top == \at(array,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre)))); */
    /*@ assert (array == \at(array,Pre)); */
    /*@ assert (data_len == \at(data_len,Pre)); */
    /*@ assert (data == \at(data,Pre)); */
    /*@ assert (\forall integer k; 0 <= k < data_len ==> data[k] == \at(data[k],Pre)); */
}
