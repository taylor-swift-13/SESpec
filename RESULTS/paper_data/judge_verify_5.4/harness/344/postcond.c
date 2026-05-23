#include <limits.h>

/*@ assigns \nothing;
  
  ensures \result == -1 || \result >= l;
  ensures \result == -1 || \result <= m;
  ensures \result == -1 || \result >= \old(l);
  ensures \result == -1 || \result <= \old(m); */
int stub_A(int code, int b, int l, int m);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int code, int b, int l, int m);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int code, int b, int l, int m) {
    return stub_A(code, b, l, m);
}

/*@ assigns \nothing;
  
  ensures \result == -1 || \result >= l;
  ensures \result == -1 || \result <= m;
  ensures \result == -1 || \result >= \old(l);
  ensures \result == -1 || \result <= \old(m); */
int check_B_implies_A(int code, int b, int l, int m) {
    return stub_B(code, b, l, m);
}
