int dominantIndex(int * nums, int nums_len);

int dominantIndex(int * nums, int nums_len) {

        int biggest_index = 0;

        for (int i = 0; i < nums_len; i++) {
            if (nums[i] > nums[biggest_index])
                biggest_index = i;
        }

        for (int i = 0; i < nums_len; i++) {
            if (i != biggest_index && 2 * nums[i] > nums[biggest_index])
                return -1;
        }

        return biggest_index;
}
