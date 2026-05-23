
#include <stdlib.h>

/*@
  // Define a custom logic function for summation over a range of array elements.
  logic integer sum(int* arr, integer start, integer end) =
    (start >= end) ? 0 : arr[start] + sum(arr, start + 1, end);
*/

int foo199(int number) {

    int *arr = (int *)malloc(sizeof(int) * (number + 1));
    int arr_len = number + 1;
    arr[0] = 1;

    /*@
      loop invariant \forall integer i; 0 <= i < c ==> arr[i] >= 0;
      loop assigns arr[0..number];
    */
    for (int c = 1; c <= number; c++) {
        arr[c] = 0;

        /*@
          loop invariant 0 <= n <= c;
          
          loop invariant \forall integer i; 0 <= i < c ==> arr[i] >= 0;
          loop assigns arr[c];
        */
        for (int n = 0; n < c; n++) {
            arr[c] += arr[n] * arr[c - n - 1];
        }
    }

    return arr[number];
}
