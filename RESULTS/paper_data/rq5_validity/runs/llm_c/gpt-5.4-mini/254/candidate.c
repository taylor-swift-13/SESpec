/*@
    requires array_len >= 0;
    requires 0 <= start <= end < array_len;
    requires \valid_read(array + (0 .. array_len - 1));
    assigns \nothing;
    ensures start <= \result <= end + 1;
*/
int findFirstMissing(int * array, int array_len, int start, int end);

 /*@
    requires array_len >= 0;
    requires 0 <= start <= end < array_len;
    requires \valid_read(array + (0 .. array_len - 1));
    assigns \nothing;
    ensures start <= \result <= end + 1;
*/
int findFirstMissing(int * array, int array_len, int start, int end) {

        int min = start;
        int max = end;
        int mid;

        /*@
            loop invariant start <= min <= end + 1;
            loop invariant start - 1 <= max < end;
            loop invariant min <= max + 1;
            loop assigns min, max, mid;
            loop variant max - min + 1;
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
