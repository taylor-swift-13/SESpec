
int foo48_c190(int * sortedArray, int sortedArray_len, int value) {

        if (value < sortedArray[0]) return -1;
        if (value > sortedArray[sortedArray_len-1]) return -1;
        int lo = 0;
        int hi = sortedArray_len-1;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant value == \at(value,Pre);
          loop invariant sortedArray_len == \at(sortedArray_len,Pre);
          loop invariant sortedArray == \at(sortedArray,Pre);
          loop invariant sortedArray[0] <= \at(value,Pre) <= sortedArray[sortedArray_len-1];
          loop invariant lo > 0 ==> sortedArray[lo-1] < \at(value,Pre);
          loop invariant hi < sortedArray_len-1 ==> \at(value,Pre) < sortedArray[hi+1];
          loop assigns lo, hi;
            */
            while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if (sortedArray[mid] == value) {
                return mid;
            } else if (sortedArray[mid] < value) {
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
            
        return -1;
}
