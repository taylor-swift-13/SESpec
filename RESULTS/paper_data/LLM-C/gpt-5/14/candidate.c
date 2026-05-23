#include <stdlib.h>

/*@ requires \true;
    assigns \nothing;
    ensures \result == 1 <==>
              ((unknown > 0 && 1 == 1) || (unknown <= 0 && 0 == 0));
*/
int func(int unknown);

int func(int unknown) {
    int arr_len = unknown > 0 ? 1 : 0;
    /*@ assert arr_len == 0 || arr_len == 1; */

    int *arr = arr_len ? (int *)malloc(sizeof(int) * arr_len) : 0;

    /*@ assert arr_len == 0 ==> arr == \null; */

    if (unknown > 0) arr[0] = 1;

    /*@ assert unknown > 0 ==> (arr_len == 1 && arr != \null); */
    /*@ assert unknown > 0 ==> \valid(arr + (0 .. arr_len-1)); */
    /*@ assert unknown > 0 ==> arr[0] == 1; */

    if (unknown > 0) return arr_len == 1 && arr[0] == 1;
    return arr_len == 0;
}
