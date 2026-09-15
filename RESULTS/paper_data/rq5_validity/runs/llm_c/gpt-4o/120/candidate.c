/*@
    requires \valid(nums + (0 .. nums_len - 1));
    requires nums_len >= 1;
    ensures \result == 1 <==> (\forall integer i; 0 <= i < nums_len - 1 ==> nums[i] <= nums[i + 1]) || 
                             (\forall integer i; 0 <= i < nums_len - 1 ==> nums[i] >= nums[i + 1]);
    ensures \result == 0 <==> !((\forall integer i; 0 <= i < nums_len - 1 ==> nums[i] <= nums[i + 1]) || 
                                (\forall integer i; 0 <= i < nums_len - 1 ==> nums[i] >= nums[i + 1]));
    assigns \nothing;
*/
int isMonotonic(int * nums, int nums_len) {

        int inc = 1, dec = 1;
        int n = nums_len;
        /*@
            loop invariant 0 <= i <= n - 1;
            loop invariant inc == 1 ==> (\forall integer j; 0 <= j < i ==> nums[j] <= nums[j + 1]);
            loop invariant dec == 1 ==> (\forall integer j; 0 <= j < i ==> nums[j] >= nums[j + 1]);
            loop assigns i, inc, dec;
            loop variant n - 1 - i;
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
