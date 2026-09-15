
void foo56_helper1_c133(int * nums, int nums_len);

/*@
  requires \valid(&nums[0] + (0..nums_len-1));
  requires \forall integer i; 0 <= i < nums_len ==> 0 <= nums[i] <= 100;
  requires nums_len > 0;
  requires nums_len < 100;
  assigns \nothing; // No caller-visible state is modified in this function
  ensures \true;    // No specific postcondition to enforce
*/
void foo133(int * nums, int nums_len, int left, int right);


/*@
  requires \valid(&nums[0] + (0..nums_len-1));
  requires \forall integer i; 0 <= i < nums_len ==> 0 <= nums[i] <= 100;
  requires nums_len > 0;
  requires nums_len < 100;
  requires 0 <= left < nums_len;
  requires 0 <= right < nums_len;
  assigns nums[left], nums[right]; // Explicitly list modified locations
  ensures nums[left] == \old(nums[right]); // Postcondition for swapped values
  ensures nums[right] == \old(nums[left]); // Postcondition for swapped values
  ensures \forall integer i; 0 <= i < nums_len && i != left && i != right ==> nums[i] == \old(nums[i]); // Unchanged elements
*/
void foo133(int * nums, int nums_len, int left, int right) {

        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
}
