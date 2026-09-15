
int foo254(int * array, int array_len, int start, int end) {

        int min = start;
        int max = end;
        int mid;

        /*@
          loop invariant start == \at(start,Pre);
          loop invariant end == \at(end,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant (!(\at(start,Pre) <= \at(end,Pre))) ==> (min == \at(start,Pre) && max == \at(end,Pre));
          loop assigns mid, min, max;
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
