
        /*@
        */
        
int foo254(int * array, int array_len, int start, int end) {

        int min = start;
        int max = end;
        int mid;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant start <= min <= end + 1;
          loop invariant start - 1 <= max <= end;
          loop invariant \forall integer i; start <= i < min ==> array[i] <= i;
          loop invariant \forall integer i; max < i <= end ==> array[i] > i;
          loop assigns min, max, mid;
            */
            while (min <= max) {
            mid = (min + max) / 2;
            int current = array[mid];

            if (current == mid) {
                min = mid + 1;
            } else if (current < mid) {
                min = mid + 1;
            } else {
                max = mid - 1;
            }
        }
            
        return min;
}
