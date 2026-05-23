class MoveZeroes {
    /*@ requires nums != null;
 
      @             (\forall int i; 0 <= i && i < m ==> nums[i] != 0) &&
      @             (\forall int i; m <= i && i < nums.length ==> nums[i] == 0) &&
      @             (\forall int k; 0 <= k && k < nums.length ==>
      @                 (\exists int j; 0 <= j && j < nums.length && nums[k] == \old(nums[j]))
      @             )
      @         );
      @*/
    public void moveZeroes(int[] nums) {
        int n = nums.length, left = 0, right = 0;
        /*@ maintaining 0 <= left && 0 <= right && right <= n && left <= right;
          @ maintaining (\forall int i; 0 <= i && i < left ==> nums[i] != 0);
          @ maintaining (\forall int i; 0 <= i && i < left ==>
          @                 (\exists int j; 0 <= j && j < right && \old(nums[j]) != 0 && nums[i] == \old(nums[j]))
          @             );
          @ maintaining (\forall int i; right <= i && i < n ==>
          @                 (\exists int j; 0 <= j && j < n && nums[i] == \old(nums[j]))
          @             );
          @ decreasing n - right;
          @*/
        while (right < n) {
            if (nums[right] != 0) {
                swap(nums, left, right);
                left++;
            }
            right++;
        }
    }

    /*@ requires nums != null && 0 <= left && left < nums.length && 0 <= right && right < nums.length;
      @ ensures nums[left] == \old(nums[right]) && nums[right] == \old(nums[left]);
      @ ensures (\forall int i; i != left && i != right ==> nums[i] == \old(nums[i]));
      @*/
    public void swap(int[] nums, int left, int right) {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
    }
}
