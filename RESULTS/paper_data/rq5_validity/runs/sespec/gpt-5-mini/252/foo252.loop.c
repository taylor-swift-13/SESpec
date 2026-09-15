
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires n >= 0;
*/
int foo252(int * arr, int arr_len, int n, int sum) {

        int count = 0;
        
        /*@
          loop invariant 0 <= count;
          loop invariant sum == \at(sum,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer x; 0 <= x < arr_len ==> 0 <= arr[x] <= 100;
          loop assigns i, count;
        */
        for (int i = 0; i < n; i++) {
            
            /*@
              loop invariant i <= n;
              loop invariant 0 <= count;
              loop assigns j, count;
            */
            for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == sum) {
                    count++;
                }
            }
            
        }
            
        return count;
}
