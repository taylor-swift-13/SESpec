#include <limits.h>

/*@ requires p != 0;
  assigns \nothing;
  ensures value < 1 || \result == 0 || (1 <= \result && \result <= value);
  ensures \result == 0 ==> \forall integer i; 1 <= i <= value ==> (i % p) != z;
  ensures \result != 0 ==> (\result % p) == z;
  ensures \result != 0 ==> \forall integer i; \result < i <= value ==> (i % p) != z;
  ensures \result != 0 ==> \forall integer i; 1 <= i <= value && (i % p) == z ==> i <= \result; */
int stub_A(int value, int p, int z);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int value, int p, int z);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int value, int p, int z) {
    return stub_A(value, p, z);
}

/*@ requires p != 0;
  assigns \nothing;
  ensures value < 1 || \result == 0 || (1 <= \result && \result <= value);
  ensures \result == 0 ==> \forall integer i; 1 <= i <= value ==> (i % p) != z;
  ensures \result != 0 ==> (\result % p) == z;
  ensures \result != 0 ==> \forall integer i; \result < i <= value ==> (i % p) != z;
  ensures \result != 0 ==> \forall integer i; 1 <= i <= value && (i % p) == z ==> i <= \result; */
int check_B_implies_A(int value, int p, int z) {
    return stub_B(value, p, z);
}
