
/*@
*/

/*@
  requires \valid_read(arr + (0 .. arr_len-1));
  requires 0 <= n <= arr_len;
  ensures \result == \sum(0, n-1, 
             \lambda integer i; \sum(i+1, n-1, 
               \lambda integer j; (arr[i] > arr[j]) ? 1 : 0));
*/
        

int foo253(int * arr, int arr_len, int n) {

        int invCount = 0;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant 0 <= invCount;
          loop invariant invCount <= \sum(0, i-1, \lambda integer ii;
                                  \sum(ii+1, n-1, \lambda integer jj; (arr[ii] > arr[jj]) ? 1 : 0));
          loop assigns i, invCount;
            */
            for (int i = 0; i < n; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant invCount ==
            \sum(0, i-1, \lambda integer ii;
              \sum(ii+1, n-1, \lambda integer jj; (arr[ii] > arr[jj]) ? 1 : 0));
          loop assigns i, invCount;
            */
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    invCount++;
                }
            }
            
        }
            
        return invCount;
}
