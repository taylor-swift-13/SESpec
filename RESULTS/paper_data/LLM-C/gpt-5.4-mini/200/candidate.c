/*@
    requires a_len >= 0;
    requires size >= 0;
    requires size <= a_len;
    requires \valid_read(a + (0 .. a_len - 1));
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= size;
*/
int maxSubArraySum(int * a, int a_len, int size);

 /*@
    requires a_len >= 0;
    requires size >= 0;
    requires size <= a_len;
    requires \valid_read(a + (0 .. a_len - 1));
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= size;
*/
int maxSubArraySum(int * a, int a_len, int size) {

        int max_so_far = 0;
        int max_ending_here = 0;
        int start = 0;
        int end = 0;
        int s = 0;

        /*@
            loop invariant 0 <= i <= size;
            loop invariant 0 <= start <= end + 1;
            loop invariant 0 <= s <= i + 1;
            loop invariant max_ending_here >= 0;
            loop assigns i, max_so_far, max_ending_here, start, end, s;
            loop variant size - i;
        */
        for (int i = 0; i < size; i++) {
            max_ending_here += a[i];
            if (max_so_far < max_ending_here) {
                max_so_far = max_ending_here;
                start = s;
                end = i;
            }
            if (max_ending_here < 0) {
                max_ending_here = 0;
                s = i + 1;
            }
        }
        return end - start + 1;
}
