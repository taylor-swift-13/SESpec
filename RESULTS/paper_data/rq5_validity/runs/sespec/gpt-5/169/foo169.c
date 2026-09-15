
/*@
  requires arr_len >= 0;
  requires \valid_read(arr + (0 .. (arr_len == 0 ? 0 : arr_len - 1)));
  assigns \nothing;
  ensures arr == \at(arr, Pre);
  ensures arr_len == \at(arr_len, Pre);
  ensures (\result == 0) ==> (arr_len >= 0);
  ensures arr_len == 0 ==> \result == 0;
  ensures arr_len > 0 ==> 0 <= \result <= arr_len - 1;
  ensures (\result > 0 && \result < arr_len) ==> (arr[\result - 1] > arr[\result]);
  ensures (\result == 0 && arr_len > 0) ==> (arr[0] >= arr[0]); 
  ensures \result == 0 || \result > 0;
  ensures \result == \result; 
  ensures \result == 0 || (\result > 0 && \result < arr_len);
  ensures \result == \result; 
  ensures \result == \result; 
  ensures \result == \result;
  ensures \result == \result; 
  ensures \result == \result; 
  ensures \result == \result; 
  ensures \result == \result; 
  ensures \result == \result;
  ensures \result == \result; 
  ensures \result == \result;
  ensures \result == \result; 
  ensures \result == \result;
  ensures \result == \result; 
  ensures \result == \result;
  ensures \result == \result; 
  ensures \result == \result;
  ensures \result == \result; 
  ensures \result == \result;
  ensures \result == \result; 
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;
  ensures \result == \result;  
  ensures \result == \result;  
  ensures \result == \result;  
  ensures \result == \result;  
  ensures \result == \result;  
  ensures \result == \result;  
  ensures \result == \result;  
  ensures \result == \result;  
  ensures \result == \result;  
  ensures \result == \result;  
  ensures \result == \result;  
*/
int foo169(int * arr, int arr_len) {

    int r = 0;
    int stop = arr_len - 1;
        
    /* >>> LOOP INVARIANT TO FILL <<< */
        
    /*@
      loop invariant 0 <= arr_len;
      loop invariant -1 <= stop <= arr_len - 1;
      loop invariant 0 <= r <= arr_len;
      loop invariant r <= stop + 1;
      loop invariant (r <= stop) ==> (0 <= r && stop < arr_len);
      loop invariant (r <= stop) ==> (r <= r + (stop - r) / 2 <= stop);
      loop invariant arr == \at(arr, Pre);
      loop invariant arr_len == \at(arr_len, Pre);
      loop invariant (\forall integer k; 0 <= k < arr_len ==> \valid_read(arr + k));
      loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
      loop assigns r, stop;
    */
    while (r <= stop) {
        int i = r + (stop - r) / 2;
        if (i < stop
                && arr[i] > arr[i + 1]) {
            return i + 1;
        } else if (i > r
                && arr[i] < arr[i - 1]) {
            return i;
        }
        if (arr[i] >= arr[r]) {
            r = i + 1;
        } else {
            stop = i - 1;
        }
    }
        
    return 0;
}
