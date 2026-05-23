#include <limits.h>



/*@requires \valid(&seqNums[0] + (0..seqNums_len-1));
  requires \forall integer i; 0 <= i < seqNums_len ==> 0 <= seqNums[i] <= 100;
  assigns \nothing;
  ensures seqNums_len == 1 ==> \result != \null;
  ensures seqNums_len > 1 ==> \result != \null;
  ensures \forall integer i; 0 <= i < seqNums_len ==> seqNums[i] == \at(seqNums[i], Pre);
  ensures \result == \null ==> \false;*/
const char * stub_A(int * seqNums, int seqNums_len);

/*@loop invariant seqNums_len > 1 ==> 0 < i;
        loop invariant seqNums_len > 1 ==> seqNums[i-1] - seqNums[0] == (i-1) * difference;
        loop invariant seqNums_len > 1 ==> seqNums[i - 1] == seqNums[0] + (i - 1) * difference;
        loop invariant seqNums_len > 1 ==> seqNums[i - 1] - seqNums[0] == (i - 1) * difference;
        loop invariant seqNums_len > 1 ==> seqNums[1] - seqNums[0] == difference;
        loop invariant seqNums_len > 1 ==> seqNums[0] + (i-1) * difference == seqNums[i-1];
        loop invariant seqNums_len > 1 ==> i >= 1;
        loop invariant seqNums_len > 1 ==> i > 0;
        loop invariant seqNums_len > 1 ==> i == 1 || seqNums[i-1] - seqNums[i-2] == difference;
        loop invariant seqNums_len > 1 ==> i == 1 || seqNums[i - 1] - seqNums[i - 2] == difference;
        loop invariant seqNums_len > 1 ==> i <= seqNums_len;
        loop invariant seqNums_len > 1 ==> i < seqNums_len + 1;
        loop invariant seqNums_len > 1 ==> i - 1 < seqNums_len;
        loop invariant seqNums_len > 1 ==> difference == seqNums[1] - seqNums[0];
        loop invariant seqNums_len > 1 ==> \forall integer k; 1 <= k < i ==> seqNums[k] == seqNums[k - 1] + difference;
        loop invariant seqNums_len > 1 ==> \forall integer k; 1 <= k < i ==> seqNums[k] == seqNums[0] + k * difference;
        loop invariant seqNums_len > 1 ==> \forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k-1] == difference;
        loop invariant seqNums_len > 1 ==> \forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k - 1] == difference;
        loop invariant seqNums_len > 1 ==> \forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[0] == k * difference;
        loop invariant seqNums_len > 1 ==> \forall integer k; 0 <= k < i ==> seqNums[k] == seqNums[k];
        loop invariant seqNums_len > 1 ==> \forall integer k; 0 <= k < i ==> seqNums[k] == seqNums[0] + k * difference;
        loop invariant seqNums_len > 1 ==> \forall integer k; 0 <= k < i ==> seqNums[k] - seqNums[0] == k * difference;
        loop invariant seqNums_len > 1 ==> 1 <= i;
        loop invariant seqNums_len > 1 ==> 1 <= i <= seqNums_len;
        loop invariant seqNums_len > 1 ==> 0 <= i - 1 < seqNums_len;
        loop invariant seqNums_len > 1 ==> 0 < i <= seqNums_len;
        loop invariant seqNums_len > 1 ==> (i == 1 || seqNums[i - 1] - seqNums[i - 2] == difference);
        loop invariant seqNums[1] - seqNums[0] == difference;
        loop invariant i > 1 ==> seqNums[i-1] - seqNums[i-2] == difference;
        loop invariant i > 1 ==> seqNums[i - 1] - seqNums[i - 2] == difference;
        loop invariant i == 1 || seqNums[i-1] - seqNums[i-2] == difference;
        loop invariant i == 1 || seqNums[i - 1] - seqNums[i - 2] == difference;
        loop invariant i == 1 ==> difference == seqNums[1] - seqNums[0];
        loop invariant difference == seqNums[1] - seqNums[0];
        loop invariant \forall integer k; 1 <= k < i ==> seqNums[k] == seqNums[k - 1] + difference;
        loop invariant \forall integer k; 1 <= k < i ==> seqNums[k] == seqNums[0] + k * difference;
        loop invariant \forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k-1] == difference;
        loop invariant \forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k - 1] == difference;
        loop invariant \forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[0] == k * difference;
        loop invariant \forall integer k; 0 <= k < i ==> seqNums[k] == seqNums[k];
        loop invariant \forall integer k; 0 <= k < i ==> seqNums[k] == seqNums[0] + k * difference;
        loop invariant \forall integer k; 0 <= k < i ==> seqNums[k] - seqNums[k] == 0;
        loop invariant \forall integer k; 0 <= k < i ==> seqNums[k] - seqNums[0] == k * difference;
        loop invariant 1 <= i;
        loop invariant 0 <= i - 1;
        loop invariant 0 < i;
        loop assigns i;*/
const char * stub_B(int * seqNums, int seqNums_len);

/*@loop invariant seqNums_len > 1 ==> 0 < i;
        loop invariant seqNums_len > 1 ==> seqNums[i-1] - seqNums[0] == (i-1) * difference;
        loop invariant seqNums_len > 1 ==> seqNums[i - 1] == seqNums[0] + (i - 1) * difference;
        loop invariant seqNums_len > 1 ==> seqNums[i - 1] - seqNums[0] == (i - 1) * difference;
        loop invariant seqNums_len > 1 ==> seqNums[1] - seqNums[0] == difference;
        loop invariant seqNums_len > 1 ==> seqNums[0] + (i-1) * difference == seqNums[i-1];
        loop invariant seqNums_len > 1 ==> i >= 1;
        loop invariant seqNums_len > 1 ==> i > 0;
        loop invariant seqNums_len > 1 ==> i == 1 || seqNums[i-1] - seqNums[i-2] == difference;
        loop invariant seqNums_len > 1 ==> i == 1 || seqNums[i - 1] - seqNums[i - 2] == difference;
        loop invariant seqNums_len > 1 ==> i <= seqNums_len;
        loop invariant seqNums_len > 1 ==> i < seqNums_len + 1;
        loop invariant seqNums_len > 1 ==> i - 1 < seqNums_len;
        loop invariant seqNums_len > 1 ==> difference == seqNums[1] - seqNums[0];
        loop invariant seqNums_len > 1 ==> \forall integer k; 1 <= k < i ==> seqNums[k] == seqNums[k - 1] + difference;
        loop invariant seqNums_len > 1 ==> \forall integer k; 1 <= k < i ==> seqNums[k] == seqNums[0] + k * difference;
        loop invariant seqNums_len > 1 ==> \forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k-1] == difference;
        loop invariant seqNums_len > 1 ==> \forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k - 1] == difference;
        loop invariant seqNums_len > 1 ==> \forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[0] == k * difference;
        loop invariant seqNums_len > 1 ==> \forall integer k; 0 <= k < i ==> seqNums[k] == seqNums[k];
        loop invariant seqNums_len > 1 ==> \forall integer k; 0 <= k < i ==> seqNums[k] == seqNums[0] + k * difference;
        loop invariant seqNums_len > 1 ==> \forall integer k; 0 <= k < i ==> seqNums[k] - seqNums[0] == k * difference;
        loop invariant seqNums_len > 1 ==> 1 <= i;
        loop invariant seqNums_len > 1 ==> 1 <= i <= seqNums_len;
        loop invariant seqNums_len > 1 ==> 0 <= i - 1 < seqNums_len;
        loop invariant seqNums_len > 1 ==> 0 < i <= seqNums_len;
        loop invariant seqNums_len > 1 ==> (i == 1 || seqNums[i - 1] - seqNums[i - 2] == difference);
        loop invariant seqNums[1] - seqNums[0] == difference;
        loop invariant i > 1 ==> seqNums[i-1] - seqNums[i-2] == difference;
        loop invariant i > 1 ==> seqNums[i - 1] - seqNums[i - 2] == difference;
        loop invariant i == 1 || seqNums[i-1] - seqNums[i-2] == difference;
        loop invariant i == 1 || seqNums[i - 1] - seqNums[i - 2] == difference;
        loop invariant i == 1 ==> difference == seqNums[1] - seqNums[0];
        loop invariant difference == seqNums[1] - seqNums[0];
        loop invariant \forall integer k; 1 <= k < i ==> seqNums[k] == seqNums[k - 1] + difference;
        loop invariant \forall integer k; 1 <= k < i ==> seqNums[k] == seqNums[0] + k * difference;
        loop invariant \forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k-1] == difference;
        loop invariant \forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k - 1] == difference;
        loop invariant \forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[0] == k * difference;
        loop invariant \forall integer k; 0 <= k < i ==> seqNums[k] == seqNums[k];
        loop invariant \forall integer k; 0 <= k < i ==> seqNums[k] == seqNums[0] + k * difference;
        loop invariant \forall integer k; 0 <= k < i ==> seqNums[k] - seqNums[k] == 0;
        loop invariant \forall integer k; 0 <= k < i ==> seqNums[k] - seqNums[0] == k * difference;
        loop invariant 1 <= i;
        loop invariant 0 <= i - 1;
        loop invariant 0 < i;
        loop assigns i;*/
const char * check_A_implies_B(int * seqNums, int seqNums_len) {
    return stub_A(seqNums, seqNums_len);
}

/*@requires \valid(&seqNums[0] + (0..seqNums_len-1));
  requires \forall integer i; 0 <= i < seqNums_len ==> 0 <= seqNums[i] <= 100;
  assigns \nothing;
  ensures seqNums_len == 1 ==> \result != \null;
  ensures seqNums_len > 1 ==> \result != \null;
  ensures \forall integer i; 0 <= i < seqNums_len ==> seqNums[i] == \at(seqNums[i], Pre);
  ensures \result == \null ==> \false;*/
const char * check_B_implies_A(int * seqNums, int seqNums_len) {
    return stub_B(seqNums, seqNums_len);
}
