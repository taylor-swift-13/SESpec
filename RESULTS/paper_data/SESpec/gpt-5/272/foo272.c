

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires 0 <= n <= arr_len;
  requires n == 0 || arr_len >= 1;
  assigns \nothing;
  ensures \result != \null;
  ensures \forall integer k; 0 <= k < arr_len ==> arr[k] == \old(arr[k]);
*/
const char * foo272(int * arr, int arr_len, int n) {

    if (n == 0) {
        return "NO";
    }

    int firstElement = arr[0];
    
    /* >>> LOOP INVARIANT TO FILL <<< */
    
    /*@
      loop invariant 1 <= i;
      loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
      loop invariant firstElement == \at(arr[0], Pre);
      loop invariant \forall integer k; 1 <= k < i ==> arr[k] == firstElement;
      loop invariant (!(i < n)) ==> (\forall integer k; 1 <= k < n ==> arr[k] == firstElement);
      loop assigns i;
    */
    for (int i = 1; i < n; i++) {
        if (arr[i] != firstElement) {
            return "NO";
        }
    }
        
    return "YES";
}
