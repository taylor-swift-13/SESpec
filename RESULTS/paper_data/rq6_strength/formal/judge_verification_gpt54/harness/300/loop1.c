#include <limits.h>

/*@ requires (0 <= found) && (found <= top) && (0 <= top) && (top < Array) && (Array == \at(Array,Pre)) && (array_len == \at(array_len,Pre)) && (array == \at(array,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int Array, int *array, int array_len, int found, int k, int top) {
    /*@ assert (top == Array - 1 || array[top] >= array[top + 1]); */
    /*@ assert (found == 0 || array[found - 1] <= array[found]); */
    /*@ assert (top == Array - 1 || array[top] >= array[top+1]); */
    /*@ assert (top <= Array - 1); */
    /*@ assert (top < Array); */
    /*@ assert (found == 0 || array[found-1] <= array[found]); */
    /*@ assert (found == 0 || array[found-1] < array[found]); */
    /*@ assert (found == 0 || array[found-1] < array[found] || array[found-1] >= array[found]); */
    /*@ assert (array_len == array_len); */
    /*@ assert (\forall integer k; found <= k < top ==> array[k] <= array[k+1] || array[k] >= array[k+1]); */
    /*@ assert (\forall integer k; found <= k < top ==> array[k] < array[k+1] || array[k] >= array[k+1]); */
    /*@ assert (\forall integer k; found <= k < top ==> (array[k] < array[k+1] || array[k] >= array[k+1])); */
    /*@ assert (\forall integer k; 0 <= k < top ==> array[k] <= array[k+1] || array[k] >= array[k+1]); */
    /*@ assert (\exists integer k; found <= k); */
    /*@ assert (\exists integer k; 0 <= k); */
    /*@ assert (0 <= found); */
}

/*@ requires (top == Array - 1 || array[top] >= array[top + 1]) && (found == 0 || array[found - 1] <= array[found]) && (top == Array - 1 || array[top] >= array[top+1]) && (top <= Array - 1) && (top < Array) && (found == 0 || array[found-1] <= array[found]) && (found == 0 || array[found-1] < array[found]) && (found == 0 || array[found-1] < array[found] || array[found-1] >= array[found]) && (array_len == array_len) && (\forall integer k; found <= k < top ==> array[k] <= array[k+1] || array[k] >= array[k+1]) && (\forall integer k; found <= k < top ==> array[k] < array[k+1] || array[k] >= array[k+1]) && (\forall integer k; found <= k < top ==> (array[k] < array[k+1] || array[k] >= array[k+1])) && (\forall integer k; 0 <= k < top ==> array[k] <= array[k+1] || array[k] >= array[k+1]) && (\exists integer k; found <= k) && (\exists integer k; 0 <= k) && (0 <= found);
    assigns \nothing;
*/
void check_B_implies_A(int Array, int *array, int array_len, int found, int k, int top) {
    /*@ assert (0 <= found); */
    /*@ assert (found <= top); */
    /*@ assert (0 <= top); */
    /*@ assert (top < Array); */
    /*@ assert (Array == \at(Array,Pre)); */
    /*@ assert (array_len == \at(array_len,Pre)); */
    /*@ assert (array == \at(array,Pre)); */
}
