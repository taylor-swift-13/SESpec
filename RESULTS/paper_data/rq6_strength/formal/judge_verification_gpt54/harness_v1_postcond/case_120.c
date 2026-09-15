#include <limits.h>



/*@requires nums_len >= 0;
  requires \valid(&nums[0] + (0..nums_len-1));
  requires \forall integer i; 0 <= i < nums_len ==> 0 <= nums[i] <= 100;
  assigns \nothing;
  ensures \result == 0 || \result == 1;
  ensures \result == 1 ==> (\forall integer k; 0 <= k < nums_len - 1 ==> nums[k] <= nums[k+1]) || (\forall integer k; 0 <= k < nums_len - 1 ==> nums[k] >= nums[k+1]);
  ensures \result == 0 ==> \true;*/
int stub_A(int * nums, int nums_len);

/*@loop invariant dec == 1 && inc == 0 ==> \forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1];
        loop invariant inc == 1 || inc == 0;
        loop invariant inc == 1 ==> dec == 1 || dec == 0;
        loop invariant inc == 1 ==> dec == 1 || (\exists integer k; 0 <= k < i && nums[k] < nums[k+1]);
        loop invariant inc == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1];
        loop invariant inc == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] <= nums[k + 1];
        loop invariant inc == 1 ==> (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1]);
        loop invariant inc == 1 && dec == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] == nums[k+1];
        loop invariant inc == 1 && dec == 1 ==> (\forall integer k; 0 <= k < i ==> nums[k] == nums[k+1]);
        loop invariant inc == 1 && dec == 0 ==> \forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1];
        loop invariant inc == 1 && dec == 0 ==> \exists integer k; 0 <= k < i && nums[k] < nums[k+1];
        loop invariant inc == 1 && dec == 0 ==> (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1]);
        loop invariant inc == 1 && dec == 0 ==> (\exists integer k; 0 <= k < i && nums[k] < nums[k+1]);
        loop invariant inc == 0 || inc == 1;
        loop invariant inc == 0 || dec == 0 || (\forall integer k; 0 <= k < i ==> nums[k] == nums[k+1]);
        loop invariant inc == 0 ==> dec == 1 || dec == 0;
        loop invariant inc == 0 ==> dec == 0 || dec == 1;
        loop invariant inc == 0 ==> \exists integer k; 0 <= k < i && nums[k] > nums[k+1];
        loop invariant inc == 0 ==> (\exists integer k; 0 <= k < i && nums[k] > nums[k+1]);
        loop invariant inc == 0 ==> (\exists integer k; 0 <= k < i && nums[k] != nums[k+1]);
        loop invariant inc == 0 && dec == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1];
        loop invariant inc == 0 && dec == 1 ==> \exists integer k; 0 <= k < i && nums[k] > nums[k+1];
        loop invariant inc == 0 && dec == 1 ==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1]);
        loop invariant inc == 0 && dec == 1 ==> (\exists integer k; 0 <= k < i && nums[k] > nums[k+1]);
        loop invariant inc == 0 && dec == 0 ==> \exists integer k; 0 <= k < i && nums[k] != nums[k+1];
        loop invariant inc == 0 && dec == 0 ==> (\exists integer k; 0 <= k < i && nums[k] > nums[k+1]) && (\exists integer k; 0 <= k < i && nums[k] < nums[k+1]);
        loop invariant inc == 0 && dec == 0 ==> (\exists integer k; 0 <= k < i && nums[k] < nums[k+1]) && (\exists integer k; 0 <= k < i && nums[k] > nums[k+1]);
        loop invariant inc == 0 && dec == 0 ==> (\exists integer k; 0 <= k < i && nums[k] != nums[k+1]);
        loop invariant i == 0 ==> inc == 1 && dec == 1;
        loop invariant dec == 1 || dec == 0;
        loop invariant dec == 1 ==> inc == 1 || inc == 0;
        loop invariant dec == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1];
        loop invariant dec == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] >= nums[k + 1];
        loop invariant dec == 1 ==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1]);
        loop invariant dec == 1 && inc == 0 ==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1]);
        loop invariant dec == 0 || dec == 1;
        loop invariant dec == 0 ==> inc == 1 || inc == 0;
        loop invariant dec == 0 ==> inc == 0 || inc == 1;
        loop invariant dec == 0 ==> \exists integer k; 0 <= k < i && nums[k] < nums[k+1];
        loop invariant dec == 0 ==> (\exists integer k; 0 <= k < i && nums[k] < nums[k+1]);
        loop invariant dec == 0 ==> (\exists integer k; 0 <= k < i && nums[k] != nums[k+1]);
        loop invariant \forall integer k; 0 <= k < i ==> (nums[k] > nums[k+1] ==> inc == 0);
        loop invariant \forall integer k; 0 <= k < i ==> (nums[k] < nums[k+1] ==> dec == 0);
        loop invariant 0 <= i;
        loop invariant 0 <= i || n <= 1;
        loop invariant (inc == 1) ==> (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1]);
        loop invariant (inc == 1) <==> (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1]);
        loop invariant (inc == 1 && dec == 0) ==> (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1]);
        loop invariant (inc == 0) ==> (\exists integer k; 0 <= k < i && nums[k] > nums[k+1]);
        loop invariant (inc == 0 || dec == 0) ==> (\exists integer k; 0 <= k < i && nums[k] != nums[k+1]);
        loop invariant (inc == 0 && dec == 1) ==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1]);
        loop invariant (dec == 1) ==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1]);
        loop invariant (dec == 1) <==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1]);
        loop invariant (dec == 0) ==> (\exists integer k; 0 <= k < i && nums[k] < nums[k+1]);
        loop invariant (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1]) ==> dec == 1;
        loop invariant (\forall integer k; 0 <= k < i ==> nums[k] > nums[k+1] ==> inc == 0);
        loop invariant (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1]) ==> inc == 1;
        loop invariant (\forall integer k; 0 <= k < i ==> nums[k] < nums[k+1] ==> dec == 0);
        loop invariant (\forall integer k; 0 <= k < i && nums[k] > nums[k+1] ==> inc == 0);
        loop invariant (\forall integer k; 0 <= k < i && nums[k] < nums[k+1] ==> dec == 0);
        loop invariant (\exists integer k; 0 <= k < i && nums[k] > nums[k+1]) ==> inc == 0;
        loop invariant (\exists integer k; 0 <= k < i && nums[k] < nums[k+1]) ==> dec == 0;
        loop assigns inc;
        loop assigns i;
        loop assigns dec;*/
int stub_B(int * nums, int nums_len);

/*@loop invariant dec == 1 && inc == 0 ==> \forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1];
        loop invariant inc == 1 || inc == 0;
        loop invariant inc == 1 ==> dec == 1 || dec == 0;
        loop invariant inc == 1 ==> dec == 1 || (\exists integer k; 0 <= k < i && nums[k] < nums[k+1]);
        loop invariant inc == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1];
        loop invariant inc == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] <= nums[k + 1];
        loop invariant inc == 1 ==> (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1]);
        loop invariant inc == 1 && dec == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] == nums[k+1];
        loop invariant inc == 1 && dec == 1 ==> (\forall integer k; 0 <= k < i ==> nums[k] == nums[k+1]);
        loop invariant inc == 1 && dec == 0 ==> \forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1];
        loop invariant inc == 1 && dec == 0 ==> \exists integer k; 0 <= k < i && nums[k] < nums[k+1];
        loop invariant inc == 1 && dec == 0 ==> (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1]);
        loop invariant inc == 1 && dec == 0 ==> (\exists integer k; 0 <= k < i && nums[k] < nums[k+1]);
        loop invariant inc == 0 || inc == 1;
        loop invariant inc == 0 || dec == 0 || (\forall integer k; 0 <= k < i ==> nums[k] == nums[k+1]);
        loop invariant inc == 0 ==> dec == 1 || dec == 0;
        loop invariant inc == 0 ==> dec == 0 || dec == 1;
        loop invariant inc == 0 ==> \exists integer k; 0 <= k < i && nums[k] > nums[k+1];
        loop invariant inc == 0 ==> (\exists integer k; 0 <= k < i && nums[k] > nums[k+1]);
        loop invariant inc == 0 ==> (\exists integer k; 0 <= k < i && nums[k] != nums[k+1]);
        loop invariant inc == 0 && dec == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1];
        loop invariant inc == 0 && dec == 1 ==> \exists integer k; 0 <= k < i && nums[k] > nums[k+1];
        loop invariant inc == 0 && dec == 1 ==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1]);
        loop invariant inc == 0 && dec == 1 ==> (\exists integer k; 0 <= k < i && nums[k] > nums[k+1]);
        loop invariant inc == 0 && dec == 0 ==> \exists integer k; 0 <= k < i && nums[k] != nums[k+1];
        loop invariant inc == 0 && dec == 0 ==> (\exists integer k; 0 <= k < i && nums[k] > nums[k+1]) && (\exists integer k; 0 <= k < i && nums[k] < nums[k+1]);
        loop invariant inc == 0 && dec == 0 ==> (\exists integer k; 0 <= k < i && nums[k] < nums[k+1]) && (\exists integer k; 0 <= k < i && nums[k] > nums[k+1]);
        loop invariant inc == 0 && dec == 0 ==> (\exists integer k; 0 <= k < i && nums[k] != nums[k+1]);
        loop invariant i == 0 ==> inc == 1 && dec == 1;
        loop invariant dec == 1 || dec == 0;
        loop invariant dec == 1 ==> inc == 1 || inc == 0;
        loop invariant dec == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1];
        loop invariant dec == 1 ==> \forall integer k; 0 <= k < i ==> nums[k] >= nums[k + 1];
        loop invariant dec == 1 ==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1]);
        loop invariant dec == 1 && inc == 0 ==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1]);
        loop invariant dec == 0 || dec == 1;
        loop invariant dec == 0 ==> inc == 1 || inc == 0;
        loop invariant dec == 0 ==> inc == 0 || inc == 1;
        loop invariant dec == 0 ==> \exists integer k; 0 <= k < i && nums[k] < nums[k+1];
        loop invariant dec == 0 ==> (\exists integer k; 0 <= k < i && nums[k] < nums[k+1]);
        loop invariant dec == 0 ==> (\exists integer k; 0 <= k < i && nums[k] != nums[k+1]);
        loop invariant \forall integer k; 0 <= k < i ==> (nums[k] > nums[k+1] ==> inc == 0);
        loop invariant \forall integer k; 0 <= k < i ==> (nums[k] < nums[k+1] ==> dec == 0);
        loop invariant 0 <= i;
        loop invariant 0 <= i || n <= 1;
        loop invariant (inc == 1) ==> (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1]);
        loop invariant (inc == 1) <==> (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1]);
        loop invariant (inc == 1 && dec == 0) ==> (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1]);
        loop invariant (inc == 0) ==> (\exists integer k; 0 <= k < i && nums[k] > nums[k+1]);
        loop invariant (inc == 0 || dec == 0) ==> (\exists integer k; 0 <= k < i && nums[k] != nums[k+1]);
        loop invariant (inc == 0 && dec == 1) ==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1]);
        loop invariant (dec == 1) ==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1]);
        loop invariant (dec == 1) <==> (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1]);
        loop invariant (dec == 0) ==> (\exists integer k; 0 <= k < i && nums[k] < nums[k+1]);
        loop invariant (\forall integer k; 0 <= k < i ==> nums[k] >= nums[k+1]) ==> dec == 1;
        loop invariant (\forall integer k; 0 <= k < i ==> nums[k] > nums[k+1] ==> inc == 0);
        loop invariant (\forall integer k; 0 <= k < i ==> nums[k] <= nums[k+1]) ==> inc == 1;
        loop invariant (\forall integer k; 0 <= k < i ==> nums[k] < nums[k+1] ==> dec == 0);
        loop invariant (\forall integer k; 0 <= k < i && nums[k] > nums[k+1] ==> inc == 0);
        loop invariant (\forall integer k; 0 <= k < i && nums[k] < nums[k+1] ==> dec == 0);
        loop invariant (\exists integer k; 0 <= k < i && nums[k] > nums[k+1]) ==> inc == 0;
        loop invariant (\exists integer k; 0 <= k < i && nums[k] < nums[k+1]) ==> dec == 0;
        loop assigns inc;
        loop assigns i;
        loop assigns dec;*/
int check_A_implies_B(int * nums, int nums_len) {
    return stub_A(nums, nums_len);
}

/*@requires nums_len >= 0;
  requires \valid(&nums[0] + (0..nums_len-1));
  requires \forall integer i; 0 <= i < nums_len ==> 0 <= nums[i] <= 100;
  assigns \nothing;
  ensures \result == 0 || \result == 1;
  ensures \result == 1 ==> (\forall integer k; 0 <= k < nums_len - 1 ==> nums[k] <= nums[k+1]) || (\forall integer k; 0 <= k < nums_len - 1 ==> nums[k] >= nums[k+1]);
  ensures \result == 0 ==> \true;*/
int check_B_implies_A(int * nums, int nums_len) {
    return stub_B(nums, nums_len);
}
