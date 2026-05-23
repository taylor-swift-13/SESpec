
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result >= 0 ;
*/
int foo252(int * arr, int arr_len, int n, int sum) {

        int count = 0;
        
            
        /*@
          loop invariant 0 <= count;
          loop invariant count >= 0;
          loop assigns i, count;
        */
            for (int i = 0; i < n; i++) {
            
            
        /*@
              loop invariant count >= 0;
              loop invariant i + 1 <= j <= n;
              loop assigns j, count;
              loop variant n - j;
            */
            for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == sum) {
                    count++;
                }
            }
            
        }
            
        return count;
}
