
int foo168(int * arr, int arr_len) {

    int ret = 0;
    int count = arr_len - 1;
        
    /* >>> LOOP INVARIANT TO FILL <<< */
        
    /*@

      loop invariant ret <= count ==> (0 <= ret && ret <= arr_len - 1 && 0 <= count && count <= arr_len - 1);

      loop invariant \at(arr_len,Pre) == arr_len && \at(arr,Pre) == arr;
      loop invariant count == arr_len - 1 || count < arr_len - 1;

      loop invariant ret <= count ==> (\exists integer r0; r0 == ret + (count - ret)/2 && ret <= r0 && r0 <= count);

      loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);

      loop invariant (ret == arr_len || count == -1) ==> (ret > count);
    */
    while (ret <= count) {
        int r = ret + (count - ret) / 2;
        if (r < count
                && arr[r] > arr[r + 1]) {
            return r + 1;
        } else if (r > ret
                && arr[r] < arr[r - 1]) {
            return r;
        }
        if (arr[r] >= arr[ret]) {
            ret = r + 1;
        } else {
            count = r - 1;
        }
    }
        
    return 0;
}
