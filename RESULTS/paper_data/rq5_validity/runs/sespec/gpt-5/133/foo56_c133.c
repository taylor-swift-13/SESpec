
void foo56_helper1_c133(int * nums, int nums_len);

/*@
  requires nums_len > 0;
  requires nums_len < 100;
  requires \valid(&nums[0] + (0 .. nums_len-1));
  requires 0 <= left < nums_len;
  requires 0 <= right < nums_len;
  requires \forall integer i; 0 <= i < nums_len ==> 0 <= nums[i] <= 100;
  assigns nums[left], nums[right];
  ensures nums[left] == \old(nums[right]) && nums[right] == \old(nums[left]);
  ensures \forall integer i; 0 <= i < nums_len && i != left && i != right ==> nums[i] == \old(nums[i]);
*/
void foo56_c133(int * nums, int nums_len, int left, int right);


/*@
  assigns nums[left], nums[right];
  ensures nums[left] == \old(nums[right]) && nums[right] == \old(nums[left]);
  ensures \forall integer i; 0 <= i < nums_len && i != left && i != right ==> nums[i] == \old(nums[i]);
*/
void foo56_c133(int * nums, int nums_len, int left, int right) {

        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
}
