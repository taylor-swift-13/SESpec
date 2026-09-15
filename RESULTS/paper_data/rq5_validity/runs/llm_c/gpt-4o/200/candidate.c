/*@
    requires \valid(a + (0..a_len-1));
    requires size > 0 && size <= a_len;
    ensures \result >= 0 && \result <= size;
    assigns \nothing;
    behavior all_non_positive:
        assumes \forall integer i; 0 <= i < size ==> a[i] <= 0;
        ensures \result == 1;
    behavior at_least_one_positive:
        assumes \exists integer i; 0 <= i < size && a[i] > 0;
        ensures \result >= 1 && \result <= size;
    complete behaviors all_non_positive, at_least_one_positive;
    disjoint behaviors all_non_positive, at_least_one_positive;
*/
int maxSubArraySum(int * a, int a_len, int size);

int maxSubArraySum(int * a, int a_len, int size) {

        int max_so_far = 0;
        int max_ending_here = 0;
        int start = 0;
        int end = 0;
        int s = 0;

        /*@
        loop invariant 0 <= i <= size;
        loop invariant 0 <= start <= i;
        loop invariant 0 <= end <= i;
        loop invariant max_so_far >= 0;
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
