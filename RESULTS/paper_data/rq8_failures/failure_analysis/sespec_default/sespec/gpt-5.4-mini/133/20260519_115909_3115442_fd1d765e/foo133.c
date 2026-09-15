
void foo56_helper1_c133(int * nums, int nums_len);

/*@
  requires \valid(&nums[0] + (0..nums_len-1));
  requires \forall integer i; 0 <= i < nums_len ==> 0 <= nums[i] <= 100;
  requires nums_len > 0;
  requires nums_len < 100;
  assigns nums[left], nums[right];
*/
void foo133(int * nums, int nums_len, int left, int right);


/*@
  requires \valid(&nums[0] + (0..nums_len-1));
  requires \forall integer i; 0 <= i < nums_len ==> 0 <= nums[i] <= 100;
  requires nums_len > 0;
  requires nums_len < 100;
  assigns nums[left], nums[right];
  ensures nums[left] == \old(nums[right]);
  ensures nums[right] == \old(nums[left]);
  ensures \forall integer i; 0 <= i < nums_len && i != left && i != right ==> nums[i] == \old(nums[i]);
*/
void foo133(int * nums, int nums_len, int left, int right) {

        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
}
