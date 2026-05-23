class MoveZeroes {
    //@ requires nums != null;
    //@ assignable nums[*];
    //@ ensures (\num_of int t; 0 <= t && t < nums.length; nums[t] == 0)
    //@           == (\num_of int t; 0 <= t && t < nums.length; \old(nums[t]) == 0);
    //@ ensures (\forall int i; 0 <= i && i < (\num_of int t; 0 <= t && t < nums.length; \old(nums[t]) != 0); nums[i] != 0);
    //@ ensures (\forall int i; (\num_of int t; 0 <= t && t < nums.length; \old(nums[t]) != 0) <= i && i < nums.length; nums[i] == 0);
    //@ ensures (\forall int k; 0 <= k && k < (\num_of int t; 0 <= t && t < nums.length; \old(nums[t]) != 0);
    //@             (\exists int j; 0 <= j && j < nums.length
    //@                 && \old(nums[j]) != 0
    //@                 && (\num_of int u; 0 <= u && u < j; \old(nums[u]) != 0) == k
    //@                 && nums[k] == \old(nums[j])));
    public void moveZeroes(int[] nums) {
        int n = nums.length, left = 0, right = 0;
        //@ maintaining 0 <= left && left <= right && right <= n;
        //@ maintaining (\forall int i; 0 <= i && i < left; nums[i] != 0);
        //@ maintaining (\forall int i; left <= i && i < right; nums[i] == 0);
        //@ maintaining (\forall int i; right < i && i < n; nums[i] == \old(nums[i]));
        //@ maintaining left == (\num_of int t; 0 <= t && t < right; \old(nums[t]) != 0);
        //@ maintaining (\forall int k; 0 <= k && k < left;
        //@                (\exists int j; 0 <= j && j < right
        //@                    && \old(nums[j]) != 0
        //@                    && (\num_of int u; 0 <= u && u < j; \old(nums[u]) != 0) == k
        //@                    && nums[k] == \old(nums[j])));
        //@ decreases n - right;
        while (right < n) {
            if (nums[right] != 0) {
                swap(nums, left, right);
                left++;
            }
            right++;
        }
    }

    //@ requires nums != null;
    //@ requires 0 <= left && left < nums.length;
    //@ requires 0 <= right && right < nums.length;
    //@ assignable nums[left], nums[right];
    //@ ensures nums[left] == \old(nums[right]) && nums[right] == \old(nums[left]);
    //@ ensures (\forall int k; 0 <= k && k < nums.length && k != left && k != right; nums[k] == \old(nums[k]));
    public void swap(int[] nums, int left, int right) {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
    }
}