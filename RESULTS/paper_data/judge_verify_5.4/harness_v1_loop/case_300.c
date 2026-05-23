#include <limits.h>

/*@ requires (0 <= found) && (found <= top) && (0 <= top) && (top < Array) && (Array == \at(Array,Pre)) && (array_len == \at(array_len,Pre)) && (array == \at(array,Pre));
    assigns \nothing;
*/
void check_A_implies_B(int *Array, int *array, int array_len, int *found, int k, int *top) {
    /*@ assert (top == Array - 1 || array[top] >= array[top + 1]) && (found == 0 || array[found - 1] <= array[found]) && (top == Array - 1 || array[top] >= array[top+1]) && (top <= Array - 1) && (top < Array) && (found == 0 || array[found-1] <= array[found]) && (found == 0 || array[found-1] < array[found]) && (found == 0 || array[found-1] < array[found] || array[found-1] >= array[found]) && (array_len == array_len) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (0 <= found); */
}

/*@ requires (top == Array - 1 || array[top] >= array[top + 1]) && (found == 0 || array[found - 1] <= array[found]) && (top == Array - 1 || array[top] >= array[top+1]) && (top <= Array - 1) && (top < Array) && (found == 0 || array[found-1] <= array[found]) && (found == 0 || array[found-1] < array[found]) && (found == 0 || array[found-1] < array[found] || array[found-1] >= array[found]) && (array_len == array_len) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\forall integer k) && (\exists integer k) && (\exists integer k) && (0 <= found);
    assigns \nothing;
*/
void check_B_implies_A(int *Array, int *array, int array_len, int *found, int k, int *top) {
    /*@ assert (0 <= found) && (found <= top) && (0 <= top) && (top < Array) && (Array == \at(Array,Pre)) && (array_len == \at(array_len,Pre)) && (array == \at(array,Pre)); */
}
