void foo56_helper1_c133(int * nums, int nums_len);

/*@
  requires \valid(&nums[0] + (0..nums_len-1));
  requires \forall integer i; 0 <= i < nums_len ==> 0 <= nums[i] <= 100;
  requires nums_len > 0;
  requires nums_len < 100;
           assigns PLACE_HOLDER; 
  ensures PLACE_HOLDER;   
*/
void foo56_c133(int * nums, int nums_len, int left, int right);


void foo56_c133(int * nums, int nums_len, int left, int right) {

        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
}