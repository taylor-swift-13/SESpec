
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
*/

int foo253(int * arr, int arr_len, int n) {

        int invCount = 0;

        /*@
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> 0 <= arr[k] <= 100;
          loop assigns i, invCount;
        */
        for (int i = 0; i < n; i++) {

            /*@
              loop invariant i + 1 <= j <= n;
              
              loop assigns j, invCount;
            */
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    invCount++;
                }
            }

        }

        return invCount;
}
