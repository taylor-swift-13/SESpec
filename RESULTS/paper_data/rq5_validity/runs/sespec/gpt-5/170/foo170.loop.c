
int foo170(int * arr, int arr_len) {

        int ret = 0;
        int stop = arr_len - 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= arr_len ==> -1 <= stop <= arr_len - 1;
          loop invariant 0 <= arr_len ==> 0 <= ret <= arr_len;
          loop invariant (ret <= stop) ==> (0 <= ret && stop < arr_len);
          loop invariant (ret <= stop) ==> (ret <= (ret + (stop - ret) / 2) <= stop);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop invariant (ret == 0 && stop == \at(arr_len,Pre) - 1) ||
                          (ret >= 1 || stop <= \at(arr_len,Pre) - 2) ||
                          (ret > stop);
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (ret == 0 || (0 <= ret && ret <= stop + 1));
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (-1 <= stop && stop <= \at(arr_len,Pre) - 1);
          loop invariant (!(0 <= \at(arr_len,Pre) - 1)) ==> ((stop == \at(arr_len,Pre) - 1)&&(ret == 0)&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre) ;
          loop assigns ret, stop;
            */
            while (ret <= stop) {
                        int r = ret + (stop - ret) / 2;
                        if (r < stop
                                        && arr[r] > arr[r + 1]) {
                                return r + 1;
                        } else if (r > ret
                                        && arr[r] < arr[r - 1]) {
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
