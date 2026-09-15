#include <limits.h>

/*@ assigns \nothing;
  ensures (1 < \old(k)) ==> (z == \old(z));
  ensures (1 < \old(k)) ==> (k == \old(k)); */
int stub_A(int z,int k);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int z,int k);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int z,int k) {
    return stub_A(z, k);
}

/*@ assigns \nothing;
  ensures (1 < \old(k)) ==> (z == \old(z));
  ensures (1 < \old(k)) ==> (k == \old(k)); */
int check_B_implies_A(int z,int k) {
    return stub_B(z, k);
}
