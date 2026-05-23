#include <limits.h>

/*@ logic integer power(integer b, integer e) =
    e <= 0 ? 1 : b * power(b, e - 1); */
/*@ logic integer geom_sum(integer b, integer e) =
    e <= 0 ? 1 : geom_sum(b, e - 1) * b + 1; */

/*@ requires k >= 1; */
void stub_A(int z,int k,int a);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
void stub_B(int z,int k,int a);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
void check_A_implies_B(int z,int k,int a) {
    stub_A(z, k, a);
}

/*@ requires k >= 1; */
void check_B_implies_A(int z,int k,int a) {
    stub_B(z, k, a);
}
