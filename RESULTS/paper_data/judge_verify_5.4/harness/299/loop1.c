#include <limits.h>

/*@ logic integer max_int(integer a, integer b) = a > b ? a : b; */

/*@ requires ((0 < \at(array,Pre) - 1) ==> (((top == \at(array,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre))) || (0 <= i <= top))) && ((0 < \at(array,Pre) - 1) ==> (((top == \at(array,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre))) || (top <= \at(array,Pre) - 1))) && ((!(0 < \at(array,Pre) - 1)) ==> ((top == \at(array,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre)))) && (array == \at(array,Pre)) && (data_len == \at(data_len,Pre)) && (data == \at(data,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int array, int *data, int data_len, int i, int k, int top) {
    /*@ assert (top <= array - 1); */
    /*@ assert (top < array); */
    /*@ assert (top < array ==> data[top] == data[top]); */
    /*@ assert (top + 1 <= array); */
    /*@ assert (i < array ==> data[i] == data[i]); */
    /*@ assert (\forall integer k; top < k < array ==> k < array); */
    /*@ assert (\forall integer k; top < k < array ==> 0 <= k < array); */
    /*@ assert (\forall integer k; i <= k <= top ==> k < array); */
    /*@ assert (\forall integer k; i <= k <= top ==> 0 <= k < array); */
    /*@ assert (\forall integer k; i <= k < top+1 ==> k < array); */
    /*@ assert (\forall integer k; i <= k < array ==> k < array); */
    /*@ assert (\forall integer k; 0 <= k <= top ==> k < array); */
    /*@ assert (\forall integer k; 0 <= k <= top ==> 0 <= k < array); */
    /*@ assert (\forall integer k; 0 <= k < top+1 ==> k < array); */
    /*@ assert (\forall integer k; 0 <= k < i ==> k < array); */
    /*@ assert (\forall integer k; 0 <= k < i ==> data[k] == data[k]); */
    /*@ assert (\forall integer k; 0 <= k < i ==> 0 <= k < array); */
    /*@ assert (\forall integer k; 0 <= k < array ==> data[k] == data[k]); */
    /*@ assert (\forall integer k; 0 <= k < array ==> 0 <= data[k] || 1); */
    /*@ assert (0 <= i); */
}

/*@ requires (top <= array - 1) && (top < array) && (top < array ==> data[top] == data[top]) && (top + 1 <= array) && (i < array ==> data[i] == data[i]) && (\forall integer k; top < k < array ==> k < array) && (\forall integer k; top < k < array ==> 0 <= k < array) && (\forall integer k; i <= k <= top ==> k < array) && (\forall integer k; i <= k <= top ==> 0 <= k < array) && (\forall integer k; i <= k < top+1 ==> k < array) && (\forall integer k; i <= k < array ==> k < array) && (\forall integer k; 0 <= k <= top ==> k < array) && (\forall integer k; 0 <= k <= top ==> 0 <= k < array) && (\forall integer k; 0 <= k < top+1 ==> k < array) && (\forall integer k; 0 <= k < i ==> k < array) && (\forall integer k; 0 <= k < i ==> data[k] == data[k]) && (\forall integer k; 0 <= k < i ==> 0 <= k < array) && (\forall integer k; 0 <= k < array ==> data[k] == data[k]) && (\forall integer k; 0 <= k < array ==> 0 <= data[k] || 1) && (0 <= i);
    assigns \nothing;
*/
void check_B_implies_A(int array, int *data, int data_len, int i, int k, int top) {
    /*@ assert ((0 < \at(array,Pre) - 1) ==> (((top == \at(array,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre))) || (0 <= i <= top))); */
    /*@ assert ((0 < \at(array,Pre) - 1) ==> (((top == \at(array,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre))) || (top <= \at(array,Pre) - 1))); */
    /*@ assert ((!(0 < \at(array,Pre) - 1)) ==> ((top == \at(array,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(data_len == \at(data_len,Pre))&&(data == \at(data,Pre)))); */
    /*@ assert (array == \at(array,Pre)); */
    /*@ assert (data_len == \at(data_len,Pre)); */
    /*@ assert (data == \at(data,Pre)); */
}
