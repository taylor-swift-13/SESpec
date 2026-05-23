/*@
    requires \valid(array + (0..array_len-1));
    requires 0 <= start <= end < array_len;
    ensures \result >= start && \result <= end + 1;
    ensures \forall integer i; start <= i < \result ==> array[i] == i;
    ensures \result == end + 1 || array[\result] != \result;
    assigns \nothing;
*/
int findFirstMissing(int * array, int array_len, int start, int end);

int findFirstMissing(int * array, int array_len, int start, int end) {

        int min = start;
        int max = end;
        int mid;

        /*@
            loop invariant start <= min <= max + 1;
            loop invariant start <= max <= end;
            loop invariant \forall integer i; start <= i < min ==> array[i] == i;
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
