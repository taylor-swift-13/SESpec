
/*@
  // Predicate or logic function to define properties of the array or variables
  // No additional predicates or logic functions are needed for this program.
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
*/

int foo100(int * arr, int arr_len, int n) {

    int count = 0;
    int length = arr_len;
    
    /*@
      loop invariant 0 <= i <= length - 1;
      loop invariant count >= 0;
      loop invariant length == \at(arr_len,Pre);
      loop invariant n == \at(n,Pre);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop invariant \forall integer x, y; 0 <= x < i && x < y < length ==> arr[x] != arr[y] ==> count >= 1;
      loop assigns i, j, count;
    */
    for (int i = 0; i < length - 1; i++) {
        
        /*@
          loop invariant i + 1 <= j <= length;
          loop invariant 0 <= count <= (i * (length - i - 1));
          loop invariant \forall integer x, y; 0 <= x < i && x < y < length ==> arr[x] != arr[y] ==> count >= 1;
          loop assigns j, count;
        */
        for (int j = i + 1; j < length; j++) {
            if (arr[i] != arr[j]) {
                count++;
            }
        }
        
    }
            
    return count;
}
