
int foo236(int * arr, int arr_len, int x, int n) {

        int i = 0;
        int j = n - 1;
        int result = -1;

        
            
        /*@
          loop invariant 0 <= i;
          loop invariant j < \at(n,Pre);
          loop invariant (n < 0) || (i <= j + 1);
          loop invariant n == \at(n,Pre);
          loop invariant x == \at(x,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
          loop invariant (0 <= \at(n,Pre) - 1) ==> ((result == -1) || (0 <= result < \at(n,Pre) && arr[result] == x));
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((result == -1)&&(j == \at(n,Pre) - 1)&&(i == 0)&&(n == \at(n,Pre))&&(x == \at(x,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (0 <= i <= \at(n,Pre)));
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((result == -1)&&(j == \at(n,Pre) - 1)&&(i == 0)&&(n == \at(n,Pre))&&(x == \at(x,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (-1 <= j < \at(n,Pre)));
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((result == -1)&&(j == \at(n,Pre) - 1)&&(i == 0)&&(n == \at(n,Pre))&&(x == \at(x,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (result == -1 || (0 <= result < \at(n,Pre) && arr[result] == x)));
          loop invariant (!(0 <= \at(n,Pre) - 1)) ==> ((result == -1)&&(j == \at(n,Pre) - 1)&&(i == 0)&&(n == \at(n,Pre))&&(x == \at(x,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop assigns result, i, j;
            */
            while (i <= j) {
            int mid = (i + j) / 2;
            if (arr[mid] == x) {
                result = mid;
                i = mid + 1;
            } else if (arr[mid] < x) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
            

        return result;
}
