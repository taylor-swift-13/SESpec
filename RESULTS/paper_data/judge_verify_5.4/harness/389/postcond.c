#include <limits.h>

/*@ assigns \nothing; */
int stub_A(int p, int q, int n);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int p, int q, int n);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int p, int q, int n) {
    return stub_A(p, q, n);
}

/*@ assigns \nothing; */
int check_B_implies_A(int p, int q, int n) {
    return stub_B(p, q, n);
}
