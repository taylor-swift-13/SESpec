
/*@
predicate bounds(int ret, int stop, int arr_len) =
  0 <= ret && ret <= arr_len && -1 <= stop && stop < arr_len;
*/


/*@ 
  requires arr_len >= 0;
  requires \valid_read(arr + (0 .. arr_len - 1));
  assigns \nothing;
  ensures 0 <= \result && \result <= arr_len;
  ensures \result > 0 ==> (\result < arr_len && arr[\result - 1] > arr[\result]);
  ensures \result == 0 || arr[\result - 1] > arr[\result];
*/
int foo170(int * arr, int arr_len) {

  int ret = 0;
  int stop = arr_len - 1;
  
  /*@
    loop invariant 0 <= ret <= arr_len;
    loop invariant -1 <= stop < arr_len;
    loop invariant ret <= stop + 1;
    loop assigns ret, stop;
    loop variant stop - ret + 1;
  */
  while (ret <= stop) {
    int r = ret + (stop - ret) / 2;
    if (r < stop && arr[r] > arr[r + 1]) {
      return r + 1;
    } else if (r > ret && arr[r] < arr[r - 1]) {
      return r;
    }
    if (arr[r] >= arr[ret]) {
      ret = r + 1;
    } else {
      stop = r - 1;
    }
  }
  
  return 0;
}
