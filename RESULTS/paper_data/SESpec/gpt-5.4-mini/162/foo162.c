
#include <stddef.h>

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns arr[0..n-1];
*/
int foo162(int * arr, int arr_len, int n) {

        int i = 0;
        
        /*@
          loop invariant 0 <= i;
          loop invariant (0 < \at(n,Pre)) ==> (0 <= i <= \at(n,Pre));
          loop invariant (0 < \at(n,Pre)) ==> (i <= \at(n,Pre));
          loop invariant (!(0 < \at(n,Pre))) ==> ((i == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop assigns arr[0..n-1], i;
        */
        while (i < n) {
            if (arr[i] <= 0 || arr[i] > n || arr[i] == i + 1) {
                i++;
            } else {
                int temp = arr[i];
                arr[i] = arr[temp - 1];
                arr[temp - 1] = temp;
            }
        }
        
        /*@
          loop invariant 0 <= i;
          loop invariant \forall integer k; 0 <= k < i ==> arr[k] == k + 1;
          loop invariant \forall integer k; 0 <= k < i ==> arr[k] != 0;
          loop invariant (i < n) ==> (\forall integer k; 0 <= k < i ==> arr[k] == k + 1);
          loop invariant (!(i < n)) ==> (\forall integer k; 0 <= k < n ==> arr[k] == k + 1);
          loop invariant \forall integer k; 0 <= k < i ==> arr[k] == k + 1;
          loop assigns i;
        */
        for (i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }
        
        return n + 1;
}
