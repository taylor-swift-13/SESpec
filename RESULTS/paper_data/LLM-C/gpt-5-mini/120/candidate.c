int isMonotonic(int * nums, int nums_len);

/*@
    requires nums_len >= 0;
    requires nums_len <= 0 || \valid_read(nums + (0 .. nums_len - 1));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures nums_len <= 1 ==> \result == 1;
    ensures \result == 1 <==> (
        (\forall integer i; 0 <= i < nums_len-1 ==> nums[i] <= nums[i+1]) ||
        (\forall integer i; 0 <= i < nums_len-1 ==> nums[i] >= nums[i+1])
    );
*/
int isMonotonic(int * nums, int nums_len) {

        int inc = 1, dec = 1;
        int n = nums_len;
        /*@
            loop invariant 0 <= n;
            loop invariant 0 <= i <= (n > 0 ? n-1 : 0);
            loop invariant inc == 0 || inc == 1;
            loop invariant dec == 0 || dec == 1;
            loop invariant inc == 1 ==> (\forall integer j; 0 <= j < i ==> nums[j] <= nums[j+1]);
            loop invariant dec == 1 ==> (\forall integer j; 0 <= j < i ==> nums[j] >= nums[j+1]);
            loop assigns i, inc, dec;
            loop variant (n - 1) - i >= 0 ? (n - 1) - i : 0;
        */
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                inc = 0;
            }
            if (nums[i] < nums[i + 1]) {
                dec = 0;
            }
        }
        return inc || dec;
}
