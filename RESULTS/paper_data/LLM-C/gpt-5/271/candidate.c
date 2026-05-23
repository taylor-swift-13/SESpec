int getOddOccurrence(int * arr, int arr_len, int arrSize);

/*@ 
  logic integer odds_count(int *a, integer n) =
    (n <= 0) ? 0 : \sum integer k; 0 <= k < n; ((a[k] % 2 != 0) ? 1 : 0);

  logic integer odds_count_prefix(int *a, integer i) =
    (i < 0) ? 0 : \sum integer k; 0 <= k <= i; ((a[k] % 2 != 0) ? 1 : 0);
*/

/*@
  requires arrSize >= 0;
  requires arr_len >= arrSize;
  requires \valid_read(arr + (0 .. arrSize - 1));

  assigns \nothing;

  ensures result == 0 <=> odds_count(arr, arrSize) == 0;
  ensures result == 0 || (result % 2 != 0);

  ensures result != 0 ==> 
    (\exists integer j; 0 <= j < arrSize &&
       arr[j] % 2 != 0 &&
       odds_count_prefix(arr, j) % 2 == 1 &&
       result == arr[j] &&
       (\forall integer k; j < k < arrSize ==>
          !((arr[k] % 2 != 0) && (odds_count_prefix(arr, k) % 2 == 1))));

  ensures (odds_count(arr, arrSize) % 2 == 1) ==>
    (\exists integer j; 0 <= j < arrSize &&
       arr[j] % 2 != 0 &&
       (\forall integer k; j < k < arrSize ==> arr[k] % 2 == 0) &&
       result == arr[j]);

  ensures (odds_count(arr, arrSize) > 0 && odds_count(arr, arrSize) % 2 == 0) ==>
    (\exists integer j1, j2; 0 <= j1 < j2 < arrSize &&
       arr[j1] % 2 != 0 &&
       arr[j2] % 2 != 0 &&
       (\forall integer k; j2 < k < arrSize ==> arr[k] % 2 == 0) &&
       (\forall integer k; j1 < k < j2 ==> arr[k] % 2 == 0) &&
       result == arr[j1]);
*/
int getOddOccurrence(int * arr, int arr_len, int arrSize) {

        int result = 0;
        int count = 0;
        /*@
          loop invariant 0 <= i <= arrSize;
          loop invariant count == (\sum integer k; 0 <= k < i; ((arr[k] % 2 != 0) ? 1 : 0));
          loop invariant (count == 0) <=> (result == 0);
          loop invariant count > 0 ==> 
            (\exists integer j; 0 <= j < i &&
               arr[j] % 2 != 0 &&
               ( (\sum integer t; 0 <= t <= j; ((arr[t] % 2 != 0) ? 1 : 0)) % 2 == 1 ) &&
               result == arr[j] &&
               (\forall integer k; j < k < i ==>
                  !((arr[k] % 2 != 0) &&
                    ((\sum integer t; 0 <= t <= k; ((arr[t] % 2 != 0) ? 1 : 0)) % 2 == 1))));
          loop assigns i, count, result;
          loop variant arrSize - i;
        */
        for (int i = 0; i < arrSize; i++) {
            if (arr[i] % 2 != 0) {
                count++;
                if (count % 2 != 0) {
                    result = arr[i];
                }
            }
        }
        return result;
}
