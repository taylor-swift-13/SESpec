#include <limits.h>

/*@ requires a_len >= 0;
  requires \valid_read(a + (0 .. a_len - 1));
  assigns \nothing;
  ensures 0 <= \result <= a_len;
  ensures \result == 0 ==> a_len >= 0;
  ensures \result < a_len ==> \valid_read(a + \result);
  ensures \result < a_len ==> a[\result] == a[\result]; */
int stub_A(int * a, int a_len, int x);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * a, int a_len, int x);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * a, int a_len, int x) {
    return stub_A(a, a_len, x);
}

/*@ requires a_len >= 0;
  requires \valid_read(a + (0 .. a_len - 1));
  assigns \nothing;
  ensures 0 <= \result <= a_len;
  ensures \result == 0 ==> a_len >= 0;
  ensures \result < a_len ==> \valid_read(a + \result);
  ensures \result < a_len ==> a[\result] == a[\result]; */
int check_B_implies_A(int * a, int a_len, int x) {
    return stub_B(a, a_len, x);
}
