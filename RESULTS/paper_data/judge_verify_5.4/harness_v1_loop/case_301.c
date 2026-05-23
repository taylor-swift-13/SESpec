#include <limits.h>

/*@ requires (0 <= found <= top + 1) && (top < array) && (array == \at(array,Pre)) && (data_len == \at(data_len,Pre)) && (data == \at(data,Pre)) && (\forall integer k) && ((0 < \at(array,Pre) - 1) ==> (0 <= found <= top + 1)) && ((0 < \at(array,Pre) - 1) ==> (((top == \at(array,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre))) || (0 <= found <= top + 1))) && ((0 < \at(array,Pre) - 1) ==> (((top == \at(array,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre))) || (0 <= top < array))) && ((!(0 < \at(array,Pre) - 1)) ==> ((top == \at(array,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre)))) && (array == \at(array,Pre)) && (data_len == \at(data_len,Pre)) && (data == \at(data,Pre)) && (\forall integer k);
    assigns \nothing;
*/
void check_A_implies_B(int *array, int *data, int data_len, int *found, int k, int *top) {
    /*@ assert (top == array - 1 || data[top] >= data[top + 1]) && (top <= array - 1) && (top < array) && (found == 0 || data[found - 1] <= data[found]) && (found == 0 || data[found - 1] < data[found]) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (0 <= found); */
}

/*@ requires (top == array - 1 || data[top] >= data[top + 1]) && (top <= array - 1) && (top < array) && (found == 0 || data[found - 1] <= data[found]) && (found == 0 || data[found - 1] < data[found]) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (0 <= found);
    assigns \nothing;
*/
void check_B_implies_A(int *array, int *data, int data_len, int *found, int k, int *top) {
    /*@ assert (0 <= found <= top + 1) && (top < array) && (array == \at(array,Pre)) && (data_len == \at(data_len,Pre)) && (data == \at(data,Pre)) && (\forall integer k) && ((0 < \at(array,Pre) - 1) ==> (0 <= found <= top + 1)) && ((0 < \at(array,Pre) - 1) ==> (((top == \at(array,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre))) || (0 <= found <= top + 1))) && ((0 < \at(array,Pre) - 1) ==> (((top == \at(array,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre))) || (0 <= top < array))) && ((!(0 < \at(array,Pre) - 1)) ==> ((top == \at(array,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre)))) && (array == \at(array,Pre)) && (data_len == \at(data_len,Pre)) && (data == \at(data,Pre)) && (\forall integer k); */
}
