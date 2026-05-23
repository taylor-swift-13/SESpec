
/*@
  logic integer abs(integer x) = x >= 0 ? x : -x;
*/

/*@ requires n >= 1;
    requires \valid_read(arr + (0 .. n-1));
*/
int foo211(int * arr, int arr_len, int n) {

        int count = 0;
        int i = 0;
        int j = 1;

        /*@
          loop invariant 0 <= i <= n;
          loop invariant 1 <= j <= n;
          loop invariant 0 <= count <= i;
          loop invariant count <= j - 1;
          loop invariant i <= j;
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
          loop invariant \forall integer k; 0 <= k < i ==> k < n;
          loop invariant \forall integer k; 1 <= k < j ==> k < n;

          loop invariant (0 < \at(n,Pre) && 1 < \at(n,Pre)) ==> (count <= i && count <= j - 1);
          loop invariant (0 < \at(n,Pre) && 1 < \at(n,Pre)) ==> (0 <= i <= \at(n,Pre));
          loop invariant (0 < \at(n,Pre) && 1 < \at(n,Pre)) ==> (1 <= j <= \at(n,Pre));
          loop invariant (!(0 < \at(n,Pre) && 1 < \at(n,Pre))) ==> ((j == 1)&&(i == 0)&&(count == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre) ;
          loop assigns i, j, count;
        */
        while (i < n && j < n) {
            if (arr[i] == arr[j]) {
                i++;
                j++;
                count++;
            } else if (arr[i] > arr[j]) {
                i++;
            } else {
                j++;
            }
        }

        return count;
}
