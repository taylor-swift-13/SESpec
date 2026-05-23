

        
/*@
  requires 0 <= arr_len;
  requires \valid_read(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \result >= 0;
  ensures \true;
  ensures arr == \at(arr,Pre);
  ensures arr_len == \at(arr_len,Pre);
  ensures n == \at(n,Pre);
  ensures \true;
  ensures \true;
  ensures \true;
*/
int foo241(int * arr, int arr_len, int n) {

        int count = 0;
        int length = arr_len;
        
        /*@
          loop invariant 0 <= count;
          loop invariant length == arr_len;
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < length ==> arr[k] == \at(arr[k], Pre);
          loop invariant \forall integer k; 0 <= k < length ==> 0 <= arr[k] <= 100;
          loop assigns i, count;
        */
        for (int i = 0; i < length - 1; i++) {
        
            /*@
              loop invariant i + 1 <= j <= length;
              loop invariant 0 <= count;
              loop invariant \forall integer k; 0 <= k < length ==> arr[k] == \at(arr[k], Pre);
              loop invariant \forall integer k; 0 <= k < length ==> 0 <= arr[k] <= 100;
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
