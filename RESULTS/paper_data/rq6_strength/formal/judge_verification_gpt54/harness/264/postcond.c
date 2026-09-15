#include <limits.h>

/*@ requires \valid(&seqNums[0] + (0..seqNums_len-1));
  requires \forall integer i; 0 <= i < seqNums_len ==> 0 <= seqNums[i] <= 100;
  assigns \nothing;
  ensures seqNums_len == 1 ==> \result != \null;
  ensures seqNums_len > 1 ==> \result != \null;
  ensures \forall integer i; 0 <= i < seqNums_len ==> seqNums[i] == \at(seqNums[i], Pre);
  ensures \result == \null ==> \false; */
const char * stub_A(int * seqNums, int seqNums_len);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
const char * stub_B(int * seqNums, int seqNums_len);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
const char * check_A_implies_B(int * seqNums, int seqNums_len) {
    return stub_A(seqNums, seqNums_len);
}

/*@ requires \valid(&seqNums[0] + (0..seqNums_len-1));
  requires \forall integer i; 0 <= i < seqNums_len ==> 0 <= seqNums[i] <= 100;
  assigns \nothing;
  ensures seqNums_len == 1 ==> \result != \null;
  ensures seqNums_len > 1 ==> \result != \null;
  ensures \forall integer i; 0 <= i < seqNums_len ==> seqNums[i] == \at(seqNums[i], Pre);
  ensures \result == \null ==> \false; */
const char * check_B_implies_A(int * seqNums, int seqNums_len) {
    return stub_B(seqNums, seqNums_len);
}
