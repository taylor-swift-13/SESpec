int dominantIndex(int * nums, int nums_len);

/*@
    requires nums_len > 0;
    requires \valid_read(nums + (0 .. nums_len-1));
    assigns \nothing;
    ensures \result == -1 || (0 <= \result && \result < nums_len);
    /* If a non-negative index is returned it is an index of a maximum element */
    ensures \result >= 0 ==> (\forall integer j; 0 <= j < nums_len ==> nums[j] <= nums[\result]);
    /* If a non-negative index is returned it satisfies the dominance condition */
    ensures \result >= 0 ==> (\forall integer j; 0 <= j < nums_len && j != \result ==> 2*nums[j] <= nums[\result]);
    /* If -1 is returned then there exists a maximum element index k and some j that violates dominance */
    ensures \result == -1 ==> (\exists integer k; 0 <= k < nums_len &&
                                (\forall integer t; 0 <= t < nums_len ==> nums[t] <= nums[k]) &&
                                (\exists integer j; 0 <= j < nums_len && j != k && 2*nums[j] > nums[k]));
*/
int dominantIndex(int * nums, int nums_len) {

        int biggest_index = 0;

        /*@
            loop invariant 0 <= i <= nums_len;
            loop invariant 0 <= biggest_index < nums_len;
            loop invariant (\forall integer j; 0 <= j < i ==> nums[j] <= nums[biggest_index]);
            loop assigns i, biggest_index;
            loop variant nums_len - i;
        */
        for (int i = 0; i < nums_len; i++) {
            if (nums[i] > nums[biggest_index])
                biggest_index = i;
        }

        /*@
            loop invariant 0 <= i <= nums_len;
            loop invariant 0 <= biggest_index < nums_len;
            /* biggest_index is an index of a global maximum (from the previous loop) */
            loop invariant (\forall integer t; 0 <= t < nums_len ==> nums[t] <= nums[biggest_index]);
            /* no violating element has been found among already checked indices */
            loop invariant (\forall integer j; 0 <= j < i ==> (j == biggest_index || 2*nums[j] <= nums[biggest_index]));
            loop assigns i;
            loop variant nums_len - i;
        */
        for (int i = 0; i < nums_len; i++) {
            if (i != biggest_index && 2 * nums[i] > nums[biggest_index])
                return -1;
        }

        return biggest_index;
}
