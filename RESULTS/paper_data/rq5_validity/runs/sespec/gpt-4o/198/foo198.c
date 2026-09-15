
#include <stdlib.h>

/*@ 
  // Logic function to compute the sum of products for array elements
  logic integer sum_of_products(int* arr, integer n, integer cat) =
    (n == 0) ? 0 : sum_of_products(arr, n - 1, cat) + arr[n - 1] * arr[cat - n];
*/

/*@ 
  // Predicate to validate the array elements
  predicate valid_array(int* arr, integer len) =
    \forall integer i; 0 <= i < len ==> arr[i] >= 0;
*/

/*@ 
  // Predicate to validate the array computation logic
  predicate computed_array(int* arr, integer len) =
    \forall integer i; 0 <= i < len ==> (i == 0 ? arr[i] == 1 : arr[i] == sum_of_products(arr, i, i));
*/

/*@
  requires c >= 0;
  assigns \nothing;
  ensures \result >= 0;
*/
int foo198(int c) {

    int *arr = (int *)malloc(sizeof(int) * (c + 1));
    int arr_len = c + 1;
    arr[0] = 1;

    /*@
      loop invariant 1 <= cat <= c + 1;
      loop invariant valid_array(arr, cat);
      loop invariant computed_array(arr, cat);
      loop assigns arr[0..c];
    */
    for (int cat = 1; cat <= c; cat++) {
        arr[cat] = 0;

        /*@
          loop invariant 0 <= n <= cat;
          loop invariant arr[cat] == sum_of_products(arr, n, cat);
          loop invariant valid_array(arr, cat);
          loop assigns arr[cat];
        */
        for (int n = 0; n < cat; n++) {
            arr[cat] += arr[n] * arr[cat - n - 1];
        }
    }

    return arr[c];
}
