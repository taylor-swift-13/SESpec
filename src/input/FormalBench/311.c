int foo311(int * nums, int nums_len, int m, int n);

int foo311(int * nums, int nums_len, int m, int n) {

        int sum = 0;
        for (int i = m; i <= n; i++) {
            sum += nums[i];
        }
        return sum;
}
