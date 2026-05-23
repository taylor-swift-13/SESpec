
void foo56_helper1_c133(int * nums, int nums_len);

/*@
  requires \valid(&nums[0] + (0..nums_len-1));
  requires \forall integer i; 0 <= i < nums_len ==> 0 <= nums[i] <= 100;
  requires nums_len > 0;
  requires nums_len < 100;
  requires 0 <= left < nums_len;
  requires 0 <= right < nums_len;
  assigns nums[left], nums[right];
  ensures nums[left] == \at(nums[right], Pre);
  ensures nums[right] == \at(nums[left], Pre);
  ensures \forall integer k; 0 <= k < nums_len && k != left && k != right ==> nums[k] == \at(nums[k], Pre);
*/
void foo133(int * nums, int nums_len, int left, int right) {

        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
}
