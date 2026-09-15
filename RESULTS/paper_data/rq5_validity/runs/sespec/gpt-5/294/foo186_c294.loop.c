
#include <stdlib.h>

/*@ logic integer fib2mod(integer k) =
      k <= 0 ? 0 :
      k == 1 ? 1 :
      ((2 * fib2mod(k - 1) + fib2mod(k - 2)) % 1000000000);
*/

/*@ predicate prefix_ok{L}(int *arr, integer i) =
      i >= 0 &&
      \at(arr[0],L) == 0 &&
      (i >= 1 ==> \at(arr[1],L) == 1) &&
      (\forall integer k; 2 <= k <= i ==> \at(arr[k],L) == ((2 * \at(arr[k - 1],L) + \at(arr[k - 2],L)) % 1000000000));
*/

int foo186_c294(int p) {

    int *arr = (int *)malloc(sizeof(int) * (p + 1));
    int arr_len = p + 1;
    arr[0] = 0;
    arr[1] = 1;

    /*@ 
      loop invariant 2 <= count;
      loop invariant arr_len == p + 1;
      loop invariant arr[0] == 0;
      loop invariant (arr_len >= 2) ==> (arr[1] == 1);
      loop invariant (count >= 3) ==> (arr[count - 1] == ((2 * arr[count - 2] + arr[count - 3]) % 1000000000));
      loop invariant (count <= p) ==> (0 <= count && count < arr_len);
      loop assigns count, arr[2..p];
    */
    for (int count = 2; count <= p; count++) {
        arr[count] = (2 * arr[count - 1]
                      + arr[count - 2]) % 1000000000;
    }

    return arr[p];
}
