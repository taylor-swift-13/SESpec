#include <limits.h>

/*@ requires a_len >= 0;
  requires b_len == a_len;
  requires \valid_read(a + (0 .. a_len - 1));
  requires \valid_read(b + (0 .. b_len - 1));
  assigns \nothing;
  ensures \result == 1 ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]);
  ensures \result == 0 ==> (\exists integer k; 0 <= k < a_len && a[k] != b[k]);
  ensures \result == 1 <==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]);
  ensures 0 <= \result <= 1;
  ensures \result == 0 ==> b_len == a_len; */
int stub_A(int * a, int a_len, int * b, int b_len);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * a, int a_len, int * b, int b_len);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * a, int a_len, int * b, int b_len) {
    return stub_A(a, a_len, b, b_len);
}

/*@ requires a_len >= 0;
  requires b_len == a_len;
  requires \valid_read(a + (0 .. a_len - 1));
  requires \valid_read(b + (0 .. b_len - 1));
  assigns \nothing;
  ensures \result == 1 ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]);
  ensures \result == 0 ==> (\exists integer k; 0 <= k < a_len && a[k] != b[k]);
  ensures \result == 1 <==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]);
  ensures 0 <= \result <= 1;
  ensures \result == 0 ==> b_len == a_len; */
int check_B_implies_A(int * a, int a_len, int * b, int b_len) {
    return stub_B(a, a_len, b, b_len);
}
