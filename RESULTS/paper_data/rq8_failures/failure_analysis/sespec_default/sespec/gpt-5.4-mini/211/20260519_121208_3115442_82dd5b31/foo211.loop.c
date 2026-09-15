
int foo211(int * arr, int arr_len, int n) {

        int count = 0;
        int i = 0;
        int j = 1;

        /*@
          loop invariant (0 < \at(n,Pre) && 1 < \at(n,Pre)) ==> (0 <= count <= i && 0 <= i <= n && 1 <= j <= n);
          loop invariant (0 < \at(n,Pre) && 1 < \at(n,Pre)) ==> (count <= i && count <= j);
          loop invariant (0 < \at(n,Pre) && 1 < \at(n,Pre)) ==> (0 <= j - i);
          loop invariant (0 < \at(n,Pre) && 1 < \at(n,Pre)) ==> (count <= j);
          loop invariant (0 < \at(n,Pre) && 1 < \at(n,Pre)) ==> (count == 0 || count > 0);
          loop invariant (!(0 < \at(n,Pre) && 1 < \at(n,Pre))) ==> ((j == 1)&&(i == 0)&&(count == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
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
