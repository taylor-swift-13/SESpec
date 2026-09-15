
/*@
  // Predicate or logic function to define properties of the array or variables
  // No additional predicates or logic functions are needed for this program.
*/

/*@ 
  logic integer count_distinct_pairs{L}(int *arr, integer length) = 
    \sum(0, length - 2, 
         \lambda integer i; \sum(i + 1, length - 1, 
                                 \lambda integer j; (arr[i] != arr[j] ? 1 : 0)));

  requires \valid(arr + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns count;
  ensures \result == count_distinct_pairs{Pre}(arr, arr_len);
*/
int foo100(int *arr, int arr_len, int n) {

    int count = 0;
    int length = arr_len;
    
    /*@
      loop invariant 0 <= i <= length - 1;
      loop invariant count == \sum(0, i - 1, 
                                   \lambda integer x; \sum(x + 1, length - 1, 
                                                           \lambda integer y; (arr[x] != arr[y] ? 1 : 0)));
      loop invariant length == \at(arr_len, Pre);
      loop invariant n == \at(n, Pre);
      loop invariant arr_len == \at(arr_len, Pre);
      loop invariant arr == \at(arr, Pre);
      loop assigns i, j, count;
    */
    for (int i = 0; i < length - 1; i++) {
        
        /*@
          loop invariant i + 1 <= j <= length;
          loop invariant count == \sum(0, i - 1, 
                                       \lambda integer x; \sum(x + 1, length - 1, 
                                                               \lambda integer y; (arr[x] != arr[y] ? 1 : 0)))
                                  + \sum(i + 1, j - 1, 
                                         \lambda integer y; (arr[i] != arr[y] ? 1 : 0));
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
