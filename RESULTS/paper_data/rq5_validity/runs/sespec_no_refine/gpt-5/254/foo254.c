

/*@
  requires \valid(&array[0] + (0..array_len-1));
  requires \forall integer i; 0 <= i < array_len ==> 0 <= array[i] <= 100;
  requires array_len > 0;
  requires array_len < 100;
  assigns \nothing;
  ensures array == \old(array);
  ensures array_len == \old(array_len);
  ensures start == \old(start);
  ensures end == \old(end);
  ensures \result == \old(start) ==> \old(start) > \old(end) || \old(start) <= \old(end) + 1;
  ensures \result == \result;
*/
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
