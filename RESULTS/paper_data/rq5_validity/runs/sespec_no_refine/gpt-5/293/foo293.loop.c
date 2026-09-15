
#include <stdlib.h>

int foo293(int seed) {

    int *arr = (int *)malloc(sizeof(int) * (seed + 1));
    int arr_len = seed + 1;
    arr[0] = 0;
    arr[1] = 1;
        
    /*@ 
      loop invariant 2 <= p <= seed + 1;
      loop invariant arr_len == seed + 1;
      loop invariant \valid(arr + (0 .. arr_len - 1));
      loop invariant arr[0] == 0;
      loop invariant arr[1] == 1;
      loop invariant \forall integer k; 2 <= k < p ==> arr[k] == ( (2 * arr[k - 1] + arr[k - 2]) % 1000000000 );
      loop assigns PLACE_HOLDER_ASSIGNMENTS;
    */
    for (int p = 2; p <= seed; p++) {
            arr[p] = (2 * arr[p - 1]
                    + arr[p - 2]) % 1000000000;
        }
        
    return arr[seed];
}
