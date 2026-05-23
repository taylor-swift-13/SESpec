
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures 0 <= \result;
  ensures \result == 0;
*/
int foo241(int * arr, int arr_len, int n) {

        int count = 0;
        int length = arr_len;
        
            
        /*@
          loop invariant (i < \at(arr_len,Pre) - 1) ==> (count >= 0);
          loop invariant (!(i < \at(arr_len,Pre) - 1)) ==> ((length == \at(arr_len,Pre))&&(count == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant length == \at(arr_len,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop assigns i, count;
        */
            for (int i = 0; i < length - 1; i++) {
            
            
        /*@
              loop invariant i <= length;
              loop invariant 0 <= count;
              loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
              loop assigns i, count;
        */
            for (int j = i + 1; j < length; j++) {
                if (arr[i] != arr[j]) {
                    count++;
                }
            }
            
        }
            
        return count;
}
