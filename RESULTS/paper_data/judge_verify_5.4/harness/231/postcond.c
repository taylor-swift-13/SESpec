#include <limits.h>

/*@ logic integer count_diff_pairs(int* p, integer n) =
    n <= 1 ? 0 : count_diff_pairs(p, n - 1) + (p[n - 2] != p[n - 1] ? 1 : 0); */

/*@ requires \valid(&p[0] + (0..p_len-1));
  requires \forall integer i; 0 <= i < p_len ==> 0 <= p[i] <= 100;
  requires p_len > 0;
  requires p_len < 100;
  
  ensures \result == count_diff_pairs(p, p_len); */
int stub_A(int * p, int p_len, int array);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * p, int p_len, int array);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * p, int p_len, int array) {
    return stub_A(p, p_len, array);
}

/*@ requires \valid(&p[0] + (0..p_len-1));
  requires \forall integer i; 0 <= i < p_len ==> 0 <= p[i] <= 100;
  requires p_len > 0;
  requires p_len < 100;
  
  ensures \result == count_diff_pairs(p, p_len); */
int check_B_implies_A(int * p, int p_len, int array) {
    return stub_B(p, p_len, array);
}
